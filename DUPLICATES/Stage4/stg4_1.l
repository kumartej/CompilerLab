%{
	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>

	int number;
%}

%%

[a-z] {yylval=makeIDNode(ID, yytext[0]);return ID;}
[0-9]+ { yylval = makeLeafNode(atoi(yytext)); return NUM;}
"read" {return READ;}
"write" {return WRITE;}
[ \t] {} 
[=] {return ASGN;}
[+] {return PLUS;}
[*] {return MUL;}
[-] {return MINUS;}
[()]	{return *yytext;}
\n {return NEWLINE;}
[;] {return *yytext;}
"==" {return EQ;}
"<" {return LT;}
">" {return GT;}
"if" {return IF;}
"else" {return ELSE;}
"then" {return THEN;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do" {return DO;}
"endwhile" {return ENDWHILE;}
. {yyerror("UNKNOWN ERROR\n");exit(1);}
%%

int yywrap(void) {
	return 1;
}

int main(int argc, char *argv[]) {
	yyin = fopen(argv[1],"r");
	yyparse();
	return 0;
}