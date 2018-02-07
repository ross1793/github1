#include<stdio.h>

union dog{
	int num;
	float size;
} dog;


int main(void){
	union dog black;

	black.num = 15;
	printf("%f\n",black.size);
	printf("%d\n",black.num);
	
	black.size = 1234.213;
	printf("%f\n",black.size);
	printf("%d\n",black.num);
	


	return 0;
}
