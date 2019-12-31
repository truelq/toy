toy: toy.l toy.y ast.c SemanticAnalysis.cpp 
	bison -d toy.y
	flex toy.l
	g++ -o $@ def.h SemanticAnalysis.cpp lex.yy.c toy.tab.h toy.tab.c ast.c -lpthread -ldl
	