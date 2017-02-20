#ifndef __BLOB_H__
#define __BLOB_H__

#include "includes_std.h"
#include "public.h"
#include "data_type.h"

typedef double BLOB_DATA_TYPE;


#define BLOB_DATA_PTR(pBLOB,ptr) BLOB_DATA_TYPE (*ptr)[pBLOB->channelSize][pBLOB->heightSize][pBLOB->widthSize] = \
				(BLOB_DATA_TYPE (*)[pBLOB->channelSize][pBLOB->heightSize][pBLOB->widthSize])pBLOB->data
				
#define PTR2BLOB_PTR(pBLOB,ptr,blobPtr)BLOB_DATA_TYPE (*blobPtr)[pBLOB->channelSize][pBLOB->heightSize][pBLOB->widthSize]= \
				(BLOB_DATA_TYPE (*)[pBLOB->channelSize][pBLOB->heightSize][pBLOB->widthSize])ptr

typedef enum
{
	BLOB_TYPE_DATA,
	BLOB_TYPE_WEIGHT,
	BLOB_TYPE_BIAS,
	BLOB_TYPE_CNT
}BLOB_TYPE_e;

typedef struct
{
	BLOB_TYPE_e type;

	BLOB_DATA_TYPE *data;
	
	unsigned long numSize;
	unsigned long channelSize;
	unsigned long heightSize;
	unsigned long widthSize;
	
	unsigned long count;/*the number of elements*/
	
	int pady;
	int padx;
}BLOB_s;

int BLOB_create(BLOB_s **pBlob,unsigned long numSize,
							unsigned long channelSize,
							unsigned long heightSize,
							unsigned long widthSize,
							BOOL bShape);
							
BLOB_DATA_TYPE BLOB_val(BLOB_s *pBOLB,unsigned long num,unsigned long channel,
								unsigned long height,unsigned long width);
BLOB_DATA_TYPE *BLOB_ptr(BLOB_s *pBOLB,unsigned long num,unsigned long channel,
								unsigned long height,unsigned long width);
BLOB_DATA_TYPE *BLOB_data(BLOB_s *pBOLB);
int BLOB_shapeLike(BLOB_s *pDataSrc,BLOB_s **pData);
int BLOB_shape(BLOB_s *pBlob);
int BLOB_shapeByPtr(BLOB_s *pBlob,BLOB_DATA_TYPE *pData,int len);
void BLOB_print(BLOB_s *pBlob);
void BLOB_printPara(BLOB_s *pBolb);
int BLOB_createAddPad(BLOB_s **pBlob,
						unsigned long numSize,
						unsigned long channelSize,
						unsigned long heightSize,
						unsigned long widthSize,
						BOOL bShape,int padySize,int padxSize);

int BLOB_shapeAddPad(BLOB_s *pDataSrc,BLOB_s *pData,int pady,int padx);

#endif