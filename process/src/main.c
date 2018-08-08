#include <unistd.h>
#include <stdio.h>

#include "progress.h"
#include "color.h"

int main(int argc, char const *argv[])
{
    for(int i=0;i<100;i++)
    {
        if(i<10)
        {
            PrintProgressWithColor(i,RED);
        }
        else
        {
            PrintProgress(i);
        }
        sleep(1);
    }
    printf("\n");
    return 0;
}
