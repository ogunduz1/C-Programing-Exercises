#include <stdio.h>

int fact(int);
void yaz();

int main(){
	int sayi;
	long sonuc;
	yaz();
	scanf("%d",&sayi);
	sonuc=fact(sayi);
	printf("\n%d sayısının faktoriyeli %ld'dir.\n",sayi,sonuc);
	return 0;
}

int fact(int x){
	int i;
	for(i=(x-1);i>0;i--){
		x*=i;
	}
	return x;
}

void yaz(){
	printf("\nLütfen sayı giriniz\n");
}
