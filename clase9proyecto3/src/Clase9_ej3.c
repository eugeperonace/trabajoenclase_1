/*
Ejercicio 3.
Utilizando la biblioteca "Producto.h" de los ejercicios anteriores,
definir un array de 100 productos.
Realizar una funcion que inicialice el array indicando que los items
no estan cargados con informacion valida.

 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Producto.h"

#define CANTIDAD_PRODUCTOS 100

int main(void)
{
	setbuf(stdout,NULL);
	Producto arrayProductos[CANTIDAD_PRODUCTOS];
	if(prod_initArray(arrayProductos,CANTIDAD_PRODUCTOS) == 0)
	{
		printf("Array INIT ok");
	}

	return EXIT_SUCCESS;
}

/*
 * int main(void) {

	int indice=0;
	Producto productos[PROD_LEN];

	prod_initArray(productos,PROD_LEN);

	if(prod_cargarProducto(productos,PROD_LEN,indice)==1)
	{
		printf("carga exitosa en posicion %d",indice);
	}

	return EXIT_SUCCESS;
}
 */



