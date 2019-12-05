#include<bits/stdc++.h>
#include"def.h"

using namespace std;
string i32="i32";
string ifloat="float";
string i8="i8";
vector<node> semantictable1;
struct node little1;
int father1;
int id1;
//一系列的全局变量表示当前位置
//可以添加一个计算表达式最大类型的函数


void semanticanalysis1(struct node *T,int level){
    int temp;
    struct node* t=NULL;
    if(T){
        //printf("1%d",T->kind);
        switch(T->kind){
            case EXT_VAR_DEF: //表示不需要初始化的外部变量
                little1.level=level;
                little1.level_father=level;
                little1.father=0;
                semanticanalysis1(T->ptr[0],level);//去设置变量类型
                semanticanalysis1(T->ptr[1],level);//去设置变量id
                semanticanalysis1(T->ptr[2],level);//继续遍历其他
                break;
            case TYPE:
                little1.type=T->type;
                break;
            case DEC_LIST:
                t=T;
                while (t) {//先不处理表达式
                    if (t->ptr[0]->kind==ID_){
                        strcpy(little1.type_id,t->ptr[0]->type_id);
                        little1.level=level;
                        if(unique_check(little1)){
                            //little1.offset=offset;
                            //offset+=little1.type==INT?4:little1.type==FLOAT?4:1;
                            little1.id=++id1;
                            semantictable1.push_back(little1);
                            if(level==0){
                            string base="@";
                            base+=little1.type_id;
                            base+=" = common global ";
                            if(little1.type==FLOAT_)
                            base+=ifloat;
                            else if(little1.type==INT_)
                            base+=i32;
                            else if(little1.type==CHAR_)
                            base+=i8;
                            base+=" 0,";
                            if(little1.type==CHAR_)
                            base+="align 1";
                            else base+="align 4";
                            cout<<base<<endl;
                            }
                        }else{
                            //printf("Error: redefination id %s at line %d\n",little1.type_id,T->pos);
                        }
                    }
                    else if (t->ptr[0]->kind==ASSIGNOP_)
                    {
                        //计算表达式的类型,进行语义判断
                        //先掠过
                        //应当先计算表达式的值
                        if(true){
                            //printf("Error");
                        }
                        semanticanalysis1(t->ptr[0]->ptr[1],level);
                        if(little1.type==CHAR&&type_check(t->ptr[0]->ptr[1])!=CHAR){
                            //printf("Error: type error at Line:%d\n",T->pos);
                        }
                        strcpy(little1.type_id,t->ptr[0]->ptr[0]->type_id);
                        little1.level=level;
                        if(unique_check(little1)){
                            //little1.offset=offset;
                            //offset+=little1.type==INT?4:little1.type==FLOAT?4:1;
                            little1.id=++id1;
                            semantictable1.push_back(little1);
                        }else{
                            //printf("Error: redefination id %s at line %d\n",little1.type_id,T->pos);
                        }
                        //显示初始化表达式
                    }
                    t=t->ptr[1];
                }
                break;
            case FUNC_DECLARE://函数声明
                little1.level=level;
                little1.is_func=1;//表示为函数
                semanticanalysis1(T->ptr[0],level);//函数类型
                semanticanalysis1(T->ptr[1],level);//函数id和参数
                //继承属性
                little1.is_func=0;
                little1.father=0;
                semanticanalysis1(T->ptr[2],level);//继续遍历其他
                break;
            case FUNC_DEF:
                little1.level=level;
                little1.is_func=2;//函数加结构体
                semanticanalysis1(T->ptr[0],level);//函数类型
                semanticanalysis1(T->ptr[1],level);//函数id和参数
                little1.is_func=0;
                semanticanalysis1(T->ptr[2],level+1);//函数结构体
                little1.level=level;
                little1.level_father=level+1;
                little1.father=0;
                semanticanalysis1(T->ptr[3],level);//继续遍历其他
                break;
            case FUNC_DEC:
                strcpy(little1.type_id,T->type_id);
                if(unique_check(little1)){
                    little1.id=++id1;
                    semantictable1.push_back(little1);//函数id保存
                    little1.father=little1.id;//临时变量level和函数id相同,但father=id
                    little1.level_father=little1.level;
                    //temp=offset;
                    //offset=0;
                    little1.is_func=0;
                    semanticanalysis1(T->ptr[0],level);
                    //offset=temp;
                    little1.level_father=little1.level;
                }else{
                            //printf("Error: redefination func %s at line %d\n",little1.type_id,T->pos);
                        }
                break;
            case PARAM_LIST:
                semanticanalysis1(T->ptr[0],level);//设置好一个id和类型
                semanticanalysis1(T->ptr[1],level);
                break;
            case PARAM_DEC:
                semanticanalysis1(T->ptr[0],level);//设置类型
                strcpy(little1.type_id,T->ptr[1]->type_id);
                if(unique_check(little1)){
                    //little1.offset=offset;//参数的偏移地址待定???
                    little1.id=++id1;
                    //offset+=little1.type==INT?4:little1.type==FLOAT?4:1;
                    semantictable1.push_back(little1);
                }else{
                            //printf("Error: redefination id %s at line %d\n",little1.type_id,T->pos);
                        }
                break;
            case VAR_DEF:
                little1.level=level;
                semanticanalysis1(T->ptr[0],level);//去设置变量类型
                semanticanalysis1(T->ptr[1],level);//去设置变量id
                semanticanalysis1(T->ptr[2],level);//继续遍历其他
                break;
            case COMP_STM:
                //这里是一个代码块的开始,应当设置偏移量为0
                little1.type_id[0]=0;
                little1.id=0;
                little1.type=OPEN_;
                semantictable1.push_back(little1);
                //temp=offset;//只是为了保存临时变量
                //offset=0;
                semanticanalysis1(T->ptr[0],level);
                semanticanalysis1(T->ptr[1],level);
                little1.type=CLOSE_;
                little1.type_id[0]=0;
                little1.id=0;
                semantictable1.push_back(little1);
                //offset=temp;
                //printf("wait....\n");
                break;
            
            case STM_LIST:
                //这一层主要表示可以为空,迭代
                semanticanalysis1(T->ptr[0],level);
                semanticanalysis1(T->ptr[1],level);
                break;
            case EXP_STMT:
                semanticanalysis1(T->ptr[0],level);
                break;
            case COMPT:
                semanticanalysis1(T->ptr[0],level+1);//结构体套结构体
                little1.level=level;
                little1.level_father=level+1;
                break;
            case RETURN_:
                semanticanalysis1(T->ptr[0],level);
                semanticanalysis1(T->ptr[1],level);
                break;
            case IF_THEN_:
                semanticanalysis1(T->ptr[0],level);
                semanticanalysis1(T->ptr[1],level+1);
                little1.level=level;
                little1.level_father=level+1;
                break;
            case IF_THEN_ELSE_:
                semanticanalysis1(T->ptr[0],level);
                semanticanalysis1(T->ptr[1],level+1);
                little1.level=level;
                little1.level_father=level+1;
                semanticanalysis1(T->ptr[2],level+1);
                little1.level=level;
                little1.level_father=level+1;
                break;
            case WHILE_:
                semanticanalysis1(T->ptr[0],level);
                //+=1;
                semanticanalysis1(T->ptr[1],level+1);
                //whiles-=1;
                little1.level=level;
                little1.level_father=level+1;
                break;
            case BREAK_:
                //if(!whiles){//在遇到不平均开闭作用域时应遇到while节点
                //    printf("Error: token break wrong at Line:%d\n",T->pos);
                //}
                break;
	        case ASSIGNOP_:
                if(T->ptr[0]->kind!=ID_){
                    //printf("Error: id not other must before = at Line:%d\n",T->pos);
                }
                strcpy(little1.type_id,T->ptr[0]->type_id);
                if(!declare_check(little1)){
                    //printf("Error: id %s must declare before = at Line:%d\n",T->ptr[0]->type_id,T->pos);
                }
                if(declare_check(little1)==CHAR_&&type_check(T->ptr[1])!=CHAR_){
                    //printf("Error: type error at Line:%d\n",T->pos);
                }
                semanticanalysis1(T->ptr[1],declare_check(little1));
                break;
            case PLUSASS_:
            case MINUSASS_:
            case STARASS_:
            case DIVASS_:
                if(T->ptr[0]->kind!=ID_){
                    //("Error: id not other must id before = at Line:%d\n",T->pos);
                }
                strcpy(little1.type_id,T->ptr[0]->type_id);
                if(!declare_check(little1)){
                    //printf("Error: must declare before = at Line:%d\n",T->pos);
                }
                if(declare_check(little1)==CHAR&&type_check(T->ptr[1])!=CHAR){
                    //printf("Error: type error at Line:%d\n",T->pos);
                }
                semanticanalysis1(T->ptr[1],declare_check(little1));
                break;
	        case AND_:
	        case OR_:
	        case RELOP_:
	        case PLUS_:
	        case MINUS_:
	        case STAR_:
	        case DIV_:
                semanticanalysis1(T->ptr[0],level);
                semanticanalysis1(T->ptr[1],level);
                break;

            case UPLUSPLUS_:
            case UMINUSMINUS_:
            //暂且将左结合有结合放在一起
            case PLUSPLUS_:
            case MINUSMINUS_:
	        case NOT_:
	        case UMINUS_:    
                semanticanalysis1(T->ptr[0],level);
                break;
            case FUNC_CALL:
                strcpy(little1.type_id,T->type_id);
                little1.is_func=3;
                if(!declare_check(little1)){
                    //printf("Error: func %s undeclare at Line:%d\n",little1.type_id,T->pos);
                }
                little1.is_func=0;
                strcpy(little1.type_id,T->type_id);
                args_check(T->ptr[0]);
                //if(!args_check(T->ptr[1])){
                //    printf("Error: args error at Line:%d\n",T->pos);
                //}
                semanticanalysis1(T->ptr[0],level);
                break;
            case ID_:
                strcpy(little1.type_id,T->type_id);
                if(!declare_check(little1)){
                    //printf("Error: id %s undeclare at Line:%d\n",little1.type_id,T->pos);
                }
                break;
	        case INT_:
                break;
	        case FLOAT_:	        
                break;
            case CHAR_:	        
                break;
	        case ARGS_:
                semanticanalysis1(T->ptr[0],level);
                semanticanalysis1(T->ptr[1],level);
                break;
            case JLT:
            case JLE:
            case JGT:
            case JGE:
            case EQ:
            case NEQ:
                break;
        }
    }
}