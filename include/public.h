#ifndef __INCLUDES_H__
#define __INCLUDES_H__

#include "includes_std.h"


#define ABS(x) ((x>(double)0)?x:(-x))

#define DBG_PRT printf("[WARNING][%s %s:%d ]\n",__FILE__,__FUNCTION__,__LINE__)

#define CHECK_EXPR_RET(expr,ret) \
		if(expr) { \
			DBG_PRT;\
			return  ret;\
		}

#define CHECK_EXPR_RET_VOID(expr) \
		if(expr) { \
			DBG_PRT;\
			return;\
		}

#define ERROR_DEBUG(str) \
		printf("[ERROR][%s %s:%d][%s]\n",__FILE__,__FUNCTION__,__LINE__,str)
		
#define CHECK_EXPR_RET_AND_PRINT(expr,ret,str) \
			if(expr) { \
			ERROR_DEBUG(str) \
			return  ret;\
		}

#define DIM_OF(a) (sizeof(a)/sizeof(a[0]))




#endif
