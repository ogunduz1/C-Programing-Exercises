#include <stdio.h>

int main() {
	int a[]={1,2,3,4,5};
	       //a0a1a2a3a4
	int gecici;//geçici elaman-boş kap
	for(int i=0;i<2;i++) {//i<2 dizinin son eleman numarasının yarısı
		gecici=a[i];
		a[i]=a[4-i];
		a[4-i]=gecici;
	}
	for(int i=0;i<5;i++) {
		printf("%d\t",a[i]);
	}       
	printf("\n");
	return 0;
}
