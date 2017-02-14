%{
	#include <stdio.h>
	#include <stdlib.h>
%}

number [0-9]+
low [a-z]+
upp [A-Z]+
op [+|-|*|/]

%%

{number} {printf("Found : %d ",atoi(yytext));}
{low} {printf("lower case :: %s ",yytext);}
{upp} {printf("Upper Case :: %s ",yytext);}
{op} {printf("AIRTHMETIC OPERATOR");}

%%

int yywrap(){
	return 0;
}

int main()
{
  yylex();
  return 1;
}