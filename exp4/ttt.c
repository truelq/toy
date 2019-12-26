int _a,b,c
int getchar()
int putchar()
int read(){
	int a=0
	int b=getchar()
	while(b!=10)
	{
		a=a*10+b-'0'
		b=getchar()
	}
	return a
}
int write(int a){
	int b=1
	int c
	while(b<=a)
	{
		b=b*10
	}
	b=b/10
	while(a>=10)
	{
		c=a/b
		a=a-c*b
		b=b/10
		c=c+'0'
		putchar(c)
	}
	putchar(a+'0')
	putchar(10)
	return a
}
int test(int a){
	int b=1
	int c=1
	while(b<=a)
	{
		c=c*b
		b=b+1
	}
	return c
}
int main(){
	int m,n
	int i=1
	m=read()
	write(m)
	while(i<=m)
	{
		n=test(i)
		write(n)
		i=i+1
	}
	return 1
}
