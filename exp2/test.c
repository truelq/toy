int _a,b,c
float m,n
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
	i=1
	while(i<=m)
	{
		fibo(i)
		break
	}
	m=m+n*i+i
	return 1
}
