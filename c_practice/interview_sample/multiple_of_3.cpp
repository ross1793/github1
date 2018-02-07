#include<iostream>
using namespace std;

bool m3( int num )
{
	if( num == 0 )
		return true;
	else if( num == 1 || num == 2 )
		return false;
	m3( num - 3 );

}


int main()
{
	cout << m3( 1111 ) << endl;
	cout << m3( 11111) << endl;
	cout << m3( 111111) << endl;


	return 0;
}
