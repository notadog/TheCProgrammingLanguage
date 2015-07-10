/*Exercise l-14. Write a program to print a histogram of the frequencies of different characters in its input.*/

#include <stdio.h>
#include "Getch.c"

#define DIFFERENT_COUNTERS	10	/*The number of different characters that can be counted in a run*/

int main (int argc,char *argv[]){
	
	short c, d;
	short unsigned freqs[DIFFERENT_COUNTERS], highest_frequency;
		
	/*Zerando a memória*/
	for (c=0; c<DIFFERENT_COUNTERS; c++)
		freqs[c] = 0;
		
	/*Getting info*/
	while ( (c=tgetche(DEFAULT_TIMER)) != EOF){
		for (d=1; d<argc; d++)
			if (c == argv[d][0])
				freqs[d-1]++;
	}
	
	/*Printing stuff*/
	printf ("\n\nThe horizontal histogram for the frequency of the words by size:\n");
	for (c=0; c<argc-1; c++){
		printf ("%2c:  ", argv[c+1][0]);
		for (d=freqs[c]; d>0; d--)
			printf("*");
		printf ("\n");
		
		/*aproveitando que já estou em um loop aqui e descubro qual é a maior frequencia*/		
		if (freqs[c] > highest_frequency)
			highest_frequency = freqs[c];
	}
	
	printf ("\nThe vertical histogram for the frequency of the words by size:\n\n");
	for (c=highest_frequency; c>0; c--){
		printf ("\n");
		for (d=0; d<argc-1; d++) {
			if (freqs[d] >= c)
				printf (" *");
			printf ("\t");
		}
		
	}
	
	printf ("\n");
	for (c=0; c<argc-1; c++)
		printf (" %c\t", argv[c+1][0]);
	printf ("\n");
	
	return 0;
}
