/*
 * cuitt.c
 *
 *  Created on: 7 may. 2020
 *      Author: Santiago
 */
#include "cuit.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//utn.c

int utn_getCuit(char* pResultado, char* mensaje, char* mensajeError, char* minimo, char* maximo, int reintentos)
{
	int retorno = -1;
	char bufferCuit[4000];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s", mensaje);
			if(getCuit(bufferCuit)==0)
			{
				if(strcmp(bufferCuit,minimo)>0 && strcmp(bufferCuit,maximo)>0)
				{
					strcpy(pResultado,bufferCuit);
				}
				else
				{
					printf("%s", mensajeError);
					reintentos--;
					continue;
				}
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

static int getCuit(char* pResultado)
{
	int retorno=-1;
	char bufferCuit[4000];
	if(getString(bufferCuit,strlen(bufferCuit)) == 0 && esCuit(bufferCuit))
	{
		strncpy(pResultado,bufferCuit,strlen(bufferCuit));
		retorno = 0;
	}
	return retorno;
}

static int esCuit(char* cadena)
{
	int retorno = 0;
	int i;
	int j;
	int contadorGuion = 0;
	if(cadena != NULL)
	{
		for(i=0; cadena[i] != '\0'; i++)
		{
			if((cadena[i] >= '0' && cadena[i] <= '9') || cadena[i] == '-')
			{
				if(cadena[2] == '-')
				{
					j=3;
					do
					{
						if(cadena[j] >= '0' && cadena[j] <= '9')
						{
							retorno = 1;
						}
						else
						{
							retorno = 0;
							break;
						}
						j++;
					}while(cadena[j]=='-');
				}

				if(cadena[i] == '-')
				{
					contadorGuion++;
				}
				if(contadorGuion==2)
				{
					retorno = 1;
				}
				else if (contadorGuion>3)
				{
					retorno = 0;
					break;
				}
				retorno = 1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
