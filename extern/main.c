#include <stdio.h>

#include "test.h"

extern int i;

int main(int argc, char const *argv[])
{
    printf("%d\n",i);
    Add();
    printf("%d\n",i);
    return 0;
}
