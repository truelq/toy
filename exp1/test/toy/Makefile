LLVM_CONFIG = llvm-config
LLVM_CXXFLAGS += $(shell $(LLVM_CONFIG) --cxxflags)
LLVM_LDFLAGS := $(shell $(LLVM_CONFIG) --ldflags)
LLVM_LIBS = $(shell $(LLVM_CONFIG) --libs bitwriter core support)

llvm_model_src = toy-as.cpp


toy: toy.l toy.y ast.c SemanticAnalysis.cpp CodeGenerate.cpp
	bison -d toy.y
	flex toy.l
	g++ -o $@ def.h SemanticAnalysis.cpp CodeGenerate.cpp lex.yy.c toy.tab.h toy.tab.c ast.c  -lfl -lstdc++ $(llvm_model_src) $(LLVM_CXXFLAGS) $(LLVM_LIBS) $(LLVM_LDFLAGS) -lpthread -ldl
	