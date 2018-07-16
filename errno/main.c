#include <stdio.h>
#include <string.h>
#include <errno.h>


int main(int argc, char const *argv[])
{
    printf("last error:%s\n",strerror(0));
    return 0;
}

