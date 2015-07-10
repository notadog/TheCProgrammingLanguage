/*Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.*/

#include <stdio.h>
#include "Getch.c"

#define MAXLINE 100				/* maximum unput line size */


/**************************************************************** FUNCTIONS ******************************************************************/
int getlineLOCAL(char s[], int lim) ;
void copy(char destiny[], char source[]);
int removetrailing (char source[], int len);

/******************************************************************* MAIN ********************************************************************/

int main() {
	int len;			/* current line length */
	char line[MAXLINE];		/* current input line */
	
	while ( (len = getlineLOCAL(line,MAXLINE)) > 0 ){
		
		printf ("\tBefore: %s\tSize: %d\n\n", line, len);
		len = removetrailing (line, len);

		if (len>0)
			printf ("\tAfter: %s\tSize: %d\n\n", line, len);
		else
			printf ("\tAfter: %s[nothing]\n\tSize: %d\n\n", line, len);
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

	s[i] = '\0';			/*puts the \0 and the line is finished!*/
	return i;
}

void copy(char destiny[], char source[]) {
	int i;
	
	for (i=0; source[i]!='\0'; i++)
		destiny[i] = source[i];
	destiny[i] = source[i];
	return;
}

/*Receives a string and its size. With that info, start from the end of the string and erase every trailing blank and tab it finds until a valid character pops up. Returns the new size of the string"*/
int removetrailing (char src[], int len){

	/*while the string has valid characters*/
	for (len--;len>0; len--) {			/*reduces 1 character right away because the initial character is a '\0'*/
		if ( src[len]==' '|| src[len]=='\t' )	/*if the currect character is a trailing blank or tab, turn it into a '\0'*/
			src[len] = '\0';
		else					/*else, revert the string with the initial index move and return*/
			return len+1;
	}
	
	/*It will end up here if there isn't any valid character in the string. In this case the new len is 0*/
	return 0;
}
