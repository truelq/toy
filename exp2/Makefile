main: toy.l toy.y ast.c SemanticAnalysis.cpp
	bison -d toy.y
	flex toy.l
	g++ -o $@ SemanticAnalysis.cpp lex.yy.c toy.tab.h toy.tab.c def.h ast.c  -lfl -lstdc++