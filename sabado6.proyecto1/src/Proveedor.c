#include "Proveedor.h"
#include "Producto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"

void harcodearProveedores (Proveedores vec[], int tam)
{
	char nombre[4][30]={"Juan","Maria","Ana","Martina"};
	char localidades[LOCALIDAD_LEN]={"Moron","Mataderos","Avellaneda","Quilmes"};
	int isEmpty[4]={0,0,0,0};
	int idProveedores[4]={100,200,300,400};
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
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prov_imprimir(Proveedores* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %s - %.2f - %s",pElemento->idProveedores,pElemento->nombre,pElemento->localidades);
	}
	return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prov_imprimirArray(Proveedores* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			prov_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prov_inicializarArray(Proveedores* array,int limite)
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
 * \param idProveedores Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prov_altaArray(Proveedores* array,int limite, int indice, int* idProveedores)
{
	int respuesta = -1;
	Proveedores bufferProveedor;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idProveedores != NULL)
	{
		if(	utn_getNombre(bufferProveedor.nombre,NOMBRE_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getDescripcion(bufferProveedor.localidades,LOCALIDAD_LEN,"\nDireccion?\n","\nERROR\n",2) == 0 )
		{
			respuesta = 0;
			bufferProveedor.idProveedores = *idProveedores;
			bufferProveedor.isEmpty = 0;
			array[indice] = bufferProveedor;
			(*idProveedores)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prov_modificarArray(Proveedores* array,int limite, int indice)
{
	int respuesta = -1;
	Proveedores bufferProveedor;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(bufferProveedor.nombre,NOMBRE_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getDescripcion(bufferProveedor.localidades,LOCALIDAD_LEN,"\nDireccion?\n","\nERROR\n",2) == 0)
		{
			respuesta = 0;
			bufferProveedor.idProveedores = array[indice].idProveedores;
			bufferProveedor.isEmpty = 0;
			array[indice] = bufferProveedor;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int prov_bajaArray(Proveedores* array,int limite, int indice)
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
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [InvalidProveedores length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prov_buscarId(Proveedores array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 0 && array[i].idProveedores == valorBuscado)
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
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int prov_getEmptyIndex(Proveedores* array,int limite)
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
 * \brief Ordenar el array de clientes por nombre
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int prov_ordenarPorNombre(Proveedores* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Proveedores buffer;
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


















