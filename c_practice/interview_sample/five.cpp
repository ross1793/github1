#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

void reverse(string *sent)
{
	string str;
	
	while( (*sent).back != ' ' ){
		str.insert( (*sent).back() );
		(*sent).popback();
	}
}


int main()
{
	//char sent[100];
	string sent;
	getline(cin,sent);
	reverse(&sent);	
	cout << sent << endl;

	return 0;
}
