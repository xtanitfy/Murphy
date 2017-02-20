#ifndef __TYPE_LAYER_REG_H__
#define __TYPE_LAYER_REG_H__
#include "para.h"
#include "net.h"

#if 0
#define REGISTER_LAYER(layerTypeName) do { \
				memcpy(pTypeLayersRegInfo[typeLayerNum].typename,layerTypeName,\
						sizeof(pTypeLayersRegInfo[typeLayerNum].typename)); \
				pTypeLayersRegInfo[typeLayerNum].funcInit = layerTypeName##LayerInit; \
				pTypeLayersRegInfo[typeLayerNum].funcForward = layerTypeName##LayerForward; \
				pTypeLayersRegInfo[typeLayerNum].funcBackward = layerTypeName##LayerBackward; \
				typeLayerNum++; \
			}while(0)
#endif


char *gLayersTypeName[] = {
	"data","conv","linear","samp","output","test"
};

extern int DataLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer);
extern int DataLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer);
extern int DataLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer);

extern int ConvLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer);
extern int ConvLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer);
extern int ConvLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer);

extern int LinearLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer);
extern int LinearLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer);
extern int LinearLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer);

extern int SampLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer);
extern int SampLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer);
extern int SampLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer);

extern int OutputLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer);
extern int OutputLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer);
extern int OutputLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer);

TYPE_LAYER_REG_INFO gLayerRegInfo[] = {
	{"data",DataLayerInit,DataLayerForward,DataLayerBackward},
	{"conv",ConvLayerInit,ConvLayerForward,ConvLayerBackward},
	{"linear",LinearLayerInit,LinearLayerForward,LinearLayerBackward},
	{"samp",SampLayerInit,SampLayerForward,SampLayerBackward},
	{"output",OutputLayerInit,OutputLayerForward,OutputLayerBackward}
};

#endif