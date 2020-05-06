//pointer ile binary search tree uygulaması

#include <stdio.h>
#include <stdlib.h>


struct n{
	int data;
	n * left;
	n * right;
};
typedef n node;

node * ekle (node* agac, int x) {
	if(agac==NULL) {
		node *root=(node *)malloc(sizeof(node));
		root->left=NULL;
		root->right=NULL;
		root->data=x;
		return root;
	}
	if(agac->data<x) { 
		agac->right=ekle(agac->right,x);
		return agac;
	}
	agac->left=ekle(agac->left,x);	
	return agac;
}
//LNR
void dolasl(node * agac) {
	if(agac==NULL)
		return;
	dolasl(agac->left);
	printf("%d ",agac->data);
	dolasl(agac->right);
}

//RNL
void dolasr(node * agac) {
	if(agac==NULL)
		return;
	dolasr(agac->right);
	printf("%d ",agac->data);
	dolasr(agac->left);
}
int bul (node *agac, int aranan) {
	if(agac==NULL)
		return -1;
	if(agac->data==aranan)
		return 1;
	if(bul(agac->right,aranan)==1)
		return 1;
	return -1;
	if(bul(agac->left,aranan)==1)
		return 1;	
}

int max(node *agac) {
	while(agac->right!=NULL)
		agac=agac->right;
	return agac->data;
}

int min(node *agac) {
	while(agac->left!=NULL)
		agac=agac->left;
	return agac->data;
}

node * sil (node * agac, int x) {
	if(agac==NULL)
		return NULL;
	if(agac->data==x) {
		if(agac->left==NULL && agac->right==NULL)
			return NULL;
		if(agac->right!=NULL) {
			agac->data=min(agac->right);
			agac->right=sil(agac->right,min(agac->right));
			return agac;
		}
		agac->data=max(agac->left);
		agac->left=sil(agac->left,max(agac->left));
		return agac;
	}
	if(agac->data < x) {
		agac->right=sil(agac->right,x);
		return agac;
	}
	agac->left=sil(agac->left,x);
	return agac;
}

int main() { 
	node * agac=NULL;
	agac=ekle(agac,45);
	agac=ekle(agac,16);
	agac=ekle(agac,85);
	agac=ekle(agac,3);
	agac=ekle(agac,78);
	agac=ekle(agac,15);
	agac=ekle(agac,75);
	agac=ekle(agac,19);
	agac=ekle(agac,87);
	agac=ekle(agac,25);
	agac=ekle(agac,35);
	dolasl(agac);
	printf("\n\n");
	dolasr(agac);
	printf("\narama sonucu %d:",bul(agac,100));
	printf("\nmax : %d min : %d \n",max(agac),min(agac));
	agac=sil(agac,45);
	dolasr(agac);
	return 0;
}		
	 
	  
