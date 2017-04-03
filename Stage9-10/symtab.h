int memory[1000];
int nsym = 0;

int sAlloc = 4096,lastfunc=-1,lAlloc=0,larg=-2;

typedef struct Gsymbol{
	char *name;
	int type;
	int size;
	int binding;
	struct argstruct *arglist;
	struct Gsymbol *next;
} gsymbol;

typedef struct argstruct{
	int type;
	char *name;
	struct argstruct *next;
}ArgStruct;

typedef struct  Lsymbol{
	char *name;
	int type;
	int binding;
	int size;
	struct Lsymbol *next;
}lsymbol;

gsymbol *root=NULL;

gsymbol* GLookup(char *name);

gsymbol* GListInstall(astnode* list, int type);

struct Gsymbol* GInstall(char *name,int type, int size,astnode * ptr2);

void GPrint();

lsymbol *lroot=NULL;
ArgStruct *argroot=NULL;

lsymbol* LLookup(char *name);

lsymbol* LListInstall(astnode *list, int type);

lsymbol* LInstall(char *name,int type,int size);

lsymbol* LInstallArg(astnode *list);

ArgStruct* ArgListInstall(astnode *list);

void LPrint();

void clearLsymbol();

void LargAssign();

int countLsym();

int checkFunctionsDecl();