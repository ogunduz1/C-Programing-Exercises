//fread() kullanımı örneği

#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *f;
	//char buffer[11];
	char *pbuffer;
	pbuffer=(char*)malloc(sizeof(char)*11);
	
	if(f=fopen("out.txt","r")) { //dosya açılırsa durumu
		fread(pbuffer,1,10,f);//her eleman 1char 10 karakter oku fread(aktarılacakdizi, elamansize, okunacakkaraktersayısı,dosya)
		pbuffer[10]=0;//son karatere manuel sıfır ekledik
		fclose(f);
		printf("dosyanın ilk 10 karakteri : \n%s\n",pbuffer);
	}
	else //Dosya açılamama durumu
		printf("Dosya açılamadı");
	
	return 0;
}

	
