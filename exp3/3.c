int _a,b,c
int fibo(int a){
	a=1
	if(a==1||a==2)
	{
		return 1
	}
	return fibo(a-1)+fibo(a-2)
}
