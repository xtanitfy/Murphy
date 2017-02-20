#include "includes_std.h"
#include <sys/time.h>
#include <stdio.h>

static struct timeval tv_begin, tv_end;


void CalTimeStart(void)
{
	gettimeofday(&tv_begin, NULL);
}

void CalTimeEnd(char *title)
{
	gettimeofday(&tv_end, NULL);

	printf("[%s]: consume time:%ld ms\n",title,(tv_end.tv_sec - tv_begin.tv_sec) * 1000 + \
		(tv_end.tv_usec - tv_begin.tv_usec)/1000);
}


