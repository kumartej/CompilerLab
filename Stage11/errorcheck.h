int checkIdDecl(astnode *root);

int checkIdExpr(astnode *root);

int checkRetType(astnode *root,typetable* type,astnode *id);

int checkBreak(int breakstmt);

int checkNullId(astnode *root);