#include<stdio.h>

int strcmp(char *first,char *second)
{
	while( *first == *second )
	{
		if( *first == '\0' )
			return 1;
		first++;
		second++;
	}
	return 0;
}

int main(void)
{
	char a[20] = "Hi how are u";
	char b[20] = "Hi how are u";
	printf("%d\n",strcmp(a,b));


	return 0;
}
