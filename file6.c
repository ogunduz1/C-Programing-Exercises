//ftell() uygulaması - curusorün dosyadaki konumunu söyler

#include <stdio.h>

int main() {
	FILE *pointer;
	pointer=fopen("MYFILE.TXT","w");
	fprintf(pointer,"c programming language");
	printf("dosyadaki konum : %ld\n",ftell(pointer));
	fclose(pointer);
	return 0;
}
