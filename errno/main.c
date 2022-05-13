#include <stdio.h>
#include <string.h>
#include <errno.h>


int main(int argc, char const *argv[])
{
    for(int tmp = 0; tmp <=256; tmp++)
    {
        printf("errno: %2d\t%s\n",tmp,strerror(tmp));
    }
    return 0;
}

