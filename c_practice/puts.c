#include<stdio.h>

int main(void){
	char str[20];
	char g;

	g = getchar();
	getchar();
	putchar(g);

	putchar('\n');
	//fflush(stdin);
	//fflush(stdout);

	char c;	
	c = getchar();
	getchar();
	putchar(c);

	//puts("put some character... " );
	//gets(str);
	//puts("the char you put are ... ");
	//puts(str);
	putchar('\n');

	return 0;
}
