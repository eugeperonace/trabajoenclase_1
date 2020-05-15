#include "Producto.h"
#include "Proveedor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"


void harcodearProductos (Producto vec[], int tam)
{
	char nombre[10][30]={"A","B","C","D","E","F","G","H","I","J"};
	float precio[10]={10.5,22,33,44,55,66,77,88,99,101};
	int isEmpty[10]={0,0,0,0,0,0,0,0,0,0};
	int id[10]={1,2,3,4,5,6,7,8,9,10};
	int stock[10]={111,222,333,444,555,666,777,888,999,155};
	int idProveedores[10]={100,200,300,400};
	int i;

	for(i=0; i<tam; i++)
	{
		vec[i].idProveedores = idProveedores[i];
		strcpy(vec[i].nombre, nombre[i]);
		strcpy(vec[i].localidades, localidades[i]);
				vec[i].isEmpty = isEmpty[i];
	}
}

/**
 * \brief Imprime los datos de un producto
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_imprimir(Producto* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %.2f - %s",pElemento->id,pElemento->nombre,pElemento->precio,pElemento->stock);
	}
	return retorno;
}

/**
 * \brief Imprime el array de productos
 * \param array Array de productos a ser actualizado
 * \param limite Limite del array de productos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_imprimirArray(Producto* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			prod_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de productos a ser actualizado
 * \param limite Limite del array de productos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_inicializarArray(Producto* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_altaArray(Producto* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Producto bufferProducto;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferProducto.nombre,NOMBRE_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferProducto.precio,"\nPrecio?\n","\nERROR\n",0,10000,2) == 0 &&
			utn_getNumero(&bufferProducto.stock,"Ingrese tipo [0:LCD 1:LED]:","No!",0,1,2)==0)
		{
			respuesta = 0;
			bufferProducto.id = *id;
			bufferProducto.isEmpty = 0;
			array[indice] = bufferProducto;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un producto en una posicion del array
 * \param array Array de productos a ser actualizado
 * \param limite Limite del array de productos
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_modificarArray(Producto* array,int limite, int indice)
{
	int respuesta = -1;
	Producto bufferProducto;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(bufferProducto.nombre,NOMBRE_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferProducto.precio,"\nPrecio?\n","\nERROR\n",0,10000,2) == 0 &&
			utn_getNumero(&bufferProducto.stock,"Ingrese tipo [0:LCD 1:LED]:","No!",0,1,2)==0)
		{
			respuesta = 0;
			bufferProducto.id = array[indice].id;
			bufferProducto.isEmpty = 0;
			array[indice] = bufferProducto;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de productos a ser actualizado
 * \param limite Limite del array de productos
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prod_bajaArray(Producto* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array producto Array de producto
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prod_buscarId(Producto array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 0 && array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de productos
 * \param limite Limite del array de productos
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int prod_getEmptyIndex(Producto* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Ordenar el array de productos por nombre
 * \param array Array de productos
 * \param limite Limite del array de productos
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int prod_ordenarPorNombre(Producto* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Producto buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}


/**
 * \brief Ordenar el array de productos por nombre y altura
 * \param array Array de productos
 * \param limite Limite del array de productos
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int prod_ordenarPorNombrePrecio(Producto* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Producto buffer;
	int auxiliarCmp;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
/*
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
				else if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) == 0)
				{
					if(array[i].altura < array[i+1].altura)
					{
						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i+1];
						array[i+1]=buffer;
					}
				}
*/
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN);
				if(	 auxiliarCmp > 0 ||
					(auxiliarCmp == 0 && array[i].precio < array[i+1].precio) )
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}



/**
 * \brief Da de alta una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
















