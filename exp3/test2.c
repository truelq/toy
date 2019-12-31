int _a,b,c
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
	while(i<=m)
	{
		n=test(i)
		i=i+1
	}
	return 1
}
