@_a = common global i32 0, align 4
@b = common global i32 0, align 4
@c = common global i32 0, align 4
define i32 @read()
{
%1 = alloca i32, align 4
store i32 0, i32* %1, align 4
%2 = call i32 @getchar()
%3 = alloca i32, align 4
store i32 %2, i32* %3, align 4
br label %hard3before
hard3before:
%4 = load i32,i32* %3, align 4
%5 = icmp ne i32 %4,  45
br i1 %5, label %hard3begin, label %hard3end
hard3begin:
%6 = load i32,i32* %1, align 4
%7 = mul i32 %6, 10
%8 = load i32,i32* %3, align 4
%9 = add i32 %7, %8
%10 = sub i32 %9, 48
store i32 %10, i32* %1, align 4
%11 = call i32 @getchar()
store i32 %11, i32* %3, align 4
br label %hard3before
hard3end:
%12 = load i32,i32* %1, align 4
ret i32 %12
}
define i32 @write(i32)
{
%2 = alloca i32, align 4
store i32 %0, i32 *%2, align 4
%3 = alloca i32, align 4
br label %hard3before
hard3before:
%4 = load i32,i32* %2, align 4
%5 = icmp sgt i32 %4,  0
br i1 %5, label %hard3begin, label %hard3end
hard3begin:
%6 = load i32,i32* %2, align 4
%7 = urem i32 %6, 10
store i32 %7, i32* %3, align 4
%8 = load i32,i32* %2, align 4
%9 = udiv i32 %8, 10
store i32 %9, i32* %2, align 4
%10 = load i32,i32* %3, align 4
%11 = call i32 @putchar(i32 %10)
br label %hard3before
hard3end:
%12 = load i32,i32* %2, align 4
ret i32 %12
}
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
store i32 3, i32* %1, align 4
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
%9 = call i32 @putchar(i32 49)
%10 = load i32,i32* %3, align 4
%11 = add i32 %10, 1
store i32 %11, i32* %3, align 4
br label %hard3before
hard3end:
ret i32 1
}
declare i32 @getchar()
declare i32 @putchar(i32)
