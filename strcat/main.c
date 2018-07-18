#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buf1[30]="i am buf1";
    char buf2[]="i am buf2";
    char buf3[5];
    printf("size\nbuf1:%ld buf2:%ld buf3:%ld\n",sizeof(buf1),sizeof(buf2),sizeof(buf3));
    printf("content\nbuf1:%s. buf2:%s. buf3:%s.\n",buf1,buf2,buf3);
    printf("test\noutput:%s,target:%s,append:%s\n",strcat(buf1,buf2),buf1,buf2);
    printf("test\noutput:%s,target:%s,append:%s\n",strcat(buf3,buf2),buf3,buf2);//error
    return 0;
}
