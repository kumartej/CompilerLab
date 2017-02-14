int ureg=-1;
int uLab=-1;
FILE *fp;

int codegenrate(astnode *root);
int codegeneval(astnode *root);
int getReg();
void freeReg();
int codegenWrite(int reg);