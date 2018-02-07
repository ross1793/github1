#include<iostream>
#include"linked_list.h"
using namespace std;


int main(){
	list *dog = new list();
	dog -> pushHead(100);
	dog -> pushHead(200);
	dog -> pushHead(300);
	dog -> pushHead(400);
	dog -> pushHead(500);
	dog -> print();

	cout << "reverse " << endl;
	dog -> reverse();
	dog -> print();

	return 0;
}
