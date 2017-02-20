#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SRC_W 4
#define SRC_H 4 

int arr[SRC_H][SRC_W] = {
	{1,2,3,4},
	{-2,-1,2,1},
	{-1,1,2,3},
	{2,-2,-2,1}
};

int k[2][2] = {
	{1,1},
	{-1,-1}
};

int dst[3][3];


int print_src(void)
{
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int print_dst(void)
{
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			printf("%d ",dst[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int conv_slow(void)
{
	int tmp = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			tmp = 0;
			for (int m = i;m < (i + 2);m++) {
				for (int n = j;n < (j + 2);n++) {
					tmp +=  arr[m][n] * k [1-m+i][1-n+j];
				}
			}
			dst[i][j] = tmp;
		}
	}
	
	return 0;
}

int conv_fast(void)
{
	int tmp = 0;
	int h = (4-2+1) * (4-2+1);
	int w = 2*2;
	int bigMartix[h][w];
	int linearK[w];
	
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			tmp = 0;
			
			dst[i][j] = tmp;
		}
	}

	return 0;
}

int main(void)
{
	printf("Before conv:\n");
	print_src();
	conv_slow();
	printf("After conv:\n");
	print_dst();
	
	return 0;
}




