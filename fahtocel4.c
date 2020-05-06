

/*fahrenheit celcuis tablosunu yazdırma programı
 * C kitabı örneği 4. versiyonu 
 * fonksiyon kullanımı gösterilmiştir */


#include <stdio.h>

#define LOWER 0 /*lower limit of the table*/
#define UPPER 300/*upper limit of the table */
#define STEP 20/*step size*/

int cel(int);

int main ()
{	short fahr, celcuis;
	
	fahr = LOWER ;
	
	while (fahr <= UPPER) {
		printf("%hd\t%hd\n", fahr, cel(fahr));
		fahr+=STEP;
	}
return 0;
}

int cel(int f) {
	return 5*(f-32)/9;
}
/*Tablo şekline çıktı almak için çok güzel bir örnek,
 * while döngüsü içinde ilk kolona üst, alt sınır ve adım sabitleri belirlenmiş 
 * bu şekilde tablonun diğer değerlerine ulaşılıyor.*/
