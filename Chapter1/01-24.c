/*Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.)*/

#include <stdio.h>
#include <stdbool.h>
#include "Getch.c"

/*********************************************************************************************************************************************/
/*FUNCTIONS*/
bool is_ANSI (int argc, char *argv[]);						/*checks if any argv is -ansi*/
bool str_compare (char str1[], char str2[]);					/*compares two strings*/
bool not_comment_anymore (bool in_comment, bool in_cpp_comment, int input);	/*tries to exit comment*/
/*********************************************************************************************************************************************/

int main (int argc, char *argv[]) {

	int input;
	int parentheses_stack=0;
	int brackets_stack=0;
	int braces_stack=0;
	bool double_quote_ON=false;
	bool single_quote_ON=false;
	bool in_comment=false;
	bool in_cpp_comment=false;
	bool cpp_enabled = !(is_ANSI (argc, argv));

	while ((input = tgetch(DEFAULT_TIMER)) != EOF ) {

		/*TRANSITION INSIDE COMMENT -> OUTSIDE COMMENT*/
		if (in_comment==true || in_cpp_comment==true) {
			

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

		/*NO COMMENT TRANSITION, WE NEED TO TEST THE INNER */
		else
			if (in_comment == false)
				putchar (input);
	}

	putchar ('\n'); putchar ('\n');
	return 0;
}

bool not_comment_anymore (bool in_comment, bool in_cpp_comment, int input) {

	/*C TRANSITION*/
	if (in_comment==true && input=='*') {
		input = tgetch(DEFAULT_TIMER);			/*grab the next character*/
		if (input == '/')				/*if it's a *, then we quitting the comment*/
			return true;
	}

	/*C++ TRANSITION*/
	else if (in_cpp_comment == true && input=='\n') {	/*if cpp is enabled, check for the endline*/
		putchar ('\n');
		return true;
	}

	return false;
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

