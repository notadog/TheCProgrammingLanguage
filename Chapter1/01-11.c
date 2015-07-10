/*Exercise 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?*/

#include <stdio.h>
#include <stdbool.h>
#include "Getch.c"

int main (){

	short word_counter=0;		
	short c;
	_Bool in_word = false;

	while ( (c=tgetche(DEFAULT_TIMER)) != EOF){
	
		if ( (c==' ')||(c=='\n')||(c=='\t') ){
			in_word = false;
			continue;
		}
		
		if (in_word==false) {
			in_word = true;
			word_counter++;
		}
	}
	printf ("\n\nI counted %d words.\n\n", word_counter);
	
	return 0;
}

/*Problemas relacionados a pontuação e outras formas de separar palavras.*/
