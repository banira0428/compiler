#include "build_node.h"

Node* build_nodes(NType t, int size, ...){

  Node *p;
  p = (Node *)malloc(sizeof(Node));
  if(p == NULL){
    yyerror("out of memory");
  }
  p->type = t;

  if(size > 0){
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
  }
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
  return p;
}

Node* build_array_node(NType t, char* s, Node* index){
  Node *p;
  p = (Node *)malloc(sizeof(Node));
  if(p == NULL){
    yyerror("out of memory");
  }
  p->type = t;
  p->variable = s;
  p->child = index;
  return p;
}