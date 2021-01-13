#include <stdio.h>
#include <string.h>
#include "structs.h"

void printVars(Var *variables[], int length);
void printVar(Var *var);
void printNode(Node *node);
void printTree(Node *node, int depth);
int getArraySize(Node *node, Var *v, int depth);