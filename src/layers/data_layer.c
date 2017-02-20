#include "data_layer.h"
#include "net.h"
#include "public.h"

int DataLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{

	return 0;
}


int DataLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	CHECK_EXPR_RET(pLayer == NULL,-1);
	
	DATA_LAYER_PARA_s *layerPara = &pLayer->para->select.dataLayer;
	
	int ret = BLOB_create(&pLayer->pData,pNetPara->batchsize,\
						1,layerPara->wSize,layerPara->hSize,FALSE);
	CHECK_EXPR_RET(ret != 0,-1);


	return 0;
}

int DataLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{

	
	return 0;
}

#if 0
int DataLayer_register(NET_s *pNet,DATA_LAYER_PARA_s *para)
{
	CHECK_EXPR_RET(para == NULL,-1);

	LAYER_s *pLayer = (LAYER_s *)malloc(sizeof(LAYER_s ));
	CHECK_EXPR_RET(pLayer == NULL,-1);
	memset(pLayer,'\0',sizeof(LAYER_s));
	
	pLayer->type = LAYER_TYPE_DATA;
	pLayer->init = DataLayerInit;
	pLayer->forward = DataLayerForward;
	pLayer->backward = DataLayerBackward;

	DATA_LAYER_s *pDataLayer = (DATA_LAYER_s *)malloc(sizeof(DATA_LAYER_s));
	CHECK_EXPR_RET(pDataLayer == NULL,-1);
	memset(pDataLayer,'\0',sizeof(DATA_LAYER_s));
	memcpy(&pDataLayer->para,para,sizeof(pDataLayer->para));
	
	pLayer->currLayer = pDataLayer;
	NET_addNames(pLayer,para->typeName,para->name,NULL,0);
	
	int ret = NET_Register(pNet,pLayer);
	CHECK_EXPR_RET(ret !=0 ,-1);
	
	return 0;
}
#endif

