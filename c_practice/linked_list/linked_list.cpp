#include<iostream>
#include"linked_list.h"
using namespace std;

void list::pushHead(int data){
	node *new_node = new node;
	new_node -> data = data;
	new_node -> next = root;
	root = new_node;	
}

void list::pushTail(int data){
	node *new_node = new node;
	new_node -> data = data;
	new_node -> next = NULL;
	if( root == NULL )
		root = new_node;
	else{
		node *current = root;
		while(current -> next != NULL )
			current = current -> next;
		current -> next = new_node;
	}
}

void list::print(){
	if( root == NULL )
		return;
	node *current = root;
	do{
		cout << current -> data << endl;
		current = current -> next;
	}while(current != NULL );
}

void list::reverse(){
	if( root == NULL )
		return;
	node *current = root;
	node *next_node = current -> next;
	node *previous_node = NULL;
	while( current -> next != NULL )
	{
		//first change direction of next pointer
		current -> next = previous_node;
	
		//move on to the next node	
		previous_node = current;
		current = next_node;
		next_node = current -> next;
	}
	current -> next = previous_node;
	root = current;
}

int list::getValueReverseOrder(int n){
   static node* current = root;

   if(current == NULL)
      return 0xFFFFFF;

   if(n == 0)
      return current->data;
   else
      current = current->next;
      getValueReverseOrder(n);

} 

