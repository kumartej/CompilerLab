%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"

%}

%%

[a-z]+ {yylval = strdup(yytext); return VAR;}
[+|-|*|/|(|)] {return *yytext;}
\n {return NEWLINE;}


%%

int yywrap(){
	return 1;
}