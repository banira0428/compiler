N =

lex:
	flex ${N}.l
	gcc lex.yy.c -o ${N} -lfl
	./${N}

run: 
	flex ${N}.l
	bison -d ${N}.y
	gcc ${N}.tab.c lex.yy.c -o ${N} -lfl -ly
	./${N}





