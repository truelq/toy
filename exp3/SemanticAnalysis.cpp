#include<bits/stdc++.h>
#include"def.h"

using namespace std;
vector<node> semantictable;
struct node little;
int offset;
int father;
int id;
int level_id;
int whiles=0;
//一系列的全局变量表示当前位置
//可以添加一个计算表达式最大类型的函数
void displaytable(){
    printf("id id type is_func level level_father father\n");
    for(int i=0;i<semantictable.size();++i){
        printf("%s\t",semantictable[i].type_id);
        printf("%d ",semantictable[i].id);
        printf("%d ",semantictable[i].type);
        printf("%d ",semantictable[i].is_func);
        printf("%d ",semantictable[i].level);
        printf("%d ",semantictable[i].level_father);
        printf("%d\n",semantictable[i].father);
    }
    cout<<endl;
}
int unique_check(node &T){
    int openc=0;
    int close=0;
    for(int i=0;i<semantictable.size();++i){
        if(semantictable[i].type==CLOSE_){
            close+=1;
            continue;
        }else if(semantictable[i].type==OPEN_){
            if(close)
                close-=1;
            else return 1;
            continue;
        }
        if(!strcmp(semantictable[i].type_id,little.type_id)&&){
            //检测函数

            //检测变量,静态变量不需要考虑,level=0表示参数,
            if(semantictable[i].is_func==little.is_func&&semantictable[i].father==little.father){
                if(little.is_func==0){
                    return 0;
                }else {
                    if(semantictable[i].is_func==1&&little.is_func!=2||semantictable[i].is_func==2)
                        return 0;
                }
            }
        }
    }
    return 1;
}
int declare_check(node &T){
    //在其可见作用域查找
    int openc=0;
    int close=0;
    int temp_level=little.level;
    int temp_father=little.level_father;
    for(int i=semantictable.size()-1;i>=0;--i){
        //对于大括号,采取只降不升策略,因为层号变深意味着作用域出问题
        //if(semantictable[i].father==little.father||semantictable[i].father==0)//同是全局变量或同是函数变量且在大括号的可见部分
        {
            if(semantictable[i].type==CLOSE_){
                close+=1;
                continue;
            }else if(semantictable[i].type==OPEN_){
                if(close)
                close-=1;
                continue;
            }
            if(!close){
                if(!strcmp(little.type_id,semantictable[i].type_id)&&little.is_func==0){
                    return semantictable[i].type;
                }
                if(!strcmp(little.type_id,semantictable[i].type_id)&&little.father==semantictable[i].father&&little.is_func==0){
                    return semantictable[i].type;
                }
            }
            /*
            //对于在相同大括号的情况
            if(semantictable[i].level==temp_level&&semantictable[i].level_father==temp_father)
                if(!strcmp(little.type_id,semantictable[i].type_id)){
                    return semantictable[i].type;
                }
            //对于在大括号的父亲的情况
            if(semantictable[i].level<temp_level){
                temp_level-=1;
                temp_father=semantictable[i].level_father;
                if(!strcmp(little.type_id,semantictable[i].type_id))
                    return semantictable[i].type;
            }
            */
        }
        if(semantictable[i].is_func){
            if(!strcmp(little.type_id,semantictable[i].type_id))
                    return semantictable[i].type;
        }
    }
    return 0;
}
int type_check(node *T){
    if(T==NULL)
        return 0;
    if(T->type==ID_){
        struct node tempp=little;
        strcpy(tempp.type_id,T->type_id);
        return declare_check(little);
    }else if(T->type==CHAR_)
        return CHAR_;
    else if(T->type==INT_)
        return INT_;
    else if(T->type==FLOAT_)
        return FLOAT_;
    int a=type_check(T->ptr[0]);
    int b=type_check(T->ptr[1]);
    return a>b?a:b;
}
int break_check(node &T){
    int openc=0;
    int closec=0;
    int flag=0;
    vector<int> ttt;
    int ccc=0;
    for(int i=0;i<semantictable.size();++i){
        if(semantictable[i].type==WHILE_){
            flag+=1;
            ccc+=1;
        }else if(semantictable[i].type==OPEN_){
            openc+=1;
            if(ccc){
                ccc-=1;
                ttt.push_back(openc);
            }
        }else if(semantictable[i].type==CLOSE_){
            openc-=1;
        }else if(semantictable[i].type==BREAK_){
            if(flag){
                if(openc<=closec){
                    return 0;
                }
            }else {
                return 0;
            }
        }
    }
    return 0;
}
int args_check(node *T){
    int flag=0;
    int fa_id=0;
    for(int i=0;i<semantictable.size();++i){
        //为了解决递归的问题只要声明了就可以
        if(!flag&&semantictable[i].is_func&&!strcmp(semantictable[i].type_id,little.type_id)){
            printf("%s %d\n",semantictable[i].type_id,semantictable[i].id);
            flag=1;
            fa_id=semantictable[i].id;
            continue;
        }
        if(flag==1&&semantictable[i].father==fa_id&&semantictable[i].id){
            printf("%d\n",semantictable[i].father);
            if(T==NULL){
                printf("Error: type conflict at Line\n");
                return 0;
            }
            if(semantictable[i].type!=type_check(T->ptr[0])){
                printf("%d\n",semantictable[i].type);
                printf("Error: type conflict at Line:%d\n",T->pos);
            }
            T=T->ptr[1];
        }else{
            if(flag==1)
                return 0;
        }
    }
}
void semanticanalysis(struct node *T,int level){
    int temp;
    struct node* t=NULL;
    if(T){
        //printf("1%d",T->kind);
        switch(T->kind){
            case EXT_VAR_DEF: //表示不需要初始化的外部变量
                little.level=level;
                little.level_father=level;
                little.father=0;
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
                    if (t->ptr[0]->kind==ID_){
                        strcpy(little.type_id,t->ptr[0]->type_id);
                        little.level=level;
                        if(unique_check(little)){
                            little.offset=offset;
                            offset+=little.type==INT?4:little.type==FLOAT?4:1;
                            little.id=++id;
                            semantictable.push_back(little);
                        }else{
                            printf("Error: redefination id %s at line %d\n",little.type_id,T->pos);
                        }
                    }
                    else if (t->ptr[0]->kind==ASSIGNOP_)
                    {
                        //计算表达式的类型,进行语义判断
                        //先掠过
                        //应当先计算表达式的值
                        if(true){
                            printf("Error");
                        }
                        semanticanalysis(t->ptr[0]->ptr[1],level);
                        if(little.type==CHAR&&type_check(t->ptr[0]->ptr[1])!=CHAR){
                            printf("Error: type error at Line:%d\n",T->pos);
                        }
                        strcpy(little.type_id,t->ptr[0]->ptr[0]->type_id);
                        little.level=level;
                        if(unique_check(little)){
                            little.offset=offset;
                            offset+=little.type==INT?4:little.type==FLOAT?4:1;
                            little.id=++id;
                            semantictable.push_back(little);
                        }else{
                            printf("Error: redefination id %s at line %d\n",little.type_id,T->pos);
                        }
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
                //继承属性
                little.is_func=0;
                little.father=0;
                semanticanalysis(T->ptr[2],level);//继续遍历其他
                break;
            case FUNC_DEF:
                little.level=level;
                little.is_func=2;//函数加结构体
                semanticanalysis(T->ptr[0],level);//函数类型
                semanticanalysis(T->ptr[1],level);//函数id和参数
                little.is_func=0;
                semanticanalysis(T->ptr[2],level+1);//函数结构体
                little.level=level;
                little.level_father=level+1;
                little.father=0;
                semanticanalysis(T->ptr[3],level);//继续遍历其他
                break;
            case FUNC_DEC:
                strcpy(little.type_id,T->type_id);
                if(unique_check(little)){
                    little.id=++id;
                    semantictable.push_back(little);//函数id保存
                    little.father=little.id;//临时变量level和函数id相同,但father=id
                    little.level_father=little.level;
                    temp=offset;
                    offset=0;
                    little.is_func=0;
                    semanticanalysis(T->ptr[0],level);
                    offset=temp;
                    little.level_father=little.level;
                }else{
                            printf("Error: redefination func %s at line %d\n",little.type_id,T->pos);
                        }
                break;
            case PARAM_LIST:
                semanticanalysis(T->ptr[0],level);//设置好一个id和类型
                semanticanalysis(T->ptr[1],level);
                break;
            case PARAM_DEC:
                semanticanalysis(T->ptr[0],level);//设置类型
                strcpy(little.type_id,T->ptr[1]->type_id);
                if(unique_check(little)){
                    little.offset=offset;//参数的偏移地址待定???
                    little.id=++id;
                    offset+=little.type==INT?4:little.type==FLOAT?4:1;
                    semantictable.push_back(little);
                }else{
                            printf("Error: redefination id %s at line %d\n",little.type_id,T->pos);
                        }
                break;
            case VAR_DEF:
                little.level=level;
                semanticanalysis(T->ptr[0],level);//去设置变量类型
                semanticanalysis(T->ptr[1],level);//去设置变量id
                semanticanalysis(T->ptr[2],level);//继续遍历其他
                break;
            case COMP_STM:
                //这里是一个代码块的开始,应当设置偏移量为0
                little.type_id[0]=0;
                little.id=0;
                little.type=OPEN_;
                semantictable.push_back(little);
                temp=offset;//只是为了保存临时变量
                offset=0;
                semanticanalysis(T->ptr[0],level);
                semanticanalysis(T->ptr[1],level);
                little.type=CLOSE_;
                little.type_id[0]=0;
                little.id=0;
                semantictable.push_back(little);
                offset=temp;
                printf("wait....\n");
                displaytable();
                break;
            
            case STM_LIST:
                //这一层主要表示可以为空,迭代
                semanticanalysis(T->ptr[0],level);
                semanticanalysis(T->ptr[1],level);
                break;
            case EXP_STMT:
                semanticanalysis(T->ptr[0],level);
                break;
            case COMPT:
                semanticanalysis(T->ptr[0],level+1);//结构体套结构体
                little.level=level;
                little.level_father=level+1;
                break;
            case RETURN_:
                semanticanalysis(T->ptr[0],level);
                semanticanalysis(T->ptr[1],level);
                break;
            case IF_THEN_:
                semanticanalysis(T->ptr[0],level);
                semanticanalysis(T->ptr[1],level+1);
                little.level=level;
                little.level_father=level+1;
                break;
            case IF_THEN_ELSE_:
                semanticanalysis(T->ptr[0],level);
                semanticanalysis(T->ptr[1],level+1);
                little.level=level;
                little.level_father=level+1;
                semanticanalysis(T->ptr[2],level+1);
                little.level=level;
                little.level_father=level+1;
                break;
            case WHILE_:
                semanticanalysis(T->ptr[0],level);
                whiles+=1;
                semanticanalysis(T->ptr[1],level+1);
                whiles-=1;
                little.level=level;
                little.level_father=level+1;
                break;
            case BREAK_:
                if(!whiles){//在遇到不平均开闭作用域时应遇到while节点
                    printf("Error: token break wrong at Line:%d\n",T->pos);
                }
                break;
	        case ASSIGNOP_:
                if(T->ptr[0]->kind!=ID_){
                    printf("Error: id not other must before = at Line:%d\n",T->pos);
                }
                strcpy(little.type_id,T->ptr[0]->type_id);
                if(!declare_check(little)){
                    printf("Error: id %s must declare before = at Line:%d\n",T->ptr[0]->type_id,T->pos);
                }
                if(declare_check(little)==CHAR_&&type_check(T->ptr[1])!=CHAR_){
                    printf("Error: type error at Line:%d\n",T->pos);
                }
                semanticanalysis(T->ptr[1],declare_check(little));
                break;
            case PLUSASS_:
            case MINUSASS_:
            case STARASS_:
            case DIVASS_:
                if(T->ptr[0]->kind!=ID_){
                    printf("Error: id not other must id before = at Line:%d\n",T->pos);
                }
                strcpy(little.type_id,T->ptr[0]->type_id);
                if(!declare_check(little)){
                    printf("Error: must declare before = at Line:%d\n",T->pos);
                }
                if(declare_check(little)==CHAR&&type_check(T->ptr[1])!=CHAR){
                    printf("Error: type error at Line:%d\n",T->pos);
                }
                semanticanalysis(T->ptr[1],declare_check(little));
                break;
	        case AND_:
	        case OR_:
	        case RELOP_:
	        case PLUS_:
	        case MINUS_:
	        case STAR_:
	        case DIV_:
                semanticanalysis(T->ptr[0],level);
                semanticanalysis(T->ptr[1],level);
                break;

            case UPLUSPLUS_:
            case UMINUSMINUS_:
            //暂且将左结合有结合放在一起
            case PLUSPLUS_:
            case MINUSMINUS_:
	        case NOT_:
	        case UMINUS_:    
                semanticanalysis(T->ptr[0],level);
                break;
            case FUNC_CALL:
                strcpy(little.type_id,T->type_id);
                little.is_func=3;
                if(!declare_check(little)){
                    printf("Error: func %s undeclare at Line:%d\n",little.type_id,T->pos);
                }
                little.is_func=0;
                strcpy(little.type_id,T->type_id);
                args_check(T->ptr[0]);
                //if(!args_check(T->ptr[1])){
                //    printf("Error: args error at Line:%d\n",T->pos);
                //}
                semanticanalysis(T->ptr[0],level);
                break;
            case ID_:
                strcpy(little.type_id,T->type_id);
                if(!declare_check(little)){
                    printf("Error: id %s undeclare at Line:%d\n",little.type_id,T->pos);
                }
                break;
	        case INT_:
                break;
	        case FLOAT_:	        
                break;
            case CHAR_:	        
                break;
	        case ARGS_:
                semanticanalysis(T->ptr[0],level);
                semanticanalysis(T->ptr[1],level);
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