/*Exercise 1-12. Write a program that prints its input one word per line.*/

/*Problemas relacted to punctuation, word separation and stuff like that*/

#include <stdio.h>
#include <stdbool.h>
#include "Getch.c"

int main (){
	
	short c;
	_Bool in_word = false;

	while ( (c=tgetch(DEFAULT_TIMER)) != EOF) {
	
		if ( (c==' ')||(c=='\n')||(c=='\t') ) {
			
			/*if you just ended a word, go to next line*/
			if (in_word==true)
				putchar('\n');

			/*anyways, you are not in a word anymore*/
			in_word = false;
			continue;
		}
		
		/*if you failed the if just before, means it's a valid word character, just print it*/
		in_word = true;
		putchar (c);
	}
	putchar ('\n');
	return 0;
}

