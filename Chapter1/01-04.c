/*Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.*/

#include <stdio.h>

int main() {
	float celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature table */
	upper = 300;		/* upper limit */
	step = 20;		/* step size */
	
	printf ("\nCelsius\tFahr\n");
	for (celsius=lower; celsius <= upper; celsius+=step)
		printf("%3.0f\t%6.1f\n", celsius, (celsius*9.0/5.0)+32.0);

	return 0;
}
