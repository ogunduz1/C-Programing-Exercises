#include <stdio.h>

/* C kitabındaki örneğin ikinci versiyonu
 * tek değişkenle ve for döngüsüyle tablo oluşturuyor
 * for döngüsünde de ayrı bir değişken tanımlaması yapılmamış */
int main()
{	int fahr;
	for(fahr =300; fahr >=0; fahr-=20) {
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
		/* yukarıdaki 3 ve 6.1 ifadeleri virgül ve sayı genişliği ile ilgili */	
	}
return 0;
}
