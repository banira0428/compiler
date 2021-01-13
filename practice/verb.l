%{
  char *chars = "", isVerb = 0;
%}
%%
[^(\t\n )]+   {if ((strcmp( yytext, "is") == 0) ||
            (strcmp( yytext, "am") == 0) ||
            (strcmp( yytext,"are") == 0) ||
            (strcmp( yytext, "were") == 0) ||
            (strcmp( yytext, "was") == 0))
            { printf("%s: is a verb.\n", yytext); }
            else { printf("%s: is not a verb.\n", yytext); }} 
%%
int main(void) {
  yylex();
  return 0;
}