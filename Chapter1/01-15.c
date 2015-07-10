/*Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.*/

#include <stdio.h>

#define LOWER	0
#define UPPER	300
#define STEP	20

float celsius_to_fahr (float celsius);

int main (){
	
	float celsius;
	
	printf ("\nCelsius\tFahr\n");
	for (celsius=LOWER; celsius <= UPPER; celsius+=STEP)
		printf("%3.0f\t%-6.1f\n", celsius, celsius_to_fahr(celsius));
	
	return 0;
}

float celsius_to_fahr (float celsius){
	return 32.0 + celsius*(9.0/5.0);
}


