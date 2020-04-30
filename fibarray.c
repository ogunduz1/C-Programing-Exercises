/* Fibonacci dizini girilen eleman sayısı kadar dizi olarak tutar.
*/
#include <stdio.h>

//int fib(int);

int main() {
	int sayi;
	printf("\nLütfen bir sayı giriniz : ");
	scanf("%d",&sayi);
	//int b[]=fib(sayi);
	int f[sayi];
	f[0]=1;
	f[1]=1;
	for(int i=2;i<sayi;i++) {
		f[i]=f[(i-1)]+f[(i-2)];
	}
	for(int i=0;i<sayi;i++) {
		printf("%d\t",f[i]);
	}
	printf("\n");
	return 0;
}
	

/* bu şekilde çalışmadı
int fib(int n) {
	int a[n];
	a[0]=1;
	a[1]=1;
	for(int i=2;i<n;i++) {
		a[i]=a[(i-1)]+a[(a-2)];
	}
	return a[];
}*/
