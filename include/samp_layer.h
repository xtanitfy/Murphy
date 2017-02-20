#ifndef __SAMP_LAYER_H__
#define __SAMP_LAYER_H__

#include "net.h"

#if 0
typedef enum
{
	SAMP_TYPE_AVERAGE,
	SAMP_TYPE_MAX,	
	SAMP_TYPE_CNT
}SAMP_TYPE_e;

typedef struct
{
	SAMP_TYPE_e type;
	int stride;
	int (*biasInit)(BLOB_s *b);
	char typeName[LAYER_NAME_SIZE];
	char name[LAYER_NAME_SIZE];
	char namePrev[LAYER_MAX_MUX][LAYER_NAME_SIZE];
	int nNamePrev;
}SAMP_LAYER_PARA_s;


typedef struct
{
	SAMP_LAYER_PARA_s para;

	BLOB_s *pData;
	//BLOB_s *b;
	BLOB_s *delta;
}SAMP_LAYER_s;
#endif

	
int SampLayer_register(NET_s *pNet,SAMP_LAYER_PARA_s *pPara);


#endif
