extern int line;
int memory[1000];
int nsym = 0;

int sAlloc = 4096,lastfunc=-1,lAlloc=0,larg=-2;

typedef struct Gsymbol{
	char *name;
	typetable* type;
	int size;
	int binding;
	struct argstruct *arglist;
	struct Gsymbol *next;
} gsymbol;

typedef struct argstruct{
	typetable* type;
	char *name;
	struct argstruct *next;
}ArgStruct;

typedef struct  Lsymbol{
	char *name;
	typetable *type;
	int binding;
	int size;
	struct Lsymbol *next;
}lsymbol;

gsymbol *root=NULL;

gsymbol* GLookup(char *name);

gsymbol* GListInstall(astnode* list, typetable* type);

struct Gsymbol* GInstall(char *name,typetable* type, int size,astnode * ptr2);

void GPrint();

lsymbol *lroot=NULL;
ArgStruct *argroot=NULL;

lsymbol* LLookup(char *name);

lsymbol* LListInstall(astnode *list, typetable* type);

lsymbol* LInstall(char *name,typetable* type,int size);

lsymbol* LInstallArg(astnode *list);

ArgStruct* ArgListInstall(astnode *list);

void LPrint();

void clearLsymbol();

void LargAssign(typetable* type);

int countLsym();

int checkFunctionsDecl();