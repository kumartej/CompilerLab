extern int line;

typedef struct Typetable{
    char *name;
    int size;
    struct Fieldlist *fields;
    struct Typetable *next;
} typetable;

typedef struct Fieldlist{
  char *name;
  int fieldIndex;
  struct Typetable *type;
  struct Fieldlist *next;
} fieldlist;

typetable* typeroot=NULL;

void TypeTableCreate();

struct Typetable* TLookup(char *name);

struct Typetable* TInstall(char *name,int size, struct Fieldlist *fields);

void TInstallId(char *name);

struct Fieldlist* FLookup(typetable *type, char *name);

int GetSize (typetable * type);

fieldlist* createfield(char* Typename,char * typeId);

int findSize(fieldlist *fld);

fieldlist* insertField(fieldlist *fld1, fieldlist *fld2);

void TypePrint();