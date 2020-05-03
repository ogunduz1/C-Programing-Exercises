/*soru: aynı kişiye gelen kargoları, güvenlik için kargonun 
 *değerine göre ucuzdan pahalıya sıralayan, bağlı liste oluşturan, 
 *kargo alınmayınca iade gönderip kutu bırakan, kargo geldikçe kutu ayıran,
 *ilk kutudam son kutuya içeriği listeleyen,
 *algoritma çalışması.
 *!!her kutu tek kargo alıyor*/
 
#include <stdio.h>
#include <stdlib.h>

struct k {
	int deger;
	k* yeni;
};

typedef k kutu;

kutu* kargocu(kutu *,int);

kutu* geri(kutu*,int);

void yazdir(kutu*);

int main() {
	kutu *ilk;//ilk işaret tanımlandı
	int fis;
	int kargosayi;
	int iade;
	//kargo geldikçe kutu açacak, dolduracak bir fonksiyon gerekli, çıktısı adres
 	ilk->yeni=NULL;
 	printf("lütfen kargo adedini giriniz :\n");
 	scanf("%d",&kargosayi);
 	for(int i=0;i<kargosayi;i++) {
 		printf("Lütfen fatura değeri giriniz :\n");
 		scanf("%d",&fis);
 		ilk=kargocu(ilk,fis);
 	}
 	yazdir(ilk);
 	
 	printf("İade verilecek kargoyu giriniz");
 	scanf("%d",&iade);
 	if(iade!=0) {
 		for(int i=0;i<iade;i++) {
 			int x;
 			printf("İade verilecek kargo değerini giriniz\n");
 			scanf("%d",&x);
 			ilk=geri(ilk,x);
 		}
 	}
 	yazdir(ilk);
 	return 0;
}	

kutu* kargocu(kutu *isaret,int fatura) {/*üç durum var,
					 *hiç kutu yok,
					 *ilk kutu daha değerli
					 *ilk kutudan değerli*/
	kutu *parmak;
	kutu *dparmak;
	if(isaret==NULL) {
		isaret=(kutu *)malloc(sizeof(kutu));//kutu ayır
		isaret->yeni=NULL;
		isaret->deger= fatura;
		return isaret;
	}
	if(isaret->deger > fatura) {
		parmak=(kutu *)malloc(sizeof(kutu));
		parmak->deger=fatura;
		parmak->yeni=isaret;
		parmak->yeni->yeni =NULL;
		return parmak;
	}
	parmak=isaret;
	while (parmak->yeni !=NULL && parmak->yeni->deger < fatura) {
		parmak=parmak->yeni;
	}
		dparmak=(kutu *)malloc(sizeof(kutu));
		dparmak->deger=fatura;
		dparmak->yeni=parmak->yeni;
		parmak->yeni=dparmak;
		return isaret;
}
		
void yazdir(kutu *basyer) {
	while(basyer!=NULL) {
		printf("\n%d\n",basyer->deger);
		basyer=basyer->yeni;	
	}
}

kutu* geri(kutu *isaret,int x) {/*özetle 4 durum var,
			    *1-silinecek eleman rootsa,
			    *2-silinecek eleman listenin son elemanı
			    *3-silinecek eleman listenin ara elamanı
			    *4-silinecek eleman listede yok */
	kutu *parmak=isaret;
	kutu *dparmak;
	if(isaret->deger==x) {//aranılan değer rootsa
		dparmak=isaret;//root adresi kopyala
		isaret=isaret->yeni;//yeni root adresini bağla
		free(dparmak);//eski root adresini sil
		return isaret;
	}
	while(parmak->yeni!=NULL && parmak->yeni->deger!=x) { //listenin sonuna kadar veya aranan değeri bulana kadar listede gez
		parmak=parmak->yeni;
	}//elemanı bulduk
	//iki durum var 1-silinecek eleman son eleman 2-silenecek eleman ara eleman
	if(parmak->yeni==NULL){//aranılan elaman bulunamadı
		printf("sayı bulunamadı\n");
		return isaret;
	}
	//linked listin ortasında sayı bulunursa, temp kullanılacak
	dparmak=parmak->yeni;
	parmak->yeni=parmak->yeni->yeni;
	free(dparmak);//temp i sil
	return isaret;					
}
		
	
	
