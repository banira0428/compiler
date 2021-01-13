#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "debug_functions.h"

void genAsmFile(Node *node, char* filename);
void codeGen(Node *node, FILE *fp);

void codeGenForAssign(Node *node, FILE *fp);
void codeGenForArrayAssign(Node *node, FILE *fp, int offset, int depth, Var *v);

void codeGenForIf(Node *node, FILE *fp);
void codeGenForElse(Node *node, FILE *fp);

void codeGenForBranch(Node *node, FILE *fp, char *label, int n);

void codeGenForCondOp(Node *node, FILE *fp);
int isCondOperator(Node *node);

void codeGenForExpr(Node *node, FILE *fp);
void gen4(Node *node,FILE *fp);
void codeGenForOperate(Node *node, FILE *fp);
int isOperator(Node *node);

void codeGenForIdentOrNumber(Node *node,char *reg, FILE *fp);
int isIdentOrNumber(Node *node);

Var* getVar(Node *node);
int getArraySize(Node *node, Var *v, int depth);
int getOffset(Node *node);

