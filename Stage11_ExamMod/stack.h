#define ll long int

struct stacknode{
	int data;
	struct stacknode * next;
};

#define node struct stacknode

struct structstack{
	node * tail;
};

#define stack struct structstack

int isempty(stack *s);

void push(stack *s,node *nd);

node * pop(stack *s);

void print_stack(stack *s);

node* createnode(int val);

stack* intstack();