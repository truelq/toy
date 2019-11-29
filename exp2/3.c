int a,b,c
float m,n
int ee=a+b+c
int fibo(int a){
	int c
	if(a==1||a==2)
	{
		return 1
	}
	return fibo(a-1)+fibo(a-2)
}
int main(){
	int m,n,i
    char t
    t=m
    t+t=m
	m=read()
	i=1
	while(i<=m)
	{
		n=fibo(i)
		write(n)
		break
	}
	return 1
}
