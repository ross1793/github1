#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>


int arr[200];

void *read()
{
	printf("doing reading\n");
	int i=0;
	for(i=0;i<100;i++)
	{
		printf("%d",arr[i]);
	}
}

void *write()
{
	printf("doing writing\n");
	int i=0;
	for(i=0;i<100;i++)
	{
		printf("x");
		arr[i] = 1;
	}	
}

int main(void)
{
	memset(arr,0,sizeof(arr));
	pthread_t thread1,thread2;
	char *msg1 = "one";
	char *msg2 = "two";

	//int *one = 1;
	//int *two = 2;


	int bb = pthread_create(&thread2,NULL,write,(void*) msg2);
	int aa = pthread_create(&thread1,NULL,read,(void*) msg1);
//	pthread_join(thread1,NULL);
//	pthread_join(thread2,NULL);

	pthread_exit(NULL);

	return 0;
}


