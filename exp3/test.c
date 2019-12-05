int _a,b,c
char kkk
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
		n=fibo(i)
		break
	}
	return 1
}
