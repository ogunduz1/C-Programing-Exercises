#include <stdio.h>
#include <math.h>
//rastgele 5x8 lik binary matris oluşturur.
int rand();
int main() {
	int r;
	for(int i=0;i<5;i++) {//i satır değeri için
		for(int j=0;j<8;j++) {//j sütun değeri için
			r=rand()%2;
			printf("%d",r);//asıl değer işleme bu satırda yapılır-satır satır işleme
		}
	printf("\n");
	}
	return 0;
}
