/*Exercise 1-22. Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.*/

#include <stdio.h>
#include <stdlib.h>
#include "Getch.c"

#define		DEFAULT_LINE_WIDTH	40	/*THE TERMINAL IS 80*/
#define		MAXLINE			100

/**************************************************************** FUNCTIONS ******************************************************************/
int getlineLOCAL(char s[], int lim);
void console_backspace (void);
void print_line (char str[], char len);
void wrap_line (char str[], char WrapPoint);
void copy(char destiny[], char source[]);
/******************************************************************* MAIN ********************************************************************/

int main (int argc, char *argv[]){	
	
	int column_limit;		/*SELECTS THE WRAPPING POINT*/
	char str[MAXLINE];		/*THE CURRENT LINE, TO BE FOLDED*/
	int len;			/*CURRENT LENGHT*/


	/*SELECTS THE LINE LIMIT AND TAB SIZE! EITHER USER-ENTERED OR DEFAULT.*/
	switch (argc) {

		case (2):
			column_limit = atoi (argv[1]);
			break;

		default:
			column_limit = DEFAULT_LINE_WIDTH;
			break;
	}

	/*MAIN LOOP*/
	while ( (len = getlineLOCAL(str,MAXLINE)) > 0 ){
		while (len > column_limit){
			print_line (str, column_limit);
			wrap_line (str, column_limit);
			len -= column_limit;
		}
		print_line (str, column_limit);

	}

	printf ("\n\n");
	return 0;
}

void print_line (char str[], char len) {
	int i;

	for (i=0; i<len; i++){
		if (str[i] == '\0')
			break;
		putchar (str[i]);
	}
	putchar ('\n');
	return;
}

void wrap_line (char str[], char WrapPoint) {
	copy (str, &str[WrapPoint]);
	return;
}

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

void console_backspace (void){
	putchar ('\b');
	putchar (' ');
	putchar ('\b');
	return;
}
