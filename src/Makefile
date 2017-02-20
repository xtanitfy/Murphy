WTD_PROJECT = ..
include  $(WTD_PROJECT)/config.local

LIB_TARGET = platform.a
SRCS    = $(wildcard *.c)
OBJS    = $(SRCS:.c=.o)

INCLUDE = -I./ -I$(WTD_PROJECT)/include 

all: $(LIB_TARGET) 

$(LIB_TARGET): $(OBJS)
	$(AR) -rc $(LIB_TARGET) $(OBJS) 
	mv $(LIB_TARGET) $(WTD_PROJECT)/lib/
	make -C layers
	
	
%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS)  -c -fpic -Wall $< 
clean:
	rm -f *.o   *.bak  *~ $(WTD_PROJECT)/lib/$(LIB_TARGET) 
	make -C layers clean