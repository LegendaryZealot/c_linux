#include <unistd.h>

int main(int argc, char const *argv[])
{
    char buf[128];
    if(0==gethostname(buf,sizeof(buf)))
    {
        printf("%s\n",buf);
    }
    else
    {
        printf("error\n");
    }
    return 0;
}
