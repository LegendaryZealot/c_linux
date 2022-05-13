#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>

extern int errno;

int main ()
{
  int a = 5;
  int b = 2;
  pid_t pid;
  pid = fork ();
  if (pid < 0)
  {
    perror ("fork error\n");
    exit(-1);
  }
  else if (pid == 0)
  {
    a = a - 1;
    printf("I'm a child process with PID [%d],parent pid:[%d]\nthe value of a: %d,the value of b:%d.\n",getpid(),getppid(), a, b);
  }
  else
  {
    printf("I'm a parent process, with PID [%d],parent pid:[%d]\nthe value of a: %d, the value of b:%d.\n",getpid,getppid(), a, b);
    exit(0);
  }
  return 0;
}