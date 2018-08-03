#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i,*j;
    i=0;
    printf("%d %d\n",i,j);
    j=&i;
    (*j)++;
    printf("%d %d\n",i,j);
    int z=*j;
    printf("%d %d\n",i,z);
    return 0;
}
