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

void bastir(node *);

void ekle(node *,int);

int main() {
	node *root;
	root=(node *)malloc(sizeof(node));
	root->next=NULL;
	root->data=10;
	for(int i=0;i<10;i++) {
		ekle(root,i*10);//hep en baştan yazar, en sona eleman ekler
	}
	bastir(root);//belirtilen yerden liste sonuna kadar basıtırır.
	return 0;
}

void bastir(node*r) {
	while(r!=NULL) {
		printf("\n%d\n",r->data);
		r=r->next;
	}
}

void ekle(node *r,int x) {/*1-en sonda değilse önce en sona git, 
			    *2-son next in gösteridiği nulla alan aç,
			    *3-alanı doldur, yeni alan pointerı Null yap*/
	while (r->next!=NULL) {//son elemana gitmeyi sağlar
		r=r->next;
	}
		r->next=(node*)malloc(sizeof(node));//alan aç
		r->next->data=x;
		r->next->next=NULL;
	
}

/*Dizilere erişim Random'dır,
 *Bağlı listelere erişim ise squential 'dır,
 *dizilerde herhangi bir elemana doğrudan erişmek mümkün,
 *bağlı listelerde adım adım gidilir, çünkü bir elemanın adresi
 *sadece bir önceki elemandadır.*/ 
