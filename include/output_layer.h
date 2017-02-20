#ifndef __OUTPUT_LAYER_H__
#define __OUTPUT_LAYER_H__

#include "net.h"
#include "functions.h"


#if 0
typedef struct
{
	char typeName[LAYER_NAME_SIZE];
	char name[LAYER_NAME_SIZE];
	char namePrev[LAYER_MAX_MUX][LAYER_NAME_SIZE];
	int nNamePrev;
	int num;/*分类的个数*/
	FUNC function;
	int (*weightInit)(BLOB_s *k);
	int (*biasInit)(BLOB_s *b);
}OUTPUT_LAYER_PARA_s;

#endif

typedef struct
{
	OUTPUT_LAYER_PARA_s para;
	BLOB_s *pTableY;
}OUTPUT_LAYER_s;

int OutputLayer_register(NET_s *pNet,OUTPUT_LAYER_PARA_s *para);

#endif
