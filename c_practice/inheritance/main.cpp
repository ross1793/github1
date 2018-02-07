#include<iostream>
using namespace std;

class animal{
	public:
	void bark() { cout << "animal bark" << endl; }
};

class dog : public animal{
	public:
	void bark() { cout << "dog bark" << endl; }
};

int main()
{
	dog *a;
	a -> bark();
	animal *b = a;
	b -> bark();

	return 0;
}
