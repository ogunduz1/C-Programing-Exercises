#ifndef stack_arr
#define stack_arr

struct s {
	int boyut;
	int tepe;
	int *dizi;
};
typedef s stack;

stack * tanimla();

int pop(stack *);

void push(int, stack *);

void bastir(stack *);

#endif
//header dosyasına değişken tanımlanmaz!
//header dosyasına değişkene değer atanamaz(struck içinde bile)
//bunlar ancak farklı bir tanımlama fonksiyonu ile yapılabilir.
