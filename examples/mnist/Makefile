WTD_PROJECT = ../..
include  $(WTD_PROJECT)/config.local

LIB_PATH = $(WTD_PROJECT)/lib

SRCS    = $(wildcard *.c)
OBJS    = $(SRCS:.c=.o)


LIBS    =   $(LIB_PATH)/platform.a $(LIB_PATH)/layers.a 

INCLUDE = -I./ -I$(WTD_PROJECT)/include/ 

all:mnist_train

#$(LOCAL_TARGET): $(OBJS) 
#	$(CC) $(CFLAGS)  $(OBJS)  $(LIBS)  -o $@ -lpthread  -ldl -lm -lstdc++

mnist_train:mnist_train.c mnist_read_input.c
	$(CC) $(INCLUDE) $(CFLAGS)  $^  $(LIBS)  -o $@ -lpthread  -ldl -lm -lstdc++

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c -fpic -Wall $< 
	
clean:
	rm -f *.o *.bak *.~ mnist_train





