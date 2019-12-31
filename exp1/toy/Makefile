toy: toy.l toy.y ast.c 
	bison -d toy.y
	flex toy.l
	g++ -o $@ def.h lex.yy.c toy.tab.h toy.tab.c ast.c  -lpthread -ldl
	