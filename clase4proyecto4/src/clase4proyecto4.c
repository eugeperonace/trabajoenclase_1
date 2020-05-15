/*
 ============================================================================
 Name        : clase4proyecto4.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//PARA QUE LA FUNCIÓN ME DEVUELVA UNA LETRA

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);

	char letra;
	int respuesta;

	respuesta = utn_getCaracter(&letra,"Letra?\n","Error la letra debe ser desde A a M\n",'A','M',1);
	if(respuesta == 0)
	{
		printf("\nLa letra es %c",letra);
	}
	else
	{
		printf("\nERROR");
	}

	return EXIT_SUCCESS;
}
