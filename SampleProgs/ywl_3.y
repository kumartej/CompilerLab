/*INFIX TO PREFIX */

%{
	
	#include <stdio.h>
	//typedef char YYSTYPE;

%}

%token VAR NEWLINE
%left '+' '-'
%left '*' '/'

%%

start : expr NEWLINE {printf("%s\nCOMPLETE\n",$1);exit(1);}

expr: expr '+' expr {$$ = (char*)malloc(100*sizeof(char));$2=(char*)malloc(100*sizeof(char));strcpy($2,"+"); strcpy($$,strcat($2,strcat($1,$3)));}
	| expr '-' expr {$$ = (char*)malloc(100*sizeof(char));$2=(char*)malloc(100*sizeof(char));strcpy($2,"-"); strcpy($$,strcat($2,strcat($1,$3)));}
	| expr '*' expr {$$ = (char*)malloc(100*sizeof(char));$2=(char*)malloc(100*sizeof(char));strcpy($2,"*"); strcpy($$,strcat($2,strcat($1,$3)));}
	| expr '/' expr {$$ = (char*)malloc(100*sizeof(char));$2=(char*)malloc(100*sizeof(char));strcpy($2,"/"); strcpy($$,strcat($2,strcat($1,$3)));}
	| '(' expr ')' {$$ = (char*)malloc(100*sizeof(char)); strcpy($$,$2);}
	| VAR {$$ = (char*)malloc(100*sizeof(char));strcpy($$,$1);}
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