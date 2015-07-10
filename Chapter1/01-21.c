/*Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?*/

/*ASSUMMING THERE IS NO LINE WRAPPER!*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Getch.c"

#define		DEFAULT_TAB	8

/**************************************************************** FUNCTIONS ******************************************************************/
int INVcounter_moduled (int var, int mod);
void space_printer (int quantity);

/******************************************************************* MAIN ********************************************************************/

int main (int argc, char *argv[]){	

	int	input;			/*CHAR INPUT. BY MAKING IT AN INT, IT CAN HOLD THE 'EOF' CHARACTER*/
	int	column=0;		/*COLUMN, USED IN THE VERTICAL TAB (AND ONLY)*/
	char	tab_var;		/*tab_var*/
	char	tab_size;		/*VARIABLE TO HOLD THE TAB SIZE, DEFAULT OR INPUTTED*/
	bool	in_blank = false;	/*VARIABLE TO CHECK IF WE ARE IN BLANK*/
	char	space_counter;		/*VARIABLE TO */

	/*SELECT BETWEEN THE DEFAULT AND INPUTTED BY THE USER*/
	if (argc>1)
		tab_size = atoi(argv[1]);
	else
		tab_size = DEFAULT_TAB;

	/*START CONDITION FOR THE TAB*/
	tab_var = tab_size;

	/*MAIN LOOP*/
	while ( (input=tgetch(DEFAULT_TIMER)) != EOF ){		

		/*TRANSFORMANDO A SEQUENCIA DE BLANKS NA MELHOR QUANTIDADE DE ESPAÇOS*/
		if (input == ' ') {
			space_counter++;
			in_blank = true;
			continue;			/*PREVENTS ENTERING ANY OTHER IF/ELSE*/
		}

		/*TRANSFORMING THE RECENT BLANKS IN TABS + BLANKS*/
		if (in_blank == true && input != ' ') {	/*THE SECOND COMPARISON IS TOTALLY UNNECESSARY, BUT GOOD FOR READABILITY*/
			in_blank = false;

			/*TABS*/
			while (space_counter >= tab_var) {
				putchar ('\t');			/*print tab*/
				column += tab_var;		/*update column*/
				space_counter -= tab_var;	/*reduces the amount of spaces left to print*/
				tab_var=tab_size;		/*put tab_var in the max size again*/
			}

			column += space_counter;
			tab_var += space_counter;

			/*Blanks*/
			for (;space_counter>0; space_counter--)
				putchar (' ');
			
			putchar (input);
			continue;
		}

		/*Primeiro caso especial*/
		else if (input == '\t'){
			putchar ('\t');
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
			space_printer (column);
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

void space_printer (int quantity) {
	int dummy;

	for (dummy = quantity; dummy>0; dummy--)
		putchar (' ');

	return;
}

int INVcounter_moduled (int var, int mod){
	var--;
	if (var<=0)
		return mod;
	return var;
}

