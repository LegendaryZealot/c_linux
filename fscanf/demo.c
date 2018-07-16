#include <stdio.h>
#include <stdlib.h>

int 
main(int argc, char const *argv[])
{
    FILE *fp;
    fp=fopen("test.ini","r");
    if(NULL==fp)
    {
        perror("file open error\n");
        exit(-1);
    }
    int i,j,k;
    int count=fscanf(fp,"%d%d%d",&i,&j,&k);
    fclose(fp);
    printf("result:read count:%d,i=%d,j=%d,k=%d\n",count,i,j,k);
    return 0;
}