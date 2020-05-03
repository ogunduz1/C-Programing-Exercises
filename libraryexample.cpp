#include <stdio.h>
#include <stdlib.h>
#include "libraryexample.h"

void bastir(node*r) {
	while(r!=NULL) {
		printf("\n%d\n",r->data);
		r=r->next;
	}
}

void ekle(node *r,int x) {
	while (r->next!=NULL) {//son elemana gitmeyi sağlar
		r=r->next;
	}
		r->next=(node*)malloc(sizeof(node));//alan aç
		r->next->data=x;
		r->next->next=NULL;
}
		
node* siraekle(node *r,int x) {//ana fonksiyona yeni root döndürmek için node* yaptık
	//küçükten büyüğe sırayı bozmayacak şekilde ekleme
	if(r==NULL) {//linkedlist boşsa
		r=(node *)malloc(sizeof(node));//yeni yer oluşturduk
		r->next=NULL;//linkedlistin sonunu gösteriyor
		r->data=x;
		return r;//mevcutta gösterilen bir yer var, ama orası null, bu nedenle pointer değişmiyor, sadece null yerine yeni node ekleniyor
	}
	node *iter=r;
	//linked list boş değilse
	if(r->data > x) {//yeni değer ilk elemandan küçük durumu
		//root değişiyor
		node *temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->next=r;//yeni kutuyu ilk sıranın önünde ekliyoruz.
		r=temp;//root pointerı artık yeni kutuyu gösteriyor
		return temp;
	}
	//linked list boş değilse, sonuna kadar incele, yerini bul
	while(iter->next!=NULL && iter->next->data < x) {//listenin sonuna veya kendinden büyük değer görünceye kadar pointeri öteler
		iter=iter->next;
	}//yeri bulunca iter durur, yani node açılabilir
	
	node *temp=(node *)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->data=x;
	return r;
	/*özetle üç ihtimal var;
	 *1-linked list boş:roota node bağla,
	 *2-linked list dolu ama yeni eleman rootdan küçük: yeni elemanı ilk elamnın önüne al roota bağla,
	 *3-linked list dolu ve yeni elaman rootdan büyük: listenin sonuna kadar veya yeni elemandan büyük değer bulana kadar devam et,
	 *yerini bulunca, araya yeni elemanı bağla, yeni eleman en büyükse listenin sonuna bağla*/
}

node* sil(node *r,int x) {/*özetle 4 durum var,
			    *1-silinecek eleman rootsa,
			    *2-silinecek eleman listenin son elemanı
			    *3-silinecek eleman listenin ara elamanı
			    *4-silinecek eleman listede yok */
	node *iter=r;
	node *temp;
	if(r->data==x) {//aranılan değer rootsa
		temp=r;//root adresi kopyala
		r=r->next;//yeni root adresini bağla
		free(temp);//eski root adresini sil
		return r;
	}
	while(iter->next!=NULL && iter->next->data!=x) { //listenin sonuna kadar veya aranan değeri bulana kadar listede gez
		iter=iter->next;
	}//elemanı bulduk
	//iki durum var 1-silinecek eleman son eleman 2-silenecek eleman ara eleman
	if(iter->next==NULL){//aranılan elaman bulunamadı
		printf("sayı bulunamadı\n");
		return r;
	}
	//linked listin ortasında sayı bulunursa, temp kullanılacak
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);//temp i sil
	return r;
}

