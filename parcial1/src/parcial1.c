/*
 ============================================================================
 Name        : parcial1.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Cliente.h"
#include "Publicacion.h"
#include "informes.h"

#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PUBLICACIONES 1000

int main(void)
{
	setbuf(stdout,NULL);
	Cliente arrayClientes[CANTIDAD_CLIENTES];
	Publicacion arrayPublicaciones[CANTIDAD_PUBLICACIONES];
	int opcionMenu;
	int auxiliarIndice;
	int idClientes=0;
	int auxiliarId;
	int idPublicacion=0;
	int auxiliarIndicePublicacion;
	int respuesta;
	int respuestaRubro;

	if(cli_inicializarArray(arrayClientes,CANTIDAD_CLIENTES) == 0)
	{
		printf("\nArray de clientes inicializado correctamente.\n\n");
	}

	if(pub_inicializarArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES) == 0)
	{
		printf("Array de publicaciones inicializado correctamente.\n\n");
	}

	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,0,&idPublicacion,0,"Primer texto",0,1);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,1,&idPublicacion,0,"Segundo texto ",1,1);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,2,&idPublicacion,0,"Tercer texto",1,1);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,3,&idPublicacion,1,"Cuarto texto",0,2);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,4,&idPublicacion,2,"Quinto texto",0,2);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,5,&idPublicacion,2,"Sexto texto",0,2);

	cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,0,&idClientes,"Eugenia","Peronace","27-45546854-3");
	cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,1,&idClientes,"Camila","Alvarez","27-78565695-2");
	cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,2,&idClientes,"Nicolas","Gomez","20-365478-1");

	do
	{
		if(!utn_getNumero(	&opcionMenu,
							"\n\nElija una opción:\n"
							"\n1) Alta de cliente"
							"\n2) Modificar datos de cliente"
							"\n3) Baja de cliente"
							"\n4) Publicar"
							"\n5) Pausar publicación"
							"\n6) Reanudar publicación"
							"\n7) Imprimir Clientes"
							"\n8) Imprimir publicaciones"
							"\n9) Informar clientes"
							"\n10) Informar publicaciones"

							"\n11)Salir\n\n",

							"\nError opción inválida",1,11,2) )
		{
			switch(opcionMenu)
			{
				case 1:
					auxiliarIndice = cli_getEmptyIndex(arrayClientes,CANTIDAD_CLIENTES);
					if(auxiliarIndice >= 0)
					{
						if(cli_altaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice,&idClientes) == 0)
						{
							printf("\nCarga realizada con éxito. El ID del cliente es: %d\n", arrayClientes[auxiliarIndice].id);
						}
					}
					break;
				case 2:
					cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
					if(!utn_getNumero(&auxiliarId,"\nIngrese el número de ID del cliente a modificar: ","\nID inválido\n",0,idClientes,2))
					{
						auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
						if( auxiliarIndice >= 0 &&
							!cli_modificarArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice)	)
						{
							printf("\nModificación realizada con éxito.\n");
						}
					}
					break;
				case 3:
					if( !utn_getNumero(&auxiliarId,"\nIngrese ID del cliente a dar de baja: ","\nError, ID inválido\n",0,idClientes,0) &&
						!pub_imprimirPublicacionesPorIdCliente(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarId))
					{
						if(!utn_getNumero(&respuesta,"\n¿Desea confirmar la eliminación del cliente junto con sus publicaciones? SÍ[1] NO[2]\n","Opción inválida",1,2,2))
						{
							switch(respuesta)
							{
								case 1:
									cli_bajaCliente(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
									pub_bajaPublicacion(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarId);
									printf("\nLa baja fue realizada con éxito.\n");
										break;
								case 2:
									printf("La baja del cliente no se realizó.\n");
										break;
							}
						}
					}
					else
					{
						printf("\nEL ID NO EXISTE.");
					}
					break;
				case 4:
					auxiliarIndicePublicacion = pub_getEmptyIndex(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					if(auxiliarIndicePublicacion >= 0)
					{
						cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
						if( !utn_getNumero(&auxiliarId,"\nIngrese ID del cliente: ","ID inválido",0,idClientes,0) &&
							cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId) != -1)
						{
							pub_altaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIndicePublicacion,&idPublicacion,auxiliarId);
							printf("\nCarga realizada con éxito. El ID de la publicación es: %d\n", arrayPublicaciones[auxiliarIndicePublicacion].id);
						}
						else
						{
							printf("\nEL ID NO EXISTE");
						}
					}

					break;
				case 5:
					pub_imprimirArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					if( !utn_getNumero(&auxiliarId,"\nIngrese ID de la publicación que desea pausar: ","\nError\n",0,idPublicacion,2) &&
						!info_imprimirInfoClientesPorIdPublicacion(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarId))
					{
						if( !utn_getNumero(&respuesta,"\n\n¿Está seguro que desea PAUSAR su publicación?: [1]SI [2]NO\n","Opción inválida",1,2,1))
						{
							switch(respuesta)
							{
								case 1:
									pub_pausarPublicacion(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarId);
									break;
								case 2:
									printf("Su publicación no ha sido pausada.\n");
									break;
							}
						}
					}
					break;
				case 6:
					if( !utn_getNumero(&auxiliarId,"\nIngrese ID de la publicación que desea reanudar: ","\nError\n",0,idPublicacion,2) &&
						!info_imprimirInfoClientesPorIdPublicacion(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarId))
					{
						if( !utn_getNumero(&respuesta,"\n\n¿Está seguro que desea REANUDAR su publicación?: [1]SI [2]NO\n","Opción inválida",1,2,1))
						{
							switch(respuesta)
							{
								case 1:
									pub_reanudarPublicacion(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarId);
									break;
								case 2:
									printf("Su publicación no ha sido reanudada.\n");
									break;
							}
						}
					}
					break;
				case 7:
					info_imprimirClientesConPublicacionesActivas(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					break;
				case 8:
					info_imprimirPublicacionesConCuit(arrayPublicaciones,CANTIDAD_PUBLICACIONES,arrayClientes,CANTIDAD_CLIENTES);
					break;
				case 9:
					info_imprimirClientesConMasPublicActivas(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					info_imprimirClientesConMasPublicPausadas(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					info_imprimirClientesConMasPublicaciones(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					break;
				case 10:
					pub_imprimirRubros(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					utn_getNumero(&respuestaRubro,"\nIngrese un número de rubro [1/300] para ver su cantidad de publicaciones activas: \n","\nEl rubro ingresado no existe.\n\n",1,300,1);
					pub_imprimirPubActivasPorRubro(arrayPublicaciones,CANTIDAD_PUBLICACIONES,&respuestaRubro);
					pub_imprimirRubroConMasPubActivas(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					pub_imprimirRubroConMenosPubActivas(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
					break;
			}
		}
	}while(opcionMenu != 11);

	return EXIT_SUCCESS;
}
