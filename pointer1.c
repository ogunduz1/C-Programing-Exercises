//pointerların çalışmasını gösteren basit bir program

#include <stdio.h>

int main() {
	int *p,*q;
	int a=10;
	p=&a;
	*q=&p;
	
	printf("a %d\n",a); //a değişkenin değeri
	printf("*p %d\n",*p); //p pointeriının gösterdiği yerdeki değer (yani a değişkenin değeri)
	printf("&a %x \n",&a);//a değişkeninin adresi
	printf("p %x \n", p);//p pointarının değeri (gösterdiği adres, bu case için a'nın adresi)
	printf("&p %x \n",&p);//p pointarının hafızada tutulduğu adres (sonucta *p de bir değişken)
	printf("*q %x \n",*q);//p poniterının pointerı q 
	printf("\n\n");
	printf("sizeof(p) %ld\n",sizeof(p));//p pointarının hafızada tutulduğu boyut (byte)
	printf("sizeof(a) %ld\n",sizeof(a));//a değişkeninin hafızada tutulduğu boyut (byte)
	
	return 0;
}
