#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
 
#define NUM_THREADS     5
 
void *wait(void *t)
{
   int i;
   long tid;
 
   tid = (long)t;
 
   sleep(1);
   printf("Sleeping in thread\n");
   printf("Thread with id : %d ...exiting\n",tid);
   pthread_exit(NULL);
}
 
int main ()
{
   int rc;
   int i;
   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;
   void *status;
 
   // 初始化并设置线程为可连接的（joinable）
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
 
   for( i=0; i < NUM_THREADS; i++ ){
      printf("main() : creating thread, %d \n",i);
      rc = pthread_create(&threads[i], NULL, wait, (void *)&i );
      if (rc){
         printf("Error:unable to create thread, %d\n",rc);
         exit(-1);
      }
   }
 
   // 删除属性，并等待其他线程
   pthread_attr_destroy(&attr);
   for( i=0; i < NUM_THREADS; i++ ){
      rc = pthread_join(threads[i], &status);
      if (rc){
         printf("Error:unable to join");
         exit(-1);
      }
      printf("Main: completed thread id :%d\n",i);
      printf("exiting with status :%d\n",status);
   }
 
   printf("Main: program exiting.\n");
   pthread_exit(NULL);
}
