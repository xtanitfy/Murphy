WTD_PROJECT = ..
include  $(WTD_PROJECT)/config.local

LIB_PATH = $(WTD_PROJECT)/lib

#LOCAL_TARGET = test_blob

LIBS    =   $(LIB_PATH)/platform.a 

INCLUDE = -I./ -I$(WTD_PROJECT)/include/ 

TARGET =   test_log test_queue test_tree test_conv

all:$(TARGET)

test_log:test_log.c
	$(CC) $^ -o $@ -lpthread  -ldl -lm -lstdc++  $(CFLAGS)  $(OBJS)  $(LIBS) -I$(INCLUDE) 

test_queue:test_queue.c
	$(CC) $^ -o $@ -lpthread  -ldl -lm -lstdc++  $(CFLAGS)  $(OBJS)  $(LIBS) -I$(INCLUDE) 

test_tree:test_tree.c
	$(CC) $^ -o $@ -lpthread  -ldl -lm -lstdc++  $(CFLAGS)  $(OBJS)  $(LIBS) -I$(INCLUDE) 

test_conv:test_conv.c
	$(CC) $^ -o $@ -lpthread  -ldl -lm -lstdc++  $(CFLAGS)  $(OBJS)  $(LIBS) -I$(INCLUDE)

	
clean:
	rm -f *.o *.bak *.~ $(TARGET) test_log test_conv





