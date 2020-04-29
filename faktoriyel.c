#include <stdio.h>

int fact(int);

int main(){
	int sayi;
	long sonuc;
	printf("\nLütfen sayı giriniz\n");
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
