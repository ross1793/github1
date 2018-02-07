#include<iostream>
using namespace std;

int ladder(int n)
{
	if( n == 1)
		return 1;
	if( n == 2)
		return 1;
	return ladder(n-1) + ladder(n-2);
}

int main()
{
	cout << ladder(30) << endl;
	return 0;
}
