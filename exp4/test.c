int _a,b,c
int getchar()
int putchar()
int read(){
	int a=0
	int b=getchar()
	while(b!='-')
	{
		a=a*10+b-'0'
		b=getchar()
	}
	return a
}
int write(int a){
	int b
	while(a>0)
	{
		b=a%10
		a=a/10
		b=b+'0'
		putchar(b)
	}
	putchar(10)
	return a
}
int fibo(int a){
	if(a==1||a==2)
	{
		return 1
	}
	return fibo(a-1)+fibo(a-2)
}
int main(){
	int m,n
	int i=1
	m=5
	//write(m)
	while(i<=m)
	{
		n=fibo(i)
		write(n)
		i=i+1
	}
	return 1
}
