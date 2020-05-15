/*
 * utn.c
 *
 *  Created on: 28 abr. 2020
 *      Author: Santiago
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Imprime a modo DEBUG la informacion de un array de enteros
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return 0 si Ok o -1 indicar un error
 *
 */
int printArrayInt(int* pArray, int limite)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && limite >= 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			printf("[DEBUG] INDICE: %d - VALOR: %d\n",i,pArray[i]);
		}
	}
	return retorno;
}

/**
 * \brief Ordena un array de enteros de manera DESCENDENTE
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return Cantidad de iteraciones necesarias para ordenar si Ok o -1 indicar un error
 *
 */
int ordenarArrayInt(int* pArray, int limite)
{
	int flagSwap; //HAGO UN FLAG QUE ME INDIQUE SI HICE O NO UN SWAP
	int i;
	int retorno = -1;
	int buffer;
	int contador = 0;
	int nuevoLimite;

	if(pArray != NULL && limite >= 0)
	{
		nuevoLimite = limite-1;
		do
		{
			flagSwap=0;
			for(i=0;i<nuevoLimite;i++)      //VA CON EL -1 PORQUE QUIERO COMPARAR el 7(i) CON LA POSICION 8(i++)
			{
				contador++;                            //SI LLEGO AL LIMITE VOY A ESTAR COMPARANDO LO QUE ESTÁ EN LA POSICIÓN
				if(pArray[i] < pArray[i+1])  //8(i) CON LO QUE ESTÁ EN LA POSICIÓN 9(i++), sería compararlo contra la misma nada
				{
					flagSwap=1;
					buffer=pArray[i];
					pArray[i]=pArray[i+1];
					pArray[i+1]=buffer;
				}
			}
			nuevoLimite--;
		}while(flagSwap); // es lo mismo que poner flagSwap==1;
		retorno = contador;
	}
	return retorno;
}




