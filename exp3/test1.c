int b
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
	while(i<=m)
	{
		n=fibo(i)
		i=i+1
	}
	return 1
}
