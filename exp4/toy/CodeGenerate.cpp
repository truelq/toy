#include "def.h"
#include <bits/stdc++.h>

using namespace std;
string i32 = "i32";
string ifloat = "float";
string i8 = "i8";
string i1 = "i1";
string ilabel = "label";
int fll;
vector<node> semantictable1;
struct tempnode {
  int tempid;
  int length;
  string ii;
};
struct templabel {
  int before;
  string beforelabel;
  int begin;
  string beginlabel;
  int end;
  string endlabel;
};
vector<tempnode> temptable;
struct node little1;
struct tempnode littletempnode;
struct templabel littletemplabel;
string tempargs;
int father1;
int id1;
//一系列的全局变量表示当前位置
//可以添加一个计算表达式最大类型的函数
int counter;
void displaytable1() {
  printf("id id type is_func level level_father father\n");
  for (unsigned int i = 0; i < semantictable1.size(); ++i) {
    printf("%s\t", semantictable1[i].type_id);
    printf("%d ", semantictable1[i].id);
    printf("%d ", semantictable1[i].type);
    printf("%d ", semantictable1[i].is_func);
    printf("%d ", semantictable1[i].level);
    printf("%d ", semantictable1[i].level_father);
    printf("%d\n", semantictable1[i].father);
  }
  cout << endl;
}
int unique_check1(node &T) {
  // int openc = 0;
  int close = 0;
  for (unsigned int i = 0; i < semantictable1.size(); ++i) {
    if (semantictable1[i].type == CLOSE_) {
      close += 1;
      continue;
    } else if (semantictable1[i].type == OPEN_) {
      if (close)
        close -= 1;
      else
        return 1;
      continue;
    }
    if (!strcmp(semantictable1[i].type_id, T.type_id)) {
      //检测函数

      //检测变量,静态变量不需要考虑,level=0表示参数,
      if (semantictable1[i].is_func == T.is_func &&
          semantictable1[i].father == T.father) {
        if (T.is_func == 0) {
          return 0;
        } else {
          if (semantictable1[i].is_func == 1 &&
              (T.is_func != 2 || semantictable1[i].is_func == 2))
            return 0;
        }
      }
    }
  }
  return 1;
}
int declare_check1(node &T) {
  //在其可见作用域查找
  // int openc = 0;
  int close = 0;
  // int temp_level = T.level;
  // int temp_father = T.level_father;
  for (int i = semantictable1.size() - 1; i >= 0; --i) {
    //对于大括号,采取只降不升策略,因为层号变深意味着作用域出问题
    // if(semantictable1[i].father==little.father||semantictable1[i].father==0)//同是全局变量或同是函数变量且在大括号的可见部分
    {
      if (semantictable1[i].type == CLOSE_) {
        close += 1;
        continue;
      } else if (semantictable1[i].type == OPEN_) {
        if (close)
          close -= 1;
        continue;
      }
      if (!close) {
        if (!strcmp(T.type_id, semantictable1[i].type_id) && T.is_func == 0) {
          return semantictable1[i].type;
        }
        if (!strcmp(T.type_id, semantictable1[i].type_id) &&
            T.father == semantictable1[i].father && T.is_func == 0) {
          return semantictable1[i].type;
        }
      }
    }
    if (semantictable1[i].is_func) {
      if (!strcmp(T.type_id, semantictable1[i].type_id))
        return semantictable1[i].type;
    }
  }
  return 0;
}
int declare_check11(node &T) {
  //在其可见作用域查找
  // int openc = 0;
  int close = 0;
  // int temp_level = T.level;
  // int temp_father = T.level_father;
  for (int i = semantictable1.size() - 1; i >= 0; --i) {
    //对于大括号,采取只降不升策略,因为层号变深意味着作用域出问题
    // if(semantictable1[i].father==little.father||semantictable1[i].father==0)//同是全局变量或同是函数变量且在大括号的可见部分
    {
      if (semantictable1[i].type == CLOSE_) {
        close += 1;
        continue;
      } else if (semantictable1[i].type == OPEN_) {
        if (close)
          close -= 1;
        continue;
      }
      if (!close) {
        if (!strcmp(T.type_id, semantictable1[i].type_id) && T.is_func == 0) {
          return i;
        }
        if (!strcmp(T.type_id, semantictable1[i].type_id) &&
            T.father == semantictable1[i].father && T.is_func == 0) {
          return i;
        }
      }
    }
    if (semantictable1[i].is_func) {
      if (!strcmp(T.type_id, semantictable1[i].type_id))
        return i;
    }
  }
  return 0;
}
int type_check1(node *T) {
  if (T == NULL)
    return 0;
  if (T->kind == ID_||T->kind == FUNC_CALL) {//注意啊,哭死
    struct node tempp = *T;
    strcpy(tempp.type_id, T->type_id);
    return declare_check1(tempp);
  } else if (T->type == CHAR_)
    return CHAR_;
  else if (T->type == INT_)
    return INT_;
  else if (T->type == FLOAT_)
    return FLOAT_;
  int a = type_check1(T->ptr[0]);
  int b = type_check1(T->ptr[1]);
  return a > b ? a : b;
}

void codeGen(struct node *T, int level) {
  // int temp;
  struct node *t = NULL;
  if (T) {
    // printf("1%d",T->kind);
    switch (T->kind) {
    case EXT_VAR_DEF: //表示不需要初始化的外部变量
      little1.level = level;
      little1.level_father = level;
      little1.tempid = -1;
      little1.father = 0;
      codeGen(T->ptr[0], level); //去设置变量类型
      codeGen(T->ptr[1], level); //去设置变量id
      codeGen(T->ptr[2], level); //继续遍历其他
      break;
    case TYPE_:
      little1.type = T->type;
      break;
    case DEC_LIST: {
      t = T;
      while (t) { //先不处理表达式
        if (t->ptr[0]->kind == ID_) {
          strcpy(little1.type_id, t->ptr[0]->type_id);
          little1.level = level;
          if (unique_check1(little1)) {
            if (level == 0) {
              little1.id = ++id1;
              semantictable1.push_back(little1);
              string base = "@";
              base += little1.type_id;
              base += " = common global ";
              if (little1.type == FLOAT_) {
                base += ifloat + " 0.000000e+00, align 4";
              } else if (little1.type == INT_) {
                base += i32 + " 0, align 4";
              } else if (little1.type == CHAR_) {
                base += i8 + " 0, align 1";
              }
              cout << base << endl;
            } else {
              little1.id = ++id1;
              little1.tempid = counter++;
              littletempnode.tempid = counter - 1;
              semantictable1.push_back(little1);
              little1.tempid = -1;
              string base = "%";
              base += to_string((counter - 1));
              if (little1.type == FLOAT_) {
                base += " = alloca " + ifloat + ", align 4";
                littletempnode.ii = ifloat;
              } else if (little1.type == INT_) {
                base += " = alloca " + i32 + ", align 4";
                littletempnode.ii = i32;
              } else if (little1.type == CHAR_) {
                base += " = alloca " + i8 + ", align 1";
                littletempnode.ii = i1;
              }
              temptable.push_back(littletempnode);
              cout << base << endl;
            }
          }
        } else if (t->ptr[0]->kind == ASSIGNOP_) {
          //计算表达式的类型,进行语义判断
          //应当先计算表达式的值
          codeGen(t->ptr[0]->ptr[1], level);
          int tttemp = type_check1(t->ptr[0]->ptr[1]);
          strcpy(little1.type_id, t->ptr[0]->ptr[0]->type_id);
          little1.level = level;
          if (level == 0) {
            little1.id = ++id1;
            semantictable1.push_back(little1);
            string base = "@";
            base += little1.type_id;
            base += " = common global ";
            if (little1.type == FLOAT_) {
              base += ifloat;
              base += " 0.000000e+00,";
            } else if (little1.type == INT_) {
              base += i32;
              base += " 0,";
            } else if (little1.type == CHAR_) {
              base += i8;
              base += " 0,";
            }
            if (little1.type == CHAR_)
              base += "align 1";
            else
              base += "align 4";
            cout << base << endl;
          } else {
            little1.id = ++id1;
            little1.tempid = counter++;
            littletempnode.tempid = counter - 1;
            semantictable1.push_back(little1);
            // little1.tempid = -1;
            string base = "%";
            base += to_string((counter - 1));
            if (little1.type == FLOAT_) {
              base += " = alloca " + ifloat + ", align 4";
              littletempnode.ii = ifloat;
            } else if (little1.type == INT_) {
              base += " = alloca " + i32 + ", align 4";
              littletempnode.ii = i32;
            } else if (little1.type == CHAR_) {
              base += " = alloca " + i8 + ", align 1";
              littletempnode.ii = i8;
            }
            temptable.push_back(littletempnode);
            cout << base << endl;
            base.clear();
            base += "store ";
            if (t->ptr[0]->ptr[1]->kind == CHAR_) {
              base += i8 + " " + to_string(t->ptr[0]->ptr[1]->type_char) + ", ";
            } else if (t->ptr[0]->ptr[1]->kind == INT_) {
              base += i32 + " " + to_string(t->ptr[0]->ptr[1]->type_int) + ", ";
            } else if (t->ptr[0]->ptr[1]->kind == FLOAT_) {
              base += ifloat + " " + to_string(t->ptr[0]->ptr[1]->type_float) +
                      ", ";
            } else if (tttemp == CHAR_) {
              base += i8 + " %" + to_string(counter - 2) + ", ";
            } else if (tttemp == INT_) {
              base += i32 + " %" + to_string(counter - 2) + ", ";
            } else if (tttemp == FLOAT_) {
              base += ifloat + " %" + to_string(counter - 2) + ", ";
            }
            if (little1.type == CHAR_) {
              base += i8 + "* %" + to_string(little1.tempid) + ", align 1";
            } else if (little1.type == INT_) {
              base += i32 + "* %" + to_string(little1.tempid) + ", align 4";
            } else if (little1.type == FLOAT_) {
              base += ifloat + "* %" + to_string(little1.tempid) + ", align 4";
            }
            cout << base << endl;
          }
          //显示初始化表达式
        }
        t = t->ptr[1];
      }
      break;
    }
    case FUNC_DECLARE: //函数声明
      little1.level = level;
      little1.is_func = 1;       //表示为函数
      codeGen(T->ptr[0], level); //函数类型
      codeGen(T->ptr[1], level); //函数id和参数
      //继承属性
      little1.is_func = 0;
      little1.father = 0;
      codeGen(T->ptr[2], level); //继续遍历其他
      break;
    case FUNC_DEF: {
      little1.level = level;
      little1.is_func = 2;       //函数加结构体
      codeGen(T->ptr[0], level); //函数类型
      codeGen(T->ptr[1], level); //函数id和参数
      little1.is_func = 0;
      //入口也是基本块
      counter++;
      littletempnode.tempid = counter - 1;
      littletempnode.ii = ilabel;
      temptable.push_back(littletempnode);
      cout << "{" << endl;
      //为参数换名
      node *t = T->ptr[1]->ptr[0];
      while (t) {
        int tempi = declare_check11(*(t->ptr[0]->ptr[1]));
        // cout<<semantictable1[tempi].type_id<<endl;
        string base = "%" + to_string(counter++) + " = alloca ";
        string basestore = "store ";
        if (semantictable1[tempi].type == CHAR_) {
          base += i8 + ", align 1";
          basestore += i8 + " %" + to_string(semantictable1[tempi].tempid) +
                       ", " + i8 + " *%" + to_string(counter - 1) + ", align 1";
        } else if (semantictable1[tempi].type == INT_) {
          base += i32 + ", align 4";
          basestore += i32 + " %" + to_string(semantictable1[tempi].tempid) +
                       ", " + i32 + " *%" + to_string(counter - 1) +
                       ", align 4";
        } else if (semantictable1[tempi].type == FLOAT_) {
          base += ifloat + ", align 4";
          basestore += ifloat + " %" + to_string(semantictable1[tempi].tempid) +
                       ", " + ifloat + " *%" + to_string(counter - 1) +
                       ", align 4";
        }
        semantictable1[tempi].tempid = counter - 1;
        cout << base << endl;
        cout << basestore << endl;
        t = t->ptr[1];
      }
      codeGen(T->ptr[2], level + 1); //函数结构体
      cout << "}" << endl;
      //结束后counter清零
      counter = 0;
      temptable.clear();
      little1.level = level;
      little1.level_father = level + 1;
      little1.father = 0;
      codeGen(T->ptr[3], level); //继续遍历其他
      if (!fll) {
        cout << "declare i32 @getchar()" << endl;
        cout << "declare i32 @putchar(i32)" << endl;
        fll = 1;
      }
      break;
    }
    case FUNC_DEC: {
      int temp = little1.is_func;
      strcpy(little1.type_id, T->type_id);
      little1.id = ++id1;
      semantictable1.push_back(little1); //函数id保存

      string base = "define ";
      if (little1.type == FLOAT_) {
        base += ifloat;
      } else if (little1.type == INT_) {
        base += i32;
      } else if (little1.type == CHAR_) {
        base += i8;
      }
      base += " @";
      base += little1.type_id;
      if (temp != 1)
        cout << base;
      if (temp != 1)
        cout << "(";
      little1.father = little1.id; //临时变量level和函数id相同,但father=id
      little1.level_father = little1.level;
      little1.is_func = 0;
      codeGen(T->ptr[0], level);
      little1.level_father = little1.level;
      if (temp != 1)
        cout << ")" << endl;
      break;
    }
    case PARAM_LIST: {
      int temp = little1.is_func;
      codeGen(T->ptr[0], level); //设置好一个id和类型
      string base;
      if (little1.type == FLOAT_) {
        base += ifloat;
        littletempnode.ii = ifloat;
      } else if (little1.type == INT_) {
        base += i32;
        littletempnode.ii = i32;
      } else if (little1.type == CHAR_) {
        base += i8;
        littletempnode.ii = i8;
      }
      little1.id = ++id1;
      little1.tempid = counter++;
      littletempnode.tempid = counter - 1;
      semantictable1.push_back(little1);
      little1.tempid = -1;
      temptable.push_back(littletempnode);
      if (temp != 1)
        cout << base;
      if (T->ptr[1])
        if (temp != 1)
          cout << ',';

      codeGen(T->ptr[1], level);
      break;
    }
    case PARAM_DEC:
      codeGen(T->ptr[0], level); //设置类型
      strcpy(little1.type_id, T->ptr[1]->type_id);

      break;
    case VAR_DEF:
      little1.level = level;
      codeGen(T->ptr[0], level); //去设置变量类型
      codeGen(T->ptr[1], level); //去设置变量id
      codeGen(T->ptr[2], level); //继续遍历其他
      break;
    case COMP_STM:
      //这里是一个代码块的开始,应当设置偏移量为0
      little1.type_id[0] = 0;
      little1.id = 0;
      little1.type = OPEN_;
      semantictable1.push_back(little1);
      // temp=offset;//只是为了保存临时变量
      // offset=0;
      codeGen(T->ptr[0], level);
      codeGen(T->ptr[1], level);
      little1.type = CLOSE_;
      //清理中间产生的变量
      little1.type_id[0] = 0;
      little1.id = 0;
      semantictable1.push_back(little1);
      // offset=temp;
      // printf("wait....\n");
      // displaytable1();

      break;

    case STM_LIST:
      //这一层主要表示可以为空,迭代
      codeGen(T->ptr[0], level);
      codeGen(T->ptr[1], level);
      break;
    case EXP_STMT:
      codeGen(T->ptr[0], level);
      break;
    case COMPT:
      codeGen(T->ptr[0], level + 1); //结构体套结构体
      little1.level = level;
      little1.level_father = level + 1;
      break;
    case RETURN_: {
      string base = "ret ";
      if (T->ptr[0]->ptr[0] != NULL) {
        codeGen(T->ptr[0], level);
        if (little1.type == CHAR_) {
          base += i8 + " %" + to_string(counter - 1);
        } else if (little1.type == INT_) {
          base += i32 + " %" + to_string(counter - 1);
        } else if (little1.type == FLOAT_) {
          base += ifloat + " %" + to_string(counter - 1);
        }
      } else {
        if (T->ptr[0]->kind == CHAR_) {
          base += i8 + " " + to_string(T->ptr[0]->type_char);
        } else if (T->ptr[0]->kind == INT_) {
          base += i32 + " " + to_string(T->ptr[0]->type_int);
        } else if (T->ptr[0]->kind == FLOAT_) {
          base += ifloat + " " + to_string(T->ptr[0]->type_float);
        } else if (T->ptr[0]->kind == ID_) {
          codeGen(T->ptr[0], level);
          if (little1.type == CHAR_) {
            base += i8 + " %" + to_string(counter - 1);
          } else if (little1.type == INT_) {
            base += i32 + " %" + to_string(counter - 1);
          } else if (little1.type == FLOAT_) {
            base += ifloat + " %" + to_string(counter - 1);
          }
        }
      }
      cout << base << endl;
      counter += 1;
      break;
    }
    case IF_THEN_: {
      if (T->ptr[0]->kind == NOT_ || T->ptr[0]->kind == AND_ ||
          T->ptr[0]->kind == OR_) {
        templabel temp = littletemplabel;
        littletemplabel.begin = 1;
        littletemplabel.end = 1;
        littletemplabel.beginlabel = "hard" + to_string(counter - 1) + "begin";
        littletemplabel.endlabel = "hard" + to_string(counter - 1) + "end";
        codeGen(T->ptr[0], level);
        string base = littletemplabel.beginlabel + ":";
        cout << base << endl;
        codeGen(T->ptr[1], level + 1);
        cout << "br label %" + littletemplabel.endlabel << endl;
        base = littletemplabel.endlabel + ":";
        cout << base << endl;
        littletemplabel = temp;
      } else {
        string base1 = "hard" + to_string(counter - 1) + "begin";
        string base2 = "hard" + to_string(counter - 1) + "end";
        codeGen(T->ptr[0], level);
        cout << "br i1 %" + to_string(counter - 1) + ", label %" + base1 +
                    ", label %" + base2
             << endl;
        cout << base1 + ":" << endl;
        codeGen(T->ptr[1], level + 1);
        cout << "br label %" + base2 << endl;
        cout << base2 + ":" << endl;
      }
      little1.level = level;
      little1.level_father = level + 1;
      break;
    }
    case IF_THEN_ELSE_:
      codeGen(T->ptr[0], level);
      codeGen(T->ptr[1], level + 1);
      little1.level = level;
      little1.level_father = level + 1;
      codeGen(T->ptr[2], level + 1);
      little1.level = level;
      little1.level_father = level + 1;
      break;
    case WHILE_: {
      if (T->ptr[0]->kind == NOT_ || T->ptr[0]->kind == AND_ ||
          T->ptr[0]->kind == OR_) {
        templabel temp = littletemplabel;
        littletemplabel.before = 1;
        littletemplabel.begin = 1;
        littletemplabel.end = 1;
        littletemplabel.beforelabel =
            "hard" + to_string(counter - 1) + "before";
        littletemplabel.beginlabel = "hard" + to_string(counter - 1) + "begin";
        littletemplabel.endlabel = "hard" + to_string(counter - 1) + "end";
        cout << "br label %" + littletemplabel.beforelabel << endl;
        cout << littletemplabel.beforelabel << endl;
        codeGen(T->ptr[0], level);
        string base = littletemplabel.beginlabel + ":";
        cout << base << endl;
        codeGen(T->ptr[1], level + 1);
        cout << "br label %" + littletemplabel.beforelabel << endl;
        base = littletemplabel.endlabel + ":";
        cout << base << endl;
        littletemplabel = temp;
      } else {
        templabel temp = littletemplabel;
        littletemplabel.before = 1;
        littletemplabel.begin = 1;
        littletemplabel.end = 1;
        littletemplabel.beforelabel =
            "hard" + to_string(counter - 1) + "before";
        littletemplabel.beginlabel = "hard" + to_string(counter - 1) + "begin";
        littletemplabel.endlabel = "hard" + to_string(counter - 1) + "end";
        cout << "br label %" + littletemplabel.beforelabel << endl;
        cout << littletemplabel.beforelabel + ":" << endl;
        codeGen(T->ptr[0], level);
        cout << "br i1 %" + to_string(counter - 1) + ", label %" +
                    littletemplabel.beginlabel + ", label %" +
                    littletemplabel.endlabel
             << endl;
        cout << littletemplabel.beginlabel + ":" << endl;
        codeGen(T->ptr[1], level + 1);
        cout << "br label %" + littletemplabel.beforelabel << endl;
        cout << littletemplabel.endlabel + ":" << endl;
      }

      little1.level = level;
      little1.level_father = level + 1;
      break;
      /*
      templabel temp = littletemplabel;
      littletemplabel.before = 1;
      littletemplabel.begin = 1;
      littletemplabel.end = 1;
      littletemplabel.beginlabel = to_string(counter - 1) + "before";
      littletemplabel.beginlabel = to_string(counter - 1) + "begin";
      littletemplabel.endlabel = to_string(counter - 1) + "end";
      cout << "label %" << littletemplabel.beginlabel << ":" << endl;
      codeGen(T->ptr[0], level);
      cout << "label %" << littletemplabel.beginlabel << ":" << endl;
      codeGen(T->ptr[1], level + 1);
      cout << "label %" << littletemplabel.endlabel << ":" << endl;
      little1.level = level;
      little1.level_father = level + 1;
      littletemplabel = temp;
      break;
      */
    }
    case BREAK_:
      // if(!whiles){//在遇到不平均开闭作用域时应遇到while节点
      //    printf("Error: token break wrong at Line:%d\n",T->pos);
      //}
      cout << "br label %" << littletemplabel.endlabel << endl;
      break;
    case ASSIGNOP_: {
      if (T->ptr[0]->kind != ID_) {
        // printf("Error: id not other must before = at Line:%d\n",T->pos);
      }
      codeGen(T->ptr[1], declare_check1(little1));
      string base;
      int tttemp = type_check1(T->ptr[1]);
      strcpy(little1.type_id, T->ptr[0]->type_id);
      int tttid = declare_check11(little1);
      base += "store ";
      if (T->ptr[1]->kind == CHAR_) {
        base += i8 + " " + to_string(T->ptr[1]->type_char) + ", ";
      } else if (T->ptr[1]->kind == INT_) {
        base += i32 + " " + to_string(T->ptr[1]->type_int) + ", ";
      } else if (T->ptr[1]->kind == FLOAT_) {
        base += ifloat + " " + to_string(T->ptr[1]->type_float) + ", ";
      } else if (tttemp == CHAR_) {
        base += i8 + " %" + to_string(counter - 1) + ", ";
      } else if (tttemp == INT_) {
        base += i32 + " %" + to_string(counter - 1) + ", ";
      } else if (tttemp == FLOAT_) {
        base += ifloat + " %" + to_string(counter - 1) + ", ";
      }
      if (semantictable1[tttid].type == CHAR_) {
        base +=
            i8 + "* %" + to_string(semantictable1[tttid].tempid) + ", align 1";
      } else if (semantictable1[tttid].type == INT_) {
        base +=
            i32 + "* %" + to_string(semantictable1[tttid].tempid) + ", align 4";
      } else if (semantictable1[tttid].type == FLOAT_) {
        base += ifloat + "* %" + to_string(semantictable1[tttid].tempid) +
                ", align 4";
      }
      cout << base << endl;
      break;
    }
    case PLUSASS_:
    case MINUSASS_:
    case STARASS_:
    case DIVASS_:
      if (T->ptr[0]->kind != ID_) {
        //("Error: id not other must id before = at Line:%d\n",T->pos);
      }
      strcpy(little1.type_id, T->ptr[0]->type_id);
      if (!declare_check1(little1)) {
        // printf("Error: must declare before = at Line:%d\n",T->pos);
      }
      if (declare_check1(little1) == CHAR && type_check1(T->ptr[1]) != CHAR) {
        // printf("Error: type error at Line:%d\n",T->pos);
      }
      codeGen(T->ptr[1], declare_check1(little1));
      break;
    case AND_: {
      templabel temp = littletemplabel;
      littletemplabel.before = 0;
      littletemplabel.begin = 1;
      littletemplabel.end = 1;
      littletemplabel.beginlabel = "hard" + to_string(counter - 1) + "beginand";
      littletemplabel.endlabel = "hard" + to_string(counter - 1) + "endand";
      codeGen(T->ptr[0], level);
      string base = "br i1 %" + to_string(counter - 1) + ", label %" +
                    littletemplabel.beginlabel + ", label %" + temp.endlabel;
      cout << base << endl;
      cout << littletemplabel.beginlabel + ":" << endl;
      codeGen(T->ptr[1], level);
      base = "br i1 %" + to_string(counter - 1) + ", label %" +
             temp.beginlabel + ", label %" + temp.endlabel;
      littletemplabel = temp;
      cout << base << endl;
      break;
    }
    case OR_: {
      templabel temp = littletemplabel;
      littletemplabel.before = 0;
      littletemplabel.begin = 1;
      littletemplabel.end = 1;
      littletemplabel.beginlabel = "hard" + to_string(counter - 1) + "beginand";
      littletemplabel.endlabel = "hard" + to_string(counter - 1) + "endand";
      codeGen(T->ptr[0], level);
      string base = "br i1 %" + to_string(counter - 1) + ", label %" +
                    temp.beginlabel + ", label %" + littletemplabel.beginlabel;
      cout << base << endl;
      cout << littletemplabel.beginlabel + ":" << endl;
      codeGen(T->ptr[1], level);
      base = "br i1 %" + to_string(counter - 1) + ", label %" +
             temp.beginlabel + ", label %" + temp.endlabel;
      littletemplabel = temp;
      cout << base << endl;
      break;
    }
    case RELOP_: {
      codeGen(T->ptr[0], level);
      int tt1 = counter - 1;
      codeGen(T->ptr[1], level);
      int tt2 = counter - 1;
      string base = "%" + to_string(counter++) + " = icmp ";
      string ttt = T->type_id;
      if (ttt == "==") {
        base += "eq ";
      } else if (ttt == "<=") {
        base += "sle ";
      } else if (ttt == ">=") {
        base += "sge ";
      } else if (ttt == "!=") {
        base += "ne ";
      } else if (ttt == "<") {
        base += "slt ";
      } else if (ttt == ">") {
        base += "sgt ";
      }
      int temptype = type_check1(T->ptr[0]);
      if (temptype == CHAR_) {
        base += i8;
      } else if (temptype == INT_) {
        base += i32;
      } else if (temptype == FLOAT_) {
        base += ifloat;
      }
      if (T->ptr[0]->kind == CHAR_) {
        base += " " + to_string(T->ptr[0]->type_char);
      } else if (T->ptr[0]->kind == INT_) {
        base += " " + to_string(T->ptr[0]->type_int);
      } else if (T->ptr[0]->kind == FLOAT_) {
        base += " " + to_string(T->ptr[0]->type_float);
      } else {
        base += " %" + to_string(tt1);
      }
      base += ", ";
      if (T->ptr[1]->kind == CHAR_) {
        base += " " + to_string(T->ptr[1]->type_char);
      } else if (T->ptr[1]->kind == INT_) {
        base += " " + to_string(T->ptr[1]->type_int);
      } else if (T->ptr[1]->kind == FLOAT_) {
        base += " " + to_string(T->ptr[1]->type_float);
      } else {
        base += " %" + to_string(tt2);
      }
      cout << base << endl;
    } break;
    case PLUS_:
    case MINUS_:
    case STAR_:
    case DIV_:
    case MOD_: {
      //都是双目运算符
      codeGen(T->ptr[0], level);
      int tt1 = counter - 1;
      codeGen(T->ptr[1], level);
      int tt2 = counter - 1;
      int temptype = type_check1(T);
      string base = "%";
      base += to_string(counter++) + " = ";
      base += T->type_id;
      if (temptype == CHAR_)
        base += " " + i8 + " ";
      else if (temptype == INT_)
        base += " " + i32 + " ";
      else if (temptype == FLOAT_)
        base += " " + ifloat + " ";
      int temp = T->ptr[0]->kind;
      if (temp == CHAR_) {
        base += to_string(T->ptr[0]->type_char);
      } else if (temp == INT_) {
        base += to_string(T->ptr[0]->type_int);
      } else if (temp == FLOAT_) {
        base += to_string(T->ptr[0]->type_float);
      } else {
        base += "%" + to_string(tt1);
      }
      base += ", ";
      temp = T->ptr[1]->kind;
      if (temp == CHAR_) {
        base += to_string(T->ptr[1]->type_char);
      } else if (temp == INT_) {
        base += to_string(T->ptr[1]->type_int);
      } else if (temp == FLOAT_) {
        base += to_string(T->ptr[1]->type_float);
      } else {
        base += "%" + to_string(tt2);
      }
      cout << base << endl;
      break;
    }
    case UPLUSPLUS_:
    case UMINUSMINUS_:
    //暂且将左结合有结合放在一起
    case PLUSPLUS_:
    case MINUSMINUS_:
    case NOT_:
    case UMINUS_:
      codeGen(T->ptr[0], level);
      break;

    case ID_: {
      strcpy(little1.type_id, T->type_id);
      int temp = declare_check11(little1);
      little1.type = semantictable1[temp].type;
      string base = "%";
      /*
      if (semantictable1[temp].level == 0 && semantictable1[temp].father) {
        //参数
        string tempbase = "%";
        string tempstore = "store ";
        tempbase += to_string(counter++) + " = alloca ";

        base += to_string(counter++) + " = load ";
        if (semantictable1[temp].type == CHAR_) {
          tempbase += i8 + ", align 1";
          tempstore += i8 + " %" + to_string(semantictable1[temp].tempid) +
                       ", " + i8 + "* %" + to_string(counter - 2) + ", align 1";
          base += i8 + "," + i8 + "* %" + to_string(counter - 2) + ", align 1";
        } else if (semantictable1[temp].type == INT_) {
          tempbase += i32 + ", align 4";
          tempstore += i32 + " %" + to_string(semantictable1[temp].tempid) +
                       ", " + i32 + "* %" + to_string(counter - 2) +
                       ", align 4";
          base +=
              i32 + "," + i32 + "* %" + to_string(counter - 2) + ", align 4";
        } else if (semantictable1[temp].type == FLOAT_) {
          tempbase += ifloat + ", align 4";
          tempstore += ifloat + " %" + to_string(semantictable1[temp].tempid) +
                       ", " + ifloat + "* %" + to_string(counter - 2) +
                       ", align 4";
          base += ifloat + "," + ifloat + "* %" + to_string(counter - 2) +
                  ", align 4";
        }
        cout << tempbase << endl;
        cout << tempstore << endl;
      } else
      */
      if (semantictable1[temp].level == 0 && semantictable1[temp].father == 0) {
        base += to_string(counter++) + " = load ";
        if (semantictable1[temp].type == CHAR_) {
          base += i8 + "," + i8 + "* @" + (semantictable1[temp].type_id) +
                  ", align 1";
        } else if (semantictable1[temp].type == INT_) {
          base += i32 + "," + i32 + "* @" + (semantictable1[temp].type_id) +
                  ", align 4";
        } else if (semantictable1[temp].type == FLOAT_) {
          base += ifloat + "," + ifloat + "* @" +
                  (semantictable1[temp].type_id) + ", align 4";
        }
        //全局变量
      } else {
        base += to_string(counter++) + " = load ";
        if (semantictable1[temp].type == CHAR_) {
          base += i8 + "," + i8 + "* %" +
                  to_string(semantictable1[temp].tempid) + ", align 1";
        } else if (semantictable1[temp].type == INT_) {
          base += i32 + "," + i32 + "* %" +
                  to_string(semantictable1[temp].tempid) + ", align 4";
        } else if (semantictable1[temp].type == FLOAT_) {
          base += ifloat + "," + ifloat + "* %" +
                  to_string(semantictable1[temp].tempid) + ", align 4";
        }
      }
      cout << base << endl;
      break;
    }
    case INT_:
      break;
    case FLOAT_:
      break;
    case CHAR_:
      break;
    case FUNC_CALL: {
      codeGen(T->ptr[0], level);

      strcpy(little1.type_id, T->type_id);
      little1.is_func = 3;
      int temptype = declare_check1(little1);

      string base = "%" + to_string(counter++) + " = call ";
      if (temptype == CHAR_) {
        base += i8;
      } else if (temptype == INT_) {
        base += i32;
      } else if (temptype == FLOAT_) {
        base += ifloat;
      }
      base = base + " @" + (T->type_id);
      cout << base << "(";
      cout << tempargs;
      tempargs.clear();
      cout << ")" << endl;
      little1.is_func = 0;
      break;
    }
    case ARGS_: {
      codeGen(T->ptr[0], level);
      int temp = T->ptr[0]->kind;
      if (temp != INT_ && temp != CHAR_ && temp != FLOAT_) {
        if (little1.type == CHAR_) {
          tempargs = i8;
        } else if (little1.type == INT_) {
          tempargs = i32;
        } else if (little1.type == FLOAT_) {
          tempargs = ifloat;
        }
        tempargs += " %" + to_string(counter - 1);
      } else {
        if (temp == CHAR_) {
          tempargs = i8;
          tempargs += " " + to_string(T->ptr[0]->type_char);
        } else if (temp == INT_) {
          tempargs = i32;
          tempargs += " " + to_string(T->ptr[0]->type_int);
        } else if (temp == FLOAT_) {
          tempargs = ifloat;
          tempargs += " " + to_string(T->ptr[0]->type_float);
        }
      }
      if (T->ptr[1])
        tempargs += ", ";
      codeGen(T->ptr[1], level);
      break;
    }
    case JLT:
    case JLE:
    case JGT:
    case JGE:
    case EQ:
    case NEQ:
      break;
    default:
      break;
    }
  }
}