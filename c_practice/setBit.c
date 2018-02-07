#include<stdio.h>

#define bit3 (0x1 << 3)


int main(void)
{
	unsigned int a = 5;
	int b = -20;
	int c;
	(a+b) > 10 ? (c = -1 ) : ( c = 1 );
	
	printf("%d\n",c);

}
