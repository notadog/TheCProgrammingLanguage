/*Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.*/

#include <stdio.h>
#include "Getch.c"

#define MAXLINE 100				/* maximum input line size, actually this is overrated by 1 as we need a \0*/

int getlineLOCAL(char s[], int lim) ;
void copy(char destiny[], char source[]);

int main() {
	int len;			/* current line length */
	int max=0;			/* maximum length seen so far*/
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];		/* longest line saved here */
	
	while ( (len = getlineLOCAL(line,MAXLINE)) > 0 ){
		if ( len > max) {
			max = len;
			copy(longest, line);
		}
		
		printf ("---------------------------\n");
		printf ("\tLongest: %.*s", MAXLINE, longest);
		if (max>MAXLINE)
			printf ("...");
		printf ("\n\tMax: %d\n", max);
		printf ("---------------------------\n");
	}

	if (max > 0 && max<MAXLINE)
		printf ( "\tFINAL LONGEST: %.*s (size %d)" , MAXLINE, longest, max) ;
	else if (max > 0 && max>=MAXLINE)
		printf ( "\tFINAL LONGEST: %.*s... (size %d)" , MAXLINE, longest, max) ;
	printf ("\n---------------------------\n");

	return 0;
}

/* getline: read a line into s, return length. This len returned does not include the \0, so if the len is 5, means that the message is contained in s[0-4] and in s[5] we have a \0. An empty line (starting with \n or EOF) has len = 0 */
int getlineLOCAL(char s[], int lim) {
	
	int c;				/*holds the input*/
	short i;			/*dummy*/
	lim--;				/*lim -1, because we need to save one slot for the \0!!*/

	/*Copying and counting*/
	for (i=0; i<lim ; i++) {		/*the for ranges the index from 0 to lim-1 and has an inner break condition too*/
		c = tgetche(DEFAULT_TIMER);
		if ( c==EOF || c=='\n')
			break;
		s[i] = c;
	}

	/*puts the \0 and the line is finished!*/
	s[i] = '\0';

	/*If we stopped because the limit was reached, not because the line ended, stop copying, but continue counting*/
	if(i>=lim)
		for ( i--; c!=EOF && c!='\n' ; i++)	/*unfortunatly, i make an extra count in here, so I have to reduce it by one*/
			c = tgetche(DEFAULT_TIMER);

	/*This uniforms the presentation, all lines shall printf a newline on the console when they end*/
	if (c == EOF)
		putchar ('\n');

	return i;
}

void copy(char destiny[], char source[]) {
	int i;
	
	for (i=0; source[i]!='\0'; i++)
		destiny[i] = source[i];
	destiny[i] = source[i];			/*Copy the \0 and then return*/

	return;
}
