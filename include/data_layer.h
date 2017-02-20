#ifndef __DATA_LAYER_H__
#define __DATA_LAYER_H__

#include "includes_std.h"
#include "blob.h"
#include "net.h"

#if 0
typedef enum
{
	DATA_TYPE_LABEL,
	DATA_TYPE_Annotation,
	DATA_TYPE_BUTT
}DATA_TYPE;


typedef struct
{
	DATA_TYPE type;
	int hSize;
	int wSize;
	int channelSize;
	char name[LAYER_NAME_SIZE];
	char typeName[LAYER_NAME_SIZE];
}DATA_LAYER_PARA_s;


typedef struct
{
	DATA_LAYER_PARA_s para;
}DATA_LAYER_s;

#endif

int DataLayer_register(NET_s *pNet,DATA_LAYER_PARA_s *para);

#endif
