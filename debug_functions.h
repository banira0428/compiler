#include <stdio.h>
#include "AST.h"

void printVars(Var *variables[], int length);
void printVar(Var *var);
void printNode(Node *node);
void printTree(Node *node, int depth);