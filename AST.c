#include<stdio.h>
#include <stdarg.h>
#include "AST.h"

Node *parse_result = NULL;

Node* build_nodes(NType t, int size, ...){

  Node *p;
  p = (Node *)malloc(sizeof(Node));
  if(p == NULL){
    yyerror("out of memory");
  }
  p->type = t;
  
  va_list ap;
  va_start(ap, size);
  p->child = va_arg(ap, Node*);

  Node *np = p->child;
  int i;
  for(i = 1; i < size; i++){
    Node *tmp = va_arg(ap, Node*);
    np->brother = tmp;
    np = tmp;
  }
  va_end(ap);

  return p;
}

Node* build_node2(NType t, Node* p1, Node* p2){
  Node *p;
  p = (Node *)malloc(sizeof(Node));
  if(p == NULL){
    yyerror("out of memory");
  }
  p->type = t;
  p->child = p1;
  p1->brother = p2;
  p->brother = NULL;
  return p;
}

Node* build_num_node(NType t, int n){
  Node *p;
  p = (Node *)malloc(sizeof(Node));
  if(p == NULL){
    yyerror("out of memory");
  }
  p->type = t;
  p->ivalue = n;
  p->child = NULL;
  return p;
}

Node* build_ident_node(NType t, char *s){
  Node *p;
  p = (Node *)malloc(sizeof(Node));
  if(p == NULL){
    yyerror("out of memory");
  }
  p->type = t;
  p->variable = s;
  p->child = NULL;
  p->brother = NULL;
  return p;
}

void printTree(Node *node, int depth){
  char space[1024] = "";
  int i;
  for(i = 0; i< depth;i++){
    strcat(space, " ");
  }
  strcat(space, "|-");
  printf(space);
  printf("type : %d, ",node->type);
  printf("value : %d\n",node->ivalue);
  if(node->brother != NULL){
    printTree(node->brother, depth);
  }
  if(node->child != NULL){
    printTree(node->child, depth + 4);
  }
}

int main(void){
    int result;
    result = yyparse();
    if(!result && parse_result != NULL){
        printTree(parse_result, 0);
    }
    return 0;
}