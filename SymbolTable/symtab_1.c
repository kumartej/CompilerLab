struct Gsymbol* GInstall(char *name,int type, int size){
	gsymbol *in;
	int bnd=0;
	in=(gsymbol*)malloc(sizeof(gsymbol));
	if(root==NULL){
		root = in;
	}else{
		gsymbol *tmp = root;
		while(tmp->next!=NULL){
			tmp=tmp->next;
			bnd = bnd+1;
		}
		tmp->next=in;
	}
	in->name = name;
	in->type = type;
	in->size = size;
	in->binding = bnd+1;
	in->pt = (int*)malloc(size*sizeof(int));
	in->next = NULL;
	return root;
}

struct Gsymbol* GLookup(char *name){
	gsymbol *tmp = root;
	while(tmp->next!=NULL){
		if(strcmp(tmp->name,name)==0)
			return tmp;
		tmp = tmp->next;
	}
}