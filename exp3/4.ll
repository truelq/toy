@_a = common global i32 0, align 4
@b = common global i32 0, align 4
@c = common global i32 0, align 4
define i32 @main()
{
%1 = alloca i32, align 4
%2 = alloca i32, align 4
%3 = alloca i32, align 4
store i32 1, i32* %3, align 4
br label %hard3before
hard3before:
%4 = load i32,i32* %3, align 4
%5 = icmp sle i32 %4,  2
br i1 %5, label %hard3begin, label %hard3end
hard3begin:
%6 = load i32,i32* %3, align 4
%7 = icmp sle i32 %6,  2
br i1 %7, label %hard5begin, label %hard5end
hard5begin:
%8 = call i32 @putchar(i8 49)
br label %hard5end
hard5end:
%9 = call i32 @putchar(i8 49)
br label %hard3end
br label %hard3before
hard3end:
ret i32 1
}
declare i32 @putchar(i8)