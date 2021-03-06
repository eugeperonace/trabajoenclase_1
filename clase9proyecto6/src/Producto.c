/*
 * Producto.c
 *
 *  Created on: Apr 23, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"
#include "utn.h"

/**
 * \brief Imprime un producto
 * \param pProducto Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
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

/**
 * \brief Imprime el array de productos
 * \param arrayProductos Array de productos a ser actualizado
 * \param limite Limite del array de productos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_imprimirArray(Producto* arrayProductos,int limite)
{
	int respuesta = -1;
	int i;
	if(arrayProductos != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(arrayProductos[i].isEmpty != 1)
			{
				printf("\n%s - %s - su valor es %.2f",arrayProductos[i].nombre,arrayProductos[i].descripcion,arrayProductos[i].precio);

			}
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array de productos
 * \param arrayProductos Array de productos a ser actualizado
 * \param limite Limite del array de productos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_initArray(Producto* arrayProductos,int limite)
{
	int respuesta = -1;
	int i;
	if(arrayProductos != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			arrayProductos[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param arrayProductos Array de productos a ser actualizado
 * \param limite Limite del array de productos
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_updateArray(Producto* arrayProductos,int limite, int indice)
{
	int respuesta = -1;
	Producto auxProducto;
	if(arrayProductos != NULL && limite > 0 && indice < limite)
	{
		if(	utn_getNombre(auxProducto.nombre, NOMBRE_LEN, "\nNombre?", "\nNombre invalido",2) == 0 &&
			utn_getDescripcion(auxProducto.descripcion, NOMBRE_LEN, "\nDescripcion?", "\nDescripcion invalida",2) == 0 &&
			utn_getNumeroFlotante(&auxProducto.precio,"\nPrecio?","\nPrecio es invalido",0.01,1000000,2) == 0)
		{
			respuesta = 0;
			arrayProductos[indice] = auxProducto;
			arrayProductos[indice].isEmpty = 0;
		}
	}
	return respuesta;
}


/**
 * \brief Buscar primer posicion vacia
 * \param arrayProductos Array de productos a ser actualizado
 * \param limite Limite del array de productos
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int prod_getEmptyIndex(Producto* arrayProductos,int limite)
{
	int respuesta = -1;
	int i;
	if(arrayProductos != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(arrayProductos[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
