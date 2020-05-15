/*
 * Producto.c
 *
 *  Created on: Apr 23, 2020
 *      Author: Mauro
 */
#include "fantasma.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/**
 * \brief Imprime los datos de un fantasma
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fan_imprimir(Fantasma* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL)
	{
		retorno = 0;
		printf("ID: %d- %s - %s - %s - su valor es %.2f",pElemento->id, pElemento->campoCharA, pElemento->campoCharB, pElemento->campoCharC, pElemento->campoFloatA);
	}
	return retorno;
}

/**
 * \brief Imprime el array de fantasmas
 * \param array Array de fantasmas a ser actualizado
 * \param limite Limite del array de fantasmas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fan_imprimirArray(Fantasma* array,int limite)
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
				printf("\nID: %d - %s - %s - %s - su altura es %.2f",array[i].id,array[i].campoCharA,array[i].campoCharB,array[i].campoCharC,array[i].campoFloatA);

			}
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de fantasmas a ser actualizado
 * \param limite Limite del array de fantasmas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fan_inicializarArray(Fantasma* array,int limite)
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
 * \brief Da de alta un fantasma en una posicion del array
 * \param array Array de fantasmas a ser actualizado
 * \param limite Limite del array de fantasmas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al fantasma
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fan_altaArray(Fantasma* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Fantasma auxiliar;
	if(array != NULL && limite > 0 && indice < limite)
	{
		if(	utn_getNombre(auxiliar.campoCharA, campoCharA_LEN, "\nNombre?", "\nNombre invalido",2) == 0 &&
			utn_getDescripcion(auxiliar.campoCharB, campoCharB_LEN, "\nDescripcion?", "\nDescripcion invalida",2) == 0 &&
			utn_getDni(auxiliar.campoCharC, campoCharC_LEN, "\nDNI?", "\nDNI invalido",2) == 0 &&
			utn_getNumeroFlotante(&auxiliar.campoFloatA,"\nAltura?","\nAltura invalida",1,5,2) == 0)
		{
			respuesta = 0;
			array[indice] = auxiliar;
			array[indice].isEmpty = 0;
			array[indice].id = *id;
			*id = *id + 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un fantasma en una posicion del array modo TEST
 * \param array Array de fantasmas a ser actualizado
 * \param limite Limite del array de fantasmas
 * \param indice Posicion a ser actualizada
 * \param id ID a ser asignado al fantasma
 *  *
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fan_altaTestArray(Fantasma* array,int limite, int indice, int* id, Fantasma auxiliar)
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
 * \brief Actualiza los datos de un fantasma en una posicion del array
 * \param array Array de fantasmas a ser actualizado
 * \param limite Limite del array de fantasmas
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fan_modificarArray(Fantasma* array,int limite, int indice)
{
	int respuesta = -1;
	Fantasma auxiliar;
	if(array != NULL && limite > 0 && indice < limite)
	{
		if(	utn_getNombre(auxiliar.campoCharA, campoCharA_LEN, "\nNombre?", "\nNombre invalido",2) == 0 &&
			utn_getDni(auxiliar.campoCharC, campoCharB_LEN, "\nDNI?", "\nDNI invalido",2) == 0 &&
			utn_getNumeroFlotante(&auxiliar.campoFloatA,"\nAltura?","\nAltura invalida",1,5,2) == 0)
		{
			respuesta = 0;
			array[indice] = auxiliar;
			array[indice].isEmpty = 0;
		}
	}
	return respuesta;
}
/**
 * \brief Actualiza una posicion del array
 * \param array Array de fantasmas a ser actualizado
 * \param limite Limite del array de fantasmas
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fan_bajaArray(Fantasma* array,int limite, int indice)
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
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fan_buscarId(Fantasma array[], int limite, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!= NULL && limite>=0)
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
 * \param array Array de fantasmas
 * \param limite Limite del array de fantasmas
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int fan_getEmptyIndex(Fantasma* array,int limite)
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
 * \brief Ordenar el array de fantasmas por nombre
 * \param array Array de fantasmas
 * \param limite Limite del array de fantasmas
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int fan_ordenarPorNombre(Fantasma* array,int limite)
{
	int respuesta = -1;
	int i;
	int flagSwap;
	Fantasma auxiliar;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{

				if(	array[i].isEmpty == 0 &&
					array[i+1].isEmpty == 0 &&
					strncmp(array[i].campoCharA,array[i+1].campoCharA,campoCharA_LEN) > 0)
				{
					auxiliar = array[i];
					array[i]= array[i+1];
					array[i+1] = auxiliar;
					flagSwap = 1;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}
