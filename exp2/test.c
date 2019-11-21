int _a,b,c
float m,n
int ee=a+b+c
int test(int a)
int fibo(int a){
	if(a==1||a==2)
	{
		return 1
	}
	return fibo(a-1)+fibo(a-2)
}
int main(){
	int m,n,i
	m=read()
	i=1
	while(i<=m)
	{
		n=fibo(i)
		write(n)
	}
	m=m+n*i+i
	i+=1
	++i
	m=2.333
	d='c'
	return 1
}
