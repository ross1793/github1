#include<iostream>
using namespace std;

int DP[1000];

int fibo_basic(int n)
{
	if( n == 1 )
		return 1;
	if( n == 2 )
		return 1;
	return fibo_basic( n-1 ) + fibo_basic( n-2 );
}

int fibo_DP(int n)
{
	if( DP[n] != 0 )
		return DP[n];
	DP[n] = fibo_DP(n-1) + fibo_DP(n-2);
	return DP[n];
}

int main(){
	int i;
	cin >> i;

	DP[1] = 1;
	DP[2] = 1;
	cout << fibo_DP(i) << endl;
	cout << fibo_basic(i) << endl;

	return 0;
}
