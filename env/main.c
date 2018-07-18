#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int setCode;
    char *env;
    env=getenv("test");
    if(env)
    {
        printf("env:%s\n",env);
    }else{
        printf("NULL env:test\n");
    }
    setCode=putenv("test=100");
    printf("%d\n",setCode);
    env=getenv("test");
    if(env)
    {
        printf("env:%s\n",env);
    }
    else{
        printf("NULL env:test");
    }
    setCode=putenv("test=200");
    printf("%d\n",setCode);
    env=getenv("test");
    if(env)
    {
        printf("env:%s\n",env);
    }
    else{
        printf("NULL env:test");
    }
    setCode=setenv("test","300",0);
    printf("%d\n",setCode);
    env=getenv("test");
    if(env)
    {
        printf("env:%s\n",env);
    }
    else{
        printf("NULL env:test");
    }
    setCode=setenv("test","300",1);
    printf("%d\n",setCode);
    env=getenv("test");
    if(env)
    {
        printf("env:%s\n",env);
    }
    else{
        printf("NULL env:test\n");
    }
    return 0;
}
