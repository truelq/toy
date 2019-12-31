@b = common global i32 0, align 4
define i32 @fibo(i32)
{
%2 = alloca i32, align 4
store i32 %0, i32 *%2, align 4
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
br label %hard3before
hard3before:
%4 = load i32,i32* %3, align 4
%5 = load i32,i32* %1, align 4
%6 = icmp sle i32 %4,  %5
br i1 %6, label %hard3begin, label %hard3end
hard3begin:
%7 = load i32,i32* %3, align 4
%8 = call i32 @fibo(i32 %7)
store i32 %8, i32* %2, align 4
%9 = load i32,i32* %3, align 4
%10 = add i32 %9, 1
store i32 %10, i32* %3, align 4
br label %hard3before
hard3end:
ret i32 1
}
declare i32 @getchar()
declare i32 @putchar(i32)
