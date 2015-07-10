/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.*/ 

#include <stdio.h>
#include <stdbool.h>
#include "Getch.c"

/*BIG PROBLEMS WITH BACKSPACES!*/

#define MAX_WORD_LENGHT	20	/*Biggest acceptable word*/

int main (){
	
	unsigned short lengths[MAX_WORD_LENGHT];
	unsigned short current_length=0;
	short c, d;
	unsigned short biggest_word=0, highest_frequency=0;
	_Bool in_word = false;
	
	/*ZEROING EVERYTHING*/
	for (c=0; c<MAX_WORD_LENGHT; c++)
		lengths[c] = 0;
	
	/*GETTING INFO*/
	while ( (c=tgetche(DEFAULT_TIMER)) != EOF){
	
		if ( (c==' ')||(c=='\n')||(c=='\t') ){

			/*if you are just out of a word, add 1 to the respective counter, provided you didn't insert a way too long word*/
			if (in_word == true) {
				if (current_length < MAX_WORD_LENGHT)
					lengths[current_length -1]++; /*moves 1 so that [0]<->len=1 ; [1]<->len=2 ; [2]<->len=3 ...*/
				current_length = 0;
			}
			in_word = false;
			continue;
		}

		/*if you failed the if just before, means it's a valid word character, just print it*/
		in_word = true;
		current_length++;
	}

	if (in_word == true) {
		lengths[current_length -1]++;
		in_word = false;
	}
	
	/*Descobrindo a maior palavra e a mais frequente*/
	/*biggest_word, highest_frequency*/	
	for (c=0; c<MAX_WORD_LENGHT; c++)
		if  (lengths[c] > 0) {
			biggest_word = c;
			
			if (lengths[c] > highest_frequency)
				highest_frequency = lengths[c];
		}

	/*If nothing was entered, go right by*/
	if (highest_frequency == 0){
		printf ("\n\n");
		return 0;
	}


	/*Printing stuff*/
	printf ("\n\nThe horizontal histogram for the frequency of the words by size:\n");
	for (c=0; c<=biggest_word; c++){
		printf ("%2hd  ", c+1);
		for (d=lengths[c]; d>0; d--)
			printf("*");
		printf ("\n");
	}
	printf ("\n");
	
	printf ("The vertical histogram for the frequency of the words by size:\n");
	for (c=highest_frequency; c>0; c--){
		printf ("\n");
		for (d=0; d<=biggest_word; d++) {
			if (lengths[d] >= c)
				printf (" *");
			printf ("\t");
		}
		
	}
	
	printf ("\n");
	for (c=0; c<=biggest_word; c++)
		printf (" %d\t", c+1);
	printf ("\n");
	
	return 0;
}
