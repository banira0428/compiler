%{
#include <stdio.h>
#include "base.tab.h"
#include "AST.h"

extern Node *parse_result;
%}
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
%token IDENT
%token NUMBER
%%
program : declarations statements { parse_result = build_nodes(PROGRAM_AST,2, $1, $2); }
        | declarations { parse_result = build_nodes(PROGRAM_AST,1, $1); };

declarations : decl_statement declarations { $$ = build_nodes(DECLARATIONS_AST, 2, $1, $2); };
    | decl_statement { $$ = build_nodes(DECLARATIONS_AST,1, $1); };

decl_statement : DEFINE decl_idents SEMIC { $$ = build_nodes(DEFINE_AST,1, $2); }
    | ARRAY IDENT array_index SEMIC { $$ = build_nodes(ARRAY_DEFINE_AST,1, $2); }
    | func_stmt { $$ = build_nodes(ARRAY_DEFINE_AST,1, $2); };

decl_idents : IDENT COMMA decl_idents { $$ = build_nodes(DECL_IDENTS_AST,2, $1, $3); };
    | IDENT { $$ = build_nodes(DECL_IDENTS_AST,1, $1); };

statements : statement statements { $$ = build_nodes(STATEMENTS_AST,2, $1, $2); }
    | statement { $$ = build_nodes(STATEMENTS_AST,1, $1); }
    ;

statement : assignment_stmt { $$ = build_nodes(STATEMENT_AST, 1, $1); }
    | loop_stmt { $$ = build_nodes(STATEMENT_AST, 1, $1); }
    | cond_stmt { $$ = build_nodes(STATEMENT_AST, 1, $1); }
    | funccall_stmt { $$ = build_nodes(STATEMENT_AST, 1, $1); }
    | break_statement { $$ = build_nodes(STATEMENT_AST, 1, $1); };

assignment_stmt : IDENT ASSIGN expression SEMIC { $$ = build_nodes(ASSIGN_AST,2, build_ident_node(IDENT_AST,"a"), $3); }
                | IDENT array_index ASSIGN expression SEMIC 
                ;

expression : expression SUR inc_expression
    | inc_expression { $$ = build_nodes(EXPRESSSION_AST, 1, $1); }
    ;

inc_expression : add_expression inc_op 
    | add_expression { $$ = build_nodes(INC_EXPRESSION_AST, 1, $1); }
    ;

add_expression : add_expression add_op term 
    | inc_op term 
    | term { $$ = build_nodes(ADD_EXPRESSION_AST, 1, $1); }
    ;

term : term mul_op fore_inc_factor 
    | fore_inc_factor { $$ = build_nodes(TERM_AST, 1, $1); }
    ;

fore_inc_factor : INC factor 
    | factor { $$ = build_nodes(FORE_INC_FACTOR_AST, 1, $1); }
    ;

factor : var { $$ = build_nodes(FACTOR_AST, 1, $1); }
    | L_PARAN expression R_PARAN;

inc_op : INC | DEC;

add_op : ADD | SUB;

mul_op : MUL | DIV;

var : IDENT { $$ = build_nodes(IDENT_AST, 1, $1);} 
    | NUMBER { $$ = build_num_node(NUM_AST, $1);} 
    | IDENT array_index ;

array_index : array_index L_BRACKET expression R_BRACKET | L_BRACKET expression R_BRACKET;

func_stmt : FUNC IDENT L_PARAN params R_PARAN L_BRACE program R_BRACE;

params : param COMMA params | param | ;

param : DEFINE IDENT | ARRAY IDENT L_BRACKET R_BRACKET;

funccall_stmt : FUNCCALL IDENT L_PARAN args R_PARAN SEMIC;

args : expression COMMA args | expression;

loop_stmt : while_stmt | for_stmt;

while_stmt : WHILE L_PARAN condition R_PARAN L_BRACE statements R_BRACE
            | WHILE L_PARAN condition R_PARAN SEMIC ;

for_stmt : FOR L_PARAN for_assign for_cond for_expr R_PARAN L_BRACE statements R_BRACE;

for_assign : assignment_stmt | SEMIC ;

for_cond : condition SEMIC | SEMIC ;

for_expr : expression | ;

cond_stmt : if_block | 
            if_block else_block;

if_block : IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE | IF L_PARAN condition R_PARAN statement

elif_block : ELSE if_block;

else_block : elif_block else_block | ELSE L_BRACE statements R_BRACE;

condition : expression cond_op expression;

cond_op : EQ | LT | GT | LTE | GTE;

break_statement : BREAK SEMIC