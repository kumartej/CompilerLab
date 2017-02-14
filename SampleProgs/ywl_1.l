%{

	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"

%}

%%

[a-z] {yylval = *yytext; return VAR;}
[+|-|*|/|(|)] {return *yytext;}
\n {return NEWLINE;}


%%

int yywrap(){
	return 1;
}