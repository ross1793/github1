#include<stdio.h>
#include<stdlib.h>




int main(void){
	int *arr = malloc(100 * sizeof(int));
	printf("%d\n",arr[99]);
	printf("%d\n",arr[100]);
	printf("%d\n",arr[101]);

	return 0;
}
