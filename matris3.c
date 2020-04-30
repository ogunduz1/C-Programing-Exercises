#include <stdio.h>

int main() {
	int n,i,j;
	printf("Lütfen bir sayı giriniz : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if((n%2==1)&&((i==(n-1)/2)||(j==(n-1)/2))||(i==(n/2))||(j==(n/2))||((n%2==0)&&(i==((n/2)-1)))||((n%2==0)&&(j==((n/2)-1))))
				printf("1");
			else
				printf("0");
		}
	printf("\n");
	}
	return 0;
}	
