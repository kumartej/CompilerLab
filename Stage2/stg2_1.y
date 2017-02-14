/* STAGE 2 IMPLEMENTATION --- YACC*/
%{
	
	#include <stdio.h>
	int *var[26];
%}

%union{
	int integer;
	char character;
}

%token <character> PLUS MINUS MUL ID ASSIGN
%token <integer> NUM

%token READ WRITE ASGN NEWLINE

%type <integer> expr

%left PLUS MINUS
%left MUL

%%

Program : slist NEWLINE {exit(1);}
     ;

slist : slist stmt
     | stmt
     ;

expr : expr PLUS expr {$$=$1+$3;}
	| expr MINUS expr {$$=$1-$3;}
	| expr MUL expr {$$=$1*$3;}
	| ID {
			if(var[$1-'a']==NULL) 
				printf("Unassigned Variable"); 
			else 
				$$ = *var[$1-'a'];
		 }
	| NUM {$$=$1;}
	;

stmt: ID ASGN expr ';' { 
							if(var[$1-'a']==NULL){
								var[$1-'a']=malloc(sizeof(int));
							} 
							*var[$1-'a'] = $3; 
						}
	| READ '(' ID ')' ';' { 
								if(var[$3-'a']==NULL){ 
									var[$3-'a']=(int*)malloc(sizeof(int));
								} 
								scanf("%d",var[$3-'a']); 
							}
	| WRITE '(' ID ')' ';' { 
								if(var[$3-'a']==NULL){
									printf("ID NOT ASSIGNED\n");
								} else { 
									printf("%d",*var[$3-'a']);
								}
							}
	;

%%

void yyerror(char const *s) { 
    printf("yyerror  %s\n",s); 
    return ;
}

int main(){
    yyparse();
    return 1;
}