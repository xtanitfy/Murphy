#include "output_layer.h"
#include "log.h"

int OutputLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer);
int OutputLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer);
int OutputLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer);

#if 0
int OutputLayer_register(NET_s *pNet,OUTPUT_LAYER_PARA_s *para)
{
	CHECK_EXPR_RET(para == NULL,-1);

	OUTPUT_LAYER_s *pOutputLayer = (OUTPUT_LAYER_s *)malloc(sizeof(OUTPUT_LAYER_s));
	CHECK_EXPR_RET(pOutputLayer == NULL,-1);
	memset(pOutputLayer,'\0',sizeof(OUTPUT_LAYER_s));
	memcpy(&pOutputLayer->para,para,sizeof(pOutputLayer->para));

	LAYER_s *pLayer = (LAYER_s *)malloc(sizeof(LAYER_s));
	CHECK_EXPR_RET(pLayer == NULL,-1);
	memset(pLayer,'\0',sizeof(LAYER_s));
	
	NET_addNames(pLayer,para->typeName,para->name,
					para->namePrev,para->nNamePrev);
	pLayer->currLayer = pOutputLayer;
	pLayer->init = OutputLayerInit;
	pLayer->forward = OutputLayerForward;
	pLayer->backward = OutputLayerBackward;
	
	return NET_Register(pNet,pLayer);
	
}
#endif



int OutputLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	CHECK_EXPR_RET(pLayer == NULL,-1);

	BLOB_s *pPrevBlob = pLayer->pPrev[0]->pData;
	CHECK_EXPR_RET(pPrevBlob == NULL,-1);

	OUTPUT_LAYER_PARA_s *pPara = &pLayer->para->select.outputLayer;

	NET_autoCreateBlob(pNetPara,pPrevBlob,&pLayer->pData,
						pPara->num,1,1,1,1,&pLayer->k,&pLayer->b);
	
	CHECK_EXPR_RET(pPara->weightInit == NULL,-1);
	pPara->weightInit(pLayer->k);
	
	CHECK_EXPR_RET(pPara->biasInit == NULL,-1);
	pPara->biasInit(pLayer->b);

	pLayer->k->type = BLOB_TYPE_WEIGHT;
	LOG_writeBlobToTxtFile("fw.txt",pLayer->k);	
	
	BLOB_shapeLike(pLayer->pData,&pLayer->pError);
	BLOB_shapeLike(pLayer->pData,&pLayer->pDelta);
	BLOB_shapeLike(pLayer->k,&pLayer->pDK);
	BLOB_shapeLike(pLayer->b,&pLayer->pDB);
	
	return 0;
}


int OutputLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	CHECK_EXPR_RET(pLayer == NULL,-1);
	BLOB_s *pPrevBlob = pLayer->pPrev[0]->pData;
	CHECK_EXPR_RET(pPrevBlob == NULL,-1);

	OUTPUT_LAYER_PARA_s *pPara = &pLayer->para->select.outputLayer;
	BLOB_s *pPrevData = pPrevBlob;
	BLOB_s *pCurrData = pLayer->pData;
	
	CHECK_EXPR_RET(pCurrData == NULL,-1);
	CHECK_EXPR_RET(pCurrData->heightSize!= 1,-1);
	CHECK_EXPR_RET(pCurrData->widthSize!= 1,-1);
	CHECK_EXPR_RET(pLayer->k == NULL,-1);
	CHECK_EXPR_RET(pLayer->b == NULL,-1);
	int kh = pLayer->k->heightSize;
	int kw = pLayer->k->widthSize;
	CHECK_EXPR_RET(kh != 1,-1);
	CHECK_EXPR_RET(kw != 1,-1);

	BLOB_DATA_PTR(pCurrData,ptrCurr);
	BLOB_DATA_PTR(pPrevData,ptrPrev);
	BLOB_DATA_PTR(pLayer->k,ptrK);
	BLOB_DATA_PTR(pLayer->b,ptrB);

	double tmp = 0;
	
	for (int i_batch = 0;i_batch < pCurrData->numSize;i_batch++) {
		for (int i_out = 0;i_out < pCurrData->channelSize;i_out++) {
			tmp = 0;
			for (int i_in = 0;i_in < pPrevBlob->channelSize;i_in++) {
				tmp += ptrPrev[i_batch][i_in][0][0] * \
					ptrK[i_out][i_in][0][0];
			}	
			ptrCurr[i_batch][i_out][0][0]  = pPara->function(tmp + \
						ptrB[0][i_out][0][0],FUNC_VALUE);
		}
	}
	
	//pCurrData->type = BLOB_TYPE_DATA;
	//LOG_writeBlobToTxtFile("output.txt",pCurrData);
	return 0;
}



int OutputLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	CHECK_EXPR_RET(pLayer == NULL,-1);

	BLOB_s *pTableY  = pNetPara->pTableY;
	CHECK_EXPR_RET(pTableY == NULL,-1);
	
	OUTPUT_LAYER_PARA_s *pPara = &pLayer->para->select.outputLayer;
	CHECK_EXPR_RET(pLayer->pError == NULL,-1);
	CHECK_EXPR_RET(pLayer->pData == NULL,-1);
	double *pErrorData = BLOB_data(pLayer->pError);
	double *pData = BLOB_data(pLayer->pData);
	double *pDelta = BLOB_data(pLayer->pDelta);
	double *pTableYData = BLOB_data(pTableY);
	CHECK_EXPR_RET(pTableY->count != pLayer->pError->count,-1);
	CHECK_EXPR_RET(pTableY->count != pLayer->pData->count,-1);
	CHECK_EXPR_RET(pTableY->count != pLayer->pDelta->count,-1);

	for (int i = 0;i < pTableY->count;i++) {
		pErrorData[i] = pData[i] - pTableYData[i]; 
		pDelta[i] = pErrorData[i] * pPara->function(pData[i],FUNC_DERIVA);
	}
	//LOG_writeBlobToTxtFile("outputDelta.txt",pLayer->pDelta);

	/*计算loss*/
	//OPTS_s *pOpts = NET_GetOpts();
	//CHECK_EXPR_RET(pOpts == NULL,-1);
	/*跟新权重和偏置*/
	BLOB_s *pDK = pLayer->pDK;
	BLOB_s *pDB = pLayer->pDB;
	BLOB_DATA_PTR(pDK,ptrDK);
	BLOB_DATA_PTR(pDB,ptrDB);
	BLOB_DATA_PTR(pLayer->pDelta,ptrDelta);
	BLOB_s *pPrevData = pLayer->pPrev[0]->pData;
	CHECK_EXPR_RET(pPrevData == NULL,-1);
	BLOB_DATA_PTR(pPrevData,ptrPrev);

	//double alpha = pOpts->alpha;
	double sum = 0;
	//CHECK_EXPR_RET(pLayer->k == NULL,-1);
	//BLOB_DATA_PTR(pLayer->k,ptrK);
	
	BLOB_s *pCurrData = pLayer->pData;
	
	for (int i_out = 0;i_out < pCurrData->channelSize;i_out++) {
		for (int i_in = 0;i_in < pPrevData->channelSize;i_in++) {
			sum = 0;
			for (int i_batch = 0;i_batch < pCurrData->numSize;i_batch++) {
				sum += ptrDelta[i_batch][i_out][0][0] *  \
					ptrPrev[i_batch][i_in][0][0] ;
			}
			ptrDK[i_out][i_in][0][0] = sum/pCurrData->numSize;
		}
	}

	//pDK->type = BLOB_TYPE_WEIGHT;
	//LOG_writeBlobToTxtFile("output_dk.txt",pDK);

	//CHECK_EXPR_RET(pLayer->b == NULL,-1);
	//BLOB_DATA_PTR(pLayer->b,ptrB);
	
	for (int i_out = 0;i_out < pCurrData->channelSize;i_out++) {
		sum = 0;
		for (int i_batch = 0;i_batch < pCurrData->numSize;i_batch++) {
			sum += ptrDelta[i_batch][i_out][0][0];
		}
		ptrDB[0][i_out][0][0] = sum/pCurrData->numSize;
	}
		
	//pDB->type = BLOB_TYPE_BIAS;
	//LOG_writeBlobToTxtFile("output_db.txt",pDB);
	
	return 0;
}

