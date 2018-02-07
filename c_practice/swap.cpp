#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	*a += *b;
	*b = *a - *b;
	*a = *a - *b;
}

void swapy(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a = 10;
	int b = 15;
	swap(&a,&b);
	cout << a << b << endl;

	return 0;
}
