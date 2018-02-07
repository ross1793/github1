#include<iostream>
using namespace std;

int * arr()
{
   int a[5] = {1,2,3,4,5};
	return &a[0];
}


int main()
{
	int *x;
	x = arr();
	for(int i=0;i<5;i++)
		cout << x[i] << endl;
	return 0;
}
