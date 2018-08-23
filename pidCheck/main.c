#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if(2!=argc)
    {
        printf("tip(s):%s <pid>\n",argv[0]);
        return 0;
    }
    int code=kill(atoi(argv[1]),0);
    printf("resu;t code:%d\n",code);
    return 0;
}
