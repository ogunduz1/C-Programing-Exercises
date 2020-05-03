#include <stdio.h>
#include <stdlib.h>

/*bu struct ve typedef kullanım şekline gcc de hata veriyor,
 *bu nedenle programı .c değil de .cpp uzantısı ile kaydedip,
 *g++ ile compile etmek gerekiyor.
 *g++ baglist.cpp
 *./a.out
 */
 
struct n{
	int data;
	n * next;
};

typedef n node;

int main() {
	node *root;
	root=(node *)malloc(sizeof(node));
	root->data=10;
	root->next=(node*)malloc(sizeof(node));
	root->next->data=20;
	root->next->next=(node*)malloc(sizeof(node));
	root->next->next->data=30;
	root->next->next->next=NULL;/*işletim sisteminde herzaman son eleman NULL olamayabilir,
	*bu nedenle yeni eleman tanımlandıkça, pointera null tanımlaması yapılmalı,
	*aksi durumda segmentation fault alınabilir.*/ 
	//yukarıdakinin daha kullanışlı yolu
	node *iter;
	iter =root;//kök adresini bir nevi kopyaladık
	printf("\n%d\n",iter->data);
	iter=iter->next;//bir sonraki adresi almış oldu
	printf("\n%d\n",iter->data);
	iter=iter->next;
	printf("\n%d\n",iter->data);
	iter =root;//iteri sıfırladık
	/*iter null olduğunda listesin sonu kaybolur, yeni eleman eklenemez,
	 *bu nedenle iter->next != NULL olmalı ki, iter hala son elemanı göstersin,
	 *böylece liste sonu kaybolmaz ve yeni data girişi yapılabilir*/
	while (iter->next!=NULL/*iter!=NULL*/) {//dizinin son elemanının pointerı boşluğu gösterir, yani NULL
		printf("\n%d\n",iter->data);
		iter=iter->next;//iter->next==Null olursa bu assignment pointarı boşluga atar
	};//şu durumda son node'da bir data var, fakat next için yeni adres tanımlı değil, yani next NULL
	printf("\n%d\n",iter->data);//son eleman için döngüye girmemişti,son elemanı göstermek için yazdım.
	/*for(iter=root;iter!=NULL;iter=iter->next) {//while yerine kullanılabilecek alternatif
		printf("\n%d\n", iter->data);
	}*/
	//dizi sonuna yeni node eklemek için çok önemli bir döngü
	for(int i=0;i<5;i++) {
		iter->next=(node *)malloc(sizeof(node));//yeni node yeri ayırdık
		iter=iter->next;//iter artık yeni bölmeyi gösteriyor
		iter->data=i*11;//yeni node'ın data kısmına değer atadık,
		iter->next=NULL;//listenin sonu bir yeri göstermiyor, NULL
	}
	return 0;
}
/*Dizilere erişim Random'dır,
 *Bağlı listelere erişim ise squential 'dır,
 *dizilerde herhangi bir elemana doğrudan erişmek mümkün,
 *bağlı listelerde adım adım gidilir, çünkü bir elemanın adresi
 *sadece bir önceki elemandadır.*/ 
