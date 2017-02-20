#ifndef __CONV_LAYER_H__
#define __CONV_LAYER_H__
#include "blob.h"
#include "net.h"

//#define CONV_FAST 1

#if 0
typedef struct
{
	int num;
	int kernelX;
	int kernelY;
	int strideX;
	int strideY;
	double (*function)(double x,int type);
	int (*weightInit)(BLOB_s *k);
	int (*biasInit)(BLOB_s *b);
	
	char typeName[LAYER_NAME_SIZE];
	char name[LAYER_NAME_SIZE];
	char namePrev[LAYER_MAX_MUX][LAYER_NAME_SIZE];
	int nNamePrev;
}CONV_LAYER_PARA_s;
#endif

typedef struct
{
	//CONV_LAYER_PARA_s para;

	int imgSize;
	int imgWidth;
	int imgheight;
	double *imgData;

#if defined(CONV_FAST)
	int matPrevAHeight;
	int matPrevAWidth;
	int matKWidth;
	int matKHeight;
	double *pMatPrevAData;
	double *pMatKRot180;
#endif

}CONV_LAYER_s;

int ConvLayer_register(NET_s *pNet,CONV_LAYER_PARA_s *pPara);


#endif
