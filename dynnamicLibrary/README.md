### ubuntu:~/Documents/c_linux/so$ls
### lib  main.c  main.o  Makefile
### ubuntu:~/Documents/c_linux/so$ls
### lib  main.c  main.o  Makefile
### ubuntu:~/Documents/c_linux/so$cd lib/
### ubuntu:~/Documents/c_linux/so/lib$make
### gcc test.c -fPIC -shared -o libtest.so
### ubuntu:~/Documents/c_linux/so/lib$cp *so ..
### ubuntu:~/Documents/c_linux/so/lib$cd ..
### ubuntu:~/Documents/c_linux/so$ls
### lib  libtest.so  main.c  main.o  Makefile
### ubuntu:~/Documents/c_linux/so$make
### gcc -g -Wall -O3  -I. -DHAVE_CONFIG_H -o app main.o  -L. -ltest
### ubuntu:~/Documents/c_linux/so$make run
### LD_LIBRARY_PATH=. ./app
### 4
