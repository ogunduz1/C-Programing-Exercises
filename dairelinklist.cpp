//dairesel linked list de aradan data silme, ekleme uygulaması ve free(*) kullanımı
 
#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	n * next;
};

typedef n node;

void cirbastir(node *);

void cirekle(node *,int);

node* cirsiraekle(node *,int);

node* cirsil(node *,int);

int main() {
	node *root;
	root=NULL;
	root=cirsiraekle(root, 400);
	root=cirsiraekle(root, 4);
	root=cirsiraekle(root, 40);
	root=cirsiraekle(root, 440);
	root=cirsiraekle(root, 45);
	root=cirsiraekle(root, 10);
	cirbastir(root);//belirtilen yerden liste sonuna kadar basıtırır.
	root=cirsil(root,40);
	cirbastir(root);
	root=cirsil(root,4);
	cirbastir(root);
	cirbastir(root);
	return 0;
}

void cirbastir(node*r) {
	node * iter=r;
	printf("\n%d\n",iter->data);//ilk hareketi vermek gerekli
	iter=iter->next;
	while(iter!=r) {
		printf("\n%d\n",iter->data);
		iter=iter->next;
	}
}

void cirekle(node *r,int x) {
	node *iter=r;
	while (iter->next!=r) {//son elemana gitmeyi sağlar
		iter=iter->next;
	}
		iter->next=(node*)malloc(sizeof(node));//alan aç
		iter->next->data=x;
		iter->next->next=r;
}
		
node* cirsiraekle(node *r,int x) {
	if(r==NULL) {//linkedlist boşsa
		r=(node *)malloc(sizeof(node));//yeni yer oluşturduk
		r->next=r;//linkedlistin sonunu gösteriyor
		r->data=x;
		return r;
	}
	//linked list boş değilse
	if(r->data > x) {//yeni değer ilk elemandan küçük durumu
		//root değişiyor
		node *temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->next=r;//yeni kutuyu ilk sıranın önünde ekliyoruz.
		node *iter=r;
		while(iter->next !=r) {
			iter=iter->next;
		}
		iter->next=temp;//root pointerı artık yeni kutuyu gösteriyor
		return temp;
	}
	node *iter=r;
	//linked list boş değilse, sonuna kadar incele, yerini bul
	while(iter->next!=r && iter->next->data < x) {//listenin sonuna veya kendinden büyük değer görünceye kadar pointeri öteler
		iter=iter->next;
	}//yeri bulunca iter durur, yani node açılabilir
	node* temp=(node *)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->data=x;
	return r;
}

node* cirsil(node *r,int x) {
	node *iter=r;
	node *temp;
	if(r->data==x) {//aranılan değer rootsa
		while(iter->next!=r) {
			iter=iter->next;
		}
		iter->next=r->next;
		free(r);
		return iter->next;
	}
	while(iter->next!=r && iter->next->data!=x) { //listenin sonuna kadar veya aranan değeri bulana kadar listede gez
		iter=iter->next;
	}//elemanı bulduk
	if(iter->next==r){//aranılan elaman bulunamadı
		printf("sayı bulunamadı\n");
		return r;
	}
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);//temp i sil
	return r;
}

