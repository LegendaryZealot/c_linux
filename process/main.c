#include <unistd.h>
#include <stdio.h>

#include "progress.h"
#include "color.h"

int main(int argc, char const *argv[])
{
    printf("progress start...\r\n");
    for(int i=0;i<101;i++)
    {
        if(i<10)
        {
            PrintProgressWithColor(i,RED);
        }
        else
        {
            PrintProgress(i);
        }
        usleep(10000);
    }
    printf("\r\ndone\n");
    return 0;
}
