TARGET  := libtest.so

.PHONY : everything clean

all :
	gcc test.c -fPIC -shared -o libtest.so
                
clean :
	-rm -f $(TARGET)