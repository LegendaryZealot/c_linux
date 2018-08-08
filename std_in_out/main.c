#include <stdio.h>

//echo "121212"|./app

int main(int argc, char const *argv[])
{
    int c;
    while(EOF!=(c=getc(stdin)))
    {
        printf("enter while\n");
        if(EOF==putc(c,stdout))
        {
            printf("error\n");
            break;
        }
        printf("print done\n");
    }
    return 0;
}
