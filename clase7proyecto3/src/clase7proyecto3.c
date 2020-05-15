/*
 ============================================================================
 Name        : clase7proyecto3.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * Ejercicio 3: Definir una funcion validarFloat() que reciba un array de chars en donde los
 * caracteres representan un numero decimal. La funcion deberá devolver en su valor de retorno
 * si la cadena recibida contiene o no un valor numerico en formato texto.
 *
 */
#include <stdio.h>
#include <stdlib.h>

static int validarFloat()
{

}

int main(void) {

	char numero[8];
/*
	// prueba 1
	numero[0]='3';
	numero[1]='.';
	numero[2]='1';
	numero[3]='4';
	numero[4]='\0';

	// prueba 2
	numero[0]='2';
	numero[1]='3';
	numero[2]='5';
	numero[3]='7';
	numero[4]='\0';

	// prueba 3
	numero[0]='2';
	numero[1]='.';
	numero[2]='5';
	numero[3]='.';
	numero[4]='9';
	numero[5]='\0';

	// prueba 4
	numero[0]='h';
	numero[1]='o';
	numero[2]='l';
	numero[3]='a';
	numero[4]='\0';
*/
	if(validarFloat(numero)==1)
	{
		printf("El numero %s es valido, se puede convertir a float!\n",numero);
	}

	return EXIT_SUCCESS;
}
