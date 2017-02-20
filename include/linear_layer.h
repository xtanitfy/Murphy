#ifndef __LINER_LAYER_H__
#define __LINER_LAYER_H__

#include "net.h"


#if 0
typedef struct
{
	char typeName[LAYER_NAME_SIZE];
	char name[LAYER_NAME_SIZE];
	char namePrev[LAYER_MAX_MUX][LAYER_NAME_SIZE];
	int nNamePrev;
}LINEAR_LAYER_PARA_s;

typedef struct
{
	LINEAR_LAYER_PARA_s para;
}LINEAR_LAYER_s;
#endif

int LinearLayer_register(NET_s *pNet,LINEAR_LAYER_PARA_s *para);

#endif
