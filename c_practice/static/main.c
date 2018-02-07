#include<stdio.h>


int main(void)
{

	extern int someVar;

	printf("%d\n",someVar);
	printf("%d\n",cat());

	return 0;
}
