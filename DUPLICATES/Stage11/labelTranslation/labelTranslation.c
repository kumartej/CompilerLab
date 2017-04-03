
void insertLab(char *str){
	ltable *tmp;
	tmp = (ltable*)malloc(sizeof(ltable));
	int len=strlen(str);
	str[len-2]='\0';
	tmp->str=str;
	tmp->addr=sAdd;
	tmp->next=NULL;
	if(lroot==NULL)
		lroot=tmp;
	else{
		tmp->next=lroot;
		lroot=tmp;
	}
	return;
}

ltable* searchLab(char *str){
	ltable *tmp;
	tmp=lroot;
	while(tmp!=NULL){
		if(strcmp(tmp->str,str)==0)
			return tmp;
		tmp=tmp->next;
	}
	return NULL;
}

void printLTable(){
	ltable *tmp;
	tmp=lroot;
	while(tmp!=NULL){
		printf("%s",tmp->str);
		tmp=tmp->next;
	}
	return;
}