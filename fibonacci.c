#include <stdio.h>

int fib(int);

int main() {
	int sayi;
	printf("\nLütfen sıra numarası giriniz\n");
	scanf("%d",&sayi);
	printf("\nFibonacci dizisinin %d'ıncı elaman değeri \n%d'dır\n",sayi,fib(sayi));
	return 0;
}

int fib(int x) {
	if(x==1||x==0)
		return 1;
	return fib(x-1)+fib(x-2);
}

	
