//dosya sonuna ulaşıncaya kadar yazı yazma uygulaması

#include <stdio.h>

int main() {
	char ch;
	FILE *fp;
	fp=fopen("out.txt","r");//çalışması için out.txt isimli dosya olmalı, yoksa segmentation fault verir
	while(!feof(fp)) { //feof bir bool ifade başındaki ünlem not anlamında
		ch=getc(fp);
		printf("\n%c",ch);
	}
	return 0;
}
