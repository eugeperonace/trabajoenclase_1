/*
Ejercicio 4.
Tomar el ejercicio 3 y realizar una funcion que reciba el
array, un indice, y le permita al usuario cargar los datos
en el item de la posicion especificada por el indice.
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Producto.h"

#define CANTIDAD_PRODUCTOS 50

int main(void)
{
	setbuf(stdout,NULL);
	Producto arrayProductos[CANTIDAD_PRODUCTOS];
	if(prod_initArray(arrayProductos,CANTIDAD_PRODUCTOS) == 0)
	{
		printf("Array INIT ok");
	}

	if(prod_updateArray(arrayProductos,CANTIDAD_PRODUCTOS,2) == 0)
	{
		prod_imprimir(&arrayProductos[2]);
	}

	return EXIT_SUCCESS;
}





