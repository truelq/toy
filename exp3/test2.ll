@_a = common global i32 0, align 4
@b = common global i32 0, align 4
@c = common global i32 0, align 4
i32define i32 @test(i32)
{
%3 = alloca i32, align 4
store i32 %1, i32 *%3, align 4
%4 = alloca i32, align 4
store i32 1, i32* %4, align 4
%5 = alloca i32, align 4
store i32 1, i32* %5, align 4
br label %hard5before
hard5before:
%6 = load i32,i32* %4, align 4
%7 = load i32,i32* %3, align 4
%8 = icmp sle i32 %6,  %7
br i1 %8, label %hard5begin, label %hard5end
hard5begin:
%9 = load i32,i32* %5, align 4
%10 = load i32,i32* %4, align 4
%11 = mul i32 %9, %10
store i32 %11, i32* %5, align 4
%12 = load i32,i32* %4, align 4
%13 = add i32 %12, 1
store i32 %13, i32* %4, align 4
br label %hard5before
hard5end:
%14 = load i32,i32* %5, align 4
ret i32 %14
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
