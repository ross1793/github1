#include<stdio.h>
#include<string.h>



int main(void)
{
	char first[50];
	char second[50];
	
	gets(first);

	strcpy(second,first);
	printf("%s\n",second);


	return 0;
}
