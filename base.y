%{
#include <stdio.h>
#include "base.tab.h"
#include "build_node.h"

extern Node *parse_result;
%}

%union{
 struct node *np; // 抽象構文木
 int ival; // 数
 char* sp; // 変数名
}

%token DEFINE
%token ARRAY
%token WHILE
%token FOR
%token IF
%token ELSE
%token FUNC
%token FUNCCALL
%token BREAK
%token SEMIC
%token COMMA
%token L_BRACKET
%token R_BRACKET
%token L_PARAN
%token R_PARAN
%token L_BRACE
%token R_BRACE
%token ASSIGN
%token ADD
%token SUB
%token MUL
%token DIV
%token SUR
%token EQ
%token LT
%token LTE
%token GT
%token GTE
%token INC
%token DEC
%token <sp>IDENT
%token <ival>NUMBER
%type <np> declarations decl_statement decl_idents
%type <np> statements statement assignment_stmt
%type <np> expression inc_expression add_expression term fore_inc_factor factor
%type <np> var array_index func_stmt params param funccall_stmt args loop_stmt
%type <np> while_stmt for_stmt for_assign for_cond for_expr cond_stmt
%type <np> if_block elif_block else_block condition break_statement
%type <ival> add_op mul_op inc_op cond_op
%%
program : declarations statements { parse_result = build_nodes(PROGRAM_AST,2, $1, $2); }
        | declarations { parse_result = build_nodes(PROGRAM_AST,1, $1); };

declarations : decl_statement declarations { $$ = build_nodes(DECLARATIONS_AST, 2, $1, $2); };
    | decl_statement { $$ = build_nodes(DECLARATIONS_AST,1, $1); };

decl_statement : DEFINE decl_idents SEMIC { $$ = build_nodes(DEFINE_AST,1, $2); }
    | ARRAY IDENT array_index SEMIC { $$ = build_nodes(ARRAY_DEFINE_AST, 1,build_array_node(ARRAY_AST, $2, $3)); }
    | func_stmt { $$ = build_nodes(FUNC_DEFINE_AST,1, $1); };

decl_idents : IDENT COMMA decl_idents { $$ = build_nodes(DECL_IDENTS_AST,2, build_ident_node(IDENT_AST,$1), $3); };
    | IDENT { $$ = build_nodes(DECL_IDENTS_AST,1, build_ident_node(IDENT_AST,$1)); };

statements : statement statements { $$ = build_nodes(STATEMENTS_AST,2, $1, $2); }
    | statement { $$ = build_nodes(STATEMENTS_AST,1, $1); }
    ;
    
statement : assignment_stmt { $$ = build_nodes(STATEMENT_AST, 1, $1); }
    | loop_stmt { $$ = build_nodes(STATEMENT_AST, 1, $1); }
    | cond_stmt { $$ = build_nodes(STATEMENT_AST, 1, $1); }
    | funccall_stmt { $$ = build_nodes(STATEMENT_AST, 1, $1); }
    | break_statement { $$ = build_nodes(STATEMENT_AST, 1, $1); };

assignment_stmt : IDENT ASSIGN expression SEMIC { $$ = build_nodes(ASSIGN_AST,2, build_ident_node(IDENT_AST,$1), $3); }
                | IDENT array_index ASSIGN expression SEMIC { $$ = build_nodes(ASSIGN_AST,2, build_array_node(ARRAY_AST, $1, $2), $4); }
                ;

expression : expression SUR inc_expression { $$ = build_nodes(SUR_EXPRESSION_AST, 2, $1, $3); }
    | inc_expression
    ;

inc_expression : add_expression inc_op  { $$ = build_nodes(INC_EXPRESSION_AST, 1, $1); }
    | add_expression
    ;

add_expression : add_expression add_op term 
    { 
        if($2 == OP_ADD){
            $$ = build_nodes(PLUS_AST, 2, $1, $3); 
        }else{
            $$ = build_nodes(MINUS_AST, 2, $1, $3); 
        }
    }
    | inc_op term 
    { 
        if($1 == OP_INC){
            $$ = build_nodes(INC_AST, 1, $2); 
        }else{
            $$ = build_nodes(DEC_AST, 1, $2);
        }
    }
    | term 
    ;

term : term mul_op fore_inc_factor 
    { 
        if($2 == OP_MUL){
            $$ = build_nodes(MUL_AST, 2, $1, $3); 
        }else{
            $$ = build_nodes(DIV_AST, 2, $1, $3); 
        }
    }
    | fore_inc_factor 
    ;

fore_inc_factor : inc_op factor 
    { 
        if($1 == OP_INC){
            $$ = build_nodes(INC_AST, 1, $2); 
        }else{
            $$ = build_nodes(DEC_AST, 1, $2);
        }
    }
    | factor 
    ;

factor : var 
    | L_PARAN expression R_PARAN { $$ = build_nodes(FACTOR_AST, 1, $2); }
    ;

add_op : ADD { $$ = OP_ADD;}
| SUB { $$ = OP_MINUS;};

mul_op : MUL { $$ = OP_MUL;}
| DIV { $$ = OP_DIV;};

inc_op : INC { $$ = OP_INC;}
        | DEC { $$ = OP_DEC;};

var : IDENT { $$ = build_ident_node(IDENT_AST,$1);} 
    | NUMBER { $$ = build_num_node(NUM_AST, $1);} 
    | IDENT array_index { $$ = build_array_node(ARRAY_AST, $1, $2);}
    ; 

array_index : array_index L_BRACKET expression R_BRACKET { $$ = build_nodes(ARRAY_INDEX_AST, 2, $1, $3);}
| L_BRACKET expression R_BRACKET { $$ = build_nodes(ARRAY_INDEX_AST, 1, $2); }
;

func_stmt : FUNC IDENT L_PARAN params R_PARAN L_BRACE declarations statements R_BRACE { $$ = build_nodes(FUNC_AST, 4, build_ident_node(IDENT_AST,$2), $4, $7, $8);}
;

params : param COMMA params { $$ = build_nodes(PARAMS_AST, 2, $1, $3);}
| param 
| { $$ = build_nodes(PARAMS_AST, 0);};

param : DEFINE IDENT { $$ = build_nodes(PARAM_AST, 1, build_ident_node(IDENT_AST,$2));}
 | ARRAY IDENT L_BRACKET R_BRACKET { $$ = build_nodes(PARAM_AST, 1, build_ident_node(IDENT_AST,$2));}
 ;

funccall_stmt : FUNCCALL IDENT L_PARAN args R_PARAN SEMIC { $$ = build_nodes(FUNCCALL_AST, 2, build_ident_node(IDENT_AST,$2), $4);}
;

args : expression COMMA args { $$ = build_nodes(ARGS_AST, 2, $1, $3);}
| expression { $$ = build_nodes(ARGS_AST, 1, $1);}
| ;

loop_stmt : while_stmt | for_stmt;

while_stmt : WHILE L_PARAN condition R_PARAN L_BRACE statements R_BRACE { $$ = build_nodes(WHILE_AST, 2, $3, $6);}
            | WHILE L_PARAN condition R_PARAN SEMIC { $$ = build_nodes(WHILE_AST, 1, $3);};

for_stmt : FOR L_PARAN for_assign for_cond for_expr R_PARAN L_BRACE statements R_BRACE { $$ = build_nodes(FOR_AST, 4, $3, $4, $5, $8);};

for_assign : assignment_stmt { $$ = build_nodes(FOR_ASSIGN_AST, 1, $1); }
| SEMIC { $$ = build_nodes(FOR_ASSIGN_AST, 0); };

for_cond : condition SEMIC { $$ = build_nodes(FOR_COND_AST, 1, $1); }
| SEMIC { $$ = build_nodes(FOR_COND_AST, 0); };

for_expr : expression { $$ = build_nodes(FOR_EXPR_AST, 1, $1); }
| { $$ = build_nodes(FOR_EXPR_AST, 0); };

cond_stmt : if_block { $$ = build_nodes(IF_AST, 1, $1); }
            | if_block else_block { $$ = build_nodes(IF_AST, 2, $1, $2); }
            | IF L_PARAN condition R_PARAN statement { $$ = build_nodes(IF_AST, 2, $3, $5); }
            ;

if_block : IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE { $$ = build_nodes(IF_BLOCK_AST, 2, $3, $6); };

elif_block : ELSE if_block { $$ = build_nodes(ELIF_BLOCK_AST, 1, $2); };

else_block : elif_block else_block { $$ = build_nodes(ELSE_BLOCK_AST, 2, $1, $2); }
    | ELSE L_BRACE statements R_BRACE { $$ = build_nodes(ELSE_BLOCK_AST, 1, $3); };

condition : expression cond_op expression 
{ 
    if($2 == OP_EQ){
        $$ = build_nodes(EQ_AST, 2, $1, $3); 
    }else if($2 == OP_LT){
        $$ = build_nodes(LT_AST, 2, $1, $3); 
    }else if($2 == OP_GT){
        $$ = build_nodes(GT_AST, 2, $1, $3); 
    }else if($2 == OP_LTE){
        $$ = build_nodes(LTE_AST, 2, $1, $3); 
    }else if($2 == OP_GTE){
        $$ = build_nodes(GTE_AST, 2, $1, $3); 
    }
};

cond_op : EQ { $$ = OP_EQ;}
        | LT { $$ = OP_LT;}
        | GT { $$ = OP_GT;}
        | LTE { $$ = OP_LTE;}
        | GTE { $$ = OP_GTE;};

break_statement : BREAK SEMIC { $$ = build_nodes(BREAK_AST, 0); };