/*
 ============================================================================
 Name        : clase4proyecto2.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//PARA QUE LA FUNCI�N ME DEVUELVA UN NUMERO ENTERO

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);
	int edad;
	int peso;
	int respuesta;

	respuesta = utn_getNumero(&edad,"Edad?\n","Error, la edad debe ser entre 0 y 99\n",0,99,2);
	if(respuesta == 0)
	{
		printf("La edad es: %d\n",edad);
	}
	else
	{
		printf("Error, ingrese una edad v�lida\n");
	}

	respuesta = utn_getNumero(&peso,"Peso?\n","Error, el peso debe ser entre 0 y 500\n",0,500,1);
	if(respuesta == 0)
	{
		printf("El peso es: %d",peso);
	}
	else
	{
		printf("Error, ingrese un peso v�lido.\n");
	}
} //CIERRE MAIN

