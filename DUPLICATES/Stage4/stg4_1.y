%{
	#include <stdio.h>
	#include <stdlib.h>
	#define YYSTYPE struct ASTNode*
	#include "exptree.h"
	#include "exptree.c"
	int yylex(void);
%}


%token PLUS MINUS MUL ID ASSIGN NUM LT GT EQ IF THEN ELSE ENDIF WHILE DO ENDWHILE

%token  READ WRITE ASGN NEWLINE

%left PLUS MINUS
%left MUL

%%

Program : slist NEWLINE {
				$$ = $2;
				evalute($1);
				exit(1);
			}
     	;

slist : slist stmt {$$ = makeOperatorNode(-1, $1, $2);}
     | stmt {$$ = $1;}
     ;

expr : expr PLUS expr {$$=makeOperatorNode(PLUS, $1, $3); }
	| expr MINUS expr {$$=makeOperatorNode(MINUS, $1, $3);}
	| expr MUL expr {$$=makeOperatorNode(MUL, $1, $3);}
	| ID { $$ = $1; }
	| NUM {$$=$1;}
	;

cond : expr EQ expr {$$=makeOperatorNode(EQ,$1,$3);}
	| expr LT expr {$$=makeOperatorNode(LT,$1,$3);}
	| expr GT expr {$$=makeOperatorNode(GT,$1,$3);}

stmt: ID ASGN expr ';' { $$ = makeAssignNode(ASGN, $1, $3); }
	| READ '(' ID ')' ';' { $$ = makeReadWriteNode(READ, $3); }
	| WRITE '(' expr ')' ';' { $$ = makeReadWriteNode(WRITE, $3); }
	| IF '(' cond ')' THEN slist ELSE slist ENDIF ';' { $$ = makeIFNode(IF,$3,$6,$8);}
	| WHILE '(' cond ')' DO slist ENDWHILE ';' { $$ = makeOperatorNode(WHILE, $3, $6);}
	;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}
