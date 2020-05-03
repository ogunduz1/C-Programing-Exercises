//header tanımlama ve oluşturma uygululaması
/*baglist6.cpp uygulamasının formüllerinin 
 *ayrı header dosyasına aktarılmış şekli
 *ilgili header dosyaları,
 *libraryexample.cpp ve libraryexample.h 
 *compile command
 *g++ headerexample.cpp libraryexample.cpp 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "libraryexample.h"

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
	root=sil(root,40);
	bastir(root);
	root=sil(root,4);
	bastir(root);
	root=sil(root,17);
	bastir(root);
	return 0;
}



