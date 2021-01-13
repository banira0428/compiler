%{
 int num_lines = 0, num_chars = 0, char_count = 0, num_count = 0;
%}
%%
[a-zA-Z]+ char_count+=yyleng; num_chars+=yyleng;
[0-9]+ num_count+=yyleng; num_chars+=yyleng;
\n ++num_lines; ++num_chars;
. ++num_chars;
%%
int main(void) {
 yylex();
 printf("# of lines = %d, # of chars = %d # of alphas = %d # of nums = %d\n", num_lines, num_chars, char_count, num_count);
 return 0;
}
