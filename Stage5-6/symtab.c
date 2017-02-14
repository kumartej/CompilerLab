gsymbol* GListInstall(astnode * list, int type){
	astnode *tmp = list;
	while(tmp!=NULL){
		GInstall(tmp->name,type,tmp->value);
		tmp=tmp->ptr1;
	}
	return NULL;
}

gsymbol* GInstall (char *name, int type, int size){
	gsymbol *tmp;
	tmp = GLookup(name);
	if(tmp!=NULL){
		printf("%s is declared again",name);
		exit(1);
	}
	tmp = (gsymbol*)malloc(sizeof(gsymbol));
	tmp->name = name;
	tmp->size = size;
	tmp->type = type;
	tmp->binding = (int*)malloc(size*sizeof(int));
	tmp->next = root;
	root = tmp;
	return root;
}

gsymbol* GLookup(char *name){
	gsymbol *tmp = root;
	int a=1;
	while(tmp!=NULL){
		if(strcmp(tmp->name,name)==0)
			return tmp;
		tmp=tmp->next;
	}
	return NULL;
}

void GPrint(){
	gsymbol *tmp = root;
	while(tmp!=NULL){
		printf("%s\n",tmp->name);
		tmp=tmp->next;
	}
	return;
}