#ifndef __MUTI_TREE_H__
#define __MUTI_TREE_H__

#include "includes_std.h"
#include "public.h"
#include "queue.h"
#include "data_type.h"
#include "dlist.h"

typedef struct MTREE_ITEM_ MTREE_ITEM_s;

#define MTREE_MAX_MUX 8
#define MTREE_MAX_END 8
#define QUEUE_MAX_N MTREE_MAX_MUX*8

struct MTREE_ITEM_
{
	int valCurr;

	MTREE_ITEM_s *next[MTREE_MAX_MUX];
	int nNext;
	int syncNext;//防止节点的计算不同步
	
	MTREE_ITEM_s *prev[MTREE_MAX_MUX];
	int nPrev;
	int syncPrev;//防止节点的计算不同步

	struct list_head list;
};


typedef struct
{
	int num;
	MTREE_ITEM_s *root; 
	QUEUE_s *pQAdd;
	QUEUE_s *pQForward;
	QUEUE_s *pQBackward;
	MTREE_ITEM_s *pEnd[MTREE_MAX_END];
	int nEnd;
	void *usr;
	MTREE_ITEM_s *rootInverse; 
	
	struct list_head head;
}MTREE_s;


MTREE_s *MTREE_create(void *usr);
int MTREE_addItem(MTREE_s *pTree,int prev,int val);
int MTREE_forward(MTREE_s *pTree,int (*callback)(void *usr,int idCurr,int *_idPrev,int _nIdPrev));
int MTREE_backward(MTREE_s *pTree,int (*callback)(void *usr,int idCurr,int *_idNext,int _nIdNext));
int MTREE_printByList(MTREE_s *pTree);
int MTREE_getEndIds(MTREE_s *pTree,int *endId,int *n);

#endif