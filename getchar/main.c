#include <stdio.h>

int main(int argc,char *argv[]){
    int tmp;
    while (1)
    {
        tmp=getchar();
        printf("%c\t%d\n",tmp,tmp);
    }
    return 0;
}