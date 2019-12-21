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
extern "C"
{	
	int yywrap(void);
	int yylex(void);
}
//flex为bison提供行号信息
%}
%option yylineno 

id   [A-Za-z_][A-Za-z0-9_]*
int    [0-9]+
char \'[^'\\]\'
float  ([0-9]*\.[0-9]+)|([0-9]+\.)

%%
{int}        {yylval.type_int=atoi(yytext); return INT;}
{float}      {yylval.type_float=atof(yytext); return FLOAT;}
{char}      {yylval.type_char=yytext[1]; return CHAR;/*这种情况下，正则需要简便处理*/}

"int"        {strcpy(yylval.type_id,  yytext);return TYPE;}
"float"      {strcpy(yylval.type_id,  yytext);return TYPE;}
"char"      {strcpy(yylval.type_id,  yytext);return TYPE;}
"return"     {return RETURN;}
"if"         {return IF;}
"else"       {return ELSE;}
"while"      {return WHILE;}
"break"		{return BREAK;}
{id}       {strcpy(yylval.type_id,  yytext); return ID;/*由于关键字的形式也符合表示符的规则，所以把关键字的处理全部放在标识符的前面，优先识别*/}

";"			{return SEMI;}
","			{return COMMA;}
">"|"<"|">="|"<="|"=="|"!=" {strcpy(yylval.type_id, yytext);return RELOP;}
"="			{return ASSIGNOP;}
"+="		{return PLUSASS;}
"-="		{return MINUSASS;}
"*="		{return STARASS;}
"/="		{return DIVASS;}
"%="		{/*模运算可能后期有点难，先不支持*/}

"++"		{return PLUSPLUS;}
"--" 		{return MINUSMINUS;}

"+"			{return PLUS;}
"-"			{return MINUS;}
"*"			{return STAR;}
"/"			{return DIV;}
"%"			{return MOD;}
"&&"        {return AND;}
"||"		{return OR;}
"!"			{return NOT;}
"("			{return LP;}
")"			{return RP;}
"{"			{return LC;}
"}"			{return RC;}
"#".*		{printf("预定义或头文件\n");}


[\n]		{yycolumn=1;return ENTER;}
[ \r\t]		{/*printf("过滤空格等字符\n");*/}
"//"[.^\n]* 		{}
\/\*([^*]|\*+[^/*])*\*+\/	{}

[0-9][a-zA-Z0-9_]* {printf("Error: Illegal ID \"%s\"\t at Line %d\n",yytext,yylineno);\
					strcpy(yylval.type_id,  yytext); return ID;/*标识非法id,但是仍旧当做正常id进行分析*/}
\'[^'\\]$	{printf("Warning: missing terminating ' character at Line %d\n",yylineno);yylval.type_char=yytext[1]; return CHAR;}
.			{if(yytext[0]=='\''){printf("Error: missing terminating ' character at Line %d\n",yylineno);yylval.type_char=yytext[1]; return CHAR;}
				else printf("Error: Mysterious character \"%s\"\t at Line %d\n",yytext,yylineno);}
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
