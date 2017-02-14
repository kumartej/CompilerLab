/* BASIC CALCULATOR */

%{
	
	#include <stdio.h>
	//typedef char YYSTYPE;

%}

%token VAR NEWLINE
%left '+' '-'
%left '*' '/'

%%

start : expr NEWLINE {printf("%d\nCOMPLETE\n",$$);exit(1);}

expr : expr '+' expr {$$=$1+$3;}
	| expr '-' expr {$$=$1-$3;}
	| expr '*' expr {$$=$1*$3;}
	| expr '/' expr {$$=$1/$3;}
	| '(' expr ')'
	| VAR {$$=$1;}
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