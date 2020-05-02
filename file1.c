//temel dosya işlemleri uygulaması

#include <stdio.h>

int main() {
	FILE *outf, *inf;
	int b=5,f;
	float a=13.72, c=6.68, e, g;
	outf=fopen("testdata","w");//fopen("dosyaismi","mod")
	fprintf(outf," %f %d %f ",a,b,c);//fprintf(pointer,"ifade",değişken)
	fclose(outf);//fclose(pointer)
	inf=fopen("testdata","r");//modlar w(write), r(read), a(append)
	fscanf(inf,"%f %d %f",&e,&f,&g);//fscanf(pointer,"değişken cinsi",&değişken)
	printf("%f %d %f \n",a,b,c);
	printf("%f %d %f \n",e,f,g);
	return 0;
}
