#include <stdio.h>

int fac(int);
int per(int,int);
int com(int,int);
void yaz1();
void yaz2();

int main(){
	int n,r;
	yaz1();
	scanf("%d",&n);
	yaz2();
	scanf("%d",&r);
	printf("\n%d sayisinin %d'li kombinasyonu %d'dir.\n",n,r,com(n,r));
	return 0;
}
int fac(int x){
	for(int i=(x-1);i>0;i--){
		x*=i;
	}
	return x;
}
int per(int n,int r){
	return fac(n)/fac(n-r);
}
int com(int n, int r){
	return per(n,r)/fac(r);
}
void yaz1(){
	printf("\nLütfen kombinasyonu alıncak sayıyı giriniz:\n");
}
void yaz2(){
	printf("\nLütfen kombine edilecek değeri giriniz:\n");
}

