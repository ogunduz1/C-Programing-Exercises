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
	node *root;//ilk adres
	root=(node *)malloc(sizeof(node));//adrese alan tanımlama
	root->data=10;
	root->next=(node*)malloc(sizeof(node));
	root->next->data=20;
	root->next->next=(node*)malloc(sizeof(node));
	root->next->next->data=30;
	//yukarıdakinin daha kullanışlı yolu
	node *iter;
	iter =root;//kök adresini bir nevi kopyaladık
	printf("\n%d\n",iter->data);
	iter=iter->next;//bir sonraki adresi almış oldu
	printf("\n%d\n",iter->data);
	iter=iter->next;
	printf("\n%d\n",iter->data);
	return 0;
}
/*Dizilere erişim Random'dır,
 *Bağlı listelere erişim ise squential 'dır,
 *dizilerde herhangi bir elemana doğrudan erişmek mümkün,
 *bağlı listelerde adım adım gidilir, çünkü bir elemanın adresi
 *sadece bir önceki elemandadır.*/ 
