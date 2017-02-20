#ifndef __LAYER_MGR_H__
#define __LAYER_MGR_H__

#include "includes_std.h"
#include "blob.h"
#include "dlist.h"
#include "public.h"
#include "muti_tree.h"
#include "platform_comm.h"
#include "para.h"

typedef struct _LAYER_s LAYER_s;
typedef int (*LAYER_f)(NET_PARA_s *pNetPara,LAYER_s *pLayer);


struct _LAYER_s
{
	void *currLayer; /*私有数据不需要共享给其他层,data层除外*/
	
	LAYER_PARA_s *para;
	
	BLOB_s *pData;
	BLOB_s *k;
	BLOB_s *b;
	BLOB_s *pDelta;
	BLOB_s *pDK; 
	BLOB_s *pDB;
	
	BOOL isNeedBackward;

	LAYER_f init;
	LAYER_f forward;
	LAYER_f backward;
	
	////////////////////////////////
	LAYER_s *pNext[LAYER_MAX_MUX];
	int nNext;

	LAYER_s *pPrev[LAYER_MAX_MUX];
	int nPrev;


	/***************************/
	/*以下参数后续可以从para中去取，因为该架构反向传播next->top-->curr->top 这样导致了思路混乱*/
	/*需要改进为curr->top ---> curr->bottom */
	/***************************/
	
	/*采样层会用到*/
	int sampScale;

	/*卷积层会用到*/
	int strideX;
	int strideY;

	/*输出层用到*/
	BLOB_s *pError;
	
	/*不需要赋值的选项*/
	int idCurr;
	int idPrev[LAYER_MAX_MUX];
	int nIdPrev;
};


typedef struct
{
	NET_PARA_s para;
	MTREE_s *pMTree;
	BLOB_s *pTableY;
	LAYER_s *layers[LAYERS_MAX_N];
	int layerId;
}NET_s;



typedef struct {
	char typename[NET_NAME_SIZE];
	LAYER_f funcInit;
	LAYER_f funcForward;
	LAYER_f funcBackward;
}TYPE_LAYER_REG_INFO;

int NET_addLayer(NET_s *pNet,LAYER_PARA_s *pLayerPara);
NET_s *NET_create(NET_PARA_s *pNetPara);
NET_PARA_s *NET_GetNetPara(NET_s *pNet);
int NET_Register(NET_s*pNet,LAYER_s *pLayer);

int NET_Forward(NET_s *pNet);
int NET_Backward(NET_s *pNet);
void NET_process(NET_s *pNet,int cnt);
int NET_autoCreateBlob(NET_PARA_s *pNetPara,BLOB_s *pPrevData,BLOB_s **pData,int num,int h,int w,int kh,int kw,
								BLOB_s **pK,BLOB_s **pB);
int NET_addNames(LAYER_s *pLayer,char *typeName,char *name,
								char (*namePrev)[LAYER_NAME_SIZE],int nNamePrev);
int NET_setTableYData(NET_s *pNet,double *dataY,int len);
BLOB_s *NET_getTableYData(NET_s *pNet);
int NET_setInputData(NET_s *pNet,double *data,int len);
int NET_Update(NET_s *pNet);
double NET_GetLoss(NET_s *pNet,char *layerName);
int NET_test(NET_s *pNet);
int NET_printForward(NET_s *pNet);
int NET_printBackward(NET_s *pNet);

#endif
