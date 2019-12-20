#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"//在C/C++函数中使用可变参数。这样在调用相同的函数名 func 的时候，编译器会自动识别入参列表的格式，从而调用相对应的函数体
#include "toy.tab.h"
#include<bits/stdc++.h>
using namespace std;
enum node_kind  {ERR, FUNC_DECLARE,EXT_VAR_DEF,FUNC_DEF,FUNC_DEC,WHILE_,RETURN_,PARAM_LIST,PARAM_DEC, VAR_DEF,DEC_LIST,COMP_STM,STM_LIST,EXP_STMT,COMPT,IF_THEN_,IF_THEN_ELSE_, FUNC_CALL,ARGS_,JLT,JLE,JGT,JGE,EQ,NEQ,ID_,CHAR_,INT_,FLOAT_,ASSIGNOP_,PLUSASS_,MINUSASS_,STARASS_,DIVASS_,AND_,OR_,RELOP_,PLUS_,MINUS_,STAR_,DIV_,UPLUSPLUS_,UMINUSMINUS_,PLUSPLUS_,MINUSMINUS_,NOT_,UMINUS_,BREAK_,OPEN_,CLOSE_};
struct node {    
	enum node_kind kind;               //结点类型
	union {
		  char type_id[33];             //由标识符生成的叶结点
		  int type_int;                 //由整常数生成的叶结点
		  float type_float;              //由浮点常数生成的叶结点
          char type_char;
	      };
    struct node *ptr[4];                   //子树指针，由kind确定有多少棵子树
    int level;                    //层号
    int type;                   //结点对应值的类型
    int pos;                     //语法单位所在位置行号
    int offset;
    int is_func;
    int id;//唯一标识符
    int father;
    int level_father;
    int tempid;
    };
struct node *mknode(int kind,struct node *first,struct node *second, struct node *third,struct node *fourth,int pos );
void display(struct node *T,int indent);
void semanticanalysis(struct node *T,int level);
void codeGen(struct node *T,int level);
int toy_as(string name);