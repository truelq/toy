int a,b,c;
float m,n;
char d;
int test(int a,int b){
	int e=a+b+c;
	return 0;
}
int fibo(int a){
	if(a==1||a==2) return 1;
	return fibo(a-1)+fibo(a-2);
}
int main(){
	int m,n,i;

	//m=read();
	i=1;
	while(i<=m){
		int m;
		m=n;
		n=fibo(i);
		//write(n);
		i=i+1;
	}
	return 1;
}