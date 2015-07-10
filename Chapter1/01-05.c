/*Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.*/

#include <stdio.h>

#define LOWER	0
#define UPPER	300
#define STEP	20

int main() {
	float celsius;

	printf ("\nCelsius\t  Fahr\n");
	for (celsius=UPPER; celsius >= LOWER; celsius-=STEP)
		printf("%5.0f\t%8.1f\n", celsius, (celsius*9.0/5.0)+32.0);

	return 0;
}
