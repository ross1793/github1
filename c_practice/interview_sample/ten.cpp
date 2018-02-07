#include<iostream>
using namespace std;

int n_one(int num)
{
	int ans = 0;
	while( num != 0 ){
		ans += num % 2;
		num = num >> 1;
	}	
	return ans;
}

int n_one1(int n)
{
	int c=0;
	for(c=0;n;c++)
		n &= n-1;
	return c;
}

int main()
{
	int num = 255;
	cout << n_one( num ) << endl;
	cout << n_one1( num ) << endl;
	
	return 0;
}
