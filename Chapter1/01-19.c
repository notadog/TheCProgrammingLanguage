/*Exercise 1-19. Write a function reverse (s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.*/


#include <stdio.h>
#include "Getch.c"

#define MAXLINE 100				/* maximum input line size */

/**************************************************************** FUNCTIONS ******************************************************************/
int getlineLOCAL(char s[], int lim) ;
void copy(char destiny[], char source[]);
void Line_reverser (char source[], char destiny[]);

/******************************************************************* MAIN ********************************************************************/

int main() {
	int len;			/* current line length */
	char line[MAXLINE];		/* current input line */
	char rLine[MAXLINE];		/* reversed line*/	

	while ( (len = getlineLOCAL(line,MAXLINE)) > 0 ){
		Line_reverser (line, rLine);

		printf ("\tOriginal: %s\n", line);
		printf ("\tReversed: %s\n", rLine);
		return 0;

		if (len>0)
			printf ("\tReverse: %s\n", rLine);
		else
			printf ("\tReverse: %s[nothing]\n", rLine);
	}

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

	s[i] = '\0';				/*puts the \0 and the line is finished!*/
	return i;
}

void copy(char destiny[], char source[]) {
	int i;
	
	for (i=0; source[i]!='\0'; i++)
		destiny[i] = source[i];
	destiny[i] = source[i];
	return;
}

/*I want to reverse the string, but only what's before the \0*/
void Line_reverser (char src[], char dest[]){
	int len, i;

	for (len=0; src[len] != '\0' ; len++);			/*finds the lenght of the src (the first position in which \0 appears*/

	dest[len] = src[len];					/*copies the endpoint*/
	for (i=0, len--; i<=len; i++)				/*moves one position back to the last good character and copies in reverse*/
		dest[i] = src[len-i];
}

