/*Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.*/

#include <stdio.h>
#include "Getch.c"

int main (){
	
	short c;

	while ( (c=tgetch(DEFAULT_TIMER)) != EOF){
		
		if (c == '\\'){
			putchar ('\\');
			putchar ('\\');
			continue;
		}

		if (c == '\t'){
			putchar ('\\');
			putchar ('t');
			continue;
		}

		if (c == '\b' || c == 127){
			putchar ('\\');
			putchar ('b');
			continue;
		}
		
		putchar(c);
	}

	putchar ('\n');
	putchar ('\n');

	return 0;
}
