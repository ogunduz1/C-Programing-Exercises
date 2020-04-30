/* 	mantıksal ifadeyi daha okunaklı olması için bu şekilde güncelledik.
	A= i==n/2
	B= j==n/2
	C= i==n/2 - 1
	D= j==n/2 - 1
	E= n%2==0
	
	A v B v E & (C v D) 
*/

#include <stdio.h>

int main() {
	int n,i,j;
	int A, B, C, D, E;//C de bool tipi olmadığı için int olarak tanımlanıyor, 0 dan farklı her değeri doğru kabul ediyor, 0 ı yanlış.
	printf("Lütfen bir sayı giriniz : ");
	scanf("%d",&n);
	//döngülü yapılarda mantıksal değişkenleri ilgili döngü içinde yapmak gerekli
	//döngü dışında yaptık hata aldık
	/*A= i==n/2;
	B= j==n/2;
	C= i==n/2 - 1;
	D= j==n/2 - 1;*/
	
	E= n%2==0;//n sabit olduğu için döngü dışında yapılmasında bir sakınca yok
	
	for(i=0;i<n;i++) {
		//j nihai değerini alt döngüde alacağı için B ve D burada hata verdi altta tanımladık.
		A= i==n/2;
		//B= j==n/2; 
		C= i==n/2 - 1;
		//D= j==n/2 - 1;
		//E= n%2==0;
		for(j=0;j<n;j++) {
			B= j==n/2;
			D= j==n/2 - 1;
			//ifadeyi mantıksal değişken atamalarıyla daha okunur yazdık, yoksa aşağıdaki alternatif ifade de doğru.
			/*if(i==(n/2)||(j==(n/2))||n%2==0&&((i==(n/2-1))||(j==(n/2-1))))*/
			if(A||B||E&&(C||D))
				printf("1");
			else
				printf("0");
		}
	printf("\n");
	}
	return 0;
}	

