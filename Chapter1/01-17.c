/*Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.*/
#include <stdio.h>
#include "Getch.c"

#define MINLINE 5				/* minimum input line size */
#define MAXLINE 100				/* maximum unput line size */

int getlineLOCAL(char s[], int lim) ;
void copy(char destiny[], char source[]);

int main() {
	int len;			/* current line length */
	char line[MAXLINE];		/* current input line */
	
	while ( (len = getlineLOCAL(line,MAXLINE)) > 0 ) {
		if ( len >= MINLINE)
			printf ("%.*s\n", MAXLINE, line);
	}
	putchar ('\n');
	return 0;
}

/* getline: read a line into s, return length. This len returned does not include the \0, so if the len is 5, means that the message is contained in s[0-4] and in s[5] we have a \0. An empty line (starting with \n or EOF) has len = 0 */
int getlineLOCAL(char s[], int lim) {
	
	int c;				/*holds the input*/
	short i;			/*dummy*/
	lim--;				/*lim -1, because we need to save one slot for the \0!!*/

	/*Copying and counting*/
	for (i=0; i<lim ; i++) {		/*the for ranges the index from 0 to lim-1 and has an inner break condition too*/
		c = tgetch(DEFAULT_TIMER);
		if ( c==EOF || c=='\n')
			break;
		s[i] = c;
	}

	s[i] = '\0';			/*puts the \0 and the line is finished!*/
	return i;
}

/*copy: copy 'from' into 'to'*/
void copy(char destiny[], char source[]) {
	int i;
	
	for (i=0; source[i]!='\0'; i++)
		destiny[i] = source[i];
	destiny[i] = source[i];			/*Copy the \0 and then return*/

	return;
}

