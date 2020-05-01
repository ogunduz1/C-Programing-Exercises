/*stringler char dizileridir.
 *string kullanımını gösteren basit bir uygulama*/
 
 #include <stdio.h>
 #include <stdlib.h> //malloc kullanılacağı için bu header yazılmalı
 
 int main() {
 	char isim[20];
 	char *soyisim;//pointer olarak da tanımlanır
 	soyisim=(char*)malloc(sizeof(char)*20);//pointer olarak tanımlayınca memory allocation yapılmalı 
 	printf("Lütfen isminizi giriniz.\n");
 	scanf("%s",isim);//%s string çalırma **normalde scanfde & kullanılmalı ama diziler pointer olduğu için dizilerde gerek yok
 	printf("Lütfen soy isminizi giriniz.\n");
 	scanf("%s",soyisim);//soyisim pointer olduğu için '&' kullanmadık
 	printf("\nTanıştığımıza memnun oldum %s %s\n",isim,soyisim);
 	return 0;
 }
  
