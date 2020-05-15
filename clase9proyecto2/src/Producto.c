/*
 * Producto.c
 *
 *  Created on: Apr 23, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"

int prod_imprimir(Producto* pProducto)
{
	int retorno=-1;
	if(pProducto != NULL)
	{
		retorno = 0;
		printf("%s - %s - su valor es %.2f",pProducto->nombre,pProducto->descripcion,pProducto->precio);
	}
	return retorno;
}
