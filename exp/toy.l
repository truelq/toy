%{
#include "toy.tab.h"
#include "string.h"
#include "def.h"
int yycolumn=1;
#define YY_USER_ACTION    	yylloc.first_line=yylloc.last_line=yylineno; \
	yylloc.first_column=yycolumn;	yylloc.last_column=yycolumn+yyleng-1; yycolumn+=yyleng;
/*为了获得列号，使用lex提供的YY_USER_ACTION宏，对它重新定义，定义为一个函数，每次在识别成分之前会调用该函数，获得yylloc结构信息，包括first_line、first_column、last_line、last_column。这些信息在之后语法分析错误处理的时候也可以用上，用来定位出错位置。*/
typedef union {
	//flex进行scanner，将数值存入yylval。而bison读取yylval之中的值。
	//
	int type_int;
	float type_float;//这里可能有错
	int type_char;//int 肯定可以保存char啊
	char type_id[32];
	struct node *ptr;
} YYLVAL;
#define YYSTYPE yylval

%}
%option yylineno

id   [A-Za-z][A-Za-z0-9]*  
int    [0-9]+
char \'([^'\\]|\\['"?\\abfnrtv"]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+)+\'
float  ([0-9]*\.[0-9]+)|([0-9]+\.)

%%
{int}        {printf("int常量：%s\n",yytext);yylval.type_int=atoi(yytext); return INT;}
{float}      {printf("float常量：%s\n",yytext);yylval.type_float=atof(yytext); return FLOAT;}
{char}      {printf("char常量：%s\n",yytext);yylval.type_char=yytext[1]; return CHAR;}

"int"        {printf("关键字：%s\n",yytext);strcpy(yylval.type_id,  yytext);return TYPE;}
"float"      {printf("关键字：%s\n",yytext);strcpy(yylval.type_id,  yytext);return TYPE;}
"char"      {printf("关键字：%s\n",yytext);strcpy(yylval.type_id,  yytext);return TYPE;}

"return"     {printf("关键字：%s\n",yytext);return RETURN;}
"if"         {printf("关键字：%s\n",yytext);return IF;}
"else"       {printf("关键字：%s\n",yytext);return ELSE;}
"while"      {printf("关键字：%s\n",yytext);return WHILE;}

{id}       {printf("标识符：%s\n",yytext);strcpy(yylval.type_id,  yytext); return ID;/*由于关键字的形式也符合表示符的规则，所以把关键字的处理全部放在标识符的前面，优先识别*/}
";"			{return SEMI;}
","			{printf("逗号运算符：%s\n",yytext);return COMMA;}
">"|"<"|">="|"<="|"=="|"!=" {printf("比较运算符：%s\n",yytext);strcpy(yylval.type_id, yytext);;return RELOP;}
"="			{printf("赋值运算符：%s\n",yytext);return ASSIGNOP;}
"+="		{printf("复合赋值运算符：%s\n",yytext);return PLUSASS;}
"-="		{printf("复合赋值运算符：%s\n",yytext);return MINUSASS;}
"*="		{printf("复合赋值运算符：%s\n",yytext);return STARASS;}
"/="		{printf("复合赋值运算符：%s\n",yytext);return DIVASS;}
"%="		{/*模运算可能后期有点难，先不支持*/}

"++"		{printf("自增运算符：%s\n",yytext);return PLUSPLUS;}
"--" 		{printf("自减运算符：%s\n",yytext);return MINUSMINUS;}

"+"			{printf("算术运算符：%s\n",yytext);return PLUS;}
"-"			{printf("算术运算符：%s\n",yytext);return MINUS;}
"*"			{printf("算术运算符：%s\n",yytext);return STAR;}
"/"			{printf("算术运算符：%s\n",yytext);return DIV;}
"%"			{}
"&&"         {printf("逻辑运算符：%s\n",yytext);return AND;}
"||"            {printf("逻辑运算符：%s\n",yytext);return OR;}
"!"			{printf("逻辑运算符：%s\n",yytext);return NOT;}
"("			{printf("左界符：%s\n",yytext);return LP;}
")"			{printf("右界符：%s\n",yytext);return RP;}
"{"			{printf("左界符：%s\n",yytext);return LC;}
"}"			{printf("右界符：%s\n",yytext);return RC;}
[\n]           {yycolumn=1;}   
[ \r\t]          {}   
"//".* 	{printf("Get \/\/ note\n");}
\/\*([^*]|\*+[^/*])*\*+\/	{printf("Get \/**/ note\n");}
.			{printf("Error type A :Mysterious character \"%s\"\n\t at Line %d\n",yytext,yylineno);}
%%

/*
//词法分析输出二元组
void main(int argc,char **argv)
{
	if(argc<2){
		fprintf(stderr,"need filename\n");
		return 1;
	}
	if(!(yyin=fopen(argv[1],"r"))){
		perror(argv[1]);
		return (1);
	}
	yylex();
	
}
*/
int yywrap()
{
return 1;
}
