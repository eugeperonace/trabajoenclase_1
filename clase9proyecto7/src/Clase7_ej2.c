/*
Ejercicio 7.
Agregar al tipo de dato el campo ID que represente un
identificador unico. Modificar el codigo anterior para
que el ID se genere automaticamente. Se debera cargar
el ID automaticamente al cargar un producto, y se debera
 imprimir al imprimir la lista.

 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Producto.h"

#define CANTIDAD_PRODUCTOS 2

int main(void)
{
	setbuf(stdout,NULL);
	Producto arrayProductos[CANTIDAD_PRODUCTOS];
	int idProductos=0;


	int opcion;
	int indiceLugarLibre;

	if(prod_initArray(arrayProductos,CANTIDAD_PRODUCTOS) == 0)
	{
		printf("Array INIT ok");
	}


	do
	{
		if(!utn_getNumero(&opcion,"\n1.Cargar un producto\n2.Imprimir lista productos\n3.Salir","\nError opcion invalida",1,3,2) )
		{
			switch(opcion)
			{
			case 1:
				indiceLugarLibre = prod_getEmptyIndex(arrayProductos,CANTIDAD_PRODUCTOS);
				if(indiceLugarLibre >= 0)
				{
					if(prod_updateArray(arrayProductos,CANTIDAD_PRODUCTOS,indiceLugarLibre,&idProductos) == 0)
					{
						printf("\nCarga OK");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				prod_imprimirArray(arrayProductos,CANTIDAD_PRODUCTOS);
				break;

			}
		}
	}while(opcion != 3);


	/*
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
	 */
	return EXIT_SUCCESS;
}





