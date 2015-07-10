/*Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n tab_vars. Should n be a variable or a symbolic parameter?*/

/*ASSUMMING THERE IS NO LINE WRAPPER!*/

#include <stdio.h>
#include <stdlib.h>
#include "Getch.c"

#define		DEFAULT_TAB	8

/**************************************************************** FUNCTIONS ******************************************************************/
int INVcounter_moduled (int var, int mod);
/******************************************************************* MAIN ********************************************************************/

int main (int argc, char *argv[]){	

	int	input;			/*CHAR INPUT. BY MAKING IT AN INT, IT CAN HOLD THE 'EOF' CHARACTER*/
	int	column=0;		/*COLUMN, USED IN THE VERTICAL TAB (AND ONLY)*/
	char	tab_var;		/*tab_var*/
	char	tab_size;		/*VARIABLE TO HOLD THE TAB SIZE, DEFAULT OR INPUTTED*/
	char	space_counter;		/*VARIABLE TO PUT ALL THE SPACES*/

	/*SELECT BETWEEN THE DEFAULT AND INPUTTED BY THE USER*/
	if (argc>1)
		tab_size = atoi(argv[1]);
	else
		tab_size = DEFAULT_TAB;

	/*START CONDITION FOR THE TAB*/
	tab_var = tab_size;

	/*MAIN LOOP*/
	while ( (input=tgetch(DEFAULT_TIMER)) != EOF ){

		/*Primeiro caso especial*/
		if (input == '\t'){
			for (space_counter=tab_var; space_counter>0; space_counter--)
				putchar (' ');
			column += tab_var;
			tab_var=tab_size;
		}

		/*Segundo caso especial*/
		else if (input == '\n'){
			tab_var=tab_size;
			column = 0;
			putchar (input);
		}

		/*Terceiro caso especial*/
		else if (input == '\v'){
			putchar ('\n');
			for (tab_var=column;tab_var > 0; tab_var--)
				putchar (' ');
			tab_var=tab_size;
		}

		/*Quarto caso especial*/
		else if (input == 127){		/*Por alguma razão misteriosa o 127 é o valor lido quando eu aperto o backspace e o \b = 8 */
			putchar ('\b');		/*VOLTA A POSIÇÃO 1 UNIDADE, SOBRESCREVE A POSIÇÃO COM O WHITESPACE E VOLTA DE NOVO*/	
			putchar (' ');
			putchar ('\b');
			column--;			

			/*tab_var tem que voltar ao estado anterior*/
			if (tab_var == tab_size)
				tab_var=1;
			else
				tab_var++;
		}

		/*Caso geral*/
		else {
			tab_var = INVcounter_moduled (tab_var, tab_size);	/*tab_spot, tab_spot-1,..., 1, tab_spot*/
			column++;
			putchar (input);
			/*printf ("%d %d\n", input, '\b');*/
		}
	}
	putchar ('\n');


	return 0;
}

int INVcounter_moduled (int var, int mod){
	var--;
	if (var<=0)
		return mod;
	return var;
}

