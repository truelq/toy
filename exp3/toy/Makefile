toy: toy.l toy.y ast.c SemanticAnalysis.cpp CodeGenerate.cpp
	bison -d toy.y
	flex toy.l
	g++ -o $@ def.h SemanticAnalysis.cpp CodeGenerate.cpp lex.yy.c toy.tab.h toy.tab.c ast.c -lpthread -ldl
	