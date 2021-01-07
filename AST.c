#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "AST.h"

Node *parse_result = NULL;

char* types[] = {"IDENT","NUM","ASSIGN","PLUS","MINUS","MUL","DIV","SUR","INC","DEC","EQ","LT","LTE","GT","GTE",
  "WHILE","IF","IF_B","ELIF_B","ELSE_B","ARRAY_INDEX","ARRAY",
  "CONDITION","FOR_ASIGN","FOR_COND","FOR_EXPR","FOR","FUNC","FUNCCALL","BREAK","PARAMS","PARAM","ARGS","ARG",
  "FACTOR","FORE_INC_FACTOR","TERM","ADD_EXPR","INC_EXPR","SUR_EXPR","EXPR","STATEMENT",
  "STATEMENTS","DECL_IDENTS","DEFINE","FUNC_DEFINE","ARRAY_DEFINE","DECLARATIONS","PROGRAM"};

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
  p->array_index = index;
  p->child = NULL;
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
  printf("type : %s, ",types[node->type]);
  if(node->type == NUM_AST){
      printf("value : %d, ",node->ivalue);
  }
  if(node->type == IDENT_AST){
      printf("variable : %s",node->variable);
  }
  printf("\n");

  if(node->array_index != NULL){
    printTree(node->array_index, depth + 2);
  }
  if(node->child != NULL){
    printTree(node->child, depth + 2);
  }
  if(node->brother != NULL){
    printTree(node->brother, depth);
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