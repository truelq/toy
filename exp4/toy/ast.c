#include "def.h"
struct node *mknode(int kind, struct node *first, struct node *second,
                    struct node *third, struct node *fourth, int pos) {
  struct node *T = (struct node *)malloc(sizeof(struct node));
  T->kind = node_kind(kind);
  T->ptr[0] = first;
  T->ptr[1] = second;
  T->ptr[2] = third;
  T->ptr[3] = fourth;
  T->pos = pos;
  return T;
}
// indent 用来控制缩进
void display(struct node *T, int indent) { //对抽象语法树的先根遍历
  int i = 1;
  struct node *T0;
  if (T) {
    switch (T->kind) {
    case EXT_VAR_DEF:
      printf("%*c外部变量定义：\n", indent, ' ');
      display(T->ptr[0], indent + 3); //显示外部变量类型
      printf("%*c变量名：\n", indent + 3, ' ');
      display(T->ptr[1], indent + 6); //显示变量列表
      display(T->ptr[2], indent);
      display(T->ptr[3], indent);
      break;
    case TYPE_:
      printf("%*c类型： %s\n", indent, ' ', T->type_id);
      break;
    case FUNC_DECLARE:
      printf("%*c函数声明：\n", indent, ' ');
      display(T->ptr[0], indent + 3);
      display(T->ptr[1], indent + 3);
      display(T->ptr[2], indent);
      display(T->ptr[3], indent);
      break;
    case FUNC_DEF:
      printf("%*c函数定义：\n", indent, ' ');
      display(T->ptr[0], indent + 3); //显示函数返回类型
      display(T->ptr[1], indent + 3); //显示函数名和参数
      display(T->ptr[2], indent + 3);
      display(T->ptr[3], indent); //显示函数体
      break;
    case FUNC_DEC:
      printf("%*c函数名：%s\n", indent, ' ', T->type_id);
      if (T->ptr[0]) {
        printf("%*c函数形参：\n", indent, ' ');
        display(T->ptr[0], indent + 3); //显示函数参数列表
      } else
        printf("%*c无参函数\n", indent + 3, ' ');
      break;
    case PARAM_LIST:
      display(T->ptr[0], indent); //依次显示全部参数类型和名称，
      display(T->ptr[1], indent);
      break;
    case PARAM_DEC:
      printf("%*c类型：%s  参数名：%s\n", indent, ' ',
             T->ptr[0]->type == INT
                 ? "int"
                 : T->ptr[0]->type == FLOAT ? "float" : "char",
             T->ptr[1]->type_id);
      break;
    case EXP_STMT:
      printf("%*c表达式语句：\n", indent, ' ');
      display(T->ptr[0], indent + 3);
      break;
    case RETURN_:
      printf("%*c返回语句：\n", indent, ' ');
      display(T->ptr[0], indent + 3);
      break;
    case COMP_STM:
      printf("%*c复合语句：\n", indent, ' ');
      printf("%*c复合语句的变量定义：\n", indent + 3, ' ');
      display(T->ptr[0], indent + 6); //显示定义部分
      printf("%*c复合语句的语句部分：\n", indent + 3, ' ');
      display(T->ptr[1], indent + 6); //显示语句部分
      break;
    case STM_LIST:
      display(T->ptr[0], indent); //显示第一条语句
      display(T->ptr[1], indent); //显示剩下语句
      break;
    case WHILE_:
      printf("%*c循环语句：\n", indent, ' ');
      printf("%*c循环条件：\n", indent + 3, ' ');
      display(T->ptr[0], indent + 6); //显示循环条件
      printf("%*c循环体：\n", indent + 3, ' ');
      display(T->ptr[1], indent + 6); //显示循环体
      break;
    case IF_THEN_:
      printf("%*c条件语句(IF_THEN)：\n", indent, ' ');
      printf("%*c条件：\n", indent + 3, ' ');
      display(T->ptr[0], indent + 6); //显示条件
      printf("%*cIF子句：\n", indent + 3, ' ');
      display(T->ptr[1], indent + 6); //显示if子句
      break;
    case IF_THEN_ELSE_:
      printf("%*c条件语句(IF_THEN_ELSE)：\n", indent, ' ');
      printf("%*c条件：\n", indent + 3, ' ');
      display(T->ptr[0], indent + 6); //显示条件
      printf("%*cIF子句：\n", indent + 3, ' ');
      display(T->ptr[1], indent + 6); //显示if子句
      printf("%*cELSE子句：\n", indent + 3, ' ');
      display(T->ptr[2], indent + 6); //显示else子句
      break;
    case VAR_DEF:
      printf("%*cLOCAL VAR_NAME：\n", indent, ' ');
      display(T->ptr[0], indent + 3); //显示变量类型
      display(T->ptr[1], indent + 3); //显示该定义的全部变量名
      display(T->ptr[2], indent);
      break;
    case DEC_LIST:
      printf("%*cVAR_NAME：\n", indent, ' ');
      T0 = T;
      while (T0) {
        if (T0->ptr[0]->kind == ID_)
          printf("%*c %s\n", indent + 3, ' ', T0->ptr[0]->type_id);
        else if (T0->ptr[0]->kind == ASSIGNOP_) {
          printf("%*c %s ASSIGNOP\n ", indent + 3, ' ',
                 T0->ptr[0]->ptr[0]->type_id);
          //显示初始化表达式
          display(T0->ptr[0]->ptr[1],
                  indent + strlen(T0->ptr[0]->ptr[0]->type_id) + 4);
        }
        T0 = T0->ptr[1];
      }

      break;
    case ID_:
      printf("%*cID： %s\n", indent, ' ', T->type_id);
      break;
    case INT_:
      printf("%*cINT：%d\n", indent, ' ', T->type_int);
      break;
    case FLOAT_:
      printf("%*cFLAOT：%f\n", indent, ' ', T->type_float);
      break;
    case CHAR_:
      printf("%*cCHAR：%c\n", indent, ' ', T->type_char);
      break;
    case ASSIGNOP_:
    case PLUSASS_:
    case MINUSASS_:
    case STARASS_:
    case DIVASS_:
    case AND_:
    case OR_:
    case RELOP_:
    case PLUS_:
    case MINUS_:
    case STAR_:
    case DIV_:
      printf("%*c%s\n", indent, ' ', T->type_id);
      display(T->ptr[0], indent + 3);
      display(T->ptr[1], indent + 3);
      break;

    case UPLUSPLUS_:
    case UMINUSMINUS_:
    //暂且将左结合有结合放在一起
    case PLUSPLUS_:
    case MINUSMINUS_:
    case NOT_:
    case UMINUS_:
      printf("%*c%s\n", indent, ' ', T->type_id);
      display(T->ptr[0], indent + 3);
      break;
    case FUNC_CALL:
      printf("%*c函数调用：\n", indent, ' ');
      printf("%*c函数名：%s\n", indent + 3, ' ', T->type_id);
      display(T->ptr[0], indent + 3);
      break;
    case ARGS_:
      i = 1;
      while (
          T) { // ARGS表示实际参数表达式序列结点，其第一棵子树为其一个实际参数表达式，第二棵子树为剩下的。
        struct node *T0 = T->ptr[0];
        printf("%*c第%d个实际参数表达式：\n", indent, ' ', i++);
        display(T0, indent + 3);
        T = T->ptr[1];
      }
      //                    printf("%*c第%d个实际参数表达式：\n",indent,' ',i);
      //                  display(T,indent+3);
      printf("\n");
      break;
    default: break;
    }
  }
}
