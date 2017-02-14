%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	extern FILE *yyin;
	
	#define YYSTYPE struct ASTNode*
	#include "exptree.h"
	#include "symtab.h"
	#include "errorcheck.h"
	#include "symtab.c"
	#include "exptree.c"
	#include "errorcheck.c"
	int yylex(void);
%}


%token PLUS MINUS MUL DIV MODULO ASSIGN LT LE GT GE EQ NE  AND OR NOT 
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE
%token ID NUM BOOLCONS
%token  READ WRITE ASGN NEWLINE BEGINM END
%token INT BOOL DECL ENDDECL

%left AND OR NOT
%left EQ LT GT LE GE NE
%left PLUS MINUS
%left MUL DIV MODULO
%%

strt : declaration Program {printf("EXECUTED");}
	 ;

declaration : DECL dclist ENDDECL
			;

dclist : decl dclist
		|

decl : INT varlist ';' {$$ = GListInstall($2,INT);}
	 | BOOL varlist ';' {$$ = GListInstall($2,BOOL);}

varlist : idDecl ',' varlist {$$ = $1; $1->ptr1 = $3;}
		| idDecl {$$ = $1;}

idDecl: ID '[' NUM ']' {$$=$1; $1->value = $3->value;}
	  | ID {$$ = $1; $1->value = 1;}

Program : BEGINM slist END {
				$$ = $3;
				evalute($2);
				exit(1);
			}
     	;

slist : slist stmt {$$ = makeOperatorNode(-1, $1, $2);}
     | stmt {$$ = $1;}
     ;

expr : expr PLUS expr {$$=makeOperatorNode(PLUS, $1, $3); }
	| expr MINUS expr {$$=makeOperatorNode(MINUS, $1, $3);}
	| expr MUL expr {$$=makeOperatorNode(MUL, $1, $3);}
	| expr DIV expr {$$=makeOperatorNode(DIV, $1, $3);}
	| expr MODULO expr {$$=makeOperatorNode(MODULO, $1, $3);}
	| expr EQ expr {$$=makeOperatorNode(EQ,$1,$3);}
	| expr LT expr {$$=makeOperatorNode(LT,$1,$3);}
	| expr GT expr {$$=makeOperatorNode(GT,$1,$3);}
	| expr LE expr {$$=makeOperatorNode(LE,$1,$3);}
	| expr GE expr {$$=makeOperatorNode(GE,$1,$3);}
	| expr NE expr {$$=makeOperatorNode(NE,$1,$3);}
	| expr AND expr {$$=makeOperatorNode(AND,$1,$3);}
	| expr OR expr {$$=makeOperatorNode(OR,$1,$3);}
	| NOT expr {$$=makeOperatorNode(NOT,$1,NULL);}
	| idexpr { $$ = $1; }
	| NUM {$$=$1;}
	| BOOLCONS {$$=$1;}
	;

idexpr : ID '[' expr ']' {$$=$1; $1->ptr1 = $3;checkIdDecl($1);checkIdExpr($1);}
	   | ID {$$=$1; $1->value = 0;checkIdDecl($1);}

stmt: idexpr ASGN expr ';' { $$ = makeAssignNode(ASGN, $1, $3); }
	| READ '(' idexpr ')' ';' { $$ = makeReadWriteNode(READ, $3); }
	| WRITE '(' expr ')' ';' { $$ = makeReadWriteNode(WRITE, $3); }
	| IF '(' expr ')' THEN slist ELSE slist ENDIF ';' { $$ = makeIFNode(IF,$3,$6,$8);}
	| WHILE '(' expr ')' DO slist ENDWHILE ';' { $$ = makeWhileNode(WHILE, $3, $6);}
	;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

int main(int argc, char *argv[]) {
	yyin = fopen(argv[1],"r");
	yyparse();
	return 0;
}