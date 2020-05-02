//fseek() uygulaması -dosya göstericisini istenilen yere taşır
/*SEEK_SET dosyanın başından
 *SEEK_CUR cursorun olduğu yerden
 *SEEK_END dosyanın sonundan
 */
 
 
#include <stdio.h>

int main() {
	FILE *f;
	f=fopen("myfile.txt","w");
	fputs("c programing language",f);//f put string kısaltması
	fseek(f,5,SEEK_SET);
	fputs(">gnu/gcc",f);
	fclose(f);
	return 0;
}
	
