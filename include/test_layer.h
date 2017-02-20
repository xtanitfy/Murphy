#ifndef __TEST_LAYER_H__
#define __TEST_LAYER_H__

typedef struct
{
	char typeName[LAYER_NAME_SIZE];
	char name[LAYER_NAME_SIZE];
	char namePrev[LAYER_MAX_MUX][LAYER_NAME_SIZE];
	int nNamePrev;
}TEST_LAYER_PARA_s;

typedef struct
{
	TEST_LAYER_PARA_s para;
	BLOB_s *pData;
}TEST_LAYER_s;


int TestLayer_register(NET_s *pNet,TEST_LAYER_PARA_s *para);

#endif