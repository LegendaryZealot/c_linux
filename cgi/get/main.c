#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("Content-Type: text/html\r\n\r\n");
    printf("QUERY_STRING: %s\n", getenv("QUERY_STRING"));
    return 0;
}
