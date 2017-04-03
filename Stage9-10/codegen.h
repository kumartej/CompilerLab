int ureg=-1;
int uLab=-1;
FILE *fp;
int start=0;

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