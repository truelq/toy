int _a,b,c
int read()
int fibo(int a){
	a=1
	if(a==1||a==2)
	{
		return 1
	}
	return fibo(a-1)+fibo(a-2)
}
int main(){
	int m,n
	int i=1
	m=read()
	while(i<=m)
	{
		n=fibo(i)
		break
	}
	return 1
}
