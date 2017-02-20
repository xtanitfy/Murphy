WTD_PROJECT = ..
include  $(WTD_PROJECT)/config.local

LIB_PATH = $(WTD_PROJECT)/lib

#LOCAL_TARGET = math_functions

LIBS    =   $(LIB_PATH)/platform.a /usr/lib/atlas-base/libcblas.a /usr/lib/libblas.a

INCLUDE = -I./ -I$(WTD_PROJECT)/include/  -I/usr/include

TARGET = test 

CFLAGS = -lpthread  -lm -w -std=c99 -lstdc++ 

all:$(TARGET)

test: test.c math_functions.c
	$(CC) $^ -o $@    $(CFLAGS)  $(OBJS)  $(LIBS) $(INCLUDE) 

	
clean:
	rm -f *.o *.bak *.~ $(TARGET) test_log test_conv





