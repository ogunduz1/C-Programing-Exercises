/*fahrenheit celcuis tablosunu yazdırma programı
 * C kitabı örneği 3. versiyonu 
 * define kullanımı gösterilmiştir */


#include <stdio.h>

#define LOWER 0 /*lower limit of the table*/
#define UPPER 300/*upper limit of the table */
#define STEP 20/*step size*/

int main ()
{	short fahr, celcuis;
	short lower, upper, step;
	
	fahr = LOWER ;
	
	while (fahr <= UPPER) {
		celcuis = 5 *(fahr -32) / 9;
		printf("%hd\t%hd\n", fahr, celcuis);
		fahr+=STEP;
	}
return 0;
}
/*Tablo şekline çıktı almak için çok güzel bir örnek,
 * while döngüsü içinde ilk kolona üst, alt sınır ve adım sabitleri belirlenmiş 
 * bu şekilde tablonun diğer değerlerine ulaşılıyor.*/
