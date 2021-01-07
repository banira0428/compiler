N = base

lex:
	flex ${N}.l
	gcc lex.yy.c -o ${N} -lfl
	./${N}

compile: 
	flex ${N}.l
	bison -d ${N}.y
	gcc -g ${N}.tab.c lex.yy.c AST.c -o ${N} -DYYERROR_VERBOSE -lfl -ly

test:
	make compile N=${N}
	./${N} < src/final1 > out/final1
	./${N} < src/final2 > out/final2
	./${N} < src/final3 > out/final3
	./${N} < src/final4 > out/final4
	./${N} < src/final5 > out/final5
	./${N} < src/final6 > out/final6





