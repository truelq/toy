define i32 @fibo(i32)
{
%2 = alloca i32, align 4
store i32 %0, i32 *%2, align 4
ret i32 1
}
define i32 @main()
{
%1 = alloca i32, align 4
%2 = alloca i32, align 4
%3 = alloca i32, align 4
store i32 1, i32* %3, align 4
%4 = load i32,i32* %3, align 4
%5 = call i32 @fibo(i32 %4)
store i32 %5, i32* %2, align 4
ret i32 1
}
declare i32 @getchar()
declare i32 @putchar(i32)
