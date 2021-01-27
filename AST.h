#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "debug_functions.h"

void genAsmFile(Node *node, char* filename);
void codeGen(Node *node, FILE *fp, Var *vars[], char *src_reg);

void codeGenForAssign(Node *node, FILE *fp, Var *vars[], char *src_reg);
void codeGenForArrayAssign(Node *node, FILE *fp, int offset, int depth, Var *v, Var *vars[], char *src_reg);

void codeGenForIf(Node *node, FILE *fp, Var *vars[], char *src_reg);
void codeGenForElse(Node *node, FILE *fp, Var *vars[], char *src_reg);

void codeGenForBranch(Node *node, FILE *fp, char *label, int n);

void codeGenForCondOp(Node *node, FILE *fp, Var *vars[], char *src_reg);
int isCondOperator(Node *node);

void codeGenForExpr(Node *node, FILE *fp, Var *vars[], char *src_reg);
void codeGenForExprPair(Node *node,FILE *fp, Var *vars[], char *src_reg);
void codeGenForExprPart(Node *node,FILE *fp,char *reg, int *result, Var *vars[], char *src_reg);
void codeGenForOperate(Node *node, FILE *fp);
int isOperator(Node *node);

void codeGenForIdentOrNumber(Node *node,char *reg, FILE *fp, Var *vars[], char *src_reg);
int isIdentOrNumber(Node *node);

Var* getVar(Node *node, Var *vars[], char *src_reg);
int getArraySize(Node *node, Var *v, int depth);
int getOffset(Node *node, Var *vars[], char *src_reg);

