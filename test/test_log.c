#include "log.h"


void help()
{
	printf("argv[1]:file1\n");
	printf("argv[2]:file2\n");
}

int main(int argc,char **argv)
{
	if (argc != 3) {
		help();
		return -1;
	}
	LOG_compBinFile(argv[1],argv[2],28*28*500*sizeof(float));
	
	
	return 0;
}