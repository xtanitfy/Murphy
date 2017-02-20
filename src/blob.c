#include "blob.h"
#include "public.h"

int BLOB_create(BLOB_s **pBlob,
						unsigned long numSize,
						unsigned long channelSize, 
						unsigned long heightSize,
						unsigned long widthSize,
						BOOL bShape)
{
	unsigned long counts = 0;
	CHECK_EXPR_RET(numSize <= 0,-1);
	CHECK_EXPR_RET(channelSize <= 0,-1);
	CHECK_EXPR_RET(heightSize <= 0,-1);
	CHECK_EXPR_RET(widthSize <= 0,-1);

	CHECK_EXPR_RET(pBlob == NULL,-1);

	*pBlob = (BLOB_s *)malloc(sizeof(BLOB_s));
	CHECK_EXPR_RET(*pBlob == NULL,-1);

	(*pBlob)->numSize = numSize;
	(*pBlob)->widthSize = widthSize;
	(*pBlob)->heightSize = heightSize;
	(*pBlob)->channelSize = channelSize;
	
	counts = (*pBlob)->numSize * (*pBlob)->channelSize *\
				(*pBlob)->heightSize * (*pBlob)->widthSize;
	
	(*pBlob)->pady = 0;
	(*pBlob)->padx = 0;
	(*pBlob)->count = counts;
	if (bShape == TRUE) {
		BLOB_shape(*pBlob);
	}

	return 0;
}

int BLOB_createAddPad(BLOB_s **pBlob,
						unsigned long numSize,
						unsigned long channelSize, 
						unsigned long heightSize,
						unsigned long widthSize,
						BOOL bShape,int pady,int padx)
{
	int ret = BLOB_create(pBlob,numSize,channelSize,heightSize+pady*2,widthSize+padx*2,bShape);
	CHECK_EXPR_RET(ret != 0,-1);

	BLOB_s *blob = *pBlob;
	blob->pady = pady;
	blob->padx = padx;

	return 0;
}

int BLOB_shapeAddPad(BLOB_s *pDataSrc,BLOB_s *pData,int pady,int padx)
{
	CHECK_EXPR_RET(pDataSrc == NULL,-1);
	CHECK_EXPR_RET(pData == NULL,-1);
	CHECK_EXPR_RET(pady > pDataSrc->heightSize,-1);
	CHECK_EXPR_RET(padx > pDataSrc->widthSize,-1);
	
	BLOB_DATA_PTR(pDataSrc,ptrDataSrc);
	BLOB_DATA_PTR(pData,ptrData);
	for (int i_num = 0;i_num < pData->numSize;i_num++) {	
		for (int i_channel = 0;i_channel  < pData->channelSize;i_channel++) {
			for (int i_height = 0;i_height < pData->heightSize - pady;i_height++) {	
				for (int i_width = 0;i_width < pData->widthSize - padx;i_width++) {	
					ptrData[i_num][i_channel][i_height + pady][i_width + padx] = 
						ptrDataSrc[i_num][i_channel][i_height][i_width];	
				
				}
			}
		}
	}

	return 0;
}



int BLOB_shapeLike(BLOB_s *pDataSrc,BLOB_s **pData)
{
	CHECK_EXPR_RET(pDataSrc == NULL,-1);
	CHECK_EXPR_RET(pData == NULL,-1);

	*pData = (BLOB_s *)malloc(sizeof(BLOB_s));
	CHECK_EXPR_RET(*pData == NULL,-1);

	memcpy(*pData,pDataSrc,sizeof(BLOB_s));
	
	BLOB_shape(*pData);
	
	return 0;	
}


int BLOB_shape(BLOB_s *pBlob)
{
	CHECK_EXPR_RET(pBlob == NULL,-1);
	pBlob->data = (BLOB_DATA_TYPE *)malloc(sizeof(BLOB_DATA_TYPE)*pBlob->count);
	memset(pBlob->data,0,pBlob->count * sizeof(BLOB_DATA_TYPE));
	return 0;
}

int BLOB_shapeByPtr(BLOB_s *pBlob,BLOB_DATA_TYPE *pData,int len)
{
	CHECK_EXPR_RET(pData == NULL,-1);
	CHECK_EXPR_RET(pBlob == NULL,-1);
	CHECK_EXPR_RET(len != pBlob->count,-1);
	
	BLOB_shape(pBlob);
	BLOB_DATA_PTR(pBlob,ptr);
	int k = 0;
	for (int i_num = 0;i_num < pBlob->numSize;i_num++) {	
		for (int i_channel = 0;i_channel  < pBlob->channelSize;i_channel++) {
			for (int i_height = 0;i_height < pBlob->heightSize;i_height++) {	
				for (int i_width = 0;i_width < pBlob->widthSize;i_width++) {	
					ptr[i_num][i_channel][i_height][i_width] = pData[k++];	
				}
			}
		}
	}
	
	return 0;
}


BLOB_DATA_TYPE *BLOB_ptr(BLOB_s *pBlob,unsigned long num,unsigned long channel,
								unsigned long height,unsigned long width)
{
	//BLOB_s *pBolb = (BLOB_s *)handle;
	//unsigned char (*ptr)[pBolb->num][pBolb->width][pBolb->height][pBolb->channels] = pBolb->data;
	//return (unsigned char *)&ptr[batches][num][width][height][channel];

	return pBlob->data + ((((num * pBlob->channelSize)+ channel)*pBlob->heightSize)+height)*pBlob->widthSize + width;
	//return pBlob->data + (((((batches * pBlob->num)+ num)*pBlob->height)+height)*pBlob->width + width)*pBlob->channels+channel;
}


void BLOB_printPara(BLOB_s *pBolb)
{	
	printf("num:     %ld\n",pBolb->numSize);
	printf("channel: %ld\n",pBolb->channelSize);
	printf("height:  %ld\n",pBolb->heightSize);
	printf("width:   %ld\n",pBolb->widthSize);
	printf("size:    %ld\n",pBolb->count);
	printf("bytes:   %ld\n",pBolb->count*sizeof(BLOB_DATA_TYPE));
}


BLOB_DATA_TYPE *BLOB_data(BLOB_s *pBolb)
{
	return pBolb->data;
}

BLOB_DATA_TYPE BLOB_val(BLOB_s *pBlob,unsigned long num,unsigned long channel,
								unsigned long height,unsigned long width)
{
#if 0
	unsigned long offset = pBolb->batcheSize*batches + num*pBolb->numSize + \
		width*pBolb->widthSize + height*pBolb->heightSize + channel;
	return *(pBolb->data + offset);
#else
	BLOB_DATA_TYPE (*ptr)[pBlob->channelSize][pBlob->heightSize][pBlob->widthSize] = \
	(BLOB_DATA_TYPE (*)[pBlob->channelSize][pBlob->heightSize][pBlob->widthSize])pBlob->data;
	return ptr[num][channel][height][width];
#endif
}

void BLOB_print(BLOB_s *pBlob)
{
	CHECK_EXPR_RET_VOID(pBlob==NULL);
	
	unsigned long batches = 1/*pBlob->batches*/;
	unsigned long width = pBlob->widthSize;
	unsigned long height = pBlob->heightSize;
	unsigned long num = pBlob->numSize;
	unsigned long channels = pBlob->channelSize;
	
	BLOB_DATA_PTR(pBlob,ptr);
	for (int i_channel = 0;i_channel  < channels;i_channel++) {
		for (int i_batch = 0;i_batch < batches;i_batch++) {
			for (int i_num = 0;i_num < num;i_num++) {	
				for (int i_height = 0;i_height < height;i_height++) {	
					for (int i_width = 0;i_width < width;i_width++) {	
						printf("%lf ",ptr[i_num][i_channel][i_height+pBlob->pady][i_width+pBlob->padx]);	
					}
					printf(" ");
				}
				printf("  ");
			}
			printf("\n");
		}
		printf(" ");
	}
}


int BLOB_mnisC(BLOB_s *pData,double c)
{


	return 0;
}

int BLOB_addC(BLOB_s *pData,double c)
{


	return 0;
}




#if 0
int BLOB_convKA(BLOB_s *pK,BLOB_s *pAIn,BLOB_s *pAOut)
{
	/*展开small*/
	int outNum = pAOut->num;
	int inNum = pAIn->num;
	int chSize = pAIn->channels;
	int batchSize = pAIn->batches;
	int kWidth =  pK->width;
	int kheight = pK->height;

	double 
	/*展开权重 and rotate 180*/
	for (int iout = 0;iout < outNum;iout++) {
		for (int iin= 0;iin < inNum;iin++) {
			pDim = (double (*)[chSize])&ptrK[iout][iin][0][0][0];
			for (int idim = kSize - 1;idim >= 0;idim--) {
				for (int ich = 0;ich < kChannel;ich++) {
					ptrMatK[iout][iin*dimK + (kSize-idim-1)*kChannel + ich]  = pDim[idim][ich];
				}
			}
		}
	}



	return 0;
}

#endif

