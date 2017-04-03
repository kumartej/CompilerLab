#include "y.tab.h"

extern int line;

int *var[26];

struct ASTNode{
  struct Typetable *type;
  int nodetype;
  char *name;
  int value;
  struct ASTNode *ptr1,*ptr2,*ptr3;
  struct Gsymbol *gsym;
  struct Lsymbol *lsym;
};

#define astnode struct ASTNode

astnode* makeLeafNode(int n, int type);

astnode* makeOperatorNode(int op,struct ASTNode *l,struct ASTNode *r);

astnode* makeAssignNode(int op, astnode *l, astnode* r);

astnode* makeReadWriteNode(int op, astnode *l);

astnode* makeIDNode(int op, char *nm);

astnode* makeIFNode(int op, astnode *l,astnode *m , astnode*r);

astnode* makeIFTHENNode(int op,astnode *l,astnode*r);

astnode* makeRetNode(int op,astnode *l);

astnode* makeFuncNode(int op,astnode *l,astnode *r);

astnode* makeAllocNode(int op, astnode *l);

astnode* makeAllocNode(int op, astnode *l);

astnode* makeFreeNode(int op, astnode *l);

astnode* makeFieldNode(astnode *ftroot);

astnode* makeBreakNode(int op);

int evaluate(astnode *t);