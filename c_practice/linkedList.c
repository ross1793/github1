#include<stdio.h>
#include<stdlib.h>

struct ex{
	int data;
	int y;
};

typedef struct node{
	int data;
   struct node *next;
}Node;

void add_tail(struct node *first,int data){
	struct node *current = first;
	while( current -> next != NULL )
	{
		current = current -> next;
	}
	struct node *new_node = malloc(sizeof(struct node));
	new_node -> next = NULL;
	new_node -> data = data;
	current -> next = new_node;
}

void print_all(struct node *root){
	struct node *current = root;
	if( current == NULL )
		return;
	
	do
	{
		printf("%d\n",current->data);
		current = current -> next;
	}	
	while( current != NULL );
}

Node* reverseList(Node *root){
   Node *previous = NULL;
   Node *current = root;
   Node *next;

   while(current != NULL){
      next = current->next;
      current->next = previous;
      previous = current;
      current = next;
   }

   return previous;


}

int main(void)
{
	struct node *root = malloc(sizeof(struct node));
	root -> data = 1;
	root -> next = NULL;

	add_tail(root,2);
	add_tail(root,3);
	add_tail(root,4);
	add_tail(root,5);
	add_tail(root,6);

	print_all(root);
   printf("\n");

   Node *newRoot = reverseList(root);
	print_all(newRoot);

	return 0;
}
