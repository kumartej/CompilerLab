/* BASIC CALCULATOR */

%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"

%}

%%

[0-9]+ {yylval = atoi(yytext); return VAR;}
[+|-|*|/|(|)] {return *yytext;}
\n {return NEWLINE;}


%%

int yywrap(){
	return 1;
}