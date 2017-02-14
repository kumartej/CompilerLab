#include "y.tab.h"
int *var[26];

struct ASTNode{
  int type;           //pointer to the type table entry
  int nodetype;                     //node type information,eg : NODETYPE_WHILE,NODETYPE_PLUS,NODETYPE_STMT etc 
  char *name;                       //stores the variable/function name in case of variable/function nodes
  int value;
  struct ASTNode *ptr1,*ptr2,*ptr3; //Subtrees of the node. (Maximum Subtrees for IF THEN ELSE)
  int gsym;
};

#define astnode struct ASTNode

astnode* makeLeafNode(int n, int type);

astnode* makeOperatorNode(int op,struct ASTNode *l,struct ASTNode *r);

astnode* makeAssignNode(int op, astnode *l, astnode* r);

astnode* makeReadWriteNode(int op, astnode *l);

astnode* makeIDNode(int op, char nm);

astnode* makeIFNode(int op, astnode *l,astnode *m , astnode*r);

astnode* makeWhileNode(int op,struct ASTNode *l,struct ASTNode *r);

int evaluate(astnode *t);