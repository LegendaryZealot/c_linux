#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static void OnSigint(int sigint);

int main(int argc, char const *argv[])
{
    signal(SIGINT,OnSigint);
    printf("pid:%d\n",getpid());
    while(1);
    return 0;
}

static void OnSigint(int sigint)
{
    printf("sigint:%d\n",signal);
    if(0==signal)
    {
        exit(0);   
    }
}
