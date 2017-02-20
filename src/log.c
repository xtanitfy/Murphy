#include "log.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

#define LOG_FILE "log.txt"

static int gLogFd;

int LOG_init(void)
{
	gLogFd = open(LOG_FILE,O_RDWR | O_CREAT,0666);
	CHECK_EXPR_RET(gLogFd < 0,-1);

	return 0;
}

int LOG_writeBlobToTxtFile(char *txtFile,BLOB_s *pBlob)
{
	char filepath[256];
	sprintf(filepath,"bin/%s",txtFile);
	
	int fd = open(filepath,O_RDWR | O_CREAT | O_TRUNC,0666);
	CHECK_EXPR_RET(fd < 0,-1);

	BLOB_DATA_PTR(pBlob,ptr);
	
	char buf[256];

	if (pBlob->type == BLOB_TYPE_BIAS) {
		for (int i_out = 0;i_out < pBlob->channelSize;i_out++) {
			sprintf(buf,"%.8f ",ptr[0][i_out][0][0]);
			write(fd,buf,strlen(buf));
			write(fd,"\n",1);
		}
		close(fd);
		return 0;	
	}

	if (pBlob->type == BLOB_TYPE_WEIGHT) {
		for (int i_out = 0;i_out < pBlob->numSize;i_out++) {
			for (int i_in = 0;i_in < pBlob->channelSize;i_in++) {	
				for (int i_height = 0;i_height < pBlob->heightSize;i_height++) {	
					for (int i_width = 0;i_width < pBlob->widthSize;i_width++) {	
						sprintf(buf,"%.8f ",ptr[i_out][i_in][i_height][i_width]);
						write(fd,buf,strlen(buf));
					}
					if (pBlob->widthSize> 1) {
						write(fd,"\n",1);
					}
				}
				write(fd,"\n\n",1);
			}
			write(fd,"\n",1);
		}
		
		close(fd);
		return 0;
	}
	
	
	for (int i_batch = 0;i_batch < 2/*pBlob->batches*/;i_batch++) {
		for (int i_num = 0;i_num < pBlob->channelSize;i_num++) {	
			for (int i_height = 0;i_height < (pBlob->heightSize - pBlob->pady*2);i_height++) {	
				for (int i_width = 0;i_width < (pBlob->widthSize - pBlob->padx*2);i_width++) {	
					sprintf(buf,"%.8f ",ptr[i_batch][i_num][i_height+pBlob->pady][i_width+pBlob->padx]);
					write(fd,buf,strlen(buf));
				}
				write(fd,"\n",1);
			}
			write(fd,"\n",1);
		}
		write(fd,"\n",1);
	}	

	close(fd);

	return 0;
}


int LOG_writeBlobToBinFile(char *binFile,BLOB_s *pBlob)
{
	int fd = open(binFile,O_RDWR | O_CREAT,0666);
	CHECK_EXPR_RET(fd < 0,-1);

	BLOB_DATA_TYPE *pData = BLOB_data(pBlob);

	int writeSize = sizeof(BLOB_DATA_TYPE)*pBlob->count;
	int nwrite = write(fd,&pData[0],writeSize);
	CHECK_EXPR_RET(nwrite != writeSize,-1);

	close(fd);

	return 0;
}

int LOG_compBinFile(char *binFile1,char *binFile2,int size)
{
	int f1 = open(binFile1,O_RDONLY,0666);
	CHECK_EXPR_RET(f1 < 0,-1);
	
	int f2 = open(binFile2,O_RDONLY,0666);
	CHECK_EXPR_RET(f1 < 0,-1);

	double *buffer1 = (double *)malloc(sizeof(double)*size);
	CHECK_EXPR_RET(buffer1 == NULL,-1);

	double *buffer2 = (double *)malloc(sizeof(double)*size);
	CHECK_EXPR_RET(buffer2 == NULL,-1);
	
	int nreadFile1 = read(f1,buffer1,size);
	CHECK_EXPR_RET(nreadFile1 != size,-1);

	int nreadFile2 = read(f2,buffer2,size);
	CHECK_EXPR_RET(nreadFile2 != size,-1);

	BOOL flag = TRUE;
	int i = 0;
	for ( i = 0;i < size;i++) {
		if (fabsf(buffer1[i] - buffer2[i]) > 0.00000001) {
			printf("NotEquale:[%s %.10lf] != [%s %.10lf] offset:%d diff:%lf\n",
						binFile1,buffer1[i],binFile2,buffer2[i],i,buffer1[i]-buffer2[i]);
			flag = FALSE;
			return -1;
		}
	}

	if (flag == TRUE) {
		printf("Equale %s == %s\n",binFile1,binFile2);
	}
	free(buffer2);
	free(buffer1);

	close(f2);
	close(f1);

	return 0;
}




