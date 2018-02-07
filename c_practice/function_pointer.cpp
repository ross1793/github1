#include<iostream>
using namespace std;


int foo();
int foo(int,int);

int main(){
	int (*ptr)() = 0;
	ptr = foo;

	int (*ptr2)(int,int) = 0;
	ptr2 = foo;

	//cout << (int)foo << endl;
	cout << (int)ptr << endl;	
	cout << ptr2(10,20) << endl;

	return 0;
}


int foo(){
	cout << "hello world" << endl;
	return 1;
}

int foo(int a,int b)
{
	cout << "i have 2 " << endl;
	return a+b;
}
