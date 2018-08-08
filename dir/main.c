#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
    DIR *dir;
    struct dirent *dirp;
    if(2!=argc)
    {
        printf("a single arg(path) is required!\n");
        return 0;
    }
    if(NULL==(dir=opendir(argv[1])))
    {
        printf("wrong path!\n");
        return 0; 
    }
    while((dirp=readdir(dir)))
    {
        printf("%s\n",dirp->d_name);
    }
    return 0;
}
