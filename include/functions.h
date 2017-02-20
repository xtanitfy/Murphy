#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "includes_std.h"
#include "blob.h"

#define FUNC_VALUE 0
#define FUNC_DERIVA 1

typedef double(*FUNC)(double x,int type);

double sigmoid(double x);
double sigmoidExt(double x,int type);
int weightInit(BLOB_s *k);
int biasInit(BLOB_s *b);
double functionLoss1(BLOB_s *pError);

#endif