//çift yönlü linked list de aradaan data silme uygulaması ve free(*) kullanımı

#include <stdio.h>
#include <stdlib.h>

struct n{//tek yönlüden farklı olarak prev pointerı eklenecek
	int data;
	n * next;
	n * prev;
};

typedef n node;

void bastir(node *);

node* dsiraekle(node *,int);

node* dsil(node *,int);//amacımız int x i linked listden silmek

int main() {
	node *root;
	root=NULL;
	root=dsiraekle(root, 400);
	root=dsiraekle(root, 4);
	root=dsiraekle(root, 40);
	root=dsiraekle(root, 440);
	root=dsiraekle(root, 45);
	root=dsiraekle(root, 10);
	bastir(root);//belirtilen yerden liste sonuna kadar basıtırır.
	root=dsil(root,40);
	bastir(root);
	root=dsil(root,4);
	bastir(root);
	root=dsil(root,17);
	bastir(root);
	root=dsil(root,440);
	bastir(root);
	printf("size of root pointer %ld byte\n",sizeof(root));
	printf("size of node %ld byte\n",sizeof(*root));
	return 0;
}

void bastir(node*r) {
	while(r!=NULL) {
		printf("\n%d\n",r->data);
		r=r->next;
	}
}
		
node* dsiraekle(node *r,int x) {//ana fonksiyona yeni root döndürmek için node* yaptık
	//küçükten büyüğe sırayı bozmayacak şekilde ekleme
	if(r==NULL) {//linkedlist boşsa
		r=(node *)malloc(sizeof(node));//yeni yer oluşturduk
		r->next=NULL;
		r->prev=NULL;
		r->data=x;
		return r;
	}
	//linked list boş değilse
	if(r->data > x) {//yeni değer ilk elemandan küçük durumu
		//root değişiyor
		node *temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->next=r;//yeni kutuyu ilk sıranın önünde ekliyoruz.
  		r->prev=temp;
		return temp;
	}
	//linked list boş değilse, sonuna kadar incele, yerini bul
	node *iter=r;
	while(iter->next!=NULL && iter->next->data < x) {//listenin sonuna veya kendinden büyük değer görünceye kadar pointeri öteler
		iter=iter->next;
	}//yeri bulunca iter durur, yani node açılabilir
	
	node *temp=(node *)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->prev=iter;
	if(temp->next!=NULL)
		temp->next->prev=temp;
	temp->data=x;
	return r;
}

node* dsil(node *r,int x) {/*özetle 4 durum var,
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
	if(iter->next!=NULL)
		iter->next->prev=iter;
	return r;
}

