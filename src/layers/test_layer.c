#include <stdio.h>
#include <stdlib.h>
#include "net.h"
#include "log.h"
#include "test_layer.h"
#if 0

static int TestLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer);
static int TestLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer);


int TestLayer_register(NET_s *pNet,TEST_LAYER_PARA_s *para)
{
	CHECK_EXPR_RET(para == NULL,-1);

	TEST_LAYER_s *pTestLayer = (TEST_LAYER_s *)malloc(sizeof(TEST_LAYER_s));
	CHECK_EXPR_RET(pTestLayer == NULL,-1);
	memset(pTestLayer,'\0',sizeof(TEST_LAYER_s));
	memcpy(&pTestLayer->para,para,sizeof(TEST_LAYER_PARA_s));

	LAYER_s *pLayer = (LAYER_s *)malloc(sizeof(LAYER_s));
	CHECK_EXPR_RET(pLayer == NULL,-1);
	memset(pLayer,'\0',sizeof(LAYER_s));

	pLayer->currLayer = pTestLayer;
	pLayer->init = TestLayerInit;
	pLayer->forward = TestLayerForward;
	pLayer->backward = NULL;
	strncpy(pLayer->name,para->name,sizeof(pLayer->name));
	strcpy(pLayer->typeName,para->typeName);
	for (int i = 0;i < para->nNamePrev;i++) {
		strcpy(pLayer->namePrev[pLayer->nNamePrev++],para->namePrev[i]);
	}
	
	NET_Register(pNet,pLayer);

	return 0;	
}


int TestLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{

	return 0;
}


int TestLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	

	return 0;
}

#endif



