int memory[1000];
int nsym = 0;

int sAlloc = 4096;
typedef struct Gsymbol{
	char *name;
	int type;
	int size;
	int binding;
	struct Gsymbol *next;
} gsymbol;

gsymbol *root=NULL;

gsymbol* GLookup(char *name);

gsymbol* GListInstall(astnode* list, int type);

struct Gsymbol* GInstall(char *name,int type, int size);

void GPrint();