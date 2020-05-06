//kruskal algoritması çalışması, abcd.txt ile birlikte çalışır(içeriği en altta).


#include <stdio.h>
#include <stdlib.h>


int main() {
	FILE *fp=fopen("abcd.txt","r");
	int ds,ks;//düğüm sayısı, kenar sayısı
	fscanf(fp,"%d",&ds);
	fscanf(fp,"%d",&ks);
	int * dolasilan=(int *)malloc(sizeof(int)*ds);
	for(int i=0;i<ds;i++) {
		dolasilan[i]=0;
	}
	int * kimden=(int *)malloc(sizeof(int)*ks);//kenar listesi
	int * kime=(int *)malloc(sizeof(int)*ks);
	int * agirlik=(int *)malloc(sizeof(int)*ks);
	int i=0;
	while(!feof(fp)) {
		fscanf(fp,"%d %d %d",&kimden [i],&kime[i],&agirlik[i]);
		i++;
	}
	//ağırlığa göre sıralama algoritması (bubblesort) yazıyoruz
	fclose(fp);
	for(int i=0;i<ks;i++) {
		for(int j=0;j<ks-1;j++) {
			if(agirlik[j]>agirlik[j+1]) {
				int x=agirlik[j];
				agirlik[j]=agirlik[j+1];
				agirlik[j+1]=x;
				x=kime[j];
				kime[j]=kime[j+1];
				kime[j+1]=x;
				x=kimden[j];
				kimden[j]=kimden[j+1];
				kimden[j+1]=x;
			}
		}
	}
	for(int i=0;i<ks;i++) {
		printf("%d %d %d \n",kimden[i],kime[i],agirlik[i]);
	}
	//kruskal çözüm
	int toplammaliyet=0;//kaç düğümün dolaşıldığı
	for(int j=0;j<ks;j++) {
		if(dolasilan[kime[j]]==0 || dolasilan[kimden[j]]==0) {
			printf("alinan düğüm : %d %d %d\n",kimden[j],kime[j],agirlik[j]);
			toplammaliyet+=agirlik[j];
			dolasilan[kime[j]]=1;
			dolasilan[kimden[j]]=1;
		}
	}
	printf("toplam maliyet : %d\n",toplammaliyet);
	return 0;
}


/* abcd.txt içeriği aşağdaki gibi olmalı
8
13
0 5 2
1 1 1
3 2 4
7 0 1
3 6 5
6 4 10
1 3 3
1 7 2
0 2 3
7 2 1
5 6 4
3 4 5
6 0 3*/
