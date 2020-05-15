/*
 * Producto.h
 *
 *  Created on: Apr 23, 2020
 *      Author: Mauro
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#define NOMBRE_LEN 50
#define DESCRIPCION_LEN 250

typedef struct
{
	char nombre[NOMBRE_LEN];
	char descripcion[DESCRIPCION_LEN];
	float precio;
}Producto;

int prod_imprimir(Producto* auxProducto);

#endif /* PRODUCTO_H_ */
