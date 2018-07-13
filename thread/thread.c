#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_function(void *args)
{
  printf("pid:%d\ntid:%d\n",(int)getpid(),(int)pthread_self());
  printf("%s\n\n",(char *)args);
  return NULL;
}

int main()
{
  int err;
  pthread_t *my_thread;
  void *thread_result;
  if(0!=(err=pthread_create(&my_thread,NULL,thread_function,"Done")))
  {
    perror("thread create error!\n");
    exit(1);
  }

  printf("pid:%d\ntid:%d\n\n",getpid(),pthread_self());

  if(0!=pthread_join(my_thread,thread_result))
  {
    perror("thread wait error!\n");
  }

  return 0;
}
