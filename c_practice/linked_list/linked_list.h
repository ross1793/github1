class list{
	private:
		struct node{
			int data;
			node *next;
		}*root;
	public:
		list(){ root = NULL; }
		list(int data) {	root = new node; 
								root -> data = data;
								root -> next = NULL;
							}
		void pushHead(int data);	
		void pushTail(int data);
		void print();
		void reverse();
      int getValueReverseOrder(int n);
};

