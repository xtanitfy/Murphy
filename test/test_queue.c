#include "queue.h"
#include "public.h"

static int arr[] = {
	1,24,5,46,76,87,
};

int main(void)
{

	QUEUE_s *pQ = QUEUE_create(sizeof(int),16);
	for (int i = 0;i < DIM_OF(arr);i++) {
		QUEUE_enqueue(pQ,&arr[i]);
	}

	int val;
	while(QUEUE_dequeue(pQ,&val) != QUEUE_EMPTY) {
		printf("val:%d\n",val);
	}

	
	return 0;
}