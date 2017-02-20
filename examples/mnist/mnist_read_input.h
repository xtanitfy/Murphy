#ifndef __MNIST_READ_INPUT_H__
#define __MNIST_READ_INPUT_H__

#include "includes_std.h"
#include "blob.h"

typedef struct
{
	int h;
	int w;
	int n;
	int c;
}SIZE_s;

int Mnist_GetData(char *file,double **data,SIZE_s *pSize);
int Mnist_dataNormalie(double *pData,SIZE_s *pSize);
int Mnist_GetInitFw(BLOB_s *pBLOB);
void Mnist_PrintSize(char *name,SIZE_s *pSize);

#endif
