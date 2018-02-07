#include<iostream>
using namespace std;

void bubble( int *num,int size )
{
	int done = 0;
	while( done == 0 )
	{
		done = 1;
		for(int i=0;i<size-1;i++ )
		{
			if( *(num+i) > *(num+1+i) )
			{
				int temp = *(num+i);
				*(num+i) = *(num+1+i);
				*(num+1+i) = temp;
				done = 0;
			}
		}
	}
}				

void selection( int *num,int size)
{
	int temp[size];
	int idx;
	for(int i=0;i<size;i++)
		temp[i] = num[i];
	for(int i=0;i<size;i++)
	{	
		int min = 9999999;
		for(int j=0;j<size;j++)
		{
			if( temp[j] < min )
			{
				min = temp[j];
				idx = j;
			}
		}
		num[i] = temp[idx];
		temp[idx] = 99999999;
	}
}

int main()
{
	int num[10] = {5,10,9,7,2,1,3,6,8,4};
	
	//bubble( num,10 );
	selection(num,10);
		
	for( int i=0;i<10;i++)
		cout << num[i] << endl;
}
