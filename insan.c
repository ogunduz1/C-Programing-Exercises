//Struct (tip) tanımlama uygulaması

#include <stdio.h>
#include <stdlib.h>

/*structlar genelde main'den önce tanımlanır, 
 *isimlendirmesi kapanan parantezden sonra 
 *';' dan sonra olur.aşağıdaki örnekde insan struct ismidir*/

typedef enum {//enum tanımlaması
	bay,
	bayan
} cinsiyet;

typedef enum {karadeniz, marmara, ege, akdeniz} bolge;

typedef struct {
	int yas;
	char * isim;
	/*enum {bay,bayan} cinsiyet;*bu şekilde tanımlanınca main'de değişkeni görmüyor,
				     *bu nedenle ayrıbir struct olarak tanımlayıp, insan 
				     *tipinde cinsiyet olarak kullanacağız*/
	cinsiyet c;
	bolge b;
} insan;

int emeklilik(insan *);

int main() {
	insan ali; //insan tipinde ali değişkeni
	ali.yas=30;//alinin yaşı
	insan *veli; /*bu şekilde pointer olarak da değişken tanımlamak mümkün*/
	veli=(insan*)malloc(sizeof(insan));
	veli->yas=40;
	printf("Ali'nin yaşı : %d\n",ali.yas);
	printf("Veli'nin yaşı : %d\n",veli->yas);//pointer olduğu için ok ile bağlanıyor
	ali.c=bay;//c cinsiyet tipinde bir değişken
	printf("cinsiyeti %u \n",ali.c);//enumlar unsign int olarak kabul edilir.bay 0 bayan 1 
	ali.b=karadeniz;
	printf("sorumluluk bölgesi %u \n",ali.b);//enum olduğu için 0-3 arası numaralandırılacak
	printf("ali emeklimi? %d\n",emeklilik(&ali));//ali pointer değil fakat fonksiyon pointer bu nedenle & ile kullandık
	printf("veli emekli mi? %d\n",emeklilik(veli));//veli pointer olduğu için direk kullandık
	return 0;
}

int emeklilik(insan *birey) {
	printf("\n %d %u",birey->yas, birey->c);//bu üç satır debuging için 
	fflush(stdout);//debuging için 
	perror("gecti");//debuging için 
	if(birey->c==bay&&birey->yas>=55)
		return 1;
	if(birey->c==bayan&&birey->yas>=50)
		return 1;
	return 0;
}
