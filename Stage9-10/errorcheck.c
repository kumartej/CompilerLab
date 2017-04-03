int checkIdDecl(astnode *root){
	if(root->gsym == NULL && root->lsym == NULL){
		printf("%d :: VARIABLE NOT DECLARED\n",line);
		exit(1);
	}
}

int checkIdExpr(astnode *root){
	if(root->ptr2->type!=INT){
		printf("%d :: INVALID ACCESS\n",line);
		exit(1);
	}
}

int checkRetType(astnode *root,int type,astnode *l){
	if(root->ptr2->type!=type){
		printf( "%d :: RETURN TYPE DOESNOT MATCH\n",line);
		exit(1);
	}
	l->gsym->size-=1;
	if(l->gsym->size<-1){
		printf("%d :: %s FUNCTION DECLARED MULTIPLE TIMES\n",line,l->name);
		exit(1);
	}
}