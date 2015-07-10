/*Exercise 1-8. Write a program to count blanks, tabs, and newlines.*/

#include <stdio.h>
#include "Getch.c"	

int main (){
	
	char c;
	short space_counter=0, newline_counter=0, tab_counter=0;

	space_counter = newline_counter = tab_counter = 0;

	while ( (c=tgetche(DEFAULT_TIMER)) != EOF ){

		if (c == ' ')
			space_counter++;
		else if (c == '\n')
			newline_counter++;
		else if (c == '\t')
			tab_counter++;
	}
	printf ("\n\nSpace: %d\nNewline: %d\nTab: %d\n\n", space_counter, newline_counter, tab_counter);
	return 0;
}

