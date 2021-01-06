N = base

lex:
	flex ${N}.l
	gcc lex.yy.c -o ${N} -lfl
	./${N}

compile: 
	flex -d ${N}.l
	bison -d ${N}.y
	gcc ${N}.tab.c lex.yy.c AST.c -o ${N} -DYYERROR_VERBOSE -lfl -ly

test:
	make compile N=${N}
	./${N} < src/final1
	./${N} < src/final2
	./${N} < src/final3
	./${N} < src/final4
	./${N} < src/final5
	./${N} < src/final6





