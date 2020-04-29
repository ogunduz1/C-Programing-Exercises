#include <stdio.h>

int fac(int);

int main() {
	int sayi;
	printf("\nLütfen bir sayı giriniz\n");
	scanf("%d",&sayi);
	printf("\n%d sayısının faktoriyeli %d'dir.\n",sayi,fac(sayi));
	return 0;
}

int fac(int x){
	if(x==0)//döngünün durması için gerekli
		return 1;
	return x*fac(x-1);//recursive fonksiyonlar kendi içinde kendini çağıran fonksiyonlardır. tıpkı döngü gibidir.
}
