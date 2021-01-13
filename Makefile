N = base
M = 1
A = 

lex:
	flex ${N}.l
	gcc lex.yy.c -o ${N} -lfl
	./${N}

compile-d: 
	flex -d ${N}.l
	bison -d ${N}.y
	gcc -g ${N}.tab.c lex.yy.c AST.c build_node.c debug_functions.c -o ${N} -DYYERROR_VERBOSE -lfl -ly

compile: 
	flex ${N}.l
	bison ${N}.y
	gcc -g ${N}.tab.c lex.yy.c AST.c build_node.c debug_functions.c -o ${N} -lfl -ly

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

maps:
	make run M=${M}
	maps -e -q out/final${M}.s -mh4

addr:
	addr2line -e ./base ${A}

reg-test:
	make compile
	for i in 1 2 3 4 5; do ./${N} out/final$$i.s < src/final$$i; done
	for i in 1 2 3 4 5; do maps -e -q out/final$$i.s -mh4; done
	for i in 1 2 3 4 5; do diff final$$i.s.mem mem/final$$i.s.mem.orig; done
	 






