%{
	#include <stdio.h>
	#include <stdlib.h>

	int nl,nw,nchar,ni,nf,no;
%}

number [0-9]+
low [a-z]
upp [A-Z]
flt number[.]number

%%

\n {nl++;nw++;}
[\t " "] {nw++;}
({low}|{upp}) {nchar++;} 
{number} {ni++;nchar+=yyleng;nw++;}
({number})[.]({number}) {nf++;nchar+=yyleng;nw++;}
A({low}|{upp})({low}|{upp}) {nchar+=3;printf("%s\n",yytext);}
[+|-|*|/] {no++;nchar++;}
. {nchar++;}

%%

int yywrap(){
	return 1;
}

int main(int argc, char *argv[]){
	nl=0;
	nw=0;
	nchar=0;
	ni=0;
	nf=0;
	no=0;
	if(argc>1){
		FILE *fp = fopen(argv[1],"r");
		if(fp)
			yyin = fp;
	}
	yylex();
	printf("%d :: %d :: %d\n",nl,nw,nchar);
	printf("%d %d\n",ni,nf);
	printf("%d\n",no);
	return 0;
}