在编写后面实验时,发现的前面的少许错误在后面改正,没有改前面
源文件主要有ast.c def.h toy.l toy.y SemanticAnalysis.cpp CodeGenerate.cpp Makefile 
最终生成文件为toy
-------------------------------------------------------------------
文件内容
exp1:
0.c 1.c 2.c 3.c 4.c bisontest.c flextest.c 均是测试文件

exp2:
1.c 2.c 3.c 4.c 5.c test.c 是测试文件

exp3:
1.c 2.c 3.c 4.c 5.c test.c 均是测试文件
.ll 结尾是IR参考文件和部分调试文件

exp4:
other 文件夹是对llvm小工具进行测试的文件夹
toy 文件夹是最终编译器的文件夹
X86 文件夹是后端文件夹 没有完成
test.c 和ttt.c 是测试程序 .ll结尾是文本形式IR .bc结尾是二进制形式IR 前两者等价

-------------------------------------------------------------------
编译编译器命令和编译器编译命令
exp1: 
make #生成toy此法和语法分析编译器
./toy 0.c #对程序进行词法分析和语法分析

exp2:
make #生成toy此法和语法分析编译器
./toy 0.c #对程序进行词法分析和语法分析和语义分析

exp3:
make #生成toy此法和语法分析编译器
./toy 1.c #生成IR代码并打印到控制台

exp4:
#linux系统中需要先安装好llvm6版本的库文件
# sudo apt-get install llvm-6.0*
cd toy
make # Makefile中利用llvm-config命令生成需要的编译参数
cd ..
./toy/toy test.c #控制台中会输出ast和符号表,IR文本形式代码被重定向输出到test.ll,IR二进制形式代码被重定向到test.bc,如果编译有错误则不会生成
llc test.bc -o test.s #生成x86汇编 test.bc 和test.ll 等价
clang test.s -o test #生成二进制 因为输入输出调用getchar等,这一步中应该有链接程序的功能
./test 
# 也可以使用lli工具直接执行test.bc 或test.ll 
# lli test.bc