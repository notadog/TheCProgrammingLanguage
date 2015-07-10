/*Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.*/

#include <stdio.h>
#include <stdbool.h>
#include "Getch.c"

int main (){
	
	short c;
	_Bool prevent_spaces, current_is_space;

	prevent_spaces = false;

	while ( (c=tgetch(DEFAULT_TIMER)) != EOF ){
		
		/*current_is_space = (c==' ')||(c=='\n')||(c=='\t');*/
		current_is_space = (c==' ');
		
		if ( (prevent_spaces == true) && (current_is_space == true) )
			continue;
		
		prevent_spaces = current_is_space;
		
		putchar (c);
	}
	
	putchar ('\n');
	putchar ('\n');
	return 0;
}

