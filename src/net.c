#include "net.h"
#include "public.h"
#include "log.h"
#include "para.h"
#include "type_layer_reg.h"

int NET_addLayer(NET_s *pNet,LAYER_PARA_s *pLayerPara)
{
	CHECK_EXPR_RET(pNet == NULL,-1);
	CHECK_EXPR_RET(pLayerPara == NULL,-1);

	LAYER_s *pLayer = (LAYER_s *)malloc(sizeof(LAYER_s));
	CHECK_EXPR_RET(pLayer == NULL,-1);
	memset(pLayer,'\0',sizeof(LAYER_s));

	char *typename = pLayerPara->typeName;
	BOOL isFind = FALSE;
	int i = 0;
	for (i = 0;i < DIM_OF(gLayerRegInfo);i++) {
		if (!strcmp(gLayerRegInfo[i].typename,typename)) {
			isFind = TRUE;
			break;
		}
	}
	CHECK_EXPR_RET(isFind == FALSE,-1);
	pLayer->init = gLayerRegInfo[i].funcInit;
	pLayer->forward = gLayerRegInfo[i].funcForward;
	pLayer->backward = gLayerRegInfo[i].funcBackward;
	LAYER_PARA_s *para = (LAYER_PARA_s *)malloc(sizeof(LAYER_PARA_s));
	CHECK_EXPR_RET(para == NULL,-1);
	memcpy(para,pLayerPara,sizeof(LAYER_PARA_s));	
	pLayer->para = para;
	
	int ret = NET_Register(pNet,pLayer);
	CHECK_EXPR_RET(ret != 0,-1);

	printf("Add %s layer ok!\n",pLayer->para->name);
	
	return 0;
}

NET_s *NET_create(NET_PARA_s *pNetPara)
{
	CHECK_EXPR_RET(pNetPara == NULL,NULL);
	
	NET_s *pNet = (NET_s *)malloc(sizeof(NET_s));
	CHECK_EXPR_RET(pNet == NULL,NULL);

	pNet->pMTree = MTREE_create(pNet);
	CHECK_EXPR_RET(pNet->pMTree == NULL,NULL);
	
	memcpy(&pNet->para, pNetPara, sizeof(pNet->para));

	for (int i = 0;i < LAYERS_MAX_N;i++) {
		pNet->layers[i] = NULL;
	} 
	pNet->layerId = 0;

	int ret = BLOB_create(&pNet->pTableY,pNetPara->batchsize,pNetPara->classifyNum,1,1,FALSE);
	CHECK_EXPR_RET(ret != 0,NULL);

	pNet->para.pTableY = pNet->pTableY;
	printf("NET_init!\n");
	
	return pNet;
}


static int NETUpdate(void *usr,int idCurr,int *idPrev,int nIdPrev)
{
	NET_s *pNet = (void *)usr;
	CHECK_EXPR_RET(pNet == NULL,-1);

	LAYER_s *pLayer = pNet->layers[idCurr];
	CHECK_EXPR_RET(pLayer == NULL,-1);
	if (pLayer->k == NULL || pLayer->b == NULL \
				|| pLayer->pDK == NULL || pLayer->pDB == NULL) {
		//DBG_PRT;
		return 0;
	}

	double alpha = pNet->para.alpha;
	BLOB_DATA_PTR(pLayer->k,ptrK);
	BLOB_DATA_PTR(pLayer->b,ptrB);
	BLOB_DATA_PTR(pLayer->pDK,ptrDK);
	BLOB_DATA_PTR(pLayer->pDB,ptrDB);

	unsigned long numOut = pLayer->k->numSize;
	unsigned long numIn = pLayer->k->channelSize;
	unsigned long width = pLayer->k->widthSize;
	unsigned long height = pLayer->k->heightSize;
	
	for (int i_out = 0;i_out < numOut;i_out++) {
		for (int i_in = 0;i_in < numIn;i_in++) {
			for (int i_h = 0;i_h < height;i_h++) {
				for (int i_w = 0;i_w < width;i_w++) {
					ptrK[i_out][i_in][i_h][i_w] -=  alpha * \
						ptrDK[i_out][i_in][i_h][i_w];		
				}
			}
		}
	}


	unsigned long b_out = pLayer->b->channelSize;	
	for (int i_out = 0;i_out < b_out;i_out++) {
		ptrB[0][i_out][0][0] = alpha * \
			ptrDB[0][i_out][0][0];	
	}


#if defined(DEBUG)
	char filename[128];
	snprintf(filename,128,"%s_newk.txt",pLayer->para->name);
	pLayer->k->type = BLOB_TYPE_WEIGHT;
	LOG_writeBlobToTxtFile(filename,pLayer->k);

	snprintf(filename,128,"%s_newb.txt",pLayer->para->name);
	pLayer->b->type = BLOB_TYPE_BIAS;
	LOG_writeBlobToTxtFile(filename,pLayer->b);
#endif
	return 0;
}


int NET_Update(NET_s *pNet)
{
	return MTREE_forward(pNet->pMTree,NETUpdate);
}

NET_PARA_s *NET_GetNetPara(NET_s *pNet)
{
	return &pNet->para;
}

static int NETForwardPrint(void *usr,int idCurr,int *idPrev,int nIdPrev)
{
	NET_s *pNet = (NET_s *)usr;
	CHECK_EXPR_RET(pNet == NULL,-1);
	
	LAYER_s *pLayerCurr =  pNet->layers[idCurr];
	CHECK_EXPR_RET(pLayerCurr == NULL,-1);
	
	printf("====>%s nNext:%d \n",pLayerCurr->para->name,pLayerCurr->nNext);
	for (int i = 0;i < nIdPrev;i++) {
		printf("**%s-->%s:\n",pNet->layers[idPrev[i]]->para->name,pLayerCurr->para->name);
	}
	CHECK_EXPR_RET(pLayerCurr->pData == NULL,-1);
	BLOB_printPara(pLayerCurr->pData);
	
	return 0;
}

int NET_printForward(NET_s *pNet)
{
	printf(">>>>NET_Forward:\n");
	return MTREE_forward(pNet->pMTree,NETForwardPrint);
}

static int NETBackwardPrint(void *usr,int idCurr,int *idNext,int nIdNext)
{
	NET_s *pNet = (NET_s *)usr;
	CHECK_EXPR_RET(pNet == NULL,-1);

	LAYER_s *pLayerCurr =  pNet->layers[idCurr];
	CHECK_EXPR_RET(pLayerCurr == NULL,-1);

	printf("<====%s:\n",pLayerCurr->para->name);
	for (int i = 0;i < nIdNext;i++) {
		printf("**%s<--%s:\n",pLayerCurr->para->name,pNet->layers[idNext[i]]->para->name);
	}
	CHECK_EXPR_RET(pLayerCurr->pData == NULL,-1);
	BLOB_printPara(pLayerCurr->pData);
	
	return 0;
}

int NET_printBackward(NET_s *pNet)
{
	printf("<<<<NET_Backward:\n");
	return MTREE_backward(pNet->pMTree,NETBackwardPrint);
}


static int NETLayerInit(NET_s *pNet,int idCurr,int *idPrev,int nIdPrev)
{
	CHECK_EXPR_RET(pNet->layers[idCurr]->init == NULL,-1);
	for (int i = 0;i < nIdPrev;i++) {
		 pNet->layers[idCurr]->pPrev[i] = pNet->layers[idPrev[i]];
	}
	CHECK_EXPR_RET(pNet->layers[idCurr]->init == NULL,-1);
	int ret = pNet->layers[idCurr]->init(&pNet->para,pNet->layers[idCurr]);
	CHECK_EXPR_RET(ret != 0,-1);
	
	return 0;
}

static int NETForward(void *usr,int idCurr,int *idPrev,int nIdPrev)
{
	NET_s *pNet = (NET_s *)usr;
	CHECK_EXPR_RET(pNet == NULL,-1);
		
	LAYER_s *pLayerCurr = pNet->layers[idCurr];
	CHECK_EXPR_RET(pLayerCurr == NULL,-1);

	CHECK_EXPR_RET(pLayerCurr->forward == NULL,-1);
	for (int i = 0;i < nIdPrev;i++) {
		pLayerCurr->pPrev[i] = pNet->layers[idPrev[i]];
	}
	pLayerCurr->nPrev = nIdPrev;

	CalTimeStart();
	CHECK_EXPR_RET(pLayerCurr->forward == NULL,-1);
	int ret = pLayerCurr->forward(&pNet->para,pLayerCurr);
	CHECK_EXPR_RET(ret != 0,-1);
	CalTimeEnd(pLayerCurr->para->name);
	
#if defined(DEBUG)
	BLOB_s *pData = pLayerCurr->pData;
	char filename[128];
	pData->type =  BLOB_TYPE_DATA;
	snprintf(filename,sizeof(filename),"%s_data.txt",pLayerCurr->para->name);
	LOG_writeBlobToTxtFile(filename,pData);
	
	BLOB_s *pK = pLayerCurr->k;
	if (pK != NULL) {
		pK->type = BLOB_TYPE_WEIGHT;
		snprintf(filename,sizeof(filename),"%s_k.txt",pLayerCurr->para->name);
		LOG_writeBlobToTxtFile(filename,pK);
	}

	BLOB_s *pB = pLayerCurr->b;
	if (pB != NULL) {
		pB->type = BLOB_TYPE_BIAS;
		snprintf(filename,sizeof(filename),"%s_b.txt",pLayerCurr->para->name);
		LOG_writeBlobToTxtFile(filename,pB);
	}
#endif

	return 0;
}

int NET_setInputData(NET_s *pNet,double *data,int len)
{
	return BLOB_shapeByPtr(pNet->layers[0]->pData,data,len);
}

int NET_setTableYData(NET_s *pNet,double *dataY,int len)
{
	return BLOB_shapeByPtr(pNet->pTableY,dataY,len);
}

BLOB_s *NET_getTableYData(NET_s *pNet)
{
	return pNet->pTableY;
}

static int NETBackward(void *usr,int idCurr,int *idNext,int nIdNext)
{
	NET_s *pNet = (NET_s *)usr;
	CHECK_EXPR_RET(pNet == NULL,-1);

	LAYER_s *pLayerCurr = pNet->layers[idCurr];
	CHECK_EXPR_RET(pLayerCurr == NULL,-1);

	CHECK_EXPR_RET(pLayerCurr->backward == NULL,-1);
	for (int i = 0;i < nIdNext;i++) {
		pLayerCurr->pNext[i] = pNet->layers[idNext[i]];
	}
	pLayerCurr->nNext = nIdNext;

	CHECK_EXPR_RET(pLayerCurr->backward == NULL,-1);
	return pLayerCurr->backward(&pNet->para,pLayerCurr);
}
int NET_Register(NET_s *pNet,LAYER_s *pLayer)
{
	CHECK_EXPR_RET(pLayer == NULL,-1);

	LAYER_PARA_s *layerPara =  pLayer->para;
	CHECK_EXPR_RET(layerPara == NULL,-1);
	
	/*判断当前的类型名字是否存在*/
	BOOL isExist = FALSE;
	for (int i = 0;i < sizeof(gLayersTypeName)/sizeof(gLayersTypeName[0]);i++) {
		if (strcmp(gLayersTypeName[i],layerPara->typeName) == 0) {
			isExist = TRUE;
		}
	}
	CHECK_EXPR_RET(isExist == FALSE,-1);
	/*判断之前的所有的层名字是否存在,如果存在就记录之前的所有层的ID*/
	isExist = FALSE;
	if (strcmp(layerPara->typeName,gLayersTypeName[0]) != 0) {
		CHECK_EXPR_RET(layerPara->nNamePrev <=0,-1);
		for (int i = 0;i < pNet->layerId;i++) {
			for (int j = 0;j < layerPara->nNamePrev;j++) {
				CHECK_EXPR_RET(pNet->layers[i]->para == NULL,-1);
				if (strcmp(layerPara->namePrev[j],pNet->layers[i]->para->name) == 0) {
					pLayer->idPrev[pLayer->nIdPrev++] = i;
					isExist = TRUE;
				}
			}
		}
		if (isExist == FALSE) {
			printf("[%s] previous name is not exist!\n",layerPara->name);
			return -1;
		}
	}
	pLayer->idCurr = pNet->layerId;
	pNet->layers[pNet->layerId++] = pLayer;

	int ret = 0;
	if (strcmp(layerPara->typeName,gLayersTypeName[0]) == 0) {
		/*如果是第一层需要特殊处理*/
		ret = MTREE_addItem(pNet->pMTree,-1,0);
		CHECK_EXPR_RET(ret != 0,-1);
		
		ret = NETLayerInit(pNet,0,NULL,0);
		CHECK_EXPR_RET(ret != 0,-1);
	} else {
		CHECK_EXPR_RET(pLayer->nIdPrev <= 0,-1);
		
		for (int i = 0;i < pLayer->nIdPrev;i++) {
			ret = MTREE_addItem(pNet->pMTree,pLayer->idPrev[i],pLayer->idCurr);
			CHECK_EXPR_RET(ret != 0,-1);
		}
		ret = NETLayerInit(pNet,pLayer->idCurr,pLayer->idPrev,pLayer->nIdPrev);
		CHECK_EXPR_RET(ret != 0,-1);
	}

	return 0;
}

int NET_test(NET_s *pNet)
{
	CHECK_EXPR_RET(pNet == NULL,-1);

	printf(">>>>NET_test:\n");
	int ret = MTREE_forward(pNet->pMTree,NETForward);
	CHECK_EXPR_RET(ret != 0,-1);

	int idEnd[LAYER_MAX_MUX];
	int nEnd;
	MTREE_getEndIds(pNet->pMTree,idEnd,&nEnd);
	CHECK_EXPR_RET(nEnd <= 0 || nEnd > LAYER_MAX_MUX,-1);
	LAYER_s *pLayer = NULL;
	for (int i = 0;i < nEnd;i++) {
		pLayer = pNet->layers[idEnd[i]];
		CHECK_EXPR_RET(pLayer == NULL,-1);
//		printf("%s test out:\n",pLayer->name);
		BLOB_print(pLayer->pData);
	}
	
	return 0;
 }

double NET_GetLoss(NET_s *pNet,char *layerName)
{
	CHECK_EXPR_RET(layerName == NULL,-1);

	int idEnd[LAYER_MAX_MUX];
	int nEnd;

	MTREE_getEndIds(pNet->pMTree,idEnd,&nEnd);
	CHECK_EXPR_RET(nEnd <= 0,-1);
	LAYER_s *pLayer = NULL;
	double  loss = 0;
	for (int i = 0;i < nEnd;i++) {
		pLayer = pNet->layers[idEnd[i]];
		if (strcmp(layerName,pLayer->para->name) == 0) {
			CHECK_EXPR_RET(pLayer->pError == NULL,-1);
			CHECK_EXPR_RET(pNet->para.loss_function == NULL,-1);
			loss = pNet->para.loss_function(pLayer->pError);
			break;
		}
	}

	return loss;
}

int NET_Forward(NET_s *pNet)
{
	return MTREE_forward(pNet->pMTree,NETForward);
}


int NET_Backward(NET_s *pNet)
{
	return MTREE_backward(pNet->pMTree,NETBackward);
}


void NET_process(NET_s *pNet,int cnt)
{
	while(cnt--) {
		NET_Forward(pNet);
		NET_Backward(pNet);
	}
}

/*只适用于卷积层、全连接层 */
int NET_autoCreateBlob(NET_PARA_s *pNetPara,BLOB_s *pPrevData,BLOB_s **pData,int num,int h,int w,int kh,int kw,
								BLOB_s **pK,BLOB_s **pB)
{
	CHECK_EXPR_RET(pPrevData == NULL || pData == NULL,-1);
	CHECK_EXPR_RET(pK == NULL || pB == NULL,-1);
	BLOB_s *pBlob = NULL;
	
	int ret = BLOB_create(pData,pNetPara->batchsize,num,
								h,w,TRUE);
	CHECK_EXPR_RET(ret != 0,-1);
	pBlob = (*pData);
	pBlob->type = BLOB_TYPE_DATA;

	ret = BLOB_create(pK,num,pPrevData->channelSize,
							kh,kw,TRUE);
	CHECK_EXPR_RET(ret != 0,-1);
	pBlob = (*pK);
	pBlob->type = BLOB_TYPE_WEIGHT;

	ret = BLOB_create(pB,1,num,1,1,TRUE);
	pBlob = (*pB);
	pBlob->type = BLOB_TYPE_BIAS;
	
	return 0;
}

