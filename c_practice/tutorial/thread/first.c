#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *print_message( void *ptr);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;


main()
{
	pthread_t thread1,thread2;
	char *message1 = "THREAD1";
	char *message2 = "THREAD2";
	int ir1,ir2;

	ir1 = pthread_create( &thread1,NULL,print_message,(void*) message1);
	ir2 = pthread_create( &thread2,NULL,print_message,(void*) message2);

	pthread_join( thread1,NULL );
	pthread_join( thread2,NULL );

	exit(0);
}

void *print_message( void *ptr)
{
	char *msg;
	msg = (char *) ptr;
	printf("%s \n",msg);
}
