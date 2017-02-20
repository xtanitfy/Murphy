#ifndef __STACK_H__  
#define __STACK_H__

#include "includes_std.h"

typedef struct
{
	int isInited;
	int maxNum;
	void *data;
	int dataNum;
	int itemLen;
}STACK;
 
int STACK_init(void **handle,int maxN,int itemLen);
int STACK_empty(void *handle);
int STACK_full(void *handle);
int STACK_push(void *handle,void *item);
int STACK_pop(void *handle,void *data);
int STACK_getStackDataArr(void *handle,void **data,int *len);
int STACK_destroy(void *handle);

#endif  