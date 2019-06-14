#include <stdio.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mutex;

void *thread_a(void *arg)
{
    printf("thread a enter\n");
    pthread_mutex_lock(&mutex);
    printf("mutex a lock\n");
    sleep(6);
    pthread_mutex_unlock(&mutex);
    printf("mutex a unlock\n");
}

void *thread_b(void *arg)
{
    printf("thread b enter\n");

    pthread_mutex_trylock(&mutex);

    while(pthread_mutex_trylock(&mutex)==EBUSY)
    {
        printf("%d\n",pthread_mutex_trylock(&mutex));
        printf("pthread b trylock\n");
        sleep(1);
    }


    // pthread_mutex_lock(&mutex);

    printf("mutex b lock\n");
    pthread_mutex_unlock(&mutex);
    printf("mutex b unlock\n");
}

int main(int argc,char **argv)
{
    pthread_t tid_a,tid_b;
    int err;

    if(pthread_mutex_init(&mutex,NULL) != 0)
    {
        perror("pthread_mutex_init");

    }

    err = pthread_create(&tid_a,NULL,thread_a,NULL);
    if(err != 0)
    {
        perror("pthread_create thread_a");
    }
    err = pthread_create(&tid_b,NULL,thread_b,NULL);
    if(err < 0)
    {
        perror("pthread_create thread_b");
    }
    sleep(10);

    printf("the main close\n");

    return 0;
}