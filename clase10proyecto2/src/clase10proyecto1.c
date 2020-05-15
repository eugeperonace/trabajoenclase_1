/*
 * >>>> CLASE 10 <<<<
 *
 * Desarrollar una aplicacion que permita gestionar una array de Fantasmas
 *
 * Se debera poder realizar
 * 	ALTAS
 * 	BAJAS
 * 	MODIFICACIONES
 *
 * La aplicacion debera permitir ordenar el array por Nombre del fantasma
 *
 * */

#include <stdio.h>
#include <stdlib.h>

#include "fantasma.h"
#include "utn.h"

#define CANTIDAD_FANTASMAS 4

int main(void)
{
	setbuf(stdout,NULL);

	Fantasma arrayFantasmas[CANTIDAD_FANTASMAS];
	int idFantasmas=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;

	if(fan_inicializarArray(arrayFantasmas,CANTIDAD_FANTASMAS) == 0)
	{
		printf("Array inicializado correctamente.\n");
	}
	do
	{
		if(!utn_getNumero(	&opcion,
							"\n1.Cargar un Fantasma"
							"\n2.Modificar un Fantasma"
							"\n3.Eliminar un Fantasma"
							"\n4.Ordenar lista de Fantasmas"
							"\n5.Imprimir lista de Fantasmas"
							"\n6.Salir\n\n",
							"\nError opcion invalida",1,6,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = fan_getEmptyIndex(arrayFantasmas,CANTIDAD_FANTASMAS);
				if(auxiliarIndice >= 0)
				{
					if(fan_altaArray(arrayFantasmas,CANTIDAD_FANTASMAS,auxiliarIndice,&idFantasmas) == 0)
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				fan_imprimirArray(arrayFantasmas,CANTIDAD_FANTASMAS);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del fantasma a modificar","\nID invalido",0,idFantasmas,0) == 0)
				{
					auxiliarIndice = fan_buscarId(arrayFantasmas,CANTIDAD_FANTASMAS,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						fan_modificarArray(arrayFantasmas,CANTIDAD_FANTASMAS,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				fan_imprimirArray(arrayFantasmas,CANTIDAD_FANTASMAS);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del fantasma a eliminar","\nID invalido",0,idFantasmas,0)==0)
				{
					auxiliarIndice = fan_buscarId(arrayFantasmas,CANTIDAD_FANTASMAS,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						fan_bajaArray(arrayFantasmas,CANTIDAD_FANTASMAS,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:
				fan_ordenarPorNombre(arrayFantasmas,CANTIDAD_FANTASMAS);
				break;

			case 5:
				fan_imprimirArray(arrayFantasmas,CANTIDAD_FANTASMAS);
				break;

			}
		}
	}while(opcion != 6);

	return EXIT_SUCCESS;
}





