#include <stdio.h>

int main() {//5x5 lik bir matrisde ortaya 1lerden oluşan bir + cizer
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			if(i==2||j==2)
				printf("1");
			else
				printf("0");
		}
	printf("\n");
	}
	return 0;
}
			
