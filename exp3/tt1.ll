
@a = common global i32 0, align 4
@b = common global i32 0, align 4
@c = common global i32 0, align 4

; Function Attrs: noinline nounwind optnone uwtable

define i32 @fibo(i32)
{
%2 = alloca i32, align 4
store i32 %0, i32* %2, align 4
%3 = load i32,i32* %2, align 4
%4 = icmp eq i32 %3,  1
br i1 %4, label %begin1, label %beginand1
beginand1:
%5 = alloca i32, align 4
store i32 %0, i32* %5, align 4
%6 = load i32,i32* %5, align 4
%7 = icmp eq i32 %6,  2
br i1 %7, label %begin1, label %end1
begin1:
ret i32 1
end1:
%8 = alloca i32, align 4
store i32 %0, i32* %8, align 4
%9 = load i32,i32* %8, align 4
%10 = sub i32 %9, 1
%11 = call i32 @fibo(i32 %10)
%12 = alloca i32, align 4
store i32 %0, i32* %12, align 4
%13 = load i32,i32* %12, align 4
%14 = sub i32 %13, 2
%15 = call i32 @fibo(i32 %14)
%16 = add i32 %11, %15
ret i32 %16
}
; Function Attrs: noinline nounwind optnone uwtable
define i32 @main() {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %6 = call i32 @getchar()
  store i32 %6, i32* %2, align 4
  store i32 1, i32* %4, align 4
  br label %7

; <label>:7:                                      ; preds = %0
  %8 = load i32, i32* %4, align 4
  %9 = load i32, i32* %2, align 4
  %10 = icmp sle i32 %8, %9
  br i1 %10, label %11, label %18

; <label>:11:                                     ; preds = %7
  %12 = load i32, i32* %3, align 4
  store i32 %12, i32* %5, align 4
  %13 = load i32, i32* %4, align 4
  %14 = call i32 @fibo(i32 %13)
  store i32 %14, i32* %3, align 4
  %15 = call i32 @putchar(i32 49)
  %16 = load i32, i32* %4, align 4
  %17 = add nsw i32 %16, 1
  store i32 %17, i32* %4, align 4
  br label %18

; <label>:18:                                     ; preds = %11, %7
  ret i32 1
}

declare i32 @getchar()

declare i32 @putchar(i32)
