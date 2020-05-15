/*
 ============================================================================
 Name        : clase9proyecto2.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Ejercicio 2.
Tomar el programa del ejercicio anterior y agregarle lo siguiente:
1) Una vez que el usuario ingreso los datos, preguntarle si
quiere aplicar un descuento del 25% al precio del producto.
Si acepta, calcular el nuevo precio.
2) Hacer una funcion que reciba la variable producto definida
y que imprima sus valores.
NOTA: Pude pasarse la variable producto por referencia o por
valor. ¿Cual es la diferencia?
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Producto.h"

int main(void)
{
	setbuf(stdout,NULL);
	Producto auxProducto;
	int repuestaDescuento;

	if(	utn_getNombre(auxProducto.nombre, NOMBRE_LEN, "Nombre?", "\nNombre invalido",2) == 0 &&
		utn_getDescripcion(auxProducto.descripcion, NOMBRE_LEN, "\nDescripcion?", "\nDescripcion invalida",2) == 0 &&
		utn_getNumeroFlotante(&auxProducto.precio,"\nPrecio?","\nPrecio es invalido",0.01,1000000,2) == 0)
	{
		prod_imprimir(&auxProducto);
	}
	if( utn_getNumero(&repuestaDescuento,"\nPara aplicar el descuento seleccione [1] - Para salir [2]\n","\nLas opciones son 1 y 2",1,2,2) == 0)
	{
		if(repuestaDescuento)
		{
			auxProducto.precio = auxProducto.precio * 0.75;
			prod_imprimir(&auxProducto);
		}
	}

	return EXIT_SUCCESS;
}





