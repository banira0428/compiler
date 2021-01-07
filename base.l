%{
#include "base.tab.h"
#include <string.h>
%}
%%
define { return DEFINE;}
array { return ARRAY;}
while { return WHILE;}
for { return FOR; }
if { return IF;}
else { return ELSE;}
funccall { return FUNCCALL;}
func { return FUNC;}
break { return BREAK;}
; { return SEMIC; }
, { return COMMA; }
\[ { return L_BRACKET; }
] { return R_BRACKET; }
\( { return L_PARAN; }
\) { return R_PARAN; }
\{ { return L_BRACE; }
\} { return R_BRACE; }
= { return ASSIGN; }
\+ { return ADD; }
- { return SUB; }
\* { return MUL; }
\/ { return DIV; }
\% { return SUR; }
== { return EQ; }
\< { return LT; }
\<= { return LTE; }
> { return GT; }
>= { return GTE; }
\+\+ { return INC; }
-- { return DEC; }


[a-zA-Z][a-zA-Z0-9]* {
    yylval.sp = (char*)malloc(sizeof(char) * yyleng);
    strncpy(yylval.sp, yytext, yyleng);
    return IDENT; }
[0-9]+ { yylval.ival = atoi(yytext); return NUMBER; }
[ \t\n];
%%