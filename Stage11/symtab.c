gsymbol* GListInstall(astnode* list, typetable* type){
	astnode *tmp = list;
	if(type==NULL){
		printf("%d IS NOT A TYPE\n",line );
		exit(1);
	}
	while(tmp!=NULL){
		GInstall(tmp->name,type,tmp->value,tmp->ptr2);
		tmp=tmp->ptr1;
	}
	return NULL;
}

gsymbol* GInstall (char *name, typetable* type, int size,astnode * ptr2){
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
	tmp->binding = sAlloc;
	tmp->next = root;
	tmp->arglist=NULL;
	root = tmp;
	sAlloc+=size;
	if(ptr2!=NULL){
		tmp->arglist=ArgListInstall(ptr2);
		lastfunc+=1;
		tmp->binding=lastfunc;
	}
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
		printf("%s :: %d\n",tmp->name,tmp->binding);
		tmp=tmp->next;
	}
	return;
}

ArgStruct* ArgListInstall(astnode *list){
	ArgStruct *tmp=NULL,*tmp2,*tmp3;
	astnode *iter=list;
	while(iter!=NULL){
		tmp2=(ArgStruct*)malloc(sizeof(ArgStruct));
		tmp2->name=iter->name;
		tmp2->type=iter->type;
		tmp2->next=tmp;
		tmp=tmp2;
		iter=iter->ptr1;
	}
	return tmp;
}

lsymbol* LListInstall(astnode *list, typetable* type){
	// printf("SUCC");
	if(type==NULL){printf("%d::TYPE NOT FOUND\n",line );exit(1);}
	astnode *tmp=list;
	while(tmp!=NULL){
		LInstall(tmp->name,type,tmp->value);
		tmp=tmp->ptr1;
	}
	return NULL;
}

lsymbol* LInstall(char* name, typetable* type,int size){
	lsymbol* tmp;
	tmp=LLookup(name);
	if(tmp!=NULL){
		printf("%d :: %s %s:: VARIALBLE REDECLARED\n",line,name,tmp->name);
		exit(1);
	}
	if(type==NULL){
		printf("%d TYPE NOT FOUND\n", line);
		exit(1);
	}
	tmp=(lsymbol*)malloc(sizeof(lsymbol));
	tmp->name=name;
	tmp->type=type;
	tmp->binding=lAlloc+1;
	lAlloc+=size;
	tmp->next=lroot;
	lroot=tmp;
	return lroot;
}

lsymbol* LInstallArg(astnode *list){
	lsymbol *tmp;
	astnode *iter=list;
	while(iter!=NULL){
		tmp=LLookup(iter->name);
		if(tmp!=NULL){
			printf("%d :: %s :: VARIALBLE REDECLARED\n",line,iter->name);
			exit(1);
		}
		if(iter->type==NULL){printf("%d::TYPE NOT FOUND\n",line );exit(1);}
		tmp=(lsymbol*)malloc(sizeof(lsymbol));
		tmp->name=iter->name;
		tmp->type=iter->type;
		tmp->binding=larg-1;
		larg-=1;
		tmp->next=lroot;
		lroot=tmp;
		iter=iter->ptr1;
	}
	return lroot;
}

void LPrint(){
	lsymbol *tmp=lroot;
	if(tmp==NULL)
		printf("NOSYMOLSINLOCALTABLE\n");
	while(tmp!=NULL){
		printf("%s %d\n",tmp->name,tmp->binding);
		tmp=tmp->next;
	}
	return ;
}

lsymbol* LLookup(char *name){
	lsymbol *tmp=lroot;
	while(tmp!=NULL){
		if(strcmp(tmp->name,name)==0)
			return tmp;
		tmp=tmp->next;
	}
	return NULL;
}

void clearLsymbol(){
	lroot=NULL;
	argroot=NULL;
	lAlloc=0;
	larg=-2;
	return;
}

void LargAssign(){
	lsymbol *tmp=lroot;
	int tmpsym=-3;
	while(tmp!=NULL){
		if(tmp->binding<0)
		tmp->binding=tmpsym--;
		tmp=tmp->next;
	}
	return;
}

int countLsym(){
	int lsym=0;
	lsymbol *tmp=lroot;
	while(tmp!=NULL){
		if(tmp->binding>0)
			lsym++;
		tmp=tmp->next;
	}
	return lsym;
}

int checkFunctionsDecl(){
	gsymbol *tmp=root;
	while(tmp!=NULL){
		if(tmp->size==0){
			printf("%s FUNCTION NOT DEFINED\n",tmp->name );
			exit(1);
		}
		tmp=tmp->next;
	}
	return 1;
}