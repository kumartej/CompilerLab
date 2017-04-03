void TypeTableCreate(){
	typetable *temp=NULL;
	temp=(typetable*)malloc(sizeof(typetable));
	temp->name=strdup("INT");
	temp->size=1;
	temp->fields=NULL;
	typeroot=temp;
	temp=(typetable*)malloc(sizeof(typetable));
	temp->name=strdup("BOOL");
	temp->size=1;
	temp->fields=NULL;
	temp->next=NULL;
	typeroot->next=temp;
	return;
}

fieldlist* createfield(char* Typename,char* typeId){
	fieldlist* temp;
	typetable *t2;
	temp=(fieldlist*)malloc(sizeof(fieldlist));
	temp->name=typeId;
	temp->next=NULL;
	temp->fieldIndex=1;
	t2=TLookup(Typename);
	if(t2==NULL){
		printf("%d FIELD DATATYPE NOT PRESENT\n",line );
		exit(1);
	}
	temp->type=t2;
	return temp;
}

void TInstallId(char *name){
	if(TLookup(name)!=NULL){
		printf("%d::%s TYPENAME ALREADY EXISTS\n",line,name);exit(1);
	}
	typetable* temp=NULL;
	temp=(typetable*)malloc(sizeof(typetable));
	temp->name=name;
	temp->fields=NULL;
	temp->next=typeroot;
	typeroot=temp;
	return;
}

struct Typetable* TLookup(char *name){
	typetable* temp=typeroot;
	while(temp!=NULL){
		if(strcmp(temp->name,name)==0)
			return temp;
		temp=temp->next;
	}
	return NULL;
}

struct Typetable* TInstall(char *name,int size, struct Fieldlist *fields){
	typetable* temp=TLookup(name);
	if(temp==NULL){
		printf("SOMETHING WENT WRONG\n");
		exit(1);
	}
	if(size>8){
		printf("%d::FIELDS SIZE EXCEEDED\n",line );exit(1);
	}
	fieldlist *t2=fields;
	while(t2!=NULL){
		if(strcmp(t2->name,name)==0){
			printf("TYPENAME REDECLARED\n");exit(1);
		}
		t2=t2->next;
	}
	temp->size=size;
	temp->fields=fields;
	return typeroot;
}

int GetSize (typetable * type){
	return type->size;
}

struct Fieldlist* FLookup(typetable *type, char *name){
	fieldlist* temp=type->fields;
	while(temp!=NULL){
		if(strcmp(temp->name,name)==0)
			return temp;
		temp=temp->next;
	}
	return NULL;
}

int findSize(fieldlist *fld){
	return fld->fieldIndex;
}

fieldlist* insertField(fieldlist *fld1, fieldlist *fld2){
	fieldlist* temp=fld1;
	while(temp!=NULL){
		if(strcmp(temp->name,fld2->name)==0){
			printf("TYPENAME REDECLARED IN FIELD\n");exit(1);
		}
		temp=temp->next;
	}
	fld2->next=fld1;
	fld2->fieldIndex=fld1->fieldIndex+1;
	return fld2;
}

void TypePrint(){
	typetable *temp=typeroot;
	while(temp!=NULL){
		printf("%s\n",temp->name );
		temp=temp->next;
	}
	return;
}