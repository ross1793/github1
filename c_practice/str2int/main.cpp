#include<iostream>
using namespace std;

int str2int(char *str)
{
	int ans = 0;
	while( *str != '\0' )
	{
		if( *str - 48 > 9 || *str - 48 < 0 )
		{
			cout << "not number \n ";
			return 0;
		}
		ans = 10*ans + (*str - 48);
		str++;
	}
	return ans;
}

int main()
{
	char str[] = "1793";
	cout << str2int(str) << endl;
	return 0;
}
