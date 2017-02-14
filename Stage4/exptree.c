astnode* makeLeafNode(int n, int type){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	temp->type = type;
	temp->value = n;
	temp->nodetype = NUM;
	temp->name = NULL;
	temp->ptr1 = NULL;
	temp->ptr2 = NULL;
	temp->ptr3 = NULL;
	temp->gsym =  -1;
	return temp;
}

astnode* makeOperatorNode(int op,struct ASTNode *l,struct ASTNode *r){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	if(op == GT || op == LT || op == EQ)
		temp->type = 1;
	else
		temp->type = 2;
	temp->value = -1;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2 = l;
	temp->ptr3 = r;
	temp->ptr1 = NULL;
	temp->gsym = -1;
	return temp;
}

astnode* makeAssignNode(int op, astnode *l, astnode* r){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	temp->type = -1;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2=l;
	temp->ptr3=r;
	temp->ptr1=NULL;
	temp->gsym=-1;
	return temp;
}

astnode* makeReadWriteNode(int op, astnode *l){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	temp->type = -1;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2 = l;
	temp->ptr3 = NULL;
	temp->ptr1 = NULL;
	temp->gsym = -1;
	return temp;
}

astnode* makeIDNode(int op, char nm){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	temp->type = 1;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr1 = NULL;
	temp->ptr2 = NULL;
	temp->ptr3 = NULL;
	temp->gsym = nm-'a';
	return temp;
}

astnode* makeIFNode(int op, astnode *l,astnode *m , astnode*r){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	temp->type = -1;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr1 = l;
	temp->ptr2 = m;
	temp->ptr3 = r;
	temp->gsym = -1;
	return temp;
}

astnode* makeWhileNode(int op,struct ASTNode *l,struct ASTNode *r){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	if(op == GT || op == LT || op == EQ)
		temp->type = 1;
	else
		temp->type = 2;
	temp->value = -1;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2 = l;
	temp->ptr3 = r;
	temp->ptr1 = NULL;
	temp->gsym = -1;
	return temp;
}

int evalute(astnode *root){
	int retval,retval2;
	if(root->nodetype == NUM){
		return root->value;
	}else if(root->nodetype == ID){
		if(var[root->gsym]==NULL){
			printf("VARIABLE NOT USED\n");
			exit(1);
		}
		return *var[root->gsym];
	}else if(root->nodetype == READ){
		if(var[root->ptr2->gsym]==NULL)
			var[root->ptr2->gsym] =(int*)malloc(sizeof(int));
		scanf("%d",var[root->ptr2->gsym]);
	}else if(root->nodetype == WRITE){
		retval = evalute(root->ptr2);
		printf("%d\n",retval);
	}else if(root->nodetype == ASGN){
		if(root->ptr2->nodetype == ID){
			retval = evalute(root->ptr3);
			if(var[root->ptr2->gsym]==NULL)
				var[root->ptr2->gsym] =(int*)malloc(sizeof(int));
			*var[root->ptr2->gsym]=retval;
		}else{
			printf("INVALID ASSIGNMENT\n");
			exit(1);
		}
	}else if(root->nodetype==PLUS){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		return retval+retval2;
	}else if(root->nodetype==MINUS){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		return retval-retval2;
	}else if(root->nodetype==MUL){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		return retval*retval2;
	}else if(root->nodetype == EQ){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		if(retval == retval2)
			return 1;
		else
			return 0;
	}else if(root->nodetype == LT){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		if(retval < retval2)
			return 1;
		else
			return 0;
	}else if(root->nodetype == GT){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		if(retval > retval2)
			return 1;
		else
			return 0;
	}else if(root->nodetype==IF){
		retval = evalute(root->ptr1);
		if(retval == 1)
			evalute(root->ptr2);
		else
			evalute(root->ptr3);
		return -1;
	}else if(root->nodetype == WHILE){
		retval = evalute(root->ptr2);
		while(retval == 1){
			evalute(root->ptr3);
			retval = evalute(root->ptr2);
		}
		return -1;
	}else{
		evalute(root->ptr2);
		evalute(root->ptr3);
		return -1;
	}
}