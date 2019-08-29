#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>

int main(int argc,char* argv[]){
    int fd[2];
    if(0!=pipe(fd)){
        exit(1);
    }
    int pid = fork();
    if(0==pid){
        exit(0);
    }else{
        exit(0);
    }
    return 0;
}