/*soru: aynı kişiye gelen kargoları, güvenlik için kargonun 
 *değerine göre ucuzdan pahalıya sıralayan, bağlı liste oluşturan, 
 *kargo alındıkça kutu bırakan, kargo geldikçe kutu ayıran,
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

void yazdir(kutu*);

int main() {
	kutu *ilk;//ilk işaret tanımlandı
	int fis;
	int kargosayi;
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
	while (parmak->yeni !=NULL && parmak->deger < fatura) {
		parmak=parmak->yeni;
	}
		dparmak=(kutu *)malloc(sizeof(kutu));
		dparmak->deger=fatura;
		dparmak->yeni=parmak->yeni;
		parmak->yeni=dparmak;
		return isaret;
}
		
void yazdir(kutu *basyer) {
	kutu *gecici;
	while(gecici->yeni !=NULL) {
		printf("\n%d\n",gecici->deger);
		gecici=gecici->yeni;	
	}
}
					
		
		
	
	
