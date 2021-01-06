typedef enum {
    IDENT_AST, // 変数のノード型
    NUM_AST, // 整数のノード型
    ASSIGN_AST, // 代入文の=のノード型
    PLUS_AST, // 加算演算子のノード型
    MINUS_AST, // 減算演算子のノード型
    WHILE_AST, // while のノード型
    IF_AST, // if のノード型
    FACTOR_AST,
    FORE_INC_FACTOR_AST,
    TERM_AST,
    ADD_EXPRESSION_AST,
    INC_EXPRESSION_AST,
    EXPRESSSION_AST,
    STATEMENT_AST,
    STATEMENTS_AST,
    DECL_IDENTS_AST,
    DEFINE_AST,
    ARRAY_DEFINE_AST,
    DECLARATIONS_AST,
    PROGRAM_AST,
} NType;

typedef struct node{
  NType type;
  int ivalue;
  char* variable;
  struct node *child;
  struct node *brother;
} Node;