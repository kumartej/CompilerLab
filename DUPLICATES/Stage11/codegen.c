int getReg(){
	ureg+=1;
	if(ureg>19){
		printf("EXCEEDED NUMBER OF REGISTERS\n");
		exit(1);
	}
	return ureg;
}

void freeReg(){
	ureg-=1;
	if(ureg<-1){
		printf("INVALID DECREMENT OF REGISTERS\n");
		exit(1);
	}
	return;
}

int getLabel(){
	uLab+=1;
	return uLab;
}

int codegenrate(astnode *root, astnode *idnode){
	s=intstack();
	if(start==0){
		fp=fopen("./labelTranslation/out1.xsm","w");
		fprintf(fp, "0 , 2056\n0 , 0\n0 , 0\n0 , 0\n");
		fprintf(fp, "MOV SP,%d\n",sAlloc-1);
		fprintf(fp, "MOV BP,%d\n",sAlloc);
		codegenIntial();
		fprintf(fp, "JMP MAIN\n");
		start=1;
	}
	if(idnode==NULL){
		fprintf(fp, "MAIN:\n");
		fprintf(fp, "BRKP\n");
		fprintf(fp, "PUSH BP\n");
		fprintf(fp, "MOV BP,SP\n");
		fprintf(fp, "ADD SP,%d\n",root->value);
		codegeneval(root->ptr1);
		fprintf(fp, "INT 10\n");
	}else{
		fprintf(fp, "F%d:\n",idnode->gsym->binding);
		fprintf(fp, "PUSH BP\n");
		fprintf(fp, "MOV BP,SP\n");
		fprintf(fp, "ADD SP,%d\n",root->value);
		codegeneval(root);
	}
	return 1;
}

int codegenWrite(int reg){
	int treg=0;
	while(treg<=ureg){
		fprintf(fp, "PUSH R%d\n",treg);
		treg+=1;
	}
	treg=getReg();
	fprintf(fp, "MOV R%d,2\n", treg);
	fprintf(fp, "PUSH R%d\n",treg );
	fprintf(fp, "MOV R%d,-2\n", treg);
	fprintf(fp, "PUSH R%d\n",treg);
	fprintf(fp, "MOV R%d,SP\n",treg );
	fprintf(fp, "SUB R%d,2\n",treg );
	fprintf(fp, "PUSH R%d\n",treg);
	fprintf(fp, "PUSH R%d\n",treg);
	fprintf(fp, "PUSH R%d\n",treg);
	fprintf(fp, "INT 7\n");
	fprintf(fp, "SUB SP,5\n",reg);
	treg=ureg-1;
	while(treg>=0){
		fprintf(fp, "POP R%d\n",treg);
		treg=treg-1;
	}
	freeReg();
	return 1;
}

int codegenRead(int reg){
	int treg = 0;
	for(treg=0;treg<=ureg;treg++)
		fprintf(fp, "PUSH R%d\n",treg);
	treg = getReg();
	fprintf(fp, "MOV R%d,1\n",treg);
	fprintf(fp, "PUSH R%d\n",treg);
	fprintf(fp, "MOV R%d,-1\n",treg);
	fprintf(fp, "PUSH R%d\n",treg);
	fprintf(fp, "MOV R%d,SP\n",treg);
	fprintf(fp, "SUB R%d,2\n",treg);
	fprintf(fp, "PUSH R%d\n",reg);
	fprintf(fp, "PUSH R%d\n",treg);
	fprintf(fp, "PUSH R%d\n",treg);
	fprintf(fp, "INT 6\n");
	fprintf(fp, "SUB SP,5\n",reg);
	for(treg=ureg-1;treg>=0;treg--)
		fprintf(fp, "POP R%d\n",treg);
	freeReg();
	return 1;
}

int codegenIf(astnode *root){
	int reg1;
	int lab1,lab2;
	reg1=codegeneval(root->ptr1);
	lab1=getLabel();
	fprintf(fp, "JZ R%d,L%d\n",reg1,lab1);
	freeReg();
	reg1=codegeneval(root->ptr2);
	lab2=getLabel();
	fprintf(fp, "JMP L%d\n",lab2);
	fprintf(fp, "L%d:\n",lab1);
	reg1=codegeneval(root->ptr3);
	fprintf(fp, "L%d:\n",lab2);
	return -1;
}

int codegenIfThen(astnode* root){
	int reg1,lab1;
	reg1=codegeneval(root->ptr1);
	lab1=getLabel();
	fprintf(fp, "JZ R%d,L%d\n",reg1,lab1);
	freeReg();
	reg1=codegeneval(root->ptr2);
	fprintf(fp, "L%d:\n",lab1);
	return -1;
}

int codegenWhile(astnode *root){
	int reg1;
	int lab1,lab2;
	lab1=getLabel();
	lab2=getLabel();
	node *t;
	t=createnode(breakLabel);
	push(s,t);
	t=createnode(continueLabel);
	push(s,t);
	continueLabel=lab1;
	breakLabel=lab2;
	fprintf(fp, "L%d:\n",lab1);
	reg1 = codegeneval(root->ptr2);
	fprintf(fp, "JZ R%d,L%d\n",reg1,lab2);
	freeReg();
	reg1=codegeneval(root->ptr3);
	fprintf(fp, "JMP L%d\n",lab1);
	fprintf(fp, "L%d:\n",lab2);
	continueLabel=pop(s)->data;
	breakLabel=pop(s)->data;
	return -1;
}

int codegenField(int reg1, astnode *ftroot){
	if(ftroot==NULL) return;
	fprintf(fp, "ADD R%d,%d\n",reg1, ftroot->value);
	fprintf(fp, "MOV R%d,[R%d]\n",reg1,reg1 );
	codegenField(reg1,ftroot->ptr1);
	return reg1;
}

int codegenAddField(int reg1,astnode *ftroot){
	fprintf(fp, "ADD R%d,%d\n",reg1,ftroot->value );
	if(ftroot->ptr1!=NULL){
		fprintf(fp, "MOV R%d,[R%d]\n",reg1,reg1 );
		codegenAddField(reg1,ftroot->ptr1);
	}
	return reg1;
}

int codegenId(astnode *root){
	int reg1,reg2,reg3;
	reg1 = getReg();
	if(root->ptr2!=NULL){
		reg2 = codegeneval(root->ptr2);
		if(root->gsym!=NULL){
			fprintf(fp, "ADD R%d,%d\n",reg2,root->gsym->binding);
			fprintf(fp, "MOV R%d,[R%d]\n",reg1,reg2);
		}else if(root->lsym!=NULL){
			printf("%d::NO ARRAYS IN FUNCTIONS\n",line );exit(1);
		}
		freeReg();
	}else{
		if(root->gsym!=NULL){
			fprintf(fp, "MOV R%d,[%d]\n",reg1,root->gsym->binding);
		}else if(root->lsym!=NULL){
			reg2=getReg();
			fprintf(fp, "MOV R%d,BP\n",reg2);
			fprintf(fp, "SUB R%d,%d\n",reg2,-1*root->lsym->binding);
			fprintf(fp, "MOV R%d,[R%d]\n",reg1,reg2);
			freeReg();
		}
		if(root->ptr1!=NULL){
				codegenField(reg1, root->ptr1);
		}
	}
	return reg1;
}

int codegenFunc(astnode *root){
	int treg = 0;
	for(treg=0;treg<=ureg;treg++)
		fprintf(fp, "PUSH R%d\n",treg);
	int reg1,narg=0;
	astnode *tmp=root->ptr3;

	while(tmp!=NULL){
		reg1=codegeneval(tmp->ptr2);
		fprintf(fp, "PUSH R%d\n",reg1);
		narg++;
		freeReg();
		tmp=tmp->ptr1;
	}
	reg1=getReg();
	fprintf(fp, "PUSH R%d\n",reg1);
	fprintf(fp, "CALL F%d\n",root->ptr2->gsym->binding);
	fprintf(fp, "POP R%d\n",reg1);
	fprintf(fp, "SUB SP,%d\n",narg);
	for(treg=ureg-1;treg>=0;treg--)
		fprintf(fp, "POP R%d\n",treg);
	return reg1;
}

int codegenAlloc(astnode *root){
	int treg=0;
	for(treg=0;treg<=ureg;treg++)
		fprintf(fp, "PUSH R%d\n",treg);
	int reg1=getReg();
	fprintf(fp, "MOV R%d,-2\n",reg1);
	fprintf(fp, "PUSH R%d\n",reg1);
	fprintf(fp, "MOV R%d,8\n",reg1);
	fprintf(fp, "PUSH R%d\n",reg1);
	fprintf(fp, "ADD SP,3\n");
	fprintf(fp, "CALL 0\n" );
	fprintf(fp, "POP R%d\n",reg1 );
	fprintf(fp, "SUB SP,4\n" );
	for(treg=ureg-1;treg>=0;treg--)
		fprintf(fp, "POP R%d\n",treg);
	return reg1;
}

int codegenFree(astnode *root){
	int treg=0;
	for(treg=0;treg<=ureg;treg++)
		fprintf(fp, "PUSH R%d\n",treg);
	int reg1=codegenId(root),reg2=getReg();
	fprintf(fp, "MOV R%d,-3\n",reg2);
	fprintf(fp, "PUSH R%d\n",reg2);
	fprintf(fp, "PUSH R%d\n",reg1);
	fprintf(fp, "ADD SP,3\n");
	fprintf(fp, "CALL 0\n" );
	fprintf(fp, "SUB SP,5\n" );
	freeReg();freeReg();
	for(treg=ureg-1;treg>=0;treg--)
		fprintf(fp, "POP R%d\n",treg);
	return -1;
}

int codegenIntial(){
	int treg=0;
	for(treg=0;treg<=ureg;treg++)
		fprintf(fp, "PUSH R%d\n",treg);
	fprintf(fp, "MOV R0,-1\n" );
	fprintf(fp, "MOV [BP],R0\n" );
	fprintf(fp, "ADD SP,5\n" );
	fprintf(fp, "CALL 0\n" );
	fprintf(fp, "SUB SP,5\n" );
	for(treg=ureg-1;treg>=0;treg--)
		fprintf(fp, "POP R%d\n",treg);
	return -1;	
}

int codegeneval(astnode *root){
	// printf("%d %d\n",root->nodetype,RET);
	int reg1,reg2;
	gsymbol *glsym;
	if(root->nodetype == NUM || root->nodetype == BOOLCONS){
		reg1 = getReg();
		fprintf(fp, "MOV R%d,%d\n",reg1,root->value );
		return reg1;
	}else if(root->nodetype == ID){		
		return codegenId(root);
	}else if(root->nodetype==PLUS){
		reg1 = codegeneval(root->ptr2);
		reg2 = codegeneval(root->ptr3);
		fprintf(fp, "ADD R%d,R%d\n",reg1,reg2 );
		freeReg();
		return reg1;		
	}else if(root->nodetype==MINUS){
		reg1 = codegeneval(root->ptr2);
		reg2 = codegeneval(root->ptr3);
		fprintf(fp, "SUB R%d,R%d\n",reg1,reg2 );
		freeReg();
		return reg1;
	}else if(root->nodetype==MUL){
		reg1 = codegeneval(root->ptr2);
		reg2 = codegeneval(root->ptr3);
		fprintf(fp, "MUL R%d,R%d\n",reg1,reg2 );
		freeReg();
		return reg1;
	}else if(root->nodetype==DIV){
		reg1 = codegeneval(root->ptr2);
		reg2 = codegeneval(root->ptr3);
		fprintf(fp, "DIV R%d,R%d\n",reg1,reg2 );
		freeReg();
		return reg1;
	}else if(root->nodetype==MODULO){
		reg1 = codegeneval(root->ptr2);
		reg2 = codegeneval(root->ptr3);
		fprintf(fp, "MOD R%d,R%d\n",reg1,reg2 );
		freeReg();
		return reg1;
	}else if(root->nodetype == EQ){
		reg1 = codegeneval(root->ptr2);
		reg2 = codegeneval(root->ptr3);
		fprintf(fp, "EQ R%d,R%d\n",reg1,reg2);
		freeReg();
		return reg1;
	}else if(root->nodetype == NE){
		reg1 = codegeneval(root->ptr2);
		reg2 = codegeneval(root->ptr3);
		fprintf(fp, "NE R%d,R%d\n",reg1,reg2);
		freeReg();
		return reg1;
	}else if(root->nodetype == LE){
		reg1 = codegeneval(root->ptr2);
		reg2 = codegeneval(root->ptr3);
		fprintf(fp, "LE R%d,R%d\n",reg1,reg2);
		freeReg();
		return reg1;
	}else if(root->nodetype == GE){
		reg1 = codegeneval(root->ptr2);
		reg2 = codegeneval(root->ptr3);
		fprintf(fp, "GE R%d,R%d\n",reg1,reg2);
		freeReg();
		return reg1;
	}else if(root->nodetype == LT){
		reg1 = codegeneval(root->ptr2);
		reg2 = codegeneval(root->ptr3);
		fprintf(fp, "LT R%d,R%d\n",reg1,reg2);
		freeReg();
		return reg1;
	}else if(root->nodetype == GT){
		reg1 = codegeneval(root->ptr2);
		reg2 = codegeneval(root->ptr3);
		fprintf(fp, "GT R%d,R%d\n",reg1,reg2);
		freeReg();
		return reg1;
	}else if(root->nodetype == WRITE){
		reg1 = codegeneval(root->ptr2);
		codegenWrite(reg1);
		freeReg();
		return -1;
	}else if (root->nodetype == READ){
		if( root->ptr2->gsym==NULL && root->ptr2->lsym==NULL){
			printf("%d :: %s VARIABLE NOT DECLARED\n",line,root->ptr2->name);
			exit(1);
		}
		if(root->ptr2->lsym!=NULL){
			if(root->ptr2->ptr2!=NULL){
				printf("NOARRAYS SHOULD BE DECLARED AS LOCAL VARIABLES\n");
				exit(1);
			}else{
				reg1=getReg();
				fprintf(fp, "MOV R%d,BP\n",reg1);
				fprintf(fp, "SUB R%d,%d\n",reg1,-1*root->ptr2->lsym->binding);
			}
		}else if(root->ptr2->gsym!=NULL){
			if(root->ptr2->ptr2!=NULL)
				reg1 = codegeneval(root->ptr2->ptr2);
			else{
				reg1=getReg();
				fprintf(fp, "MOV R%d,0\n",reg1);
			}
			fprintf(fp, "ADD R%d,%d\n",reg1,root->ptr2->gsym->binding);
		}
		if(root->ptr2->ptr1!=NULL){
			fprintf(fp, "MOV R%d,[R%d]\n",reg1,reg1 );
			codegenAddField(reg1,root->ptr2->ptr1);
		}
		codegenRead(reg1);
		freeReg();
		return -1;
	}else if(root->nodetype == ASGN){
		if(root->ptr2->nodetype == ID){
			reg1 = codegeneval(root->ptr3);
			if(root->ptr2->gsym==NULL && root->ptr2->lsym==NULL){
				printf("%d :: %s VARIABLE NOT DECLARED\n",line,root->ptr2->name);
				exit(1);
			}
			if(root->ptr2->lsym!=NULL){
				if(root->ptr2->ptr2!=NULL){
					printf("NOARRAYS SHOULD BE DECLARED AS LOCAL VARIABLES\n");
					exit(1);
				}else{
					reg2=getReg();
					fprintf(fp, "MOV R%d,BP\n",reg2);
					fprintf(fp, "SUB R%d,%d\n",reg2,-1*root->ptr2->lsym->binding);
				}
			}else if(root->ptr2->gsym!=NULL){
				if(root->ptr2->ptr2!=NULL)
					reg2 = codegeneval(root->ptr2->ptr2);
				else{
					reg2 = getReg();
					fprintf(fp, "MOV R%d,0\n",reg2);
				}
				fprintf(fp, "ADD R%d,%d\n",reg2,root->ptr2->gsym->binding);
			}
			if(root->ptr2->ptr1!=NULL){
				fprintf(fp, "MOV R%d,[R%d]\n",reg2,reg2 );
				codegenAddField(reg2,root->ptr2->ptr1);
			}
			fprintf(fp, "MOV [R%d],R%d\n",reg2,reg1);
			freeReg();
			freeReg();
			return -1;
		}else{
			printf("%d :: INVALID ASSIGNMENT\n",line);
			exit(1);
		}
	}else if(root->nodetype==IF){
		reg1 = codegenIf(root);
		return -1;
	}else if(root->nodetype==IFTHEN){
		reg1 = codegenIfThen(root);
		return -1;
	}else if(root->nodetype == WHILE){
		reg1 = codegenWhile(root);
		return -1;
	}else if(root->nodetype == FUNC){
		return codegenFunc(root);
	}else if(root->nodetype == RET){
		codegeneval(root->ptr1);
		reg1=codegeneval(root->ptr2);
		reg2=getReg();
		fprintf(fp, "MOV R%d,BP\n",reg2);
		fprintf(fp, "SUB R%d,2\n",reg2);
		fprintf(fp, "MOV [R%d],R%d\n",reg2,reg1);
		fprintf(fp, "SUB SP,%d\n",root->value);
		fprintf(fp, "POP BP\n");
		fprintf(fp, "RET\n");
		freeReg();
		freeReg();
		return -1;
	}else if(root->nodetype == AND){
		reg1=codegeneval(root->ptr2);
		reg2=codegeneval(root->ptr3);
		fprintf(fp, "ADD R%d,R%d\n",reg1,reg2 );
		fprintf(fp, "MOV R%d,2\n",reg2);
		fprintf(fp, "EQ R%d,R%d\n",reg1,reg2);
		freeReg();
		return reg1;
	}else if(root->nodetype == OR){
		reg1=codegeneval(root->ptr2);
		reg2=codegeneval(root->ptr3);
		fprintf(fp, "ADD R%d,R%d\n",reg1,reg2 );
		fprintf(fp, "MOV R%d,1\n",reg2);
		fprintf(fp, "GE R%d,R%d\n",reg1,reg2);
		freeReg();
		return reg1;
	}else if(root->nodetype == NOT){
		reg1=codegeneval(root->ptr2);
		fprintf(fp, "LT R%d,1\n",reg1);
		return reg1;
	}else if(root->nodetype == ALLOC){
		reg1=codegenAlloc(root);
		return reg1;
	}else if(root->nodetype == FREE){
		reg1=codegenFree(root->ptr2);
		return -1;
	}else if(root->nodetype == NULLV){
		root->nodetype=NUM;
		return codegeneval(root);
	}else if(root->nodetype == BREAK){
		if(breakLabel==-1){
			printf("INVALID BREAK STATEMENT\n");exit(1);
		}
		fprintf(fp, "JMP L%d\n",breakLabel );
		return -1;
	}else if(root->nodetype == CONTINUE){
		if(breakLabel==-1){
			printf("INVALID CONTINUE STATEMENT\n");exit(1);
		}
		fprintf(fp, "JMP L%d\n",continueLabel );
		return -1;
	}else{
		codegeneval(root->ptr2);
		codegeneval(root->ptr3);
		return -1;
	}
}