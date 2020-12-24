%{
#include <stdio.h>
#include "base.tab.h"
%}
%token DEFINE
%token ARRAY
%token WHILE
%token IF
%token ELSE
%token SEMIC
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
%token EQ
%token LT
%token GT
%token IDENT
%token NUMBER
%%
program : declarations statements;

declarations : decl_statement declarations | decl_statement;

decl_statement : DEFINE IDENT SEMIC
 | ARRAY IDENT L_BRACKET NUMBER R_BRACKET SEMIC;

statements : statement statements | statement;

statement : assignment_stmt | loop_stmt | cond_stmt;

assignment_stmt : IDENT ASSIGN expression SEMIC
                | IDENT L_BRACKET NUMBER R_BRACKET ASSIGN expression SEMIC;

expression : expression add_op term | term;

term : term mul_op factor | factor;

factor : var | L_PARAN expression R_PARAN;

add_op : ADD | SUB;

mul_op : MUL | DIV;

var : IDENT | NUMBER | IDENT L_BRACKET NUMBER R_BRACKET;

loop_stmt : WHILE L_PARAN condition R_PARAN L_BRACE statements R_BRACE;

cond_stmt : IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE | 
            IF L_PARAN condition R_PARAN L_BRACE statements R_BRACE ELSE L_BRACE statements R_BRACE;

condition : expression cond_op expression;

cond_op : EQ | LT | GT ;

%%
int main(void){
 if (yyparse()) {
 fprintf(stderr, "Error ! Error ! Error !\n");
 return 1;
 }
}