int checkIdDecl(astnode *root){
	if(root->gsym == NULL && root->lsym == NULL){
		printf("%d :: VARIABLE NOT DECLARED\n",line);
		exit(1);
	}
}

int checkIdExpr(astnode *root){
	if(root->ptr2->type!=TLookup(strdup("INT"))){
		printf("%d :: INVALID ACCESS\n",line);
		exit(1);
	}
}

int checkRetType(astnode *root,typetable* type,astnode *l){
	if(root->ptr2->type!=type){
		printf( "%d :: RETURN TYPE DOESNOT MATCH\n",line);
		exit(1);
	}
	if(l->gsym==NULL){
		printf("FUNCTION UNDECLARED\n");exit(1);
	}
	l->gsym->size-=1;
	if(l->gsym->size<-1){
		printf("%d :: %s FUNCTION DECLARED MULTIPLE TIMES\n",line,l->name);
		exit(1);
	}
	return 1;
}

int checkBreak(int breakstmt){
	if(breakstmt==1){
		printf("INVALID BREAK STATEMENT\n");
		exit(1);
	}
	return 1;
}

int checkNullId(astnode *root){
	if(root->type==TLookup(strdup("INT")) || root->type==TLookup(strdup("BOOL"))){
		printf("%d:: NULL CANNOT BE ASSIGNED \n",line);
		exit(1);
	}
}