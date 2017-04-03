%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	extern FILE *yyin;
	
	#define YYSTYPE struct ASTNode*
	#include "exptree.h"
	#include "symtab.h"
	#include "errorcheck.h"
	#include "codegen.h"
	#include "symtab.c"
	#include "exptree.c"
	#include "errorcheck.c"
	#include "codegen.c"
	int yylex(void);
	extern int line;
%}


%token PLUS MINUS MUL DIV MODULO ASSIGN LT LE GT GE EQ NE  AND OR NOT 
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE IFTHEN
%token ID NUM BOOLCONS
%token  READ WRITE ASGN NEWLINE BEGINM END
%token INT BOOL DECL ENDDECL MAIN RET FUNC

%left AND OR NOT
%left EQ LT GT LE GE NE
%left PLUS MINUS
%left MUL DIV MODULO
%%

Prog : GDefblock FdefList Mainblock {printf("SUCCESFULLY GENERATED CODE\n");}

GDefblock : DECL GDefList ENDDECL {GPrint(); }

GDefList : GDecl GDefList
		 | GDecl
		 ;

GDecl : Type GIdList ';' { $$ = GListInstall($2,$1);}
	  ;

Type : INT { $$ = INT; }
	 | BOOL { $$ = BOOL; }
	 ;

GIdList : GId ',' GIdList{ $$ = $1; $1->ptr1 = $3; }
		| GId {$$=$1;}
		;

GId : ID { $$ = $1; $1->value = 1; }
	| ID '[' NUM ']' { $$=$1; $1->value = $3->value; }
	| ID '(' ArgList ')' { $$ = $1; $1->value = 0; $1->ptr2=$3;}
	;

ArgList : Type ID ',' ArgList { $$=$2; $2->type=$1; $2->ptr1=$4;}
		| Type ID { $$=$2; $2->type=$1;}
		| { $$=NULL;}
		;

ArgFuncList : Type ID ',' ArgFuncList { $2->type=$1; LInstallArg($2); }
		| Type ID { $2->type=$1; LInstallArg($2); }
		| { }
		;
FdefList :
		 | FdefList Fdef {printf("FUNCTION CREATED\n");clearLsymbol();LPrint();}
		 ;

Fdef : Type ID '(' ArgFuncList ')' '{' LDefblock Body '}' { $8->value=countLsym(); checkRetType($8,$1,$2); codegenrate($8,$2);}
	 ;

LDefblock : DECL LDefList ENDDECL {LargAssign();LPrint();}
		  ;

LDefList : LDecl LDefList {}
		 |

LDecl : Type LIdList ';' { $$=LListInstall($2,$1); }

LIdList : LId ',' LIdList { $$ = $1; $1->ptr1 = $3; }
		| LId { $$=$1; }

LId : ID { $$ = $1; $1->value = 1; }

Mainblock : INT MAIN '(' ')' '{' LDefblock Body '}' { $7->value=countLsym(); checkFunctionsDecl(); codegenrate($7,NULL);}

Body : BEGINM slist RetStmt END {$$=$3; $3->ptr1=$2; }

slist : slist stmt {$$ = makeOperatorNode(-1, $1, $2);}
     | stmt {$$ = $1;}
     ;

stmt: idexpr ASGN expr ';' { $$ = makeAssignNode(ASGN, $1, $3); }
	| READ '(' idexpr ')' ';' { $$ = makeReadWriteNode(READ, $3); }
	| WRITE '(' expr ')' ';' { $$ = makeReadWriteNode(WRITE, $3); }
	| IF '(' expr ')' THEN slist ENDIF ';' { $$ = makeIFTHENNode(IFTHEN,$3,$6);}
	| IF '(' expr ')' THEN slist ELSE slist ENDIF ';' { $$ = makeIFNode(IF,$3,$6,$8);}
	| WHILE '(' expr ')' DO slist ENDWHILE ';' { $$ = makeWhileNode(WHILE, $3, $6);}
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

idexpr : ID '[' expr ']' {$$=$1; $1->ptr2 = $3;checkIdDecl($1);checkIdExpr($1);}
	   | ID {$$=$1; $1->value = 0;checkIdDecl($1);}
	   | ID '(' ExprList ')' {$$=makeFuncNode(FUNC,$1,$3); }

ExprList : expr ',' ExprList {$$=InstallExpression($3,$1);}
		 | expr {$$=InstallExpression(NULL,$1);}
		 | {$$=NULL;}
		 ;

RetStmt : RET expr ';' {$$=makeRetNode(RET,$2);printf("%d %dret%d\n",makeRetNode(RET,$2)->nodetype,$$->nodetype,RET);}
		;
%%

yyerror(char const *s)
{
    printf("%d :: yyerror %s\n",line,s);
}

int main(int argc, char *argv[]) {
	yyin = fopen(argv[1],"r");
	yyparse();
	return 0;
}