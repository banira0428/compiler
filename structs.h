typedef enum {
    IDENT_AST, // 変数のノード型
    NUM_AST, // 整数のノード型
    ASSIGN_AST, // 代入文の=のノード型
    PLUS_AST, // 加算演算子のノード型
    MINUS_AST, // 減算演算子のノード型
    MUL_AST,
    DIV_AST,
    SUR_AST,
    INC_AST,
    DEC_AST,
    EQ_AST,
    LT_AST,
    LTE_AST,
    GT_AST,
    GTE_AST,
    WHILE_AST, // while のノード型
    IF_AST, // if のノード型
    IF_BLOCK_AST,
    ELIF_BLOCK_AST,
    ELSE_BLOCK_AST,
    ARRAY_INDEX_AST,
    ARRAY_AST,
    CONDITION_AST,
    FOR_ASSIGN_AST,
    FOR_COND_AST,
    FOR_EXPR_AST,
    FOR_AST,
    FUNC_AST,
    FUNCCALL_AST,
    BREAK_AST,
    PARAMS_AST,
    PARAM_AST,
    ARGS_AST,
    ARG_AST,
    FACTOR_AST,
    FORE_INC_FACTOR_AST,
    TERM_AST,
    ADD_EXPRESSION_AST,
    INC_EXPRESSION_AST,
    SUR_EXPRESSION_AST,
    EXPRESSSION_AST,
    STATEMENT_AST,
    STATEMENTS_AST,
    DECL_IDENTS_AST,
    DEFINE_AST,
    FUNC_DEFINE_AST,
    ARRAY_DEFINE_AST,
    DECLARATIONS_AST,
    PROGRAM_AST,
} NType;

typedef enum {
  OP_ADD,
  OP_MINUS,
  OP_MUL,
  OP_DIV,
  OP_SUR,
  OP_INC,
  OP_DEC,
  OP_EQ,
  OP_LT,
  OP_LTE,
  OP_GT,
  OP_GTE
} OP;

typedef struct node{
  NType type;
  int ivalue;
  char* variable;
  struct node *child;
  struct node *brother;
} Node;

typedef struct variable {
  char* name;
  int offset;
  int size;
  int sizes[3];
} Var;

typedef struct expression {
  NType type;
  int result;
  int left;
  int right;
} Expr;