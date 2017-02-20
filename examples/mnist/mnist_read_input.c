#include "mnist_read_input.h"


static int getSizeFromFilename(char *file,SIZE_s *pSize)
{
	char buf[256];
	memcpy(buf,file,strlen(file)+1);
	
	char *ptr = strrchr(buf,'_');
	pSize->n = atoi(ptr+1);
	*ptr = '*';
	
	ptr = strrchr(buf,'_');
	pSize->w = atoi(ptr+1);
	*ptr = '*';
	
	ptr = strrchr(buf,'_');
	pSize->h = atoi(ptr+1);
	
	return 0;
}

static int readMatFromFile(char *file,double *data,int size)
{
	FILE *fp = fopen(file,"rb");
	if (fp == NULL) {
		printf("fopen error!\n");
		return -1;
	}
	
	int nread = fread(data,sizeof(double),size,fp);
	if (nread != size) {
		printf("read error,size:%d needreadsize:%d\n",nread,size);
		return -1;
	} else {
		//printf("read success!\n");
	}

	return 0;
}

void Mnist_PrintSize(char *name,SIZE_s *pSize)
{
	printf("======name:%s:\n",name);
	printf("pSize->h:%d\n",pSize->h);
	printf("pSize->w:%d\n",pSize->w);
	printf("pSize->n:%d\n",pSize->n);
}

int Mnist_GetData(char *file,double **data,SIZE_s *pSize)
{
	getSizeFromFilename(file,pSize);
	
	int allSize = pSize->w*pSize->h*pSize->n;
	*data = (double *)malloc(sizeof(double)*allSize);
	int ret = readMatFromFile(file,*data,allSize);
	CHECK_EXPR_RET(ret != 0,-1);
	
	return 0;
}


int Mnist_GetInitFw(BLOB_s *pBLOB)
{
#define INIT_FW_BIN_FILE  "data/mnist/ffw_10_192_1.bin"

	SIZE_s size;
	getSizeFromFilename(INIT_FW_BIN_FILE,&size);
	//readMatFromFile
	int allSize = size.w*size.h*size.n;
#if 0
	printf("pBLOB->num :%ld\n",pBLOB->num);
	printf("pBLOB->height:%ld\n",pBLOB->height);
	printf("pBLOB->width:%ld\n",pBLOB->width);
	printf("size.h:%d\n", size.h);
	printf("size.w:%d\n", size.w);
#endif
	CHECK_EXPR_RET(pBLOB->numSize!= size.h,-1);
	CHECK_EXPR_RET(pBLOB->channelSize!= size.w,-1);
	
	double *data = (double *)malloc(sizeof(double)*allSize);
	readMatFromFile(INIT_FW_BIN_FILE,data,allSize);
	
	BLOB_s *pBlobData;
	BLOB_create(&pBlobData,size.h,size.w,1,1,FALSE);
	BLOB_shapeByPtr(pBlobData,data,allSize);
	
	BLOB_DATA_PTR(pBLOB,ptr);
	BLOB_DATA_PTR(pBlobData,ptr1);
	
	for (int i_out = 0;i_out < pBLOB->numSize;i_out++) {	
		for (int i_in = 0;i_in < pBLOB->channelSize;i_in++) {
			for (int i_height = 0;i_height < pBLOB->heightSize;i_height++) {
				for (int i_width = 0;i_width < pBLOB->widthSize;i_width++) {	
					ptr[i_out][i_in][i_height][i_width] = 
							ptr1[i_out][i_in][i_height][i_width];
				}
			}
		}
	}
	
	

	
	return 0;
}


int Mnist_GetDataLabel(char *file,double **data,SIZE_s *pSize)
{

	return 0;
}



int Mnist_dataNormalie(double *pData,SIZE_s *pSize)
{
	int allSize = pSize->w*pSize->h*pSize->n;
	for (int i= 0;i < allSize;i++) {
		pData[i] /= (double)255; 
	}
	
	return 0;
}


