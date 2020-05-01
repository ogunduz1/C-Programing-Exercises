/* Fibonacci dizini girilen eleman sayısı kadar dizi olarak tutar.
*/
#include <stdio.h>
#include <stdlib.h>//malloc kullanımı için stdlib.h aktif olmalı

int main() {
	int a;
	printf("\nLütfen bir sayı giriniz : ");
	scanf("%d",&a);
	int *p=(int*)malloc(sizeof(int)*a);//dinamik dizi tanımlama
	p[0]=1;
	p[1]=1;
	if(a>=2){
	for(int i=2;i<a;i++) {
		p[i]=p[(i-1)]+p[(i-2)];
	}
	}
	for(int i=0;i<a;i++) {
		printf("%d\t",p[i]);
	}
	printf("\n");
	return 0;
}
	
//dinamik hafıza kullanımı yapmak zorundayız(en altta sebebi belirtildi)

/* 	int a=10;
	int d[a]; 
	tanımlaması C de doğru değildir, yapılamaz, 
	bunun için aşağıdaki tanımlama kullanılabilir
	int *p=(int*)malloc(sizeof(int)*10)
	*/
