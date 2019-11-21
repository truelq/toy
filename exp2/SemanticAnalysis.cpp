#include<bits/stdc++.h>
#include"def.h"

using namespace std;
vector<node> semantictable;
struct node little;
int offset;
int father;
int id;
//一系列的全局变量表示当前位置
//可以添加一个计算表达式最大类型的函数
void displaytable(){
    for(int i=0;i<semantictable.size();++i){
        printf("%s ",semantictable[i].type_id);
        printf("%d ",semantictable[i].id);
        printf("%d ",semantictable[i].is_func);
        printf("%d ",semantictable[i].level);
        printf("%d\n",semantictable[i].father);
    }
    cout<<endl;
}
int calculate(struct node *T);
void semanticanalysis(struct node *T,int level){
    
    struct node* t=NULL;
    if(T){
        //printf("1%d",T->kind);
        switch(T->kind){
            case EXT_VAR_DEF: //表示不需要初始化的外部变量
                little.level=level;
                semanticanalysis(T->ptr[0],level);//去设置变量类型
                semanticanalysis(T->ptr[1],level);//去设置变量id
                semanticanalysis(T->ptr[2],level);//继续遍历其他
                break;
            case TYPE:
                little.type=T->type;
                break;
            case DEC_LIST:
                t=T;
                while (t) {//先不处理表达式
                    if (t->ptr[0]->kind==ID){
                        strcpy(little.type_id,t->ptr[0]->type_id);
                        little.level=level;
                        little.offset=offset;
                        offset+=little.type==INT?4:little.type==FLOAT?4:1;
                        little.id=++id;
                        semantictable.push_back(little);
                    }
                    else if (t->ptr[0]->kind==ASSIGNOP)
                    {
                        //计算表达式的类型,进行语义判断
                        //先掠过
                        if(true){
                            printf("error");
                        }
                        strcpy(little.type_id,t->ptr[0]->ptr[0]->type_id);
                        little.level=level;
                        little.offset=offset;
                        offset+=little.type==INT?4:little.type==FLOAT?4:1;
                        little.id=++id;
                        semantictable.push_back(little);
                        //显示初始化表达式
                    }
                    t=t->ptr[1];
                }
                break;
            case FUNC_DECLARE://函数声明
                little.level=level;
                little.is_func=1;//表示为函数
                semanticanalysis(T->ptr[0],level);//函数类型
                semanticanalysis(T->ptr[1],level);//函数id和参数
                little.father=node_kind(ERR);
                semanticanalysis(T->ptr[2],level);//继续遍历其他
                break;
            case FUNC_DEF:
                little.level=level;
                little.is_func=2;//函数加结构体
                semanticanalysis(T->ptr[0],level);//函数类型
                semanticanalysis(T->ptr[1],level);//函数id和参数
                semanticanalysis(T->ptr[2],level);//函数结构体
                little.father=node_kind(ERR);
                semanticanalysis(T->ptr[3],level+1);//继续遍历其他
                break;
            case FUNC_DEC:
                strcpy(little.type_id,T->type_id);
                little.offset=0;
                little.id=++id;
                little.level=level;
                semantictable.push_back(little);//函数id保存
                little.is_func=0;//恢复正常
                t=T;//遍历参数
                little.father=node_kind(little.id);//临时变量level和函数id相同,但father=id
                semanticanalysis(t->ptr[0],level);
                
                break;
            case PARAM_LIST:
                semanticanalysis(T->ptr[0],level);//设置好一个id和类型
                semanticanalysis(T->ptr[1],level);
                break;
            case PARAM_DEC:
                little.level=level;
                semanticanalysis(T->ptr[0],level);//设置类型
                strcpy(little.type_id,T->ptr[1]->type_id);
                little.offset=offset;
                little.id=++id;
                offset+=little.type==INT?4:little.type==FLOAT?4:1;
                semantictable.push_back(little);
                break;
            case COMP_STM:
                //这里是一个代码块的开始,应当设置偏移量为0
                semanticanalysis(T->ptr[0],level);
                semanticanalysis(T->ptr[1],level);
                printf("wait....\n");
                displaytable();
                break;
            case VAR_DEF:
                little.level=level;
                semanticanalysis(T->ptr[0],level);//去设置变量类型
                semanticanalysis(T->ptr[1],level);//去设置变量id
                semanticanalysis(T->ptr[2],level);//继续遍历其他
                break;
            case COMPT:
                semanticanalysis(T->ptr[0],level+1);
            case STM_LIST:
                //这一层主要表示可以为空
                semanticanalysis(T->ptr[0],level);
                semanticanalysis(T->ptr[1],level);
                break;
            case EXP_STMT:
            case RETURN:
            case IF_THEN:
            case IF_THEN_ELSE:
            case WHILE:

                break;
        }
    }
}

/*
	case EXT_VAR_DEF:     printf("%*c外部变量定义：\n",indent,' ');
                        display(T->ptr[0],indent+3);        //显示外部变量类型
                        printf("%*c变量名：\n",indent+3,' ');
                        display(T->ptr[1],indent+6);        //显示变量列表
                        display(T->ptr[2],indent);
                        display(T->ptr[3],indent);
                        break;
	case TYPE:          printf("%*c类型： %s\n",indent,' ',T->type_id);
                        break;
  case FUNC_DECLARE:
                      printf("%*c函数声明：\n",indent,' ');
                      display(T->ptr[0],indent+3);
                      display(T->ptr[1],indent+3);
                      display(T->ptr[2],indent);
                      display(T->ptr[3],indent);
                      break;
	case FUNC_DEF:        printf("%*c函数定义：\n",indent,' ');
                        display(T->ptr[0],indent+3);      //显示函数返回类型
                        display(T->ptr[1],indent+3);      //显示函数名和参数
                        display(T->ptr[2],indent+3);
                        display(T->ptr[3],indent);      //显示函数体
                        break;
	case FUNC_DEC:      printf("%*c函数名：%s\n",indent,' ',T->type_id);
                        if (T->ptr[0]) {
                                printf("%*c函数形参：\n",indent,' ');
                                display(T->ptr[0],indent+3);  //显示函数参数列表
                                }
                        else printf("%*c无参函数\n",indent+3,' ');
                        break;
	case PARAM_LIST:    display(T->ptr[0],indent);     //依次显示全部参数类型和名称，
                        display(T->ptr[1],indent);
                        break;
	case PARAM_DEC:     printf("%*c类型：%s  参数名：%s\n", indent,' ',  \
                               T->ptr[0]->type==INT?"int":T->ptr[0]->type==FLOAT? "float":"char",T->ptr[1]->type_id);
                        break;
	case EXP_STMT:      printf("%*c表达式语句：\n",indent,' ');
                        display(T->ptr[0],indent+3);
                        break;
	case RETURN:        printf("%*c返回语句：\n",indent,' ');
                        display(T->ptr[0],indent+3);
                        break;
	case COMP_STM:      printf("%*c复合语句：\n",indent,' ');
                        printf("%*c复合语句的变量定义：\n",indent+3,' ');
                        display(T->ptr[0],indent+6);      //显示定义部分
                        printf("%*c复合语句的语句部分：\n",indent+3,' ');
                        display(T->ptr[1],indent+6);      //显示语句部分
                        break;
	case STM_LIST:      display(T->ptr[0],indent);      //显示第一条语句
                        display(T->ptr[1],indent);        //显示剩下语句
                        break;
	case WHILE:         printf("%*c循环语句：\n",indent,' ');
                        printf("%*c循环条件：\n",indent+3,' ');
                        display(T->ptr[0],indent+6);      //显示循环条件
                        printf("%*c循环体：\n",indent+3,' ');
                        display(T->ptr[1],indent+6);      //显示循环体
                        break;
	case IF_THEN:       printf("%*c条件语句(IF_THEN)：\n",indent,' ');
                        printf("%*c条件：\n",indent+3,' ');
                        display(T->ptr[0],indent+6);      //显示条件
                        printf("%*cIF子句：\n",indent+3,' ');
                        display(T->ptr[1],indent+6);      //显示if子句
                        break;
	case IF_THEN_ELSE:  printf("%*c条件语句(IF_THEN_ELSE)：\n",indent,' ');
                        printf("%*c条件：\n",indent+3,' ');
                        display(T->ptr[0],indent+6);      //显示条件
                        printf("%*cIF子句：\n",indent+3,' ');
                        display(T->ptr[1],indent+6);      //显示if子句
                        printf("%*cELSE子句：\n",indent+3,' ');
                        display(T->ptr[2],indent+6);      //显示else子句
                        break;
    case VAR_DEF:       printf("%*cLOCAL VAR_NAME：\n",indent,' ');
                        display(T->ptr[0],indent+3);   //显示变量类型
                        display(T->ptr[1],indent+3);   //显示该定义的全部变量名
                        display(T->ptr[2],indent);
                        break;
    case DEC_LIST:      printf("%*cVAR_NAME：\n",indent,' ');
                        T0=T;
                        while (T0) {
                            if (T0->ptr[0]->kind==ID)
                                printf("%*c %s\n",indent+3,' ',T0->ptr[0]->type_id);
                            else if (T0->ptr[0]->kind==ASSIGNOP)
                                {
                                printf("%*c %s ASSIGNOP\n ",indent+3,' ',T0->ptr[0]->ptr[0]->type_id);
							//显示初始化表达式
                                display(T0->ptr[0]->ptr[1],indent+strlen(T0->ptr[0]->ptr[0]->type_id)+4);       
                                }
                            T0=T0->ptr[1];
                            }
                        
                        break;
	case ID:	        printf("%*cID： %s\n",indent,' ',T->type_id);
                        break;
	case INT:	        printf("%*cINT：%d\n",indent,' ',T->type_int);
                        break;
	case FLOAT:	        printf("%*cFLAOT：%f\n",indent,' ',T->type_float);
                        break;
  case CHAR:	        printf("%*cCHAR：%c\n",indent,' ',T->type_char);
                        break;
	case ASSIGNOP:
  case PLUSASS:
  case MINUSASS:
  case STARASS:
  case DIVASS:
	case AND:
	case OR:
	case RELOP:
	case PLUS:
	case MINUS:
	case STAR:
	case DIV:
                    printf("%*c%s\n",indent,' ',T->type_id);
                    display(T->ptr[0],indent+3);
                    display(T->ptr[1],indent+3);
                    break;
  
  case UPLUSPLUS:
  case UMINUSMINUS:
  //暂且将左结合有结合放在一起
  case PLUSPLUS:
  case MINUSMINUS:
	case NOT:
	case UMINUS:    printf("%*c%s\n",indent,' ',T->type_id);
                    display(T->ptr[0],indent+3);
                    break;
  case FUNC_CALL: printf("%*c函数调用：\n",indent,' ');
                    printf("%*c函数名：%s\n",indent+3,' ',T->type_id);
                    display(T->ptr[0],indent+3);
                    break;
	case ARGS:      i=1;
                    while (T) {  //ARGS表示实际参数表达式序列结点，其第一棵子树为其一个实际参数表达式，第二棵子树为剩下的。
                        struct node *T0=T->ptr[0];
                        printf("%*c第%d个实际参数表达式：\n",indent,' ',i++);
                        display(T0,indent+3);
                        T=T->ptr[1];
                        }
//                    printf("%*c第%d个实际参数表达式：\n",indent,' ',i);
  //                  display(T,indent+3);
                    printf("\n");
                    break;
         }
      }
}
*/