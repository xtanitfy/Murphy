#include "includes_std.h"
#include "queue.h"
#include "public.h"
#include "muti_tree.h"


/*-1ЮЊПе*/
static int gArr[][2] = {
	{-1,1},{1,20},
	{20,2},{1,3},{1,4},
	{2,5},{2,6},{2,7},{3,8},{3,9},{4,10},
	{5,13},{6,13},{7,13},{8,14},{9,14},{10,11},{10,12},
	{11,21},{21,22},{22,23},{23,14},
	{13,15},{14,15},
	{15,16},
	{16,17}
};

int forwardPrint(void *usr,int idCurr,int *_idPrev,int _nIdPrev)
{
	printf("curr:%d\n",idCurr);
	return 0;
}

int backwardPrint(void *usr,int idCurr,int *_idNext,int _nIdNext)
{
	printf("curr:%d\n",idCurr);
	return 0;
}



int main(void)
{
	MTREE_s *pTree = MTREE_create(NULL);

	for (int i = 0;i < DIM_OF(gArr);i++) {
		MTREE_addItem(pTree,gArr[i][0],gArr[i][1]);
	}

	printf("MTREE_forward:\n");
	MTREE_forward(pTree,forwardPrint);

	printf("MTREE_backward:\n");
	MTREE_backward(pTree,backwardPrint);

	MTREE_printByList(pTree);

	printf("MTREE_forward:\n");
	MTREE_forward(pTree,forwardPrint);

	printf("MTREE_backward:\n");
	MTREE_backward(pTree,backwardPrint);

	
	return 0;
}
