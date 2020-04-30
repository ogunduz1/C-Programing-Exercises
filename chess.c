#include <stdio.h>

int main() {
	//8x8 ebatlarında satranc tahtası dizilini ekrana yansıtır
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++){//j sütün değerini belirtir
			if((i+j)%2==0)
				printf("X");
			else	
				printf(" ");
		}
	printf("\n");//i satırı belirti
	}
	printf("\n");
	return 0;
}
