
astnode* makeLeafNode(int n, int type){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	temp->value = n;
	if(type==INT){
		temp->type = TLookup(strdup("INT"));
		temp->nodetype = NUM;
	}else{
		temp->type = TLookup(strdup("BOOL"));
		temp->nodetype = BOOLCONS;
	}
	temp->name = NULL;
	temp->ptr1 = NULL;
	temp->ptr2 = NULL;
	temp->ptr3 = NULL;
	temp->gsym =  NULL;
	temp->lsym =  NULL;
	return temp;
}

astnode* makeOperatorNode(int op,struct ASTNode *l,struct ASTNode *r){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	if(op == GT || op == LT || op == EQ || op==AND || op==OR || op==NOT || op==LE || op==NE || op==GE)
		temp->type = TLookup(strdup("BOOL"));
	else if(op==-1)
		temp->type = NULL;
	else
		temp->type = TLookup(strdup("INT"));;
	if(op!=-1 && op!=NOT && l->type!=r->type){
		printf("%d :: TYPE a MISMATCH\n",line);
		exit(1);
	}
	if((op==AND || op==OR || op==NOT) && l->type!=TLookup(strdup("BOOL"))){
		printf("%d :: TYPE b MISMATCH\n",line);
		exit(1);
	}else if((op==EQ || op==NE) && l->type!=TLookup(strdup("INT")) && r->nodetype!=NULLV){
		printf("%d :: TYPE c MISMATCH\n",line);
		exit(1);
	}else if(op!=-1 && op!=AND && op!=OR && op!=NOT && op!=EQ && op!=NE && l->type!=TLookup(strdup("INT"))){
		printf("%d :: TYPE d MISMATCH\n",line);
		exit(1);
	}
	temp->value = -1;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2 = l;
	temp->ptr3 = r;
	temp->ptr1 = NULL;
	temp->gsym = NULL;
	temp->lsym =  NULL;
	return temp;
}

astnode* makeAssignNode(int op, astnode *l, astnode* r){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	temp->type = NULL;
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
	temp->lsym =  NULL;
	return temp;
}

astnode* makeReadWriteNode(int op, astnode *l){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	if(op==READ && (l->nodetype!=ID || l->type!=TLookup(strdup("INT")))){
		printf("%d :: NOT AN ID\n",line);
		exit(1);
	}
	if(op==WRITE && l->type!=TLookup(strdup("INT"))) {
		printf("%d :: NOT AN EXPRESSION\n",line );
		exit(1);
	}
	temp->type = NULL;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2 = l;
	temp->ptr3 = NULL;
	temp->ptr1 = NULL;
	temp->gsym = NULL;
	temp->lsym =  NULL;
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
	temp->lsym =  LLookup(nm);
	if(temp->lsym==NULL){
		temp->gsym = GLookup(nm);
		if(temp->gsym!=NULL){
			temp->type = temp->gsym->type;
		}
	}else{
		temp->type=temp->lsym->type;
	}
	temp->value = 1;
	return temp;
}

astnode* makeIFNode(int op, astnode *l,astnode *m , astnode*r){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	if(l->type!=TLookup(strdup("BOOL"))){
		printf("%d :: NOT BOOLEAN INSIDE IF\n",line);
		exit(1);
	}
	if(r->type!=NULL || m->type!=NULL){
		printf("%d :: NOT A STATEMENT IN IF\n",line);
		exit(1);
	}
	temp->type = NULL;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr1 = l;
	temp->ptr2 = m;
	temp->ptr3 = r;
	temp->gsym = NULL;
	temp->lsym =  NULL;
	return temp;
}

astnode* makeIFTHENNode(int op,astnode *l,astnode*r){
	astnode* temp;
	temp = (astnode*)malloc(sizeof(astnode));
	if(l->type!=TLookup(strdup("BOOL"))){
		printf("%d :: NOT BOOLEAN INSIDE IF\n",line);
		exit(1);
	}
	if(r->type!=NULL){
		printf("%d :: NOT A STATEMENT IN IF\n",line);
		exit(1);
	}
	temp->type = NULL;
	temp->nodetype = op;
	temp->name=NULL;
	temp->ptr1=l;
	temp->ptr2=r;
	temp->ptr3=NULL;
	temp->gsym=NULL;
	temp->lsym=NULL;
	return temp;
}

astnode* makeWhileNode(int op,struct ASTNode *l,struct ASTNode *r){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	temp->type = NULL;
	if(l->type!=TLookup(strdup("BOOL"))){
		printf("%d :: NOT BOOLEAN INSIDE WHILE\n",line);
		exit(1);
	}
	if(r->type!=NULL){
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
	temp->lsym =  NULL;
	return temp;
}

astnode* makeRetNode(int op,astnode *l){
	astnode *temp;
	temp=(astnode*)malloc(sizeof(astnode));
	if(l->type==NULL){
		printf("%d :: NOT A RETURN TYPE\n",line);
		exit(1);
	}
	temp->type=NULL;
	temp->value=-1;
	temp->nodetype=op;
	temp->name=NULL;
	temp->ptr1=NULL;
	temp->ptr2=l;
	temp->ptr3=NULL;
	temp->gsym=NULL;
	temp->lsym=NULL;
	return temp;
}

astnode* makeFuncNode(int op,astnode *l,astnode *r){
	astnode *temp;
	temp=(astnode*)malloc(sizeof(astnode));
	if(l->gsym==NULL){
		printf("%d :: FUNCTION UNDECLARED\n",line);
		exit(1);
	}
	ArgStruct* atmp=l->gsym->arglist;
	astnode *t2=r;
	while(atmp!=NULL && t2!=NULL){
		if(atmp->type!=t2->type){
			printf("%d :: TYPE MISMATCH IN FUNCTION CALL\n",line );
			exit(1);
		}
		atmp=atmp->next;
		t2=t2->ptr1;
	}
	if(atmp!=NULL || t2!=NULL){
		printf("%d :: WRONG ARGUMENTS PASSED\n",line);
		exit(1);
	}
	temp->type=l->type;
	temp->value=-1;
	temp->nodetype=op;
	temp->name=NULL;
	temp->ptr1=NULL;
	temp->ptr2=l;
	temp->ptr3=r;
	temp->gsym=NULL;
	temp->lsym=NULL;
	return temp;

}

astnode* InstallExpression(astnode *root, astnode *l){
	astnode *temp,*tmp2;
	temp = root;
	tmp2=(astnode*)malloc(sizeof(astnode));
	tmp2->type=l->type;
	tmp2->nodetype=-1;
	tmp2->name=NULL;
	tmp2->ptr1=NULL;
	tmp2->ptr2=l;
	tmp2->ptr3=NULL;
	tmp2->gsym=NULL;
	tmp2->lsym=NULL;
	if(temp==NULL)
		return tmp2;
	while(temp->ptr1!=NULL)
		temp=temp->ptr1;
	temp->ptr1=tmp2;
	return root;
}

astnode* makeAllocNode(int op,astnode *l){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	if(l->type==TLookup(strdup("INT")) || l->type==TLookup(strdup("BOOL"))){
		printf("%d:: NOT A USER DEFINED TYPE\n",line);exit(1);
	}
	temp->type = l->type;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2 = NULL;
	temp->ptr1 = NULL;
	temp->ptr3 = NULL;
	temp->gsym=NULL;
	temp->lsym=NULL;
	return temp;
}

astnode* makeFreeNode(int op, astnode *l){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	if(l->type==TLookup(strdup("INT")) || l->type==TLookup(strdup("BOOL"))){
		printf("%d:: NOT A POINTER\n",line);exit(1);
	}
	temp->type = NULL;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2 = l;
	temp->ptr1 = NULL;
	temp->ptr3 = NULL;
	temp->gsym=NULL;
	temp->lsym=NULL;
	return temp;
}

typetable* findFinalType(typetable* type, astnode *ftroot){
	fieldlist* temp=type->fields;
	while(temp!=NULL){
		if(strcmp(temp->name,ftroot->name)==0)
			break;
		temp=temp->next;
	}
	if(temp==NULL){
		printf("%d:: %s FIELD NOT FOUN IN TYPE %s\n",line,ftroot->name,type->name );exit(1);
	}
	ftroot->value=temp->fieldIndex-1;
	ftroot->type=temp->type;
	if(ftroot->ptr1==NULL) return temp->type;
	return findFinalType(temp->type,ftroot->ptr1);
}

astnode* makeFieldNode(astnode *ftroot){
	astnode *temp;
	if(ftroot->gsym==NULL && ftroot->lsym==NULL){
		printf("%d::%s VARIABLE NOT DECLARED\n",line,ftroot->name );exit(1);
	}
	ftroot->type=findFinalType(ftroot->type,ftroot->ptr1);
	return ftroot;
}

astnode* makeBreakNode(int op){
	astnode *temp;
	temp = (astnode*)malloc(sizeof(astnode));
	temp->type = NULL;
	temp->value = -1;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2 = NULL;
	temp->ptr3 = NULL;
	temp->ptr1 = NULL;
	temp->gsym = NULL;
	temp->lsym =  NULL;
	return temp;
}

astnode* makePairNode(astnode* l, astnode*r){
	astnode *temp= (astnode*)malloc(sizeof(astnode));
	temp->type = TLookup(strdup("PAIR"));
	temp->value = -1;
	temp->nodetype = PAIRNODE;
	temp->name = NULL;
	temp->ptr2 = l;
	temp->ptr3 = r;
	temp->ptr1 = NULL;
	temp->gsym = NULL;
	temp->lsym = NULL;
	return temp;
}

astnode* makeFSTNode(int op,astnode *l){
	astnode *temp= (astnode*)malloc(sizeof(astnode));
	if(l->type!=TLookup(strdup("PAIR"))){
		printf("INVALID TYPE FOR FST\n");exit(1);
	}
	temp->type = TLookup(strdup("INT"));
	temp->value = -1;
	temp->nodetype = op;
	temp->name = NULL;
	temp->ptr2 = l;
	temp->ptr3 = NULL;
	temp->ptr1 = NULL;
	temp->gsym = NULL;
	temp->lsym = NULL;
	return temp;
}
/*int evalute(astnode *root){
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
		if(root->ptr2!=NULL)
			root->value=evalute(root->ptr2);
		return *(root->gsym->binding+root->value);
	}else if(root->nodetype == READ){
		if( root->ptr2->gsym==NULL){
			printf("%d :: %s VARIABLE NOT DECLARED\n",line,root->ptr2->name);
			exit(1);
		}
		if(root->ptr2->ptr2!=NULL)
			root->ptr2->value = evalute(root->ptr2->ptr2);
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
			if(root->ptr2->ptr2!=NULL)
				root->ptr2->value = evalute(root->ptr2->ptr2);
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
}*/