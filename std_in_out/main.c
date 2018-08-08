#include <stdio.h>

//echo "121212"|./app

int main(int argc, char const *argv[])
{
    //old version
    // int c;
    // while(EOF!=(c=getc(stdin)))
    // {
    //     printf("enter while\n");
    //     if(EOF==putc(c,stdout))
    //     {
    //         printf("error\n");
    //         break;
    //     }
    //     printf("print done\n");
    // }
    char buf[128];
    while(NULL!=fgets(buf,sizeof(buf),stdin))
    {
        printf("%s",buf);
    }
    printf("\n");
    return 0;
}
