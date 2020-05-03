//linked list de araya sıralı data ekleme uygulaması

#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	n * next;
};

typedef n node;

void bastir(node *);

void ekle(node *,int);

node* siraekle(node *,int);

int main() {
	node *root;
	root=NULL;
	root=siraekle(root, 400);
	root=siraekle(root, 4);
	root=siraekle(root, 40);
	root=siraekle(root, 440);
	root=siraekle(root, 45);
	root=siraekle(root, 10);
	bastir(root);//belirtilen yerden liste sonuna kadar basıtırır.
	return 0;
}

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



