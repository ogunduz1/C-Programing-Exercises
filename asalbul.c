//en yakın asal sayı bulucu 

#include <stdio.h>


int main() {
 	int n;
 	printf("lütfen bir sayı giriniz : \n");
 	scanf("%d",&n);
 	for(int i=n;i>2;i--) {//aşağı doğru sayı taraması
 		int asal=1;//logic ifade
 		for(int j=2;j<i;j++) {//yukarı doğru bölen taraması
 			if(i%j==0)
 				asal=0;
 		}
 		if (asal==1) {//break komutunun if döngüsü içinde kalmasına dikkat et
 			printf("\n%d sayısından küçük, en büyük asal sayı %d'dir.\n",n,i);
 			break;
 			}
 	}
 	return 0;
}

 	
