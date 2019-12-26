toy: toy.l toy.y ast.c
	bison -d toy.y
	flex toy.l
	cc -o $@  lex.yy.c toy.tab.h toy.tab.c def.h ast.c  -lfl