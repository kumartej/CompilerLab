
typedef struct LabelTable{
	char *str;
	int addr;
	struct LabelTable *next;
} ltable;

ltable *lroot=NULL;
ltable* adres;

void insertLab(char *str);
ltable* searchLab(char *str);
void printLTable();