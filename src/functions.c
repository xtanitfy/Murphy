#include "functions.h"
#include <math.h>



inline double sigmoid(double x)
{
	return  (double)1/((double)1+(double)exp(-x));
}

double sigmoidExt(double x,int type)
{
	/*0: 函数值 1:函数导数*/
	if (type == FUNC_VALUE) {
		return  (double)1/((double)1+(double)exp(-x));
	} else {
		return (x) * ((double)1-x);
	}
}


int weightInit(BLOB_s *k)
{
	double arr[][5]= {
		{0.1667,0.0971,0.0427,-0.0349,-0.1637},
        { -0.0996,-0.0161,0.1081,0.1613,-0.0545},
        {0.0396,-0.1783,0.1562,0.1544,0.1160},
        {-0.0052,0.1190,0.0882,-0.0332,-0.1815},
        {0.1449,-0.0205,-0.1199,0.1458,-0.1337}
	};

	BLOB_DATA_PTR(k,ptr);

	int outputNum = k->numSize;
	int inputNum = k->channelSize;
	int sectionY = k->heightSize;
	int sectionX = k->widthSize;
	
	/*暂时先这样搞*/
	CHECK_EXPR_RET(sectionY != 5,-1);
	CHECK_EXPR_RET(sectionX != 5,-1);
	
	for (int oy = 0;oy < outputNum;oy++) {	
		for (int ix = 0;ix < inputNum;ix++) {
			for (int y = 0;y < sectionY;y++) {	
				for (int x = 0;x  < sectionX;x++) {
					ptr[oy][ix][y][x] = arr[y][x];
				}
			}
		}
	}
	

	//printf("weightInit OK!\n");
	return 0;
}

int biasInit(BLOB_s *b)
{
	BLOB_DATA_PTR(b,ptr);
	
	for (int i_batch = 0;i_batch < b->numSize;i_batch++) {
		for (int i_num = 0;i_num < b->channelSize;i_num++) {	
			for (int i_height = 0;i_height < b->heightSize;i_height++) {
				for (int i_width = 0;i_width < b->widthSize;i_width++) {	
					ptr[i_batch][i_num][i_height][i_width] = 0;
				}
			}
		}
	}
	
	
	return 0;
}


double functionLoss1(BLOB_s *pError)
{
	CHECK_EXPR_RET(pError == NULL,-1);

	double loss = 0.0;
	for (int i = 0;i < pError->count;i++) {
		loss += 0.5 * pError->data[i] * pError->data[i];
	}
	loss /= pError->numSize;

	return loss;
}





