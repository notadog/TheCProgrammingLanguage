/*Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments do not nest.*/

#include <stdio.h>
#include <stdbool.h>
#include "Getch.c"

/*********************************************************************************************************************************************/
/*FUNCTIONS*/
bool is_ANSI (int argc, char *argv[]);			/*checks if any argv is -ansi*/
bool str_compare (char str1[], char str2[]);		/*compares two strings*/

/*********************************************************************************************************************************************/
int main (int argc, char *argv[]){

	int input;
	bool in_comment=false;
	bool in_cpp_comment=false;
	bool cpp_enabled = !(is_ANSI (argc, argv));

	while ((input = tgetch(DEFAULT_TIMER)) != EOF ) {

		/*TRANSITION INSIDE COMMENT -> OUTSIDE COMMENT*/
		if (in_comment==true || in_cpp_comment==true) {

			/*C TRANSITION*/
			if (input=='*') {
				input = tgetch(DEFAULT_TIMER);			/*grab the next character*/
				if (input == '/')				/*if it's a *, then we quitting the comment*/
					in_comment = false;
			}

			/*C++ TRANSITION*/
			else if (cpp_enabled == true && input=='\n') {		/*if cpp is enabled, check for the endline*/
				in_cpp_comment = false;
				putchar ('\n');
			}
		}
		/*TRANSITION OUTSIDE COMMENT -> INSIDE COMMENT*/
		else if (in_comment==false && in_cpp_comment==false && input=='/') {
			input = tgetch(DEFAULT_TIMER);				/*grab the next character*/
			
			/*C TRANSITION*/
			if (input == '*')					/*checks for the c comment begin*/
				in_comment = true;

			/*C++ TRANSITION*/
			else if (cpp_enabled == true && input == '/')		/*checks for the c++ comment begin*/
				in_cpp_comment = true;

			/*TRANSITION FAILED MIDTERM*/
			else {
				putchar ('/');
				putchar (input);
			}
		}

		/*NO TRANSITION, PRINT IF INSIDE AND DONT PRINT IF OUTSIDE*/
		else
			if (in_comment == false)
				putchar (input);
	}

	putchar ('\n'); putchar ('\n');
	return 0;
}

bool is_ANSI (int argc, char *argv[]) {
	int i;

	for (i=0; i<argc; i++)
		if ( str_compare("-ansi", argv[i]) == true )
			return true;
	return false;
}

bool str_compare (char str1[], char str2[]) {
	int i;

	for (i=0; str1[i]!='\0' ; i++)
		if (str1[i] != str2[i])
			return false;
	return true;
}
