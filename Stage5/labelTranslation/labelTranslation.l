%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int sAdd=2048;
	int iter=1;
	FILE *fp;
	char *fst;
	#include "labelTranslation.h"
	#include "labelTranslation.c"
	int temp;
%}

%%

"L"[0-9]+ {if(iter==2){adres=searchLab(yytext);if(adres==NULL) printf("NOLABELSTRING :: %s\n",yytext); else fprintf(fp, "%d",adres->addr);}}
"F"[0-9]+ {if(iter==2){adres=searchLab(yytext);if(adres==NULL) printf("NOLABELSTRING :: %s\n",yytext); else fprintf(fp, "%d",adres->addr);}}
"MAIN" {if(iter==2){adres=searchLab(yytext);if(adres==NULL) printf("NOLABELSTRING :: %s\n",yytext); else fprintf(fp, "%d",adres->addr);}}
"L"[0-9]+":"\n  {if(iter==1){insertLab(strdup(yytext));}}
"F"[0-9]+":"\n  {if(iter==1){insertLab(strdup(yytext));}}
"MAIN:"\n  {if(iter==1){insertLab(strdup(yytext));}}
\n {if(iter==2){fprintf(fp,"\n");}else if(iter==1){sAdd+=2;}}
. {if(iter==2){fprintf(fp, "%c",*yytext);}}

%%

int yywrap(){
	if(iter==1){
		yyin=fopen(fst,"r");
		iter++;
		return 0;
	}else
		return 1;
}

int main(int argc, char const *argv[])
{
	yyin = fopen(argv[1],"r");
	fst = argv[1];
	fp=fopen("../../xsm_expl/out2.xsm","w");
	yylex();
	return 0;
}
