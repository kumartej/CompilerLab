
astnode* makeLeafNode(int n, int type){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	temp->type = type;
	temp->value = n;
	if(type==INT)
		temp->nodetype = NUM;
	else
		temp->nodetype = BOOLCONS;
	temp->name = NULL;
	temp->ptr1 = NULL;
	temp->ptr2 = NULL;
	temp->ptr3 = NULL;
	temp->gsym =  NULL;
	return temp;
}

astnode* makeOperatorNode(int op,struct ASTNode *l,struct ASTNode *r){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	if(op == GT || op == LT || op == EQ || op==AND || op==OR || op==NOT)
		temp->type = BOOL;
	else if(op==-1)
		temp->type = -1;
	else
		temp->type = INT;
	if(op!=-1 && op!=NOT && l->type!=r->type){
		printf("%d :: TYPE a MISMATCH\n",line);
		exit(1);
	}
	if((op==AND || op==OR || op==NOT) && l->type!=BOOL){
		printf("%d :: TYPE b MISMATCH\n",line);
		exit(1);
	}else if(op!=-1 && op!=AND && op!=OR && op!=NOT && l->type!=INT){
		printf("%d :: TYPE c MISMATCH\n",line);
		exit(1);
	}
	temp->value = -1;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2 = l;
	temp->ptr3 = r;
	temp->ptr1 = NULL;
	temp->gsym = NULL;
	return temp;
}

astnode* makeAssignNode(int op, astnode *l, astnode* r){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	temp->type = -1;
	if(l->type!=r->type){
		printf("%d :: TYPE d MISMATCH\n",line);
		exit(1);
	}
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2=l;
	temp->ptr3=r;
	temp->ptr1=NULL;
	temp->gsym=NULL;
	return temp;
}

astnode* makeReadWriteNode(int op, astnode *l){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	if(op==READ && (l->nodetype!=ID || l->type!=INT) ){
		printf("%d :: NOT AN ID\n",line);
		exit(1);
	}
	if(op==WRITE && l->type!=INT){
		printf("%d :: NOT AN EXPRESSION\n",line );
		exit(1);
	}
	temp->type = -1;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2 = l;
	temp->ptr3 = NULL;
	temp->ptr1 = NULL;
	temp->gsym = NULL;
	return temp;
}

astnode* makeIDNode(int op, char *nm){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	temp->nodetype = op;
	temp->name = nm;
	temp->ptr1 = NULL;
	temp->ptr2 = NULL;
	temp->ptr3 = NULL;
	temp->gsym = GLookup(nm);
	if(temp->gsym!=NULL){
		temp->type = temp->gsym->type;
	}
	temp->value = 1;
	return temp;
}

astnode* makeIFNode(int op, astnode *l,astnode *m , astnode*r){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	if(l->type!=BOOL){
		printf("%d :: NOT BOOLEAN INSIDE IF\n",line);
		exit(1);
	}
	if(r->type!=-1 || m->type!=-1){
		printf("%d :: NOT A STATEMENT IN IF\n",line);
		exit(1);
	}
	temp->type = -1;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr1 = l;
	temp->ptr2 = m;
	temp->ptr3 = r;
	temp->gsym = NULL;
	return temp;
}

astnode* makeWhileNode(int op,struct ASTNode *l,struct ASTNode *r){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	temp->type = -1;
	if(l->type!=BOOL){
		printf("%d :: NOT BOOLEAN INSIDE WHILE\n",line);
		exit(1);
	}
	if(r->type!=-1){
		printf("%d :: NOT A STATEMENT IN WHILE\n",line);
		exit(1);
	}
	temp->value = -1;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2 = l;
	temp->ptr3 = r;
	temp->ptr1 = NULL;
	temp->gsym = NULL;
	return temp;
}

int evalute(astnode *root){
	int retval,retval2;
	gsymbol *glsym;
	if(root->nodetype == NUM){
		return root->value;
	}else if(root->nodetype == BOOLCONS){
		return root->value;
	}else if(root->nodetype == ID){
		if(root->gsym==NULL){
			printf("%d :: VARIABLE NOT DECLARED\n",line);
			exit(1);
		}
		if(root->ptr1!=NULL)
			root->value=evalute(root->ptr1);
		return *(root->gsym->binding+root->value);
	}else if(root->nodetype == READ){
		if( root->ptr2->gsym==NULL){
			printf("%d :: %s VARIABLE NOT DECLARED\n",line,root->ptr2->name);
			exit(1);
		}
		if(root->ptr2->ptr1!=NULL)
			root->ptr2->value = evalute(root->ptr2->ptr1);
		scanf("%d",root->ptr2->gsym->binding+root->ptr2->value);
		
	}else if(root->nodetype == WRITE){
		retval = evalute(root->ptr2);
		printf("%d\n",retval);
	}else if(root->nodetype == ASGN){
		if(root->ptr2->nodetype == ID){
			retval = evalute(root->ptr3);
			if(root->ptr2->gsym==NULL){
				printf("%d :: %s VARIABLE NOT DECLARED\n",line,root->ptr2->name);
				exit(1);
			}
			if(root->ptr2->ptr1!=NULL)
				root->ptr2->value = evalute(root->ptr2->ptr1);
			*(root->ptr2->gsym->binding+root->ptr2->value)=retval;
		}else{
			printf("%d :: INVALID ASSIGNMENT\n",line);
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
	}else if(root->nodetype==DIV){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		if(retval2==0){
			printf("DIVSION BY ZERO\n");
			exit(1);
		}
		return retval/retval2;
	}else if(root->nodetype==MODULO){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		return retval%retval2;
	}else if(root->nodetype == EQ){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		if(retval == retval2)
			return 1;
		else
			return 0;
	}else if(root->nodetype == NE){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		if(retval != retval2)
			return 1;
		else
			return 0;
	}else if(root->nodetype == LE){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		if(retval <= retval2)
			return 1;
		else
			return 0;
	}else if(root->nodetype == GE){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		if(retval >= retval2)
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
	}else if(root->nodetype == AND){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		return retval && retval2;
	}else if(root->nodetype == OR){
		retval = evalute(root->ptr2);
		retval2 = evalute(root->ptr3);
		return retval || retval2;
	}else if(root->nodetype == NOT){
		retval = evalute(root->ptr2);
		return !retval;
	}else if(root->nodetype==IF){
		retval = evalute(root->ptr1);
		if(retval == 1)
			evalute(root->ptr2);
		else if(root->ptr3!=NULL)
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