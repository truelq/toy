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
%5 = icmp ne i32 %4,  10
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
store i32 1, i32* %3, align 4
%4 = alloca i32, align 4
br label %hard4before
hard4before:
%5 = load i32,i32* %3, align 4
%6 = load i32,i32* %2, align 4
%7 = icmp sle i32 %5,  %6
br i1 %7, label %hard4begin, label %hard4end
hard4begin:
%8 = load i32,i32* %3, align 4
%9 = mul i32 %8, 10
store i32 %9, i32* %3, align 4
br label %hard4before
hard4end:
%10 = load i32,i32* %3, align 4
%11 = udiv i32 %10, 10
store i32 %11, i32* %3, align 4
br label %hard11before
hard11before:
%12 = load i32,i32* %2, align 4
%13 = icmp sge i32 %12,  10
br i1 %13, label %hard11begin, label %hard11end
hard11begin:
%14 = load i32,i32* %2, align 4
%15 = load i32,i32* %3, align 4
%16 = udiv i32 %14, %15
store i32 %16, i32* %4, align 4
%17 = load i32,i32* %2, align 4
%18 = load i32,i32* %4, align 4
%19 = load i32,i32* %3, align 4
%20 = mul i32 %18, %19
%21 = sub i32 %17, %20
store i32 %21, i32* %2, align 4
%22 = load i32,i32* %3, align 4
%23 = udiv i32 %22, 10
store i32 %23, i32* %3, align 4
%24 = load i32,i32* %4, align 4
%25 = add i32 %24, 48
store i32 %25, i32* %4, align 4
%26 = load i32,i32* %4, align 4
%27 = call i32 @putchar(i32 %26)
br label %hard11before
hard11end:
%28 = load i32,i32* %2, align 4
%29 = add i32 %28, 48
%30 = call i32 @putchar(i32 %29)
%31 = call i32 @putchar(i32 10)
%32 = load i32,i32* %2, align 4
ret i32 %32
}
define i32 @test(i32)
{
%2 = alloca i32, align 4
store i32 %0, i32 *%2, align 4
%3 = alloca i32, align 4
store i32 1, i32* %3, align 4
%4 = alloca i32, align 4
store i32 1, i32* %4, align 4
br label %hard4before
hard4before:
%5 = load i32,i32* %3, align 4
%6 = load i32,i32* %2, align 4
%7 = icmp sle i32 %5,  %6
br i1 %7, label %hard4begin, label %hard4end
hard4begin:
%8 = load i32,i32* %4, align 4
%9 = load i32,i32* %3, align 4
%10 = mul i32 %8, %9
store i32 %10, i32* %4, align 4
%11 = load i32,i32* %3, align 4
%12 = add i32 %11, 1
store i32 %12, i32* %3, align 4
br label %hard4before
hard4end:
%13 = load i32,i32* %4, align 4
ret i32 %13
}
define i32 @main()
{
%1 = alloca i32, align 4
%2 = alloca i32, align 4
%3 = alloca i32, align 4
store i32 1, i32* %3, align 4
%4 = call i32 @read()
store i32 %4, i32* %1, align 4
%5 = load i32,i32* %1, align 4
%6 = call i32 @write(i32 %5)
br label %hard6before
hard6before:
%7 = load i32,i32* %3, align 4
%8 = load i32,i32* %1, align 4
%9 = icmp sle i32 %7,  %8
br i1 %9, label %hard6begin, label %hard6end
hard6begin:
%10 = load i32,i32* %3, align 4
%11 = call i32 @test(i32 %10)
store i32 %11, i32* %2, align 4
%12 = load i32,i32* %2, align 4
%13 = call i32 @write(i32 %12)
%14 = load i32,i32* %3, align 4
%15 = add i32 %14, 1
store i32 %15, i32* %3, align 4
br label %hard6before
hard6end:
ret i32 1
}
declare i32 @getchar()
declare i32 @putchar(i32)
