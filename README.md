[toc]

## flex

文件包括定义部分，规则部分和用户子程序部分，其中定义部分主要包含c语言的一些宏定义，如文件包含、宏名定义，以及一些变量和类型的定义和声明。%{ 到%}之外的部分是一些正规式宏名的定义，这些宏名在后面的规则部分会用到。

{int}表示在宏定义中正则式宏名定义对应的名

int    [0-9]+表示int类型数字

“int"表示匹配int

## bison
和flex基本结构相似，用来进行语法分析
使用Bison采用的是LR分析法，需要在每条规则后给出相应的语义动作,例如对规则：Exp →Exp =Exp，在parser.y中为：

	Exp:  Exp ASSIGNOP Exp {$$=mknode(ASSIGNOP,$1,$3,NULL,yylineno); }
	规则后面{}中的是当完成归约时要执行的语义动作。规则左部的Exp的属性值用$$表示，右部有2个Exp，位置序号分别是1和3，其属性值分别用$1和$3表示。
## 定义高级语言
数据类型包括char，int和float

基本运算包括算术运算、比较运算、逻辑运算、自增自减运算和复合赋值运算

控制语句包括if while

函数包括声明和定义

其他包括数组、结构、for循环

需要识别的单词有五类：关键字（保留字）、运算符、界符、常量和标识符
关键字 auto char const double enum extern float int long resister restrict 等
**可以考虑16进制数字**
语法分析相当于使用bison中根据文法设置的规则进行LR分析，可以设置规约时指定的函数，设计结构保存数据到语法树。当归约到开始符时执行display以及语义分析的函数。

**需要搞明白bison调用flex时，flex是怎么执行，其语句是否有用**
**不同进制之间的转换**

注释：\/\*([^*]|\*+[^/*])*\*+\/ {printf("Get \/**/!\n");} 需要对/进行转义
单行注释："//".*\n? 	{}   ？表示匹配0或1次换行

自定义版本
优化变量定义语句，减少一个定义语法，内外变量使用相同的语法，换成优化内部语法，因为仍需要判断内外。。。。并且外部变量和内部变量的空间分配不同
支持函数声明 因此在ast中针对修改根据是否有函数体输出函数声明

删除分号

结构中必须以中括号开头和结尾
```
G[program]:
  program → ExtDefList//开始
  ExtDefList → ε              //变量定义或函数定义或函数声明
        | Specifier DecList ENTERS ExtDefList// 外部变量
        | Specifier DecList  ExtDefList 
        | Specifier FunDec CompSt ENTERS ExtDefList
        | Specifier FunDec ENTERS ExtDefList
  Specifier → int 
            | float 
            | char//类型
  DecList → Dec  
          | Dec , DecList		//解决一次性定义多个情况
  Dec → VarDec  
      | VarDec = Exp //初始化问题
  VarDec → ID//变量名字对应到ID

  FunDec → ID ( VarList )  //形参比较特殊并没有分配实际的空间因此需要特殊处理
  VarList → ε//无参
        | ParamDec//参数变量定义，同样是递归定义
        | ParamDec , VarList   
  ParamDec → Specifier VarDec//参数只是临时或内部变量  
  
  CompSt → { ENTERS DefList StmList }//代码段
  DefList → ε
          | Specifier DecList ENTERS DefList
  StmList → ε
          | Stmt StmList
  Stmt → Exp ENTERS
        | CompSt ENTERS
        | return Exp ENTERS
        | if ( Exp ) ENTERS CompSt ENTERS
        | if ( Exp ) ENTERS CompSt else CompSt ENTERS
        | while ( Exp ) ENTERS CompSt ENTERS
        | BREAK ENTERS

  Exp → Exp =Exp  
        | Exp += Exp 
        | Exp -= Exp 
        | Exp *= Exp 
        | Exp /= Exp //复合赋值运算 

        | ++ Exp 
        | -- Exp 
        | Exp --
        | Exp ++ //自增自减运算

        | Exp && Exp 
        | Exp || Exp//逻辑运算
        | Exp < Exp
        | Exp <= Exp
        | Exp == Exp
        | Exp != Exp
        | Exp > Exp 
        | Exp >= Exp //比较运算
        | Exp + Exp
        | Exp - Exp  
        | Exp * Exp
        | Exp / Exp	
        | Exp % Exp //算术运算
        | ( Exp ) //括号表达式
        | - Exp  
        | ! Exp  
        | ID ( Args )  
      
        | ID 
        | INT | FLOAT |CHAR //终结符
  Args→ ε
        | Exp , Args  
        | Exp
  ENTERS→ ENTER
        | ENTER ENTERS
```

重写文法，将错误处理融合到语法中。

Bison使用的时LR分析，需要在每条规则后给出相应的语义动作。

支持函数声明，因此需要将函数是声明还是定义保存在节点信息中。

首先区分逻辑如下：

- 变量的定义和声明，
- 函数的声明和定义
- 代码块，可以是函数的代码块也可以是if while 等结构体的代码块
- if while等控制语句，需要注意if_else if_else if_else 等。
- 计算语句也就是复杂表达式，这里可以函数的调用，
- bison提供了error和yyerror记号用来进行错误处理
词法分析中的错误处理和恢复
错误分类
- 标识符违法，标识符是以字母或下划线开头的一串由字母、数字或下划线构成的序列
- 常量违法，常量违法一般为写法不对，比如单个字符'c'缺少前或后单引号，float只有.后面没有数字
- 缺少";",单字符缺少"'",
- 遇到定义之外的字符串,
匹配非法单字符常量遇到很大二义性的问题，因为所有的可打印字符都是常量也就是所有的代码都是常量,哈哈哈哈哈，幸好我用gcc试了一下，他也没辙,
- ![image-20191116211217400](./char.png)

- \'[^'\\] {**printf**("单字符缺少后引号:\"%s\"\n\t at Line %d\n",yytext,yylineno);\

  ​          yylval.type_char=yytext[1]; return CHAR;/*仍可以返回，但可能对其他产生影响*/}

  [^'\\]\' {**printf**("单字符缺少前引号:\"%s\"\n\t at Line %d\n",yytext,yylineno);\

  ​          yylval.type_char=yytext[0]; return CHAR;/*仍可以返回，但可能对其他产生影响*/}这样不行，可以考虑全部放在.模式中间

- ![image-20191116211812532](./char2.png)

- 因此自己的处理策略就是报错，加将单引号当做前单引号，因为对前后单引号的区分涉及语法语义。

- 支持一类warning，也就是关键字拼写错误被误判成id。

词法分析错误

- 外部变量只能定义和初始化，当出现表达式,结构体,代码段时应当报错并进行下一行,

- 多变量定义出错a,,b

- 基本运算包括算术运算、比较运算、逻辑运算、自增自减运算和复合赋值运算

- 等于号之前出错,最难处理,

- 加减乘除运算符,

- 复合赋值运算符,

- 其他错误

- 控制语句包括if while

- 这里主要是括号不匹配,

- 函数包括声明和定义

- 函数括号不匹配,参数定义不匹配,这个在上面已经解决

- 大括号不匹配

- 其他包括数组、结构、for循环

- 行尾没有终结符

- 多重定义的名字或没有引用没有定义的id

- 




![image-20191117204847678](./conflict.png)







Dec:      VarDec  {\$\$=\$1;}
        | VarDec ASSIGNOP Exp ENTER  {​\$\$=mknode(ASSIGNOP,\$1,\$3,NULL,NULL,yylineno);strcpy(\$\$->type_id,"ASSIGNOP");}
        ;
这里不加enter会产生二义性这时因为之前换行符没有匹配好

然后修改ast文件，修改节点类型构成

语义分析：

1. 符号表的管理
   1. 保存信息:程序,过程,函数,自定义标识符,常量,标点,类型,函数参数个数,常量数值,目标地址.
   2. 顺序表
   3. 添加read和write默认函数,因此程序不可声明read和write
   4. 操作包括创建符号表,插入表项,查询表项,修改表项,删除表项,释放符号表.
2. 静态语义分析
   1. 控制流检查,break,必须出现在循环当中
   2. 唯一性检查,同一作用域的标识符不能同名,
   3. 名字的上下文相关性检查,变量和函数在使用前必须经过声明
   4. 类型检查,函数参数传递过程中形参和实参类型是否匹配,是否进行自动类型转换.
   5. 赋值语句前表达式必须是id
3. 使用顺序数组保存结构,每个结构中保存当前节点类型,所属结构,或结构中所拥有的变量,表达式,


语义分析对应的语义计算,遍历语法树模拟语法制导的语义分析,考虑继承属性和综合属性


语义检查

    变量或过程未经声明就使用
    变量或过程名重复声明
    运算分量类型不匹配
    操作符与操作数之间的类型不匹配
        数组下标不是整数
        对非数组变量使用数组访问操作符
        对非过程名使用过程调用操作符
        过程调用的参数类型或数目不匹配
        函数返回类型有误

定位一个变量
既然支持函数声明,就需要在最后检测声明的函数是否定义
用level_father表示上一个而非父亲节点,这样可以检测所有的情况

## 中间代码生成
首先参照llvm的中间代码
http://llvm.org/docs/LangRef.html#abstract

描述整个代码分布
- 外部变量段
- 函数声明段
- 函数定义段
 - 局部变量段
 - 表达式,条件语句,while循环
 - 函数调用,break控制
 - 表达式
  - 单目
  - 双目
  - 优先级和结合性
  - 中间变量
 - 条件语句
  - 标号跳转
 - return语句

对于全局的附加描述
可以使用llvm IR标号思想,将自定义变量和中间变量通过不同的命名方式分开

标识符:

现在需要解决参数的关系,然后就可以进行了.

不care函数声明
设置一个全局counter表示临时变量,重点在于如何组织符号表,可以将原符号表的唯一id和这个counter临时变量结合,动态修改符号表
又一难点是基本块的划分,
先只支持同类型赋值

对于参数的处理,当使用参数时先将参数复制到新临时变量然后引用该临时变量;对于全局变量的处理,直接判断,因为全局变量有自己的标识符

对于操作符的处理:http://llvm.org/docs/LangRef.html#binary-operations

关于流程控制语句if while return break 等共同分析共性,进行跳转,跳转时针对ast每一次都会跳转到上一层,这样利用栈很方便,while 语句需要无条件跳回语句实现循环,or 和 and 结构相同,逻辑相反,但是稍微修改即可

如果if里面是逻辑语句则进入逻辑语句跳转由逻辑语句实现,如果是比较语句最后的跳转由if语句实现,

如果是逻辑语句,其根据实现跳转到上一层对应位置

这个label真奇怪为什么和冒号之间不能有空格
在引用label之前需要添加%
**函数参数出错**

i32* :i32指针
label 命名规则:
函数定义包含基本块列表，这些基本块构成函数的CFG（控制流程图）。每个基本块可以选择以标签开头（为基本块提供符号表条目），包含指令列表，并以终止符指令（例如分支或函数返回）结束。如果未提供明确的标签名称，则会使用与**未命名临时对象相同的计数器中的下一个值**，为块分配隐式编号标签（请参见上文）。例如，如果功能输入块没有显式标签，则将为其分配标签“％0”，然后该块中的第一个未命名临时名称将是“％1”，依此类推。如果显式指定了数字标签，它必须与将隐式使用的数字标签匹配。
#hao:
属性组是IR中对象引用的属性组。它们对于保持.ll文件可读性很重要，因为许多功能将使用同一组属性。在与.ll单个.c文件对应的文件的退化情况下 ，单个属性组将捕获用于构建该文件的重要命令行标志。

属性组是模块级别的对象。要使用属性组，对象应引用属性组的ID（例如#37）。一个对象可以引用多个属性组。在这种情况下，来自不同组的属性将合并。

这是一个应始终内联，堆栈对齐方式为4且不应使用SSE指令的函数的属性组示例：

; Target-independent attributes:
attributes #0 = { alwaysinline alignstack=4 }

; Target-dependent attributes:
attributes #1 = { "no-sse" }

; Function @f has attributes: alwaysinline, alignstack=4, and "no-sse".
define void @f() #0 #1 { ... }


外部变量
函数
内部参数


使用llvm方式添加架构生成对应的汇编码及文件
lli llc llvm-as
llvm-as的主要功能就是将汇编代码转换到二进制指令

lli 可以执行ll和bc两种格式,因为他们本质是一样的
