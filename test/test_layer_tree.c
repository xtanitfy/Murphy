#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "public.h"
/*
使用队列而不是栈就可以实现层遍历
这里一定要用队列 !!!入队列的时候发现队列尾部已经有相同的值 就不入队列，防止路径重复
*/


#define TEST_NAME_MAX_SIZE 64
#define MUTI_MUX_MAX 8
#define TEST_TEST_LAYER_MAX_N  128 

typedef struct TEST_LAYER_ TEST_LAYER_s;

typedef struct
{
	char name[TEST_NAME_MAX_SIZE];
	int type;
	int val;
	int prevName[MUTI_MUX_MAX];
	int nPrevName;
}TEST_LAYER_PARA_s;


struct 	TEST_LAYER_
{
	TEST_LAYER_PARA_s para;
	int id;
	TEST_LAYER_s *next[MUTI_MUX_MAX];
	int nNext;
	
	TEST_LAYER_s *prev[MUTI_MUX_MAX];
	int nPrev;
};

typedef struct TEST_LAYER_TREE_
{
	int num;
	TEST_LAYER_s head;
}TEST_LAYER_TREE_s;

static TEST_LAYER_TREE_s gLayerTree;
static int gIdAlloc = 0;
static 	void *gStackHanlde;

static int checkBoundary(TEST_LAYER_s *pLayer)
{
	CHECK_EXPR_RET(pLayer == NULL,-1);
	if (pLayer->nNext == MUTI_MUX_MAX || pLayer->nPrev == MUTI_MUX_MAX) {
		return -1;
	}
	return 0;
}

int LYTREE_init(void)
{
	memset(&gLayerTree,'\0',sizeof(gLayerTree));
	STACK_init(gStackHanlde,TEST_TEST_LAYER_MAX_N,sizeof(TEST_LAYER_s *));
}

int LYTREE_add(TEST_LAYER_PARA_s *pPara)
{
	
	TEST_LAYER_s *pHead = &gLayerTree.head;
	TEST_LAYER_s *pFisrt = pHead->next[0];
	TEST_LAYER_s *pLayer = (TEST_LAYER_s *)malloc(sizeof(TEST_LAYER_s));
	memset(pLayer,'\0',sizeof(TEST_LAYER_s));

	if (pFisrt == NULL) {
		memcpy(&pLayer->para,pPara,sizeof(TEST_LAYER_PARA_s));
		pHead->next[0] = pLayer;
		
		gLayerTree.num++;
		return 0;
	}
	TEST_LAYER_s *pLayerTmp = NULL;
	BOOL isFindPrev = FALSE;
	for (int i = 0;i < pPara->nPrevName;i++) {
		
		if (!strncmp(pPara->prevName[i], pFisrt->para.name,strlen(pFisrt->para.name))) {
			memcpy(&pLayer->para,pPara,sizeof(TEST_LAYER_PARA_s));
			CHECK_EXPR_RET(checkBoundary(pFisrt) < 0,-1);
			CHECK_EXPR_RET(checkBoundary(pLayer) < 0,-1);
			pFisrt->next[pFisrt->nNext++] = pLayer;
			pLayer->prev[pLayer->nPrev++] = pFisrt;
			isFindPrev = TRUE;
			continue;
		}
		

		/*将所有后边的节点压栈*/
		for (int i = 0;i < pFisrt->nNext;i++) {
			if (pFisrt->next[i] != NULL) {
				STACK_push(gStackHanlde,&pFisrt->next[i]);
			}
		}

		while(!STACK_empty(gStackHanlde)) {
			STACK_pop(gStackHanlde,&pLayerTmp);
			if (!strncmp(pLayerTmp->para.name, pPara->prevName[i],strlen(pPara->prevName[i])) {
				CHECK_EXPR_RET(checkBoundary(pLayer) < 0,-1);
				CHECK_EXPR_RET(checkBoundary(pLayerTmp) < 0,-1);
				pLayerTmp->next[pLayerTmp->nNext++] = pLayer;
				pLayer->prev[pLayer->nPrev++] = pLayerTmp;
				isFindPrev = TRUE;
			}
			
			for (int i = 0;i < pLayerTmp->nNext;i++) {
				if (pLayerTmp->next[i] != NULL) {
					STACK_push(gStackHanlde,&pLayerTmp->next[i]);
				}
			}
		}		
	}

	if (isFindPrev == FALSE) {
		free(pLayer);
		CHECK_EXPR_RET(TRUE,-1);
	}

	gLayerTree.num++;
	
	return 0;
}

int LYTREE_forward(void)
{
	TEST_LAYER_s *pHead = &gLayerTree.head;
	TEST_LAYER_s *pFisrt = pHead->next[0];

	

	
	return 0;
}

int LYTREE_backward(void)
{
	
	return 0;
}


int main(int argc,char **argv)
{
	
	TEST_LAYER_PARA_s para0;
	strcpy(para0.name,"layer0");
	para0.val = 23;
	para0.nPrev = 0;
	LYTREE_add(&para0);
	
	
	return 0;
}













