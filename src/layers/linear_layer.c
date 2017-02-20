#include <stdio.h>
#include <stdlib.h>
#include "conv_layer.h"
#include "net.h"
#include "log.h"
#include "linear_layer.h"

int LinearLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer);
int LinearLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer);
int LinearLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer);

#if 0
int LinearLayer_register(NET_s *pNet,LINEAR_LAYER_PARA_s *para)
{
	CHECK_EXPR_RET(para == NULL,-1);

	LINEAR_LAYER_s *pLinearLayer = (LINEAR_LAYER_s *)malloc(sizeof(LINEAR_LAYER_s));
	CHECK_EXPR_RET(pLinearLayer == NULL,-1);
	memset(pLinearLayer,'\0',sizeof(LINEAR_LAYER_s));
	memcpy(&pLinearLayer->para,para,sizeof(LINEAR_LAYER_PARA_s));

	LAYER_s *pLayer = (LAYER_s *)malloc(sizeof(LAYER_s));
	CHECK_EXPR_RET(pLayer == NULL,-1);
	memset(pLayer,'\0',sizeof(LAYER_s));

	pLayer->currLayer = pLinearLayer;
	pLayer->init = LinearLayerInit;
	pLayer->forward = LinearLayerForward;
	pLayer->backward = LinearLayerBackward;
	NET_addNames(pLayer,para->typeName,para->name,
					para->namePrev,para->nNamePrev);
	
	NET_Register(pNet,pLayer);

	return 0;
}
#endif


int LinearLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	CHECK_EXPR_RET(pLayer == NULL,-1);
	BLOB_s *pPrevBlob = pLayer->pPrev[0]->pData;
	CHECK_EXPR_RET(pPrevBlob == NULL,-1);
	
	int size = pPrevBlob->channelSize * pPrevBlob->heightSize* pPrevBlob->widthSize;
	int ret = BLOB_create(&pLayer->pData,pNetPara->batchsize,size,
								1,1,TRUE);
	CHECK_EXPR_RET(ret != 0,-1);

	ret = BLOB_shapeLike(pLayer->pData,&pLayer->pDelta);
	CHECK_EXPR_RET(ret != 0,-1);

	return 0;
}

int LinearLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	CHECK_EXPR_RET(pLayer == NULL,-1);
	
	BLOB_s *pPrevData = pLayer->pPrev[0]->pData;
	CHECK_EXPR_RET(pPrevData == NULL,-1);
	
	BLOB_DATA_PTR(pLayer->pData,ptrCurr);
	BLOB_DATA_PTR(pPrevData,ptrPrev);

	int cnt = 0;
	BLOB_s *pData = pLayer->pData;
	
	for (int i_batch = 0;i_batch < pData->numSize;i_batch++) {
		cnt = 0;
		for (int i_in = 0;i_in < pPrevData->channelSize;i_in++) {
			for (int i_w = 0; i_w < pPrevData->widthSize;i_w++) {
				for (int i_h = 0; i_h < pPrevData->heightSize;i_h++) {
					ptrCurr[i_batch][cnt++][0][0] = 
						ptrPrev[i_batch][i_in][i_h][i_w];
				}
			}
		}
	}
	
	
	return 0;
}


int LinearLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	/*线性层是上一层的展开，因为无需进行函数的求导*/
	CHECK_EXPR_RET(pLayer == NULL,-1);
	CHECK_EXPR_RET(pLayer->nNext <= 0,-1);
	BLOB_s *pNextK = pLayer->pNext[0]->k;
	CHECK_EXPR_RET(pNextK == NULL,-1);
	
	BLOB_s *pNextDelta = pLayer->pNext[0]->pDelta;
	CHECK_EXPR_RET(pNextDelta == NULL,-1);
	
	BLOB_s *pDelta = pLayer->pDelta;
	CHECK_EXPR_RET(pDelta == NULL,-1);
	
	BLOB_DATA_PTR(pNextK,ptrNextK);
	BLOB_DATA_PTR(pNextDelta,ptrNextDelta);
	BLOB_DATA_PTR(pDelta,ptrCurrDelta);

	double tmp = 0;
	
	for (int i_batch = 0;i_batch < pDelta->numSize;i_batch++) {
		for (int i_in = 0;i_in < pDelta->channelSize;i_in++) {
			tmp = 0;
			for (int i_out = 0;i_out < pNextDelta->channelSize;i_out++) {
				tmp += ptrNextK[i_out][i_in][0][0] * \
							ptrNextDelta[i_batch][i_out][0][0];
			}
			ptrCurrDelta[i_batch][i_in][0][0] = tmp;
		}
	}
	
	//LOG_writeBlobToTxtFile("linearDelta.txt",pDelta);
	
	/*线性还原,这里暂时不考虑多层的合并，这里需要LAYER_TYPE_MERGE去做*/
	BLOB_s *pPrevDelta = pLayer->pPrev[0]->pDelta;
	BLOB_s *pPrevData = pLayer->pPrev[0]->pData;
	CHECK_EXPR_RET(pPrevDelta == NULL,-1);
	CHECK_EXPR_RET(pPrevData == NULL,-1);
	BLOB_DATA_PTR(pPrevDelta,ptrPrevDelta);
//	BLOB_DATA_PTR(pPrevData,ptrPrevData);

	int cnt = 0;
	
	for (int i_batch = 0;i_batch < pPrevData->numSize;i_batch++) {
		cnt = 0;
		for (int i_in = 0;i_in < pPrevData->channelSize;i_in++) {
			for (int i_w = 0; i_w < pPrevData->widthSize;i_w++) {
				for (int i_h = 0; i_h < pPrevData->heightSize;i_h++) {
					ptrPrevDelta[i_batch][i_in][i_h][i_w] = \
						ptrCurrDelta[i_batch][cnt++][0][0]; 
				}
			}
		}
	}

	return 0;
}


