//stack array çalışması

#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

stack * tanimla(){
	stack *s=(stack *)malloc(sizeof(stack));
	s->dizi=NULL;
	s->tepe=0;
	s->boyut=2;
	return s;
}

void push(int a,stack *s) {
	if(s->dizi==NULL)
		s->dizi=(int *)malloc(sizeof(int)*s->boyut);
	if(s->tepe>=s->boyut-1) {
		int *dizi2=(int *)malloc(sizeof(int)*s->boyut*2);
		for(int i=0;i<s->boyut;i++)
			dizi2[i]=s->dizi[i];
		free(s->dizi);     
		s->dizi=dizi2;
		s->boyut *=2;
			
	}
	s->dizi[s->tepe++]=a;
}
	
int pop(stack *s) {
	if(s->tepe<=0 || s->dizi==NULL){
		printf("dizi boş \n");
		return -1;
	}
	if(s->tepe<=s->boyut/4) {
		int *dizi2=(int *)malloc(sizeof(int)*s->boyut/2);
		for(int i=0;i<s->tepe;i++)
			dizi2[i]=s->dizi[i];
		free(s->dizi);     
		s->dizi=dizi2;
		s->boyut /=2;
	}
	return s->dizi[--s->tepe];
}	
void bastir(stack *s) {
	printf("boyut : %d \n",s->boyut);
	for(int i=0;i<s->tepe;i++) {
		printf("%d \n",s->dizi[i]);
	}
}

	
