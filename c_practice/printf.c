#include<stdio.h>
#include<stdlib.h>

int main(void){
	printf("show character %c\n",'a');
	printf("show ascii %d\n",'a');
	printf("show decimal %d\n",123);
	printf("show oct %o\n",123);
	printf("show 0x %x\n",123);
	printf("show scientific %e\n",0.1234);
	printf("show float %.3f\n",0.123535);

	float dog = 0.12345;
	int cat;
	cat = dog * 1000;
	dog = (float) cat / 1000;
	printf("dog is %f\n",dog);

	return 0;
}	
