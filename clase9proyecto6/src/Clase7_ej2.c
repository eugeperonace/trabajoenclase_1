/*
-Ejercicio 6.
Tomar la biblioteca producto del "Ejercicio 5" y realizar un programa con un menu de dos opciones:
a) Cargar un producto
b) Imprimir lista productos
Se deberá utilizar la función que devuelve una posición vacía para indicar en que posición del array se
guardaran los datos ingresados.

 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Producto.h"

#define QTY_PROD 2

int main(void)
{
	setbuf(stdout,NULL);
	int opcionElegida;
	Producto arrayProd[QTY_PROD];
	int indiceLugarLibre;

	if(prod_initArray(arrayProd,QTY_PROD)==0)
	{
		printf("Array init ok\n");
	}

	do
	{
		if(utn_getNumero(&opcionElegida,"\nElija una opcion:\n[1] Cargar producto \n[2]Imprimir lista productos \n[3]Salir\n","No es una opcion valida",1,3,2)==0)
		{
			switch (opcionElegida)
			{
			case 1:
				indiceLugarLibre = prod_getEmptyIndex(arrayProd,QTY_PROD);

				if (indiceLugarLibre >=0)
				{
					if(prod_updateArray(arrayProd,QTY_PROD,indiceLugarLibre) == 0)
					{
						printf("Carga OK");
					}
				}
				else
				{
					printf("NO HAY MÁS LUGAR");
				}

				break;
			case 2:
				prod_imprimirArray(arrayProd,QTY_PROD);
				break;
			}
	}

	}while(opcionElegida != 3);

	return EXIT_SUCCESS;
}





