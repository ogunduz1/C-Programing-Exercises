#include <stdio.h>

int main()
{
	int saat, ucret;
	printf("\n çalışma saatini giriniz :\n");
	scanf("%d",&saat);
	if(saat<10)
		ucret=saat*3;
	else if((saat>=10)&&(saat<20))
		ucret=(saat-10)*3+(10*5);
	else
		ucret=(saat-20)*2+(10*3)+(10*5);
	printf("\n%d TL almaya hak kazandınız.\n",ucret);
	return 0;
}
