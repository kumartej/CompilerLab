%{
	
	#include <stdio.h>
	//typedef char YYSTYPE;

%}

%token VAR NEWLINE
%left '+' '-'
%left '*' '/'

%%

start : expr NEWLINE {printf("\nCOMPLETE\n");exit(1);}

expr : expr '+' expr {printf("+");}
	| expr '-' expr {printf("-");}
	| expr '*' expr {printf("*");}
	| expr '/' expr {printf("/");}
	| '(' expr ')' 
	| VAR {printf("%c",$1);}
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