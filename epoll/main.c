#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <poll.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <netinet/in.h>

#include <sys/types.h>
#include <unistd.h>
 
#define MYPORT 12345
 
//最多处理的connect
#define MAX_EVENTS 4096
 
//当前的连接数
int currentClient = 0; 
 
//数据接受 buf
#define REVLEN 128
char recvBuf[REVLEN+1];

int handledFd=0;
 
 
//epoll描述符
int epollfd;
//事件数组
struct epoll_event eventList[MAX_EVENTS];
 
void AcceptConn(int srvfd);
void RecvData(int fd);


char *tmp="Content-Type:text/html\r\n\r\nhi,epoll\n";
 
int main()
{
    printf("pid is:%d\n",getpid());

    int i, ret, sinSize;
    int recvLen = 0;
    fd_set readfds, writefds;
    int sockListen, sockSvr, sockMax;
    int timeout;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    if(0>(sockListen=socket(AF_INET, SOCK_STREAM, 0))){
        char error[128];
        perror(error);
        printf("%s\n",error);
        printf("socket error\n");
        return -1;
    }
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family  =  AF_INET;
    server_addr.sin_port = htons(MYPORT);
    server_addr.sin_addr.s_addr  =  htonl(INADDR_ANY); 
    if(0!=bind(sockListen, (struct sockaddr*)&server_addr, sizeof(server_addr))){
        char error[128];
        perror(error);
        printf("%s\n",error);
        printf("bind error\n");
        return -1;
    }
    if(0!=listen(sockListen, 5)){
        char error[128];
        perror(error);
        printf("%s\n",error);
        printf("listen error\n");
        return -1;
    }
    
    epollfd = epoll_create(MAX_EVENTS);
    struct epoll_event event;
    event.events = EPOLLIN|EPOLLET;
    event.data.fd = sockListen;
    if(0!=epoll_ctl(epollfd, EPOLL_CTL_ADD, sockListen, &event)){
        char error[128];
        perror(error);
        printf("%s\n",error);
        printf("epoll add fail : fd = %d\n", sockListen);
        return -1;
    }
    while(1){
        timeout=3000;
        int ret = epoll_wait(epollfd, eventList, MAX_EVENTS, timeout);
        if(ret < 0){
            char error[128];
            perror(error);
            printf("%s\n",error);
            break;
        }else if(ret == 0)
        {
            printf("timeout ...\r");
            fflush(stdout);
            continue;
        }else{        
            printf("current link:%d\r",ret);
            fflush(stdout);
        }
        for(int i=0; i<ret; i++)
        {
            if ((eventList[i].events & EPOLLERR) ||
                (eventList[i].events & EPOLLHUP) ||
                !(eventList[i].events & EPOLLIN))
            {
              printf ( "epoll error\n");
              close (eventList[i].data.fd);
              continue;
            }
            if (eventList[i].data.fd == sockListen)
            {
                AcceptConn(sockListen);
        
            }else{
                struct epoll_event event;
                event.data.fd = eventList[i].data.fd;
                event.events =  EPOLLIN|EPOLLET;
                epoll_ctl(epollfd, EPOLL_CTL_DEL, eventList[i].data.fd, &event);
                RecvData(eventList[i].data.fd);
            }
        }
    }
    close(sockListen);
    close(epollfd);
    return 0;
}

void AcceptConn(int srvfd)
{
    struct sockaddr_in sin;
    socklen_t len = sizeof(struct sockaddr_in);
    bzero(&sin, len);
    int confd = accept(srvfd, (struct sockaddr*)&sin, &len);
    if (confd < 0){
       printf("bad accept\n");
       return;
    }
    struct epoll_event event;
    event.data.fd = confd;
    event.events =  EPOLLIN|EPOLLET;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, confd, &event);
}

void RecvData(int fd)
{
    int ret;
    int recvLen = 0;
    const int msgLen=16;
    memset(recvBuf, 0, REVLEN);
    while (0<(ret=read(fd, (char *)recvBuf+recvLen, msgLen))){
        recvLen+=ret;
        if(msgLen>ret){
            break;
        }
        if(msgLen>(REVLEN-recvLen)){
            break;
        }
    }
    write(fd,recvBuf,strlen(recvBuf));
    printf("handled socket fd:%d\r",++handledFd);
    fflush(stdout);
    close(fd);
}