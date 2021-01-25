#include "AST.h"

Node *parse_result = NULL;

Var *variables[10];
int num_vars = 0; 
int offset_vars = 0; 
int num_loops = 0;
int num_branches = 0;
int num_if_blocks = 0;

int heap_addr = 4;

void genAsmFile(Node *node, char* filename){
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

    codeGen(node, fp);

    fprintf(fp, "        jr $ra\n");
    fprintf(fp, "        nop\n");
    fprintf(fp, "\n        .data 0x10004000\n");
    fprintf(fp, "RESULT:\n");

    fclose(fp);
}

int getArraySize(Node *node, Var *v, int depth){ // param = ARRAY_INDEX
  if(node->child->type == NUM_AST){
    v->sizes[depth] = node->child->ivalue;
    return node->child->ivalue;
  }else if(node->child->type == ARRAY_INDEX_AST){
    v->sizes[depth] = node->child->brother->ivalue;
    return getArraySize(node->child, v, depth + 1) * node->child->brother->ivalue;
  }
}

void codeGenForArrayAssign(Node *node, FILE *fp, int offset, int depth, Var *v){  // param = ARRAY_INDEX

  if(node->type == IDENT_AST){

    int n;
    int size = 4;
    for(n = depth + 1; n < 3; n++){
      if(v->sizes[n] != 0){
        size = size * v->sizes[n];
      }
    }

    codeGenForIdentOrNumber(node, "t1", fp);
    fprintf(fp, "        li $t3, %d\n", size);
    fprintf(fp, "        mult $t1, $t3\n");
    fprintf(fp, "        mflo $t1\n");
  }else if(node->type == NUM_AST){

    int n;
    int size = 4;
    for(n = depth + 1; n < 3; n++){
      if(v->sizes[n] != 0){
        size = size * v->sizes[n];
      }
    }

    fprintf(fp, "        addi $t1, $zero, %d\n", (node->ivalue) * size);
  }else if(node->type == ARRAY_INDEX_AST){
    codeGenForArrayAssign(node->child, fp, offset, depth, v);
    fprintf(fp, "        add $t4, $t1, $zero\n");
    codeGenForArrayAssign(node->brother, fp, offset, depth + 1, v);
    fprintf(fp, "        add $t1, $t1, $t4\n");
  }
}

Var* getVar(Node *node){
  int i;
  for(i = 0; i <num_vars; i++){
    if(!strcmp(variables[i]->name, node->variable)){
      return variables[i];
    }
  }
  fprintf(stderr,"Compile Error! undefined variable: %s\n",node->variable);
  exit(0);
  return NULL;
}

void codeGen(Node *node, FILE *fp){

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
    v->size = getArraySize(node->child->child,v, 0);

    variables[num_vars] = v;
    num_vars++;
    offset_vars+= v->size * 4;

    if(node->brother != NULL){
      codeGen(node->brother, fp);
    }

  }else if(node->type == ASSIGN_AST){

    codeGenForExpr(node->child->brother, fp);
    codeGenForAssign(node, fp);
    
  }else if(node->type == WHILE_AST){
    int n = num_loops;
    num_loops++;

    fprintf(fp, "$LOOP%d:\n",n);

    codeGenForCondOp(node->child, fp);
    codeGenForBranch(node->child,fp, "$EXIT", n);

    codeGen(node->child->brother,fp);
    fprintf(fp, "        j $LOOP%d\n", n);
    fprintf(fp, "        nop\n");
    fprintf(fp, "$EXIT%d:\n",n);

  }else if(node->type == FOR_AST){
    int n = num_loops;
    num_loops++;

    codeGenForExpr(node->child->child->child->brother, fp);
    codeGenForAssign(node->child->child, fp);

    fprintf(fp, "$LOOP%d:\n",n);

    codeGenForCondOp(node->child->brother->child, fp);
    codeGenForBranch(node->child->brother->child,fp,"$EXIT", n);

    codeGen(node->child->brother->brother->brother,fp);

    codeGenForExpr(node->child->brother->brother->child,fp);
    fprintf(fp, "        j $LOOP%d\n", n);
    fprintf(fp, "        nop\n");
    fprintf(fp, "$EXIT%d:\n",n);
  
  }else if(node->type == IF_BLOCK_AST){

    codeGenForIf(node, fp);

    fprintf(fp, "$END%d:\n", num_if_blocks);
    num_if_blocks++;

  }else if(node->type == IF_BLOCK_AST){

    codeGenForIf(node, fp);

  }else if(node->type == INC_AST){
    codeGenForIdentOrNumber(node->child, "v0", fp);
    fprintf(fp, "        addi $v0, $v0, 1\n");
    codeGenForAssign(node, fp);
  }else if(node->type == DEC_AST){
    codeGenForIdentOrNumber(node->child, "v0", fp);
    fprintf(fp, "        addi $v0, $v0, -1\n");
    codeGenForAssign(node, fp);
  }else{
    if(node->child != NULL){
      codeGen(node->child, fp);
    }
    if(node->brother != NULL){
      codeGen(node->brother, fp);
    }
  }
}

void codeGenForCondOp(Node *node, FILE *fp){
  if(isCondOperator(node)){
    codeGenForExpr(node->child, fp);
    fprintf(fp, "        add $t4, $v0, $zero\n");

    codeGenForExpr(node->child->brother, fp);
    
    fprintf(fp, "        add $t1, $t4, $zero\n");
    fprintf(fp, "        add $t3, $v0, $zero\n");

    //todo 命令セットが足りなくて使えない 
    //codeGenForCondOperate(node, fp);
  }
}

void codeGenForAssign(Node *node, FILE *fp){ // param: ASSIGN_AST
    int offset = getOffset(node->child);
    Var *v = getVar(node->child);

    if(node->child->type == IDENT_AST){
      fprintf(fp, "        sw $v0, %d($t0)\n", offset);
    }else if(node->child->type == ARRAY_AST){

      codeGenForArrayAssign(node->child->child->child, fp, offset, 0, v);

      fprintf(fp, "        addi $t1, $t1, %d\n", offset);
      fprintf(fp, "        add $t1, $t1, $t0\n");
      fprintf(fp, "        sw $v0, 0($t1)\n");
    }
}

void codeGenForIf(Node *node, FILE *fp){

    int n = num_branches;
    num_branches++;

    codeGenForCondOp(node->child, fp);
    codeGenForBranch(node->child,fp, "$L", n);
    codeGen(node->child->brother,fp);
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
    codeGen(node->child,fp);
  }else if(node->child->type == ELIF_BLOCK_AST){
    codeGenForIf(node->child->child, fp);
    if(node->child->brother->type == ELSE_BLOCK_AST){
      codeGenForElse(node->child->brother,fp);
    }
  }
}

void codeGenForExprPair(Node *node,FILE *fp){

  if(isOperator(node)){
    Expr *expr;
    expr = (Expr *)malloc(sizeof(Expr));
    expr->type = node->type;
    expr->result = heap_addr;
    heap_addr += 4;

    codeGenForExprPart(node->child,fp, "t1",&(expr->left));
    heap_addr += 4;
    codeGenForExprPart(node->child->brother,fp,"t3", &(expr->right));
    heap_addr += 4;

    fprintf(fp, "        lw $t1, %d($t0)\n", offset_vars + expr->left);
    fprintf(fp, "        lw $t3, %d($t0)\n", offset_vars + expr->right);
    fprintf(fp, "        nop\n");

    codeGenForOperate(node, fp);

    fprintf(fp, "        sw $v0, %d($t0)\n", offset_vars + expr->result);
    fprintf(fp, "        nop\n");
  }else{
    if(node->child != NULL){
      codeGenForExprPair(node->child, fp);
    }
  }
}

void codeGenForExprPart(Node *node,FILE *fp,char *reg, int *result){

  *result = heap_addr;
  if(isOperator(node)){
    codeGenForExprPair(node, fp);
  }else if(isIdentOrNumber(node)){
    codeGenForIdentOrNumber(node, reg, fp);
    fprintf(fp, "        sw $%s, %d($t0)\n", reg, offset_vars + heap_addr);
  }else{
    codeGenForExprPair(node, fp);
  }
}

void codeGenForExpr(Node *node, FILE *fp){
  if(isOperator(node)){

    codeGenForExprPair(node, fp);
    heap_addr = 4;
    
  }else if(isIdentOrNumber(node)){
    codeGenForIdentOrNumber(node, "v0", fp);
  }else if(node->type == INC_AST){
    codeGenForIdentOrNumber(node->child, "v0", fp);
    fprintf(fp, "        addi $v0, $v0, 1\n");
    codeGenForAssign(node, fp);
  }else if(node->type == DEC_AST){
    codeGenForIdentOrNumber(node->child, "v0", fp);
    fprintf(fp, "        addi $v0, $v0, -1\n");
    codeGenForAssign(node, fp);
  }else{
    codeGenForExpr(node->child, fp);
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

void codeGenForBranch(Node *node, FILE *fp, char *label, int n){
  if(node->type == EQ_AST){
    fprintf(fp, "        bne $t1, $t3, %s%d\n", label, n);
    fprintf(fp, "        nop\n");
  }else if(node->type == LT_AST){
    fprintf(fp, "        slt $t2, $t1, $t3\n");
    fprintf(fp, "        beq $t2, $zero, %s%d\n", label, n);    
    fprintf(fp, "        nop\n");
  }else if(node->type == LTE_AST){
    fprintf(fp, "        addi $t3, $t3, 1\n");
    fprintf(fp, "        slt $t2, $t1, $t3\n");
    fprintf(fp, "        beq $t2, $zero, %s%d\n", label, n);
    fprintf(fp, "        nop\n");
  }else if(node->type == GT_AST){
    fprintf(fp, "        slt $t2, $t3, $t1\n");
    fprintf(fp, "        beq $t2, $zero, %s%d\n", label, n);
    fprintf(fp, "        nop\n");
  }else if(node->type == GTE_AST){
    fprintf(fp, "        addi $t3, $t3, 1\n");
    fprintf(fp, "        slt $t2, $t3, $t1\n");
    fprintf(fp, "        beq $t2, $zero, %s%d\n", label, n);
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
  return node->type == IDENT_AST || node->type == NUM_AST || node->type == ARRAY_AST;
}

void codeGenForIdentOrNumber(Node *node,char *reg, FILE *fp){

  if(node->type == IDENT_AST){
    int offset = getOffset(node);
    fprintf(fp, "        lw $%s, %d($t0)\n", reg, offset);
    fprintf(fp, "        nop\n");
  }else if(node->type == NUM_AST){
    fprintf(fp, "        li $%s, %d\n", reg, node->ivalue);
  }else if(node->type == ARRAY_AST){
    int offset = getOffset(node);
    Var *v = getVar(node);
    codeGenForArrayAssign(node->child->child,fp, offset, 0, v);
    fprintf(fp, "        addi $t1, $t1, %d\n", offset);
    fprintf(fp, "        add $t1, $t1, $t0\n");
    fprintf(fp, "        lw $%s, 0($t1)\n", reg);
    fprintf(fp, "        nop\n");
  }
}

int getOffset(Node *node){
  int i;
  for(i = 0; i <num_vars; i++){
    if(!strcmp(variables[i]->name, node->variable)){
      return variables[i]->offset;
    }
  }
  fprintf(stderr,"Compile Error! undefined variable: %s\n",node->variable);
  exit(1);
  return 0;
}

int main(int argc, char* argv[]){
    int result;
    result = yyparse();
    if(!result && parse_result != NULL){
        printTree(parse_result, 0);
        genAsmFile(parse_result, argv[1]);
    }
    return 0;
}