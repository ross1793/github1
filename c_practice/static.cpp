#include<iostream>
using namespace std;

class dog{
	public:
	int number;
	static int size;
	void setSize(int size) { this->size = size; }
};
int dog::size = 10;

int main()
{
	dog black;
	dog white;
	cout << white.size << endl;
	white.setSize(100);	
	cout << black.size << endl;
	return 0;
}
