%error-verbose
%locations
//bison的.y文件中，加入％locations，这样bison加入－d编译后的.h符号表文件中会多出一个YYLTYPE结构体定义和一个该结构体类型的全局变量yylloc，这样，flex的.l文件include该.h文件后，该结构体类型就可以被flex知道，且flex可以向yylloc里面填入信息。

%{
#include "stdio.h"
#include "math.h"
#include "string.h"
#include "def.h"
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
char myerror[255];
void myyyerror();
extern "C"
{	
void yyerror(const char* fmt, ...);
extern int yylex(void);
}
%}

%union {
	int    type_int;
	float  type_float;
        int   type_char;
	char   type_id[32];
	struct node *ptr;
};
//union的默认结构体类型为YYSTYPE，相当于自己把YYSTYPE重新定义为union类型。所以相应的yylval也变为union类型。
//这个union类型-d选项编译时会放在头文件中
//  %type 定义非终结符的语义值类型
%type  <ptr> program ExtDefList Specifier FunDec  Stmt  CompSt VarList VarDec ParamDec StmList DefList DecList Dec Exp Args

//% token 定义终结符的语义值类型
%token <type_int> INT              //指定INT的语义值是type_int，有词法分析得到的数值
%token <type_id> ID RELOP TYPE  //指定ID,RELOP 的语义值是type_id，有词法分析得到的标识符字符串mmecpy得到的
%token <type_float> FLOAT         //指定ID的语义值是type_float，有词法分析得到的float
%token <type_char> CHAR
%token LP RP LC RC SEMI COMMA ENTER  //用bison对该文件编译时，带参数-d，生成的exp.tab.h中给这些单词进行编码，可在lex.l中包含parser.tab.h使用这些单词种类码
%token PLUS MINUS STAR DIV ASSIGNOP AND OR NOT IF BREAK ELSE WHILE RETURN PLUSASS MINUSASS STARASS DIVASS PLUSPLUS MINUSMINUS
//由低到高的定义优先级

%left COMMA
%left ASSIGNOP PLUSASS MINUSASS STARASS DIVASS
//先不支持？三目运算
%left OR
%left AND
%left RELOP//比较运算内部暂不定义优先级
%left PLUS MINUS
%left STAR DIV
%right UMINUS NOT UPLUSPLUS UMINUSMINUS
%left PLUSPLUS MINUSMINUS

%nonassoc LOWER_THEN_ELSE //无结合性
%nonassoc ELSE

%%

program: ExtDefList    { display($1,0);semanticanalysis($1,0);semanticanalysis1($1,0);}     /*显示语法树*/
        ;
ExtDefList: {$$=NULL;}
        | Specifier DecList ENTERS ExtDefList {$$=mknode(EXT_VAR_DEF,$1,$2,$4,NULL,yylineno);}
        | Specifier DecList  ExtDefList {$$=mknode(EXT_VAR_DEF,$1,$2,$3,NULL,yylineno);}
        | Specifier FunDec CompSt ENTERS ExtDefList{$$=mknode(FUNC_DEF,$1,$2,$3,$5,yylineno);}
        | Specifier FunDec ENTERS ExtDefList{$$=mknode(FUNC_DECLARE,$1,$2,$4,NULL,yylineno);}
        
        | Specifier FunDec CompSt error RC ExtDefList{$$=mknode(FUNC_DECLARE,$1,$2,$6,NULL,yylineno);sprintf(myerror," error in Func def");}

        | RETURN Exp  ENTERS ExtDefList{sprintf(myerror," Error : wrong  stmt");$$=$4;myyyerror();}
        | IF LP Exp  RP ENTERS CompSt ENTERS ExtDefList %prec LOWER_THEN_ELSE   {sprintf(myerror," Error : wrong  stmt");$$=$8;myyyerror();}
        | IF LP Exp  RP ENTERS CompSt ENTERS ELSE ENTERS CompSt ENTERS  ExtDefList {sprintf(myerror," Error : wrong  stmt");$$=$12;myyyerror();}
        | WHILE LP Exp  RP ENTERS CompSt ENTERS ExtDefList {sprintf(myerror," Error : wrong  stmt");$$=$8;myyyerror();}
        | error ENTERS ExtDefList {sprintf(myerror," Error : wrong ");$$=$3;myyyerror();}
        ;
Specifier: TYPE {$$=mknode(TYPE,NULL,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);$$->type=!strcmp($1,"int")?INT_:!strcmp($1,"float")?FLOAT_:CHAR_;}   
        ;
DecList:  Dec  {$$=mknode(DEC_LIST,$1,NULL,NULL,NULL,yylineno);}
        | Dec COMMA DecList  {$$=mknode(DEC_LIST,$1,$3,NULL,NULL,yylineno);}
        | COMMA  DecList {sprintf(myerror," too more ','");$$=$2;myyyerror();}
        | COMMA  {sprintf(myerror," too more ','");$$=NULL;myyyerror();}
        ;
Dec:      VarDec  {$$=$1;}
        | VarDec ASSIGNOP Exp  {$$=mknode(ASSIGNOP_,$1,$3,NULL,NULL,yylineno);strcpy($$->type_id,"ASSIGNOP");}
        ;
VarDec:  ID {$$=mknode(ID_,NULL,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}   //ID结点，标识符符号串存放结点的type_id
        ;
FunDec: ID LP VarList RP   {$$=mknode(FUNC_DEC,$3,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);}//函数名存放在$$->type_id

        ;
VarList: {$$=NULL;}
        | ParamDec {$$=mknode(PARAM_LIST,$1,NULL,NULL,NULL,yylineno);}
        | ParamDec COMMA  VarList  {$$=mknode(PARAM_LIST,$1,$3,NULL,NULL,yylineno);}
        ;
ParamDec: Specifier VarDec {$$=mknode(PARAM_DEC,$1,$2,NULL,NULL,yylineno);}
        ;
CompSt:   LC ENTERS DefList StmList RC {$$=mknode(COMP_STM,$3,$4,NULL,NULL,yylineno);}
        | error RC {sprintf(myerror," big error in Conmpst");$$=NULL;}
        ;
DefList: {$$=NULL; }
        | Specifier DecList ENTERS DefList {$$=mknode(VAR_DEF,$1,$2,$4,NULL,yylineno);}
        ;
StmList: {$$=NULL; }  
        | Stmt StmList  {$$=mknode(STM_LIST,$1,$2,NULL,NULL,yylineno);}
        ;
Stmt:     Exp ENTERS {$$=mknode(EXP_STMT,$1,NULL,NULL,NULL,yylineno);}
        | CompSt ENTERS {$$=mknode(COMPT,$1,NULL,NULL,NULL,yylineno);}      //复合语句结点直接最为语句结点，不再生成新的结点
        | RETURN Exp ENTERS {$$=mknode(RETURN_,$2,NULL,NULL,NULL,yylineno);}
        | IF LP Exp RP ENTERS CompSt ENTERS %prec LOWER_THEN_ELSE   {$$=mknode(IF_THEN_,$3,$6,NULL,NULL,yylineno);}
        | IF LP Exp RP ENTERS CompSt ENTERS ELSE ENTERS CompSt ENTERS   {$$=mknode(IF_THEN_ELSE_,$3,$6,$10,NULL,yylineno);}
        | WHILE LP Exp RP ENTERS CompSt ENTERS {$$=mknode(WHILE_,$3,$6,NULL,NULL,yylineno);}
        | BREAK ENTERS {$$=mknode(BREAK_,NULL,NULL,NULL,NULL,yylineno);}

        | RETURN Exp error ENTERS {$$=mknode(RETURN_,$2,NULL,NULL,NULL,yylineno);}
        | IF LP Exp error RC ENTERS %prec LOWER_THEN_ELSE   {sprintf(myerror," IF wrong");myyyerror();$$=NULL;}
        | WHILE LP Exp error RP ENTERS CompSt error ENTERS {sprintf(myerror," WHILE wrong");$$=mknode(WHILE_,$3,$7,NULL,NULL,yylineno);}
        ;
Exp:      Exp ASSIGNOP Exp {$$=mknode(ASSIGNOP_,$1,$3,NULL,NULL,yylineno);strcpy($$->type_id,"ASSIGNOP");}//$$结点type_id空置未用，正好存放运算符
        | Exp PLUSASS Exp   {$$=mknode(PLUSASS_,$1,$3,NULL,NULL,yylineno);strcpy($$->type_id,"PLUSASS");}//复合赋值运算
        | Exp MINUSASS Exp   {$$=mknode(MINUSASS_,$1,$3,NULL,NULL,yylineno);strcpy($$->type_id,"MINUSASS");}
        | Exp STARASS Exp   {$$=mknode(STARASS_,$1,$3,NULL,NULL,yylineno);strcpy($$->type_id,"STARASS");}
        | Exp DIVASS Exp   {$$=mknode(DIVASS_,$1,$3,NULL,NULL,yylineno);strcpy($$->type_id,"DIVASS");}

        | PLUSPLUS Exp %prec UPLUSPLUS   {$$=mknode(UPLUSPLUS_,$2,NULL,NULL,NULL,yylineno);strcpy($$->type_id,"UPLUSPLUS");}//这里利用BISON %prec表示和UMINUS同优先级
        | MINUSMINUS Exp %prec UMINUSMINUS   {$$=mknode(UMINUSMINUS_,$2,NULL,NULL,NULL,yylineno);strcpy($$->type_id,"UMINUSMINUS");}//这里利用BISON %prec表示和UMINUS同优先级
        | Exp PLUSPLUS   {$$=mknode(PLUSPLUS_,$1,NULL,NULL,NULL,yylineno);strcpy($$->type_id,"PLUSPLUS");}//这里利用BISON %prec表示和UMINUS同优先级
        | Exp MINUSMINUS  {$$=mknode(MINUSMINUS_,$1,NULL,NULL,NULL,yylineno);strcpy($$->type_id,"MINUSMINUS");}//这里利用BISON %prec表示和UMINUS同优先级


        | Exp AND Exp   {$$=mknode(AND_,$1,$3,NULL,NULL,yylineno);strcpy($$->type_id,"and");}
        | Exp OR Exp    {$$=mknode(OR_,$1,$3,NULL,NULL,yylineno);strcpy($$->type_id,"or");}
        | Exp RELOP Exp {$$=mknode(RELOP_,$1,$3,NULL,NULL,yylineno);strcpy($$->type_id,$2);}  //词法分析关系运算符号自身值保存在$2中
        | Exp PLUS Exp  {$$=mknode(PLUS_,$1,$3,NULL,NULL,yylineno);strcpy($$->type_id,"add");}
        | Exp MINUS Exp {$$=mknode(MINUS_,$1,$3,NULL,NULL,yylineno);strcpy($$->type_id,"sub");}
        | Exp STAR Exp  {$$=mknode(STAR_,$1,$3,NULL,NULL,yylineno);strcpy($$->type_id,"mul");}
        | Exp DIV Exp   {$$=mknode(DIV_,$1,$3,NULL,NULL,yylineno);strcpy($$->type_id,"udiv");}
        | LP Exp RP     {$$=$2;}
        | MINUS Exp %prec UMINUS   {$$=mknode(UMINUS_,$2,NULL,NULL,NULL,yylineno);strcpy($$->type_id,"UMINUS");}//这里利用BISON %prec表示和UMINUS同优先级 相当于虚拟出一个运算符
        | NOT Exp       {$$=mknode(NOT_,$2,NULL,NULL,NULL,yylineno);strcpy($$->type_id,"NOT");}
        | ID LP Args RP {$$=mknode(FUNC_CALL,$3,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);$$->type=FUNC_CALL;}
        | ID            {$$=mknode(ID_,NULL,NULL,NULL,NULL,yylineno);strcpy($$->type_id,$1);$$->type=ID_;}
        | INT           {$$=mknode(INT_,NULL,NULL,NULL,NULL,yylineno);$$->type_int=$1;$$->type=INT_;}
        | FLOAT         {$$=mknode(FLOAT_,NULL,NULL,NULL,NULL,yylineno);$$->type_float=$1;$$->type=FLOAT_;}
        | CHAR          {$$=mknode(CHAR_,NULL,NULL,NULL,NULL,yylineno);$$->type_char=$1;$$->type=CHAR_;}
        | error    {sprintf(myerror," error in Exp");$$=NULL;myyyerror();}
        ;
Args:   {$$=NULL;}
        | Exp COMMA Args {$$=mknode(ARGS_,$1,$3,NULL,NULL,yylineno);}
        | Exp {$$=mknode(ARGS_,$1,NULL,NULL,NULL,yylineno);}
        ;
ENTERS:   ENTER {}
        | ENTER ENTERS {}
%%

int main(int argc, char *argv[]){
	yyin=fopen(argv[1],"r");
	if (!yyin) return 1;
	yylineno=1;
	yyparse();
	return 0;
}

#include<stdarg.h>
void yyerror(const char* fmt, ...)
{
    va_list ap;//取参数对应的函数
    va_start(ap, fmt);
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr,"%s",myerror);
    fprintf(stderr,"%s", ".\n");
    memset(myerror,0,sizeof(myerror));
}	
void myyyerror()
{
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
    fprintf(stderr,"%s",myerror);
    fprintf(stderr, "%s",".\n");
    memset(myerror,0,sizeof(myerror));
}