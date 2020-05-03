#ifndef libraryexample
#define libraryexample
struct n{
	int data;
	n * next;
};
typedef n node;
void bastir(node*);
void ekle(node *,int );
node* siraekle(node *,int );
node* sil(node *,int );

#endif

