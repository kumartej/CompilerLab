int checkIdDecl(astnode *root){
	if(root->gsym == NULL){
		printf("%d :: VARIABLE NOT DECLARED\n",line);
		exit(1);
	}
}

int checkIdExpr(astnode *root){
	if(root->ptr1->type!=INT){
		printf("%d :: INVALID ACCESS\n",line);
		exit(1);
	}
}