
int isempty(stack *s){
	if(s->tail==NULL)
		return 1;
		return 0;
}

void push(stack *s,node *nd){
	nd->next=s->tail;
	s->tail=nd;
}

node * pop(stack *s){
	if(isempty(s))
		return NULL;
	node* t=s->tail;
	s->tail=t->next;
	return t;
}

void print_stack(stack *s){
	if(isempty(s)){
	  printf("EMPTY\n");
	  return;
	}
	node* t=s->tail;
	while(t!=NULL){
		if(t->data==-pow(2,31))
			printf("%ld ",(ll)-1*(t->data));
		   else
		   printf("%d ",t->data);
	   //printf("%d ",t->data);
	   t=t->next;
	}
	printf("\n");
	return;
}

node* createnode(int val){
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=val;
	temp->next=NULL;
	return temp;
}
stack* intstack(){
	stack *s;
	s=(stack *)malloc(sizeof(stack));
	s->tail=NULL;
}