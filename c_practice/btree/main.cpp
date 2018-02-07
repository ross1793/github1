#include<iostream>
using namespace std;

class tree{
	private:
		struct node{
			int data;
			node *rr;
			node *ll;
		}*root;
	public:
		tree();
		void insert(int data);
		void print(node*);
		void printAll();
		int depth(node*);
		int height();
};

tree::tree()
{
	root = NULL;
}

int tree::height()
{
	return depth(root);
}

int tree::depth(node *current)
{
	if( current == NULL )
		return 0;
	int l_depth = depth( current -> ll );	
	int r_depth = depth( current -> rr );
	return (l_depth > r_depth) ? 1+l_depth : 1+r_depth;
}

void tree::insert(int data)
{
	node *temp = new node;
	temp -> data = data;
	temp -> rr = NULL;
	temp -> ll = NULL;
	
	if( root == NULL )
	{
		root = temp;
		return;
	}
	cout << "here" << endl;	
	node *current = root;
	node *parent;
	int LR;
	while( current != NULL )
	{
		parent = current;
		if( data < current -> data )
		{
			current = current -> ll;
			LR = -1;
		}
		else if( data > current -> data )
		{
			current = current -> rr;
			LR = 1;
		}
		else
		{
			cout << "this data already exist... " << endl;
			return;
		}
	}
	if( LR == -1 )
		parent -> ll = temp;
	else
		parent -> rr = temp;

}

void tree::printAll()
{
	print(root);
}

void tree::print(node *current)
{
	if( current == NULL )
		return;
	cout << current -> data << endl;
	print(current -> ll);	
	print(current -> rr);
}

int main()
{
	tree *x = new tree;
	x->insert(10);
	x->insert(20);
	x->insert(50);
	x->insert(5 );
	x->printAll();
	cout <<	x->height() << endl; 
	return 0;
}
