struct Gsymbol{
	char *name;
	int type;
	int size;
	int binding;
	struct Gsymbol *next;
};

#define gsymbol struct Gsymbol

gsymbol *root=NULL;

struct Gsymbol* GInstall(char *name,int type, int size);
struct Gsymbol* GLookup(char *name);