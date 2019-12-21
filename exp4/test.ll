@_a = common global i32 0, align 4
@b = common global i32 0, align 4
@c = common global i32 0, align 4
define i32 @read()
define i32 @fibo(i32)
{
%2 = alloca i32, align 4
store i32 %0, i32 *%2, align 4
store i32 1, i32* %2, align 4
%3 = load i32,i32* %2, align 4
%4 = icmp eq i32 %3,  1
br i1 %4, label %hard2begin, label %hard2beginand
hard2beginand:
%5 = load i32,i32* %2, align 4
%6 = icmp eq i32 %5,  2
br i1 %6, label %hard2begin, label %hard2end
hard2begin:
ret i32 1
br label %hard2end
hard2end:
%8 = load i32,i32* %2, align 4
%9 = sub i32 %8, 1
%10 = call i32 @fibo(i32 %9)
%11 = load i32,i32* %2, align 4
%12 = sub i32 %11, 2
%13 = call i32 @fibo(i32 %12)
%14 = add i32 %10, %13
ret i32 %14
}
define i32 @main()
{
%1 = alloca i32, align 4
%2 = alloca i32, align 4
%3 = alloca i32, align 4
store i32 1, i32* %3, align 4
%4 = call i32 @read()
store i32* %1, align 4
br label %hard4before
hard4before:
%5 = load i32,i32* %3, align 4
%6 = load i32,i32* %1, align 4
%7 = icmp sle i32 %5,  %6
br i1 %7, label %hard4begin, label %hard4end
hard4begin:
%8 = load i32,i32* %3, align 4
%9 = call i32 @fibo(i32 %8)
store i32 %9, i32* %2, align 4
br label %hard4end
br label %hard4before
hard4end:
ret i32 1
}
declare i32 @putchar(i8)
