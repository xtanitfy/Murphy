

#include "stack.h"


int STACK_init(void **handle,int maxN,int itemLen)
{
	STACK *s;
	
	if(handle == NULL){
		return -1;
	}
	
	s = (STACK *)malloc(sizeof(STACK));
	if(s == NULL){
		return -1;
	}
	s->maxNum = maxN;
	s->itemLen = itemLen;
    s->data = (void *)malloc(s->maxNum * s->itemLen);
	if(s == NULL){
		return -1;
	}
    s->dataNum = 0;
	*handle = (void *)s;
	
	return 0;
}

int STACK_empty(void *handle)
{
	STACK *s;
	s = (STACK *)handle;
	if(handle == NULL){
		return -1;
	}
    return (s->dataNum == 0);
}

int STACK_full(void *handle)
{
	STACK *s;
	
	if(handle == NULL){
		return -1;
	}
	s = (STACK *)handle;
	return (s->dataNum >= s->maxNum);
}

int STACK_push(void *handle,void *item)
{
	STACK *s;

	if(handle == NULL || item == NULL) {
		return -1;
	}
	s = (STACK *)handle;
	if(s->dataNum >= s->maxNum){
		return -1;
	}
	memcpy((char *)s->data+(s->dataNum)*(s->itemLen),(char *)item,s->itemLen);
	s->dataNum++;
	
	return 0;
}

int STACK_pop(void *handle,void *data)
{	
	STACK *s;
	
	if(handle == NULL || data == NULL){
		return -1;
	}
	
	s = (STACK *)handle;
	if(s->dataNum == 0){
		return -1;
	}
	s->dataNum--;
	memcpy(data,(char *)s->data+(s->dataNum)*(s->itemLen),s->itemLen);
	
	return 0;
}

int STACK_getStackDataArr(void *handle,void **data,int *len)
{
	STACK *s;
	
	if(handle == NULL || data == NULL || len == NULL){
		return -1;
	}
	if(STACK_empty(handle)){
		return -1;
	}
	s = (STACK *)handle;
	*data = s->data;
	*len = s->dataNum;
	
	return 0;
}

int STACK_destroy(void *handle)
{
	STACK *s = (STACK *)handle;
	
	if(handle == NULL)
		return -1;
	else
	{
		if(s->data != NULL)
			free(s->data);
		free(s);
	}
	return 0;
}
