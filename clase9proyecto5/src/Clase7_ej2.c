/*
Ejercicio 5.
Tomar el ej 4 y agregar a la biblioteca producto una funcion
que me devuelva el indice de un item vacio (sin cargar) o -1
en caso de error o de que no haya mas lugar.
Esta funcion debe recibir el array y su longitud:

int prod_getEmptyIndex(Producto lista[], int len);

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

	printf("\n Primer lugar vacio: %d",prod_getEmptyIndex(arrayProductos,CANTIDAD_PRODUCTOS));
	if(prod_updateArray(arrayProductos,CANTIDAD_PRODUCTOS,0) == 0)
	{
		prod_imprimir(&arrayProductos[0]);
	}
	printf("\n Primer lugar vacio: %d",prod_getEmptyIndex(arrayProductos,CANTIDAD_PRODUCTOS));

	return EXIT_SUCCESS;
}





