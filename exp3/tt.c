#include<stdio.h>

int a,b,c;

int fibo(int a){
	if(a==1||a==2) return 1;
	return fibo(a-1)+fibo(a-2);
}
int main(){
	int m,n,i;

	m=getchar();
	i=1;
	while(i<=m){
		int m;
		m=n;
		n=fibo(i);
		putchar('1');
		i=i+1;
	}
	return 1;
}