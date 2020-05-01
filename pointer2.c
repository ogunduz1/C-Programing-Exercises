//pointerların dizi gibi çalışmasını gösteren program
//her dizi bir pointerdır, her pointer bir dizidir.

#include <stdio.h>

int main() {
	int d[5]={00,11,22,33,44};
	int *p;
	p=d;//p1 e dizinin ilk elemanı(d[0]) adresi atanır
	
	printf("d[3]  %d\n",d[3]);//dizinin üçüncü elemanı
	printf("*(p+3) %d\n",*(p+3));//p1 pointerının (d[0]) 3 eleman sonrası yani dizinin 3. elemanı
	
	return 0;
}
/*Pointerlar üzerinde aritmetik işlemler yapılabilir.
  örneğin;
  		int *p; için p+3 demek, p'nin RAM'deki adresinin(saklandığı bölümün) 3 integer bloğu(4 bayt) sonrası demek 
  			p-1 demek, p'nin RAM'deki adresinin 1 integer bloğu evveli(berisi,önü) demek
  		
  fakat;
  		int a=10; için a+3 demek 13 demek. 
  		
  pointerlar üzerinde yapılan matematiksel işlemler, adresi değişken cinsinden öteler veya beriler, integersa 4 gibi.
 */
  	
