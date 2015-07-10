/*Exercise 1-7. Write a program to print the value of EOF.*/

#include <stdio.h>

int main () {
	int i = EOF;
	int j = sizeof(int);

	printf ("\n%d %*X\n", i, 2*j, i);
	return 0;
}


/*	EOF = -1 na notação int (complemento de 2)
	Ou seja, em hex = 0xFFFF FFFF
	Usei o sizeof int para tornar cross-platform, já que em máquinas antigas (16 bits) o int tinha 2 bytes, hoje em dia (32 e 64 bits) costuma ter 4 bytes e sei lá quantos vai ter no futuro ou em máquinas alternativas*/
