#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define FULL 25

int resource;
sem_t sema;

void *producer(void* ptr);
void *consumer(void* ptr);


int main(void)
{
	pthread_t thread1,thread2;
	sem_init(&sema,0,1);
	resource = FULL/2;

	char *msg1 = "DOG";

	pthread_create(&thread1,NULL,producer,(void*) msg1);
	pthread_create(&thread2,NULL,consumer,(void*) msg1);

	pthread_join( thread1,NULL);
	pthread_join( thread2,NULL);

	return 0;
}

void *producer(void* ptr)
{
	while(1)
	{
		//sleep(1);
		if( resource == FULL)
			sem_wait(&sema);
		else
		{	
			printf("adding resource\n");
			resource++;
			sem_post(&sema);
		}

	}
}

void *consumer(void* ptr)
{
	while(1)
	{
		
		if( resource == 0)
			sem_wait(&sema);
		else
		{
			sem_post(&sema);
			printf("consuming resource %d\n",resource);
			resource--;
		}

	}
}
