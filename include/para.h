#ifndef __LAYERS_PARA_H__
#define __LAYERS_PARA_H__

#include "functions.h"

#define LAYER_NAME_SIZE 64
#define LAYER_MAX_MUX MTREE_MAX_MUX//parallel
 
#define LAYERS_MAX_N 1024
#define TYPE_LAYERS_MAX_N 256

#define NET_NAME_SIZE 64

typedef enum
{
	NET_STAT_FORWRD,
	NET_STAT_BACKWARD,
	NET_STAT_CNT
}NET_TRAIN_STAT_e;

typedef struct
{
	int phase;//train or test
	char *netName[NET_NAME_SIZE];	
	
	double alpha;
	int batchsize;
	int numepochs;
	int channels;
	int classifyNum;
	double (*loss_function)(BLOB_s *e);

	/*暂时先放这里 后续改进要放进DataLayer*/
	BLOB_s *pTableY;
}NET_PARA_s;



typedef enum
{
	LAYER_TYPE_DATA,
	LAYER_TYPE_CONV,
	LAYER_TYPE_SAMPLE,
	LAYER_TYPE_MERGE, /*这个层的前边可能有几个层，需要合并*/
	LAYER_TYPE_FULL_CONNECT,
	LAYER_TYPE_CNT
}LAYER_TYPE_e;

typedef struct
{
	char typeName[LAYER_NAME_SIZE];
	char name[LAYER_NAME_SIZE];
	char namePrev[LAYER_MAX_MUX][LAYER_NAME_SIZE];
	int nNamePrev;
}LAYER_NAME_s;

typedef struct
{
	LAYER_TYPE_e type;
	int hSize;
	int wSize;
	int channelSize;
}DATA_LAYER_PARA_s;


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
}CONV_LAYER_PARA_s;



typedef enum
{
	SAMP_TYPE_AVERAGE,
	SAMP_TYPE_MAX,	
	SAMP_TYPE_CNT
}SAMP_LAYER_TYPE_e;


typedef struct
{
	SAMP_LAYER_TYPE_e type;
	int stride;
}SAMP_LAYER_PARA_s;



typedef struct
{
	

}LINEAR_LAYER_PARA_s;


typedef struct
{
	int num;/*分类的个数*/
	FUNC function;
	int (*weightInit)(BLOB_s *k);
	int (*biasInit)(BLOB_s *b);	
}OUTPUT_LAYER_PARA_s;

typedef struct
{
	LAYER_TYPE_e type;
	
	char typeName[LAYER_NAME_SIZE];
	char name[LAYER_NAME_SIZE];
	char namePrev[LAYER_MAX_MUX][LAYER_NAME_SIZE];
	int nNamePrev;
	union{
		DATA_LAYER_PARA_s dataLayer;
		CONV_LAYER_PARA_s convLayer;
		SAMP_LAYER_PARA_s sampLayer;
		LINEAR_LAYER_PARA_s linearLayer;
		OUTPUT_LAYER_PARA_s outputLayer;
	}select;
}LAYER_PARA_s;




#endif
