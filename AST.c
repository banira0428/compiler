#include "AST.h"

Node *parse_result = NULL;

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

    Var *variables[10];
    codeGen(node, fp, variables, "$t0");

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

void codeGenForArrayAssign(Node *node, FILE *fp, int offset, int depth, Var *v, Var *vars[], char *src_reg){  // param = ARRAY_INDEX

  if(node->type == IDENT_AST){

    int n;
    int size = 4;
    for(n = depth + 1; n < 3; n++){
      if(v->sizes[n] != 0){
        size = size * v->sizes[n];
      }
    }

    codeGenForIdentOrNumber(node, "t1", fp, vars, src_reg);
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
    codeGenForArrayAssign(node->child, fp, offset, depth, v, vars, src_reg);
    fprintf(fp, "        add $t4, $t1, $zero\n");
    codeGenForArrayAssign(node->brother, fp, offset, depth + 1, v, vars, src_reg);
    fprintf(fp, "        add $t1, $t1, $t4\n");
  }
}

Var* getVar(Node *node, Var *vars[], char *src_reg){
  int i;
  for(i = 0; vars[i] != NULL; i++){
    if(!strcmp(vars[i]->name, node->variable)){
      return vars[i];
    }
  }
  fprintf(stderr,"Compile Error! undefined variable: %s\n",node->variable);
  exit(0);
  return NULL;
}

void codeGen(Node *node, FILE *fp, Var *vars[], char *src_reg){

  if(node->type == DECL_IDENTS_AST){

    Var *v;
    v = (Var *)malloc(sizeof(Var));
    v->offset = offset_vars;
    v->name = node->child->variable;
    v->size = 1;
    int i;
    for(i=0; vars[i] != NULL; i++);
    vars[i] = v;
    offset_vars+= v->size * 4;
  }else if(node->type == ARRAY_DEFINE_AST){
    Var *v;
    v = (Var *)malloc(sizeof(Var));
    v->offset = offset_vars;
    v->name = node->child->variable;
    v->size = getArraySize(node->child->child,v, 0);

    int i;
    for(i=0; vars[i] != NULL; i++);
    vars[i] = v;
    offset_vars+= v->size * 4;

    if(node->brother != NULL){
      codeGen(node->brother, fp, vars, src_reg);
    }

  }else if(node->type == ASSIGN_AST){

    codeGenForExpr(node->child->brother, fp, vars, src_reg);
    codeGenForAssign(node, fp, vars, src_reg);
    
  }else if(node->type == WHILE_AST){
    int n = num_loops;
    num_loops++;

    fprintf(fp, "$LOOP%d:\n",n);

    codeGenForCondOp(node->child, fp, vars, src_reg);
    codeGenForBranch(node->child,fp, "$EXIT", n);

    if(node->child->brother != NULL){
        codeGen(node->child->brother,fp, vars, src_reg);
    }
    fprintf(fp, "        j $LOOP%d\n", n);
    fprintf(fp, "        nop\n");
    fprintf(fp, "$EXIT%d:\n",n);

  }else if(node->type == FOR_AST){
    int n = num_loops;
    num_loops++;

    if(node->child->child != NULL){
        codeGenForExpr(node->child->child->child->brother, fp, vars, src_reg);
        codeGenForAssign(node->child->child, fp, vars, src_reg);
    }

    fprintf(fp, "$LOOP%d:\n",n);

    if(node->child->brother->child != NULL){
      codeGenForCondOp(node->child->brother->child, fp, vars, src_reg);
      codeGenForBranch(node->child->brother->child,fp,"$EXIT", n);
    }

    if(node->child->brother->brother->brother != NULL){
      codeGen(node->child->brother->brother->brother,fp, vars, src_reg);
    }
    if(node->child->brother->brother->child != NULL){
      codeGenForExpr(node->child->brother->brother->child,fp, vars, src_reg);
    }
    fprintf(fp, "        j $LOOP%d\n", n);
    fprintf(fp, "        nop\n");
    fprintf(fp, "$EXIT%d:\n",n);
  
  }else if(node->type == IF_BLOCK_AST){

    codeGenForIf(node, fp, vars, src_reg);

    fprintf(fp, "$END%d:\n", num_if_blocks);
    num_if_blocks++;

  }else if(node->type == INC_AST){
    codeGenForIdentOrNumber(node->child, "v0", fp, vars, src_reg);
    fprintf(fp, "        addi $v0, $v0, 1\n");
    codeGenForAssign(node, fp, vars, src_reg);
  }else if(node->type == DEC_AST){
    codeGenForIdentOrNumber(node->child, "v0", fp, vars, src_reg);
    fprintf(fp, "        addi $v0, $v0, -1\n");
    codeGenForAssign(node, fp, vars, src_reg);
  }else if(node->type == FUNCCALL_AST){

    codeGenForArgs(node->child->brother, 0, fp, vars, src_reg);
    fprintf(fp, "        jal _%s\n", node->child->variable);
    fprintf(fp, "        nop\n");
    
  }else if(node->type == FUNC_AST){
    if(strcmp(node->child->variable, "main")){
      fprintf(fp, "_%s:\n", node->child->variable);
    }

    int stack_size = 4;
    Var *l_variables[100] = {NULL};

    int param_num = countParams(node->child->brother, l_variables, 0, fp);
    int local_var_num = countLocalVars(node->child->brother->brother, l_variables, param_num, fp);
    stack_size += (param_num + local_var_num) * 4;

    fprintf(fp, "        addi $sp, $sp, %d\n", -1 * stack_size);
    fprintf(fp, "        sw   $ra, 0($sp)\n");

    codeGenParams(node->child->brother, l_variables, 0, fp);
    codeGen(node->child->brother, fp, l_variables, "$sp");

    fprintf(fp, "        lw   $ra, 0($sp)\n");
    fprintf(fp, "        addi $sp, $sp, %d\n", stack_size);
    fprintf(fp, "        jr   $ra\n");
    
  }else if(node->type == BREAK_AST){
    fprintf(fp, "        j  $EXIT0\n");
    fprintf(fp, "        nop\n");
  
  }else if(node->type == SIMPLE_IF_AST){

    codeGenForIf(node, fp, vars, src_reg);
    fprintf(fp, "$END%d:\n", num_if_blocks);
    num_if_blocks++;

  }else{
    if(node->child != NULL){
      codeGen(node->child, fp, vars, src_reg);
    }
    if(node->brother != NULL){
      codeGen(node->brother, fp, vars, src_reg);
    }
  }
}

void codeGenForArgs(Node *node, int index, FILE *fp, Var *vars[], char *src_reg){ // node->type == ARGS

  if(node->child->type == IDENT_AST){
    Var *v = getVar(node->child, vars, src_reg);
    if(v->size > 1){

      if(!v->isAddress){

        int offset = getOffset(node->child, vars, src_reg);
        fprintf(fp, "        addi $t1, %s, %d\n", src_reg, offset);
        fprintf(fp, "        add $v0, $t1, $zero\n", index);

      }

    }else{
      codeGenForExpr(node->child, fp, vars, src_reg);
    }
  }else{
    codeGenForExpr(node->child, fp, vars, src_reg);
  }
  fprintf(fp, "        add $a%d, $v0, $zero\n", index);

  if(node->child->brother != NULL){
    codeGenForArgs(node->child->brother, index+1, fp, vars, src_reg);
  }
}

void codeGenParams(Node *node, Var *vars[], int index, FILE *fp){
  if(node->child == NULL){
    return;
  }else if(node->child->type == PARAM_AST && node->child->brother == NULL){

    if(node->child->child->type == IDENT_AST){

      Var *v;
      v = (Var *)malloc(sizeof(Var));
      v->offset = 4 + index*4;
      v->name = node->child->child->variable;
      v->size = 1;
      vars[index] = v;

    }else if(node->child->child->type == ARRAY_AST){

      Var *v;
      v = (Var *)malloc(sizeof(Var));
      v->offset = 4 + index*4;
      v->name = node->child->child->variable;
      v->size = 1;
      v->isAddress = 1;
      vars[index] = v;
    }

    fprintf(fp, "        sw   $a%d, %d($sp)\n",index, 4 + index*4);
    return;
  }else{

    if(node->child->child->type == IDENT_AST){
      
      Var *v;
      v = (Var *)malloc(sizeof(Var));
      v->offset = 4 + index*4;
      v->name = node->child->child->variable;
      v->size = 1;
      vars[index] = v;

    }else if(node->child->child->type == ARRAY_AST){

      Var *v;
      v = (Var *)malloc(sizeof(Var));
      v->offset = 4 + index*4;
      v->name = node->child->child->variable;
      v->size = 1;
      v->isAddress = 1;
      vars[index] = v;
    }

    fprintf(fp, "        sw   $a%d, %d($sp)\n",index, 4 + index*4);
    return codeGenParams(node->child->brother, vars, index + 1, fp);
  }
}

int countParams(Node *node, Var *vars[], int index, FILE *fp){
  if(node->child == NULL){
    return 0;
  }else if(node->child->type == PARAM_AST && node->child->brother == NULL){
    return 1;
  }else{
    return countParams(node->child->brother, vars, index + 1, fp) + 1;
  }
}

int countLocalVars(Node *node, Var *vars[], int index, FILE *fp){ // DECLARATIONS
  if(node->child == NULL){
    return 0;
  }else if(node->child->type == DEFINE_AST && node->child->brother == NULL){
    return countIdents(node->child->child, vars, index, fp);
  }else if(node->child->type == ARRAY_DEFINE_AST && node->child->brother == NULL){
    return countIdents(node->child->child, vars, index, fp);
  }else{
    int count = countIdents(node->child->child, vars, index, fp);
    return count + countLocalVars(node->child->brother, vars, index + count, fp);
  }
}

int countIdents(Node *node, Var *vars[], int index, FILE *fp){ // DECL_IDENTS
  if(node->child == NULL){
    return 0;
  }else if(node->child->type == IDENT_AST && node->child->brother == NULL){
    
    Var *v;
    v = (Var *)malloc(sizeof(Var));
    v->offset = 4 + index*4;
    v->name = node->child->variable;
    v->size = 1;
    vars[index] = v;

    return 1;
  }else if(node->type == ARRAY_AST && node->child->brother == NULL){
    
    Var *v;
    v = (Var *)malloc(sizeof(Var));
    v->offset = 4 + index*4;
    v->name = node->variable;
    v->size = getArraySize(node->child,v, 0);
    vars[index] = v;

    return v->size;

  }else{

    int count = 0;

    if(node->type == ARRAY_AST){

      Var *v;
      v = (Var *)malloc(sizeof(Var));
      v->offset = 4 + index*4;
      v->name = node->variable;
      v->size = getArraySize(node->child,v, 0);

      int i;
      vars[index] = v;
      count = v->size;

    }else{

      Var *v;
      v = (Var *)malloc(sizeof(Var));
      v->offset = 4 + index*4;
      v->name = node->child->variable;
      v->size = 1;
      vars[index] = v;
      count = 1;

    }

    return countIdents(node->child->brother, vars, index + 1, fp) + count;
  }
}

void codeGenForCondOp(Node *node, FILE *fp, Var *vars[], char *src_reg){
  if(isCondOperator(node)){
    codeGenForExpr(node->child, fp, vars, src_reg);
    fprintf(fp, "        add $t4, $v0, $zero\n");

    codeGenForExpr(node->child->brother, fp, vars, src_reg);
    
    fprintf(fp, "        add $t1, $t4, $zero\n");
    fprintf(fp, "        add $t3, $v0, $zero\n");

    //todo 命令セットが足りなくて使えない 
    //codeGenForCondOperate(node, fp);
  }
}

void codeGenForAssign(Node *node, FILE *fp, Var *vars[], char *src_reg){ // param: ASSIGN_AST
    int offset = getOffset(node->child, vars, src_reg);
    Var *v = getVar(node->child, vars, src_reg);

    if(node->child->type == IDENT_AST){
      fprintf(fp, "        sw $v0, %d(%s)\n", offset, src_reg);
    }else if(node->child->type == ARRAY_AST){

      if(v->isAddress){
        fprintf(fp, "## 参照渡しの配列に代入\n");
        codeGenForArrayAssign(node->child->child->child,fp, offset, 0, v, vars, src_reg);
        fprintf(fp, "        lw $t3, %d(%s)\n", offset, src_reg);
        fprintf(fp, "        nop\n");
        fprintf(fp, "        add $t3, $t1, $t3\n", offset, src_reg);
        fprintf(fp, "        sw $v0, 0($t3)\n");
        fprintf(fp, "## 参照渡しの配列に代入終わり\n");
      }else{

        codeGenForArrayAssign(node->child->child->child, fp, offset, 0, v, vars, src_reg);

        fprintf(fp, "        addi $t1, $t1, %d\n", offset);
        fprintf(fp, "        add $t1, $t1, %s\n", src_reg);
        fprintf(fp, "        sw $v0, 0($t1)\n");

      }
    }
}

void codeGenForIf(Node *node, FILE *fp, Var *vars[], char *src_reg){

    int n = num_branches;
    num_branches++;

    codeGenForCondOp(node->child, fp, vars, src_reg);
    codeGenForBranch(node->child,fp, "$L", n);
    codeGen(node->child->brother,fp, vars, src_reg);
    fprintf(fp, "        j $END%d\n", num_if_blocks);
    fprintf(fp, "$L%d:\n", n);

    if(node->brother != NULL){
      if(node->brother->type == ELSE_BLOCK_AST){
        codeGenForElse(node->brother, fp, vars, src_reg);
      }
    }
}

void codeGenForElse(Node *node, FILE *fp, Var *vars[], char *src_reg){
  if(node->child->type == STATEMENTS_AST){
    codeGen(node->child,fp, vars, src_reg);
  }else if(node->child->type == ELIF_BLOCK_AST){
    codeGenForIf(node->child->child, fp, vars, src_reg);
    if(node->child->brother->type == ELSE_BLOCK_AST){
      codeGenForElse(node->child->brother,fp, vars, src_reg);
    }
  }
}

void codeGenForExprPair(Node *node,FILE *fp, Var *vars[], char *src_reg){

  if(isOperator(node)){
    Expr *expr;
    expr = (Expr *)malloc(sizeof(Expr));
    expr->type = node->type;
    expr->result = heap_addr;
    heap_addr += 4;

    codeGenForExprPart(node->child,fp, "t1",&(expr->left), vars, src_reg);
    heap_addr += 4;
    codeGenForExprPart(node->child->brother,fp,"t3", &(expr->right), vars, src_reg);
    heap_addr += 4;

    fprintf(fp, "        lw $t1, %d(%s)\n", offset_vars + expr->left, "$t0");
    fprintf(fp, "        lw $t3, %d(%s)\n", offset_vars + expr->right, "$t0");
    fprintf(fp, "        nop\n");

    codeGenForOperate(node, fp);

    fprintf(fp, "        sw $v0, %d(%s)\n", offset_vars + expr->result, "$t0");
    fprintf(fp, "        nop\n");
  }else{
    if(node->child != NULL){
      codeGenForExprPair(node->child, fp, vars, src_reg);
    }
  }
}

void codeGenForExprPart(Node *node,FILE *fp,char *reg, int *result, Var *vars[], char *src_reg){

  *result = heap_addr;
  if(isOperator(node)){
    codeGenForExprPair(node, fp, vars, src_reg);
  }else if(isIdentOrNumber(node)){
    codeGenForIdentOrNumber(node, reg, fp, vars, src_reg);
    fprintf(fp, "        sw $%s, %d(%s)\n", reg, offset_vars + heap_addr, "$t0");
  }else{
    codeGenForExprPair(node, fp, vars, src_reg);
  }
}

void codeGenForExpr(Node *node, FILE *fp, Var *vars[], char *src_reg){
  if(isOperator(node)){

    codeGenForExprPair(node, fp, vars, src_reg);
    heap_addr = 4;
    
  }else if(isIdentOrNumber(node)){
    codeGenForIdentOrNumber(node, "v0", fp, vars, src_reg);
  }else if(node->type == INC_AST){
    codeGenForIdentOrNumber(node->child, "v0", fp, vars, src_reg);
    fprintf(fp, "        addi $v0, $v0, 1\n");
    codeGenForAssign(node, fp, vars, src_reg);
  }else if(node->type == DEC_AST){
    codeGenForIdentOrNumber(node->child, "v0", fp, vars, src_reg);
    fprintf(fp, "        addi $v0, $v0, -1\n");
    codeGenForAssign(node, fp, vars, src_reg);
  }else{
    codeGenForExpr(node->child, fp, vars, src_reg);
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
    fprintf(fp, "        addi $t1, $t1, 1\n");
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

void codeGenForIdentOrNumber(Node *node,char *reg, FILE *fp, Var *vars[], char *src_reg){

  if(node->type == IDENT_AST){
    int offset = getOffset(node, vars, src_reg);
    if(offset != -1){
      fprintf(fp, "        lw $%s, %d(%s)\n", reg, offset, src_reg);
      fprintf(fp, "        nop\n");
    }    
  }else if(node->type == NUM_AST){
    fprintf(fp, "        li $%s, %d\n", reg, node->ivalue);
  }else if(node->type == ARRAY_AST){
    int offset = getOffset(node, vars, src_reg);
    Var *v = getVar(node, vars, src_reg);

    if(v->isAddress){
      codeGenForArrayAssign(node->child->child,fp, offset, 0, v, vars, src_reg);
      fprintf(fp, "        lw $t3, %d(%s)\n", offset, src_reg);
      fprintf(fp, "        nop\n");
      fprintf(fp, "        add $t3, $t1, $t3\n", offset, src_reg);
      fprintf(fp, "        lw $%s, 0($t3)\n", reg);
      fprintf(fp, "        nop\n");
    }else{

      codeGenForArrayAssign(node->child->child,fp, offset, 0, v, vars, src_reg);
      fprintf(fp, "        addi $t1, $t1, %d\n", offset);
      fprintf(fp, "        add $t1, $t1, %s\n", src_reg);
      fprintf(fp, "        lw $%s, 0($t1)\n", reg);
      fprintf(fp, "        nop\n");

    }
  }
}

int getOffset(Node *node, Var *vars[], char *src_reg){
  int i;
  for(i = 0; vars[i] != NULL; i++){
    if(!strcmp(vars[i]->name, node->variable)){
      return vars[i]->offset;
    }
  }
  return -1;
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