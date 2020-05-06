//queue yapısının linked list ile oluşturulması
#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	n * next;
};
typedef n node;

node * root=NULL; //global varible
node *son=NULL;
void enque(int x) {
	if(root==NULL) {
		root=(node*)malloc(sizeof(node));
		root->data=x;
		root->next=NULL;
		son=root;
	}
	else {
		son->next=(node *)malloc(sizeof(node));
		son->next->data=x;
		son=son->next;
		son->next=NULL;
	}
	
}

int deque(){
	if(root==NULL) {
		printf("Linked list boş");
		return -1;
	}
	int rvalue=root->data;
	node * temp;
	temp=root;
	root=root->next;
	free(temp);
	return rvalue;
	
}

	
int main() {
	for(int i=0;i<20;i++) 
		enque(i*10);
	for(int i=0;i<10;i++)
		printf("%d ",deque());
	for(int i=0;i<20;i++) 
		enque(i*10);
	for(int i=0;i<30;i++)
		printf("%d ",deque());
	return 0;
	

}
