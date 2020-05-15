/*
 ============================================================================
 Name        : clase5proyecto5.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//ORDENAMIENTO BURBUJEO

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define QTY_EMPLEADOS 9

int main(void)
{
	setbuf(stdout,NULL);

	int arrayEdades[QTY_EMPLEADOS] = {54,26,93,17,77,31,44,55,27}; //INICIALIZAMOS EL ARRAY P EVITAR PEDIR NUMEROS
	int respuesta;

	printArrayInt(arrayEdades, QTY_EMPLEADOS);         //NO SE PONE & PORQUE EL NOMBRE DEL ARRAY YA HACE
	respuesta = ordenarArrayInt(arrayEdades, QTY_EMPLEADOS);    //REFERECIA A LA DIRECCION DE MEMORIA DEL ARRAY
	if (respuesta > 0)                             //SI ESTA BIEN ME TUVO QUE HABER DEVUELTO ALGO MAYOR QUE 0
	{
		printf("\nIteraciones: %d\n\n", respuesta);
	}
	printArrayInt(arrayEdades, QTY_EMPLEADOS);

	return 0;
}
