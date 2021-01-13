#include "debug_functions.h"

char* types[] = {"IDENT","NUM","ASSIGN","PLUS","MINUS","MUL","DIV","SUR","INC","DEC","EQ","LT","LTE","GT","GTE",
  "WHILE","IF","IF_B","ELIF_B","ELSE_B","ARRAY_INDEX","ARRAY",
  "CONDITION","FOR_ASIGN","FOR_COND","FOR_EXPR","FOR","FUNC","FUNCCALL","BREAK","PARAMS","PARAM","ARGS","ARG",
  "FACTOR","FORE_INC_FACTOR","TERM","ADD_EXPR","INC_EXPR","SUR_EXPR","EXPR","STATEMENT",
  "STATEMENTS","DECL_IDENTS","DEFINE","FUNC_DEFINE","ARRAY_DEFINE","DECLARATIONS","PROGRAM"};

void printVars(Var *variables[], int length){
  int i;
  for(i = 0; i<length;i++){
    printVar(variables[i]);
  }
}

void printVar(Var *var){
  printf("name: %s, ", var->name);
  printf("offset: %d, ", var->offset);
  printf("size: %d, ", var->size);
  int i;
  printf("sizes: ");
  for(i = 0; i< 3 ;i ++){
    printf("%d,", var->sizes[i]);
  }
  printf("\n");
}

void printNode(Node *node){
  printf("type : %s, ",types[node->type]);
  if(node->type == NUM_AST){
      printf("value : %d, ",node->ivalue);
  }
  if(node->type == IDENT_AST){
      printf("variable : %s",node->variable);
  }
  if(node->type == ARRAY_AST){
      printf("variable : %s",node->variable);
  }
  printf("\n");
}

void printTree(Node *node, int depth){
  char space[1024] = "";
  int i;
  for(i = 0; i< depth;i++){
    strcat(space, " ");
  }
  strcat(space, "|-");
  printf(space);
  printNode(node);

  if(node->child != NULL){
    printTree(node->child, depth + 2);
  }
  if(node->brother != NULL){
    printTree(node->brother, depth);
  }
}