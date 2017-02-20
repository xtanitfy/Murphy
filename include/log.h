#ifndef __LOG_H__
#define __LOG_H__

#include "blob.h"
#include "data_type.h"

int LOG_init(void);
int LOG_writeBlob(BLOB_s *pBlob);
int LOG_compBinFile(char *binFile1,char *binFile2,int size);
int LOG_writeBlobToBinFile(char *binFile,BLOB_s *pBlob);
int LOG_writeBlobToTxtFile(char *txtFile,BLOB_s *pBlob);
#endif