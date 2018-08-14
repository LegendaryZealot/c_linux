#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char const *argv[])
{
    printf("%d\n",1|1);
    printf("%d\n",1|2);
    printf("%d\n",O_WRONLY);
    printf("%d\n",O_CREAT);
    printf("%d\n",O_WRONLY|O_CREAT);

    int souce_fd;
    int target_fd;
    int read_bytes;
    int write_bytes;
    char buf[BUFSIZE];
    char *cptr;

    if(3!=argc)
    {
        fprintf(stderr,"use:%s\n",argv[0]);
        exit(0);
    }

    if(-1==(souce_fd=open(argv[1],O_RDONLY)))
    {
        fprintf(stderr,"open %s error:%s\n",argv[1],strerror(errno));
        exit(0);
    }

    if(-1==(target_fd=open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR)))
    {
        fprintf(stderr,"open %s error:%s\n",argv[2],strerror(errno));
        exit(0);
    }

    while(read_bytes=read(souce_fd,buf,BUFSIZE))
    {
        if((read_bytes==-1)&&(errno!=EINTR))
        {
            break;
        }
        else if(read_bytes>0)
        {
            cptr=buf;
            while(write_bytes=write(target_fd,cptr,read_bytes))
            {
                if((write_bytes==-1)&&(errno!=EINTR))
                    break;
                else if(write_bytes==read_bytes)
                    break;
                else if(write_bytes>0)
                {
                    cptr+=write_bytes;
                    read_bytes-=read_bytes;
                }
            }
            if(-1==write_bytes)
            {
                break;
            }
        }
    }

    close(souce_fd);
    close(target_fd);
    return 0;
}
