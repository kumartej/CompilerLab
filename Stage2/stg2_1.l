/* STAGE 2 IMPLEMENTATION ---- LEX */

%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	int a;
%}

%%

[a-z] {yylval.character = yytext[0];return ID;}
[0-9]+ {yylval.integer = atoi(yytext);return NUM;}
"read" {return READ;}
"write" {return WRITE;}
[ \t]+ 
[=] {return ASGN;}
[+] {return PLUS;}
[*] {return MUL;}
[-] {return MINUS;}
\n {return NEWLINE;}
. {return *yytext;}

%%

int yywrap(){
	return 0;
}