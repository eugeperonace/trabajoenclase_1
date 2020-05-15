/*
 * Producto.c
 *
 *  Created on: Apr 23, 2020
 *      Author: Mauro
 */
#include "Cliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimir(Cliente* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno = 0;
		printf("\nID: %d- %s - %s - su valor es %.2f",pElemento->id, pElemento->nombre,pElemento->dni,pElemento->altura);
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
int cli_imprimirArray(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty != 1)
			{
				printf("\nID: %d - %s - %s - su altura es %.2f",array[i].id,array[i].nombre,array[i].dni,array[i].altura);

			}
		}
	}
	return respuesta;
}

/*
 	 cli_imprimirArray(Cliente* array, int limite)
 	 {
 	 	 int respuesta = -1;
 	 	 int i;

 	 	 if(array != NULL && limite > 0)
 	 	 {
 	 	 	 respuesta = 0;
 	 	 	 for(i=0;i<limite;i++)
 	 	 	 {
 	 	 	  	  cli_imprimir(&array[i]);
 	 	 	 }
 	 	 }
 	 	 return respuesta;
 	 }

 */

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_inicializarArray(Cliente* array,int limite)
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
 * \brief Da de alta un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_altaArray(Cliente* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Cliente bufferCliente;
	if(array != NULL && limite > 0 && indice < limite)
	{
		if(	utn_getNombre(bufferCliente.nombre, NOMBRE_LEN, "\nNombre?", "\nNombre invalido",2) == 0 &&
			utn_getDni(bufferCliente.dni, DNI_LEN, "\nDNI?", "\nDNI invalido",2) == 0 &&
			utn_getNumeroFlotante(&bufferCliente.altura,"\nAltura?","\nAltura invalida",1,5,2) == 0)
		{
			respuesta = 0;
			array[indice] = bufferCliente;
			array[indice].isEmpty = 0;
			array[indice].id = *id;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un cliente en una posicion del array modo TEST
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \param id ID a ser asignado al cliente
 *  *
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_altaTestArray(Cliente* array,int limite, int indice, int* id, Cliente auxiliar)
{
	int respuesta = -1;

	if(array != NULL && limite > 0 && indice < limite)
	{
		respuesta = 0;
		array[indice] = auxiliar;
		array[indice].isEmpty = 0;
		array[indice].id = *id;
		*id = *id + 1;
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
int cli_modificarArray(Cliente* array,int limite, int indice)
{
	int respuesta = -1;
	Cliente bufferCliente;

	if(array != NULL && limite > 0 && indice >= 0 && indice < limite && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(bufferCliente.nombre, NOMBRE_LEN, "\nNombre?", "\nNombre invalido",2) == 0 &&
			utn_getDni(bufferCliente.dni, DNI_LEN, "\nDNI?", "\nDNI invalido",2) == 0 &&
			utn_getNumeroFlotante(&bufferCliente.altura,"\nAltura?","\nAltura invalida",1,5,2) == 0)
		{
			respuesta = 0;
			bufferCliente.id = array[indice].id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
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
int cli_bajaArray(Cliente* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite)
	{
		respuesta = 0;
		array[indice].isEmpty = 1;
	}
	return respuesta;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cli_buscarId(Cliente array[], int limite, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!= NULL && limite > 0 && valorBuscado >= 0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==0 && array[i].id==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}



/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int cli_getEmptyIndex(Cliente* array,int limite)
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
int cli_ordenarPorNombre(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;
	int flagSwap;
	Cliente buffer;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
						continue;
				}
				if(	array[i].isEmpty == 0 &&
					array[i+1].isEmpty == 0 &&
					strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) > 0)
				{
					buffer = array[i];
					array[i]= array[i+1];
					array[i+1] = buffer;
					flagSwap = 1;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}

int cli_ordenarPorNombreAltura(Cliente* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Cliente buffer;
	int auxiliarCmp;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN);
				if( auxiliarCmp > 0 ||
					(auxiliarCmp == 0 && array[i].altura < array[i+1].altura) )
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

