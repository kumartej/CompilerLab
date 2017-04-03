
int ureg=-1;
int uLab=-1;
FILE *fp;
int start=0;

stack *s;
int retcounter=-1;

int breakLabel=-1,continueLabel=-1;

int codegenrate(astnode *root, astnode *idnode);
int codegeneval(astnode *root);
int getReg();
void freeReg();
int getLabel();
int codegenWrite(int reg);
int codegenRead(int reg);
int codegenIf(astnode *root);
int codegenWhile(astnode *root);
int codegenFunc(astnode *root);
int codegenIfThen(root);
int codegenField(int reg1, astnode *ftroot);
int codegenAddField(int reg1,astnode *ftroot);
int codegenAlloc(astnode *root);
int codegenFree(astnode *root);
int codegenIntial();
int codegenId(astnode *root);