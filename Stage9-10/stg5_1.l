%{
	#include <stdio.h>
	#include "exptree.h"
	#include <stdlib.h>
	#include "y.tab.h"
	#include <string.h>

	int number;
	int line=1;
%}

%%

[0-9]+ { yylval = makeLeafNode(atoi(yytext),INT); return NUM;}
"read" {return READ;}
"write" {return WRITE;}
[ \t] {} 
[=] {return ASGN;}
[+] {return PLUS;}
[*] {return MUL;}
[-] {return MINUS;}
[/] {return DIV;}
[%] {return MODULO;}
[()]	{return *yytext;}
[{}] {return *yytext;}
\n {line++;}
[;] {return *yytext;}
[,] {return *yytext;}
"TRUE" {yylval = makeLeafNode(1,BOOL); return BOOLCONS;}
"FALSE" {yylval = makeLeafNode(0,BOOL); return BOOLCONS;}
"[" {return *yytext;}
"]" {return *yytext;}
"==" {return EQ;}
"<" {return LT;}
">" {return GT;}
"<=" {return LE;}
">=" {return GE;}
"!=" {return NE;}
"&&" {return AND;}
"||" {return OR;}
"!" {return NOT;}
"decl" {return DECL;}
"enddecl" {return ENDDECL;}
"int" {return INT;}
"bool" {return BOOL;}
"begin" {return BEGINM;}
"end" {return END;}
"if" {return IF;}
"else" {return ELSE;}
"then" {return THEN;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do" {return DO;}
"endwhile" {return ENDWHILE;}
"main" {return MAIN;}
"return" {return RET;}
[a-zA-Z][a-zA-Z0-9]* {yylval=makeIDNode(ID, strdup(yytext));return ID;}
. {yyerror("UNKNOWN ERROR\n");exit(1);}
%%

int yywrap(void) {
	return 1;
}
