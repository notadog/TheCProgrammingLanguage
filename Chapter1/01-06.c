/*Exercise 1-6. Verify that the expression getchar ( ) != EOF is 0 or 1.*/

#include <stdio.h>

int main () {
	int i = getchar() ;

	printf ("\n (getchar() == eof) = %d \n (getchar() != eof) = %d \n", i == EOF, i!=EOF);
	return 0;
}
