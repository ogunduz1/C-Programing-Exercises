#include <stdio.h>

/*fahrenheit celcuis tablosunu yazdırma programı
 * C kitabı örneği */

int main ()
{	short fahr, celcuis;
	short lower, upper, step;

	lower = 0; //lower limit of temperature table
	upper = 300; //upper limit of temperature table
	step = 20; //step size
	
	fahr = lower ;
	
	while (fahr <= upper) {
		celcuis = 5 *(fahr -32) / 9;
		printf("%hd\t%hd\n", fahr, celcuis);
		fahr+=step;
	}
return 0;
}
/*Tablo şekline çıktı almak için çok güzel bir örnek,
 * while döngüsü içinde ilk kolona üst, alt sınır ve adım sabitleri belirlenmiş 
 * bu şekilde tablonun diğer değerlerine ulaşılıyor.*/
