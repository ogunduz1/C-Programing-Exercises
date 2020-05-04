//stack array çalışması

#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

int main() {
	stack *s1=tanimla();
	stack *s2=tanimla();
	for(int i=0;i<10;i++)
		push(10*i,s1);
	bastir(s1);
	for(int i=0;i<10;i++)
		push(pop(s1),s2);
	bastir(s2);
}

	
