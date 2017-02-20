#include <stdio.h>


int main(void)
{
    int a = 4,b = 3;
	int i = 0,j = 0;
	
	char data[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	char arr[a][b];
	char (*ptr)[b] = (char (*)[b])data;
	for (i = 0;i < a;i++) {
		for (j = 0;j < b;j++) {
			printf("0x%x ",ptr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	a = 2;
	b = 2;
	for (i = 0;i < a;i++) {
		for (j = 0;j < b;j++) {
			printf("0x%x ",ptr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;

}
