#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "AST.h"

Node *parse_result = NULL;

Var *variables[10];
int num_vars = 0; 
int offset_vars = 0; 

int num_loops = 0;
int num_branches = 0;
int num_if_blocks = 0;

int heap_addr = 4;

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
  p->child = index;
  return p;
}

void printVar(Var *var){
  printf("name: %s, ", var->name);
  printf("offset: %d, ", var->offset);
  printf("size: %d\n", var->size);
}

void printNode(Node *node){
  printf("type : %s, ",types[node->type]);
  if(node->type == NUM_AST){
      printf("value : %d, ",node->ivalue);
  }
  if(node->type == IDENT_AST){
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

void generate_s_file(Node *node, char* filename){
    FILE *fp;
    int count;

    if ((fp = fopen(filename, "w")) == NULL) {
        fprintf(stderr, "ファイルのオープンに失敗しました．\n");
        return;
    }

    fprintf(fp, "        INITIAL_GP = 0x10008000\n");
    fprintf(fp, "        INITIAL_SP = 0x7ffffffc\n");
    fprintf(fp, "        stop_service = 99\n");
    fprintf(fp, "\n        .text\n");
    fprintf(fp, "init:\n");
    fprintf(fp, "        la $gp, INITIAL_GP\n");
    fprintf(fp, "        la $sp, INITIAL_SP\n");
    fprintf(fp, "        jal main\n");
    fprintf(fp, "        nop\n");
    fprintf(fp, "        li $v0, stop_service\n");
    fprintf(fp, "        syscall\n");
    fprintf(fp, "        nop\n");
    fprintf(fp, "stop:\n");
    fprintf(fp, "        j stop\n");
    fprintf(fp, "        nop\n");
    fprintf(fp, "\n        .text 0x00001000\n");
    fprintf(fp, "main:\n");
    fprintf(fp, "        la $t0, RESULT\n");

    gen_code(node, fp);

    fprintf(fp, "        jr $ra\n");
    fprintf(fp, "        nop\n");
    fprintf(fp, "\n        .data 0x10004000\n");
    fprintf(fp, "RESULT:\n");

    fclose(fp);
}

void gen_code(Node *node, FILE *fp){

  if(node->type == DECL_IDENTS_AST){
    Var *v;
    v = (Var *)malloc(sizeof(Var));
    v->offset = offset_vars;
    v->name = node->child->variable;
    v->size = 1;
    variables[num_vars] = v;
    num_vars++;
    offset_vars+= v->size * 4;
  }else if(node->type == ARRAY_DEFINE_AST){
    Var *v;
    v = (Var *)malloc(sizeof(Var));
    v->offset = offset_vars;
    v->name = node->child->variable;
    v->size = node->child->child->child->ivalue;
    variables[num_vars] = v;
    num_vars++;
    offset_vars+= v->size * 4;

  }else if(node->type == ASSIGN_AST){
    int offset = getOffset(node->child);
    codeGeneration_for_expression(node->child->brother, fp);

    if(node->child->type == IDENT_AST){
      fprintf(fp, "        sw $v0, %d($t0)\n", offset);
    }else if(node->child->type == ARRAY_AST){
      if(node->child->child->child->type == IDENT_AST){
        codeGenForIdentOrNumber(node->child->child->child, "t1", fp);
        fprintf(fp, "        li $t3, 4\n");
        fprintf(fp, "        mult $t1, $t3\n");
        fprintf(fp, "        mflo $t1\n");
        fprintf(fp, "        add $t1, $t1, $t0\n");
        fprintf(fp, "        addi $t1, $t1, %d\n", offset);
        fprintf(fp, "        sw $v0, 0($t1)\n");
      }else if(node->child->child->child->type == NUM_AST){
        fprintf(fp, "        addi $t1, $t0, %d\n", node->child->child->child->ivalue * 4 + offset);
        fprintf(fp, "        sw $v0, 0($t1)\n");
      }
    }

    
  }else if(node->type == WHILE_AST){
    int n = num_loops;
    num_loops++;

    fprintf(fp, "$LOOP%d:\n",n);

    codeGeneration_for_cond_expression(node->child, fp);
    char label[10]; 
    sprintf(label, "$EXIT%d", n);
    codeGenForBranch(node->child,fp, label);

    gen_code(node->child->brother,fp);
    fprintf(fp, "        j $LOOP%d\n", n);
    fprintf(fp, "        nop\n");
    fprintf(fp, "$EXIT%d:\n",n);

  }else if(node->type == IF_BLOCK_AST){

    codeGenForIf(node, fp);

    fprintf(fp, "$END%d:\n", num_if_blocks);
    num_if_blocks++;

  }else{
    if(node->child != NULL){
      gen_code(node->child, fp);
    }
    if(node->brother != NULL){
      gen_code(node->brother, fp);
    }
  }
}

void codeGeneration_for_cond_expression(Node *node, FILE *fp){
  if(isCondOperator(node)){
    codeGeneration_for_expression(node->child, fp);
    fprintf(fp, "        add $t4, $v0, $zero\n");

    codeGeneration_for_expression(node->child->brother, fp);
    
    fprintf(fp, "        add $t1, $t4, $zero\n");
    fprintf(fp, "        add $t3, $v0, $zero\n");

    //todo 命令セットが足りなくて使えない 
    //codeGenForCondOperate(node, fp);
  }
}

void codeGenForIf(Node *node, FILE *fp){

    int n = num_branches;
    num_branches++;

    codeGeneration_for_cond_expression(node->child, fp);

    char label[10]; 
    sprintf(label, "$L%d", n);
    codeGenForBranch(node->child,fp, label);
    gen_code(node->child->brother,fp);
    fprintf(fp, "        j $END%d\n", num_if_blocks);
    fprintf(fp, "$L%d:\n", n);

    if(node->brother != NULL){
      if(node->brother->type == ELSE_BLOCK_AST){
        codeGenForElse(node->brother, fp);
      }
    }
}

void codeGenForElse(Node *node, FILE *fp){
  if(node->child->type == STATEMENTS_AST){
    gen_code(node->child,fp);
  }else if(node->child->type == ELIF_BLOCK_AST){
    codeGenForIf(node->child->child, fp);
    if(node->child->brother->type == ELSE_BLOCK_AST){
      codeGenForElse(node->child->brother,fp);
    }
  }
}

void gen4(Node *node,FILE *fp){

  if(isOperator(node)){
    Expr *expr;
    expr = (Expr *)malloc(sizeof(Expr));
    expr->type = node->type;
    expr->result = heap_addr;
    heap_addr += 4;

    if(isOperator(node->child)){
      expr->left = heap_addr;
      gen4(node->child, fp);
      heap_addr += 4;
    }else if(isIdentOrNumber(node->child)){
      expr->left = heap_addr;
      codeGenForIdentOrNumber(node->child, "t1", fp);
      fprintf(fp, "        sw $t1, %d($t0)\n", offset_vars + heap_addr);
      heap_addr += 4;
    }else{
      if(node->child != NULL){
        expr->left = heap_addr;
        gen4(node->child, fp);
        heap_addr += 4;
      }
    }

    if(isOperator(node->child->brother)){
      expr->right = heap_addr;
      gen4(node->child, fp);
      heap_addr += 4;
    }else if(isIdentOrNumber(node->child->brother)){
      expr->right = heap_addr;
      codeGenForIdentOrNumber(node->child->brother, "t3", fp);
      fprintf(fp, "        sw $t3, %d($t0)\n", offset_vars + heap_addr);
      heap_addr += 4;
    }else{
      if(node->child->brother != NULL){
        expr->right = heap_addr;
        gen4(node->child->brother, fp);
        heap_addr += 4;
      }
    }

    fprintf(fp, "        lw $t1, %d($t0)\n", offset_vars + expr->left);
    fprintf(fp, "        nop\n");
    fprintf(fp, "        lw $t3, %d($t0)\n", offset_vars + expr->right);
    fprintf(fp, "        nop\n");

    codeGenForOperate(node, fp);

    fprintf(fp, "        sw $v0, %d($t0)\n", offset_vars + expr->result);
    fprintf(fp, "        nop\n");
  }else{
    if(node->child != NULL){
      gen4(node->child, fp);
    }
  }
}

void codeGeneration_for_expression(Node *node, FILE *fp){
  if(isOperator(node)){

    gen4(node, fp);
    heap_addr = 4;
    
  }else if(isIdentOrNumber(node)){
    codeGenForIdentOrNumber(node, "v0", fp);
  }else{
    codeGeneration_for_expression(node->child, fp);
  }
}

void codeGenForOperate(Node *node, FILE *fp){
  if(node->type == PLUS_AST){
    fprintf(fp, "        add $v0, $t1, $t3\n");
  }else if(node->type == MINUS_AST){
    fprintf(fp, "        sub $v0, $t1, $t3\n");
  }else if(node->type == MUL_AST){
    fprintf(fp, "        mult $t1, $t3\n");
    //todo 64ビットの場合はどうするの？
    fprintf(fp, "        mflo $v0\n");
  }else if(node->type == DIV_AST){
    fprintf(fp, "        div $t1, $t3\n");
    fprintf(fp, "        mflo $v0\n");
  }else if(node->type == SUR_AST){
    fprintf(fp, "        div $t1, $t3\n");
    fprintf(fp, "        mfhi $v0\n");
  }
}

void codeGenForBranch(Node *node, FILE *fp, char *label){
  if(node->type == EQ_AST){
    fprintf(fp, "        bne $t1, $t3, %s\n", label);
    fprintf(fp, "        nop\n");
  }else if(node->type == LT_AST){
    fprintf(fp, "        slt $t2, $t1, $t3\n");
    fprintf(fp, "        beq $t2, $zero, %s\n", label);    
    fprintf(fp, "        nop\n");
  }else if(node->type == LTE_AST){
    fprintf(fp, "        addi $t3, $t3, 1\n");
    fprintf(fp, "        slt $t2, $t1, $t3\n");
    fprintf(fp, "        beq $t2, $zero, %s\n", label);
    fprintf(fp, "        nop\n");
  }else if(node->type == GT_AST){
    fprintf(fp, "        slt $t2, $t3, $t1\n");
    fprintf(fp, "        beq $t2, $zero, %s\n", label);
    fprintf(fp, "        nop\n");
  }else if(node->type == GTE_AST){
    fprintf(fp, "        addi $t3, $t3, 1\n");
    fprintf(fp, "        slt $t2, $t3, $t1\n");
    fprintf(fp, "        beq $t2, $zero, %s\n", label);
    fprintf(fp, "        nop\n");
  }
}

int isCondOperator(Node *node){
  if(node->type == EQ_AST) return 1;
  if(node->type == LT_AST) return 1;
  if(node->type == LTE_AST) return 1;
  if(node->type == GT_AST) return 1;
  if(node->type == GTE_AST) return 1;
  return 0; 
}

int isOperator(Node *node){
  if(node == NULL) return 0;
  if(node->type == PLUS_AST) return 1;
  if(node->type == MINUS_AST) return 1;
  if(node->type == MUL_AST) return 1;
  if(node->type == DIV_AST) return 1;
  if(node->type == SUR_AST) return 1;
  return 0; 
}

int isIdentOrNumber(Node *node){
  if(node == NULL) return 0;
  return node->type == IDENT_AST || node->type == NUM_AST;
}

void codeGenForIdentOrNumber(Node *node,char *reg, FILE *fp){

  if(node->type == IDENT_AST){
    int offset = getOffset(node);
    fprintf(fp, "        lw $%s, %d($t0)\n", reg, offset);
    fprintf(fp, "        nop\n");
  }else if(node->type == NUM_AST){
    fprintf(fp, "        li $%s, %d\n", reg, node->ivalue);
  }
}

int getOffset(Node *node){
  int i;
  for(i = 0; i <num_vars; i++){
    if(!strcmp(variables[i]->name, node->variable)){
      return variables[i]->offset;
    }
  }
  return 0;
}

int main(int argc, char* argv[]){
    int result;
    result = yyparse();
    if(!result && parse_result != NULL){
        printTree(parse_result, 0);
        generate_s_file(parse_result, argv[1]);
    }
    return 0;
}