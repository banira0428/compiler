N = base
M = 1

lex:
	flex ${N}.l
	gcc lex.yy.c -o ${N} -lfl
	./${N}

compile: 
	flex -d ${N}.l
	bison -d ${N}.y
	gcc -g ${N}.tab.c lex.yy.c AST.c -o ${N} -DYYERROR_VERBOSE -lfl -ly

run: 
	make compile
	./${N} out/final${M}.s < src/final${M}

test:
	make compile N=${N}
	./${N} < src/final1 > out/final1.s
	./${N} < src/final2 > out/final2.s
	./${N} < src/final3 > out/final3.s
	./${N} < src/final4 > out/final4.s
	./${N} < src/final5 > out/final5.s
	./${N} < src/final6 > out/final6.s





