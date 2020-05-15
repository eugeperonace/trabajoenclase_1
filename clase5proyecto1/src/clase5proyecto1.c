/*
 ============================================================================
 Name        : clase5proyecto1.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
  ARRAYS

 // Ejemplo 1
	int X=0;
	do{
		numeros[X] = 5;
		X=X+1;
	}while(X<7);

	// Ejemplo 2
	int i;
	for(i=0; i<7; i++) // de 0 a 6
	{
		numeros[i] = 5;
	}
  */

//EJERCICIO: Pedirle al usuario 5 edades y LUEGO
// imprimir las 5 edades. Definir un array de 5 posiciones.
// y usar la funcion utn_getNumero() para pedir los valores

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define EDADESSIZE 5

int main(void)
{
	setbuf(stdout,NULL);
	int edad;
	int edades [EDADESSIZE];
	int i;

	//recorro para cargas las edades en forma secuencial

	for(i=0; i<EDADESSIZE; i++)
	{
		if(utn_getNumero(&edad,"Edad?\n","Error la edad debe ser desde 0 a 99\n",0,99,2) == 0)
		{
			edades[i] = edad;
		}
		else
		{
			printf("Edad invalida\n");
		}
	}

	// recorro para imprimir
	for(i=0; i<EDADESSIZE; i++)
	{
		printf("La edad ingresada fue: %d\n", edades[i]);
	}

	return 0;
}
