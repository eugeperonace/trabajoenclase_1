/*
 * informes.c
 *
 *  Created on: 10 may. 2020
 *      Author: Eugenia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Publicacion.h"
#include "utn.h"
#include "informes.h"

static const char TXT_ESTADOS[2][8]={"ACTIVA","PAUSADA"};

/**
 * \brief Imprime la informacion de clientes habiendo recibido el ID de la publicacion
 * \param arrayClientes Array de clientes
 * \param lenCli limite array de clientes
 * \param arrayPublicaciones Array de publicaciones
 * \param lenPub Limite del array de publicaciones
 * \param auxiliarIdPub id de la publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int info_imprimirInfoClientesPorIdPublicacion(Cliente* arrayClientes,int lenCli, Publicacion* arrayPublicaciones,int lenPub, int auxiliarIdPub)
{
	int retorno = -1;
	int i;
	int indiceCliente;
	int idCliente;
	if(arrayClientes != NULL && lenCli > 0 && arrayPublicaciones != NULL && lenPub > 0 && auxiliarIdPub >= 0)
	{
		for(i=0;i<lenPub;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].id == auxiliarIdPub)
			{
				retorno = 0;
				idCliente = arrayPublicaciones[i].idCliente;
				indiceCliente = cli_buscarId(arrayClientes,lenCli,idCliente);

				printf("\nEsta publicación pertenece a:\n-ID CLIENTE: %d - NOMBRE: %s - APELLIDO: %s - CUIT: %s",arrayClientes[indiceCliente].id,arrayClientes[indiceCliente].nombre,arrayClientes[indiceCliente].apellido,arrayClientes[indiceCliente].cuit);
			}
		}
	}
	return retorno;
}

/**
 * \brief Imprime la info de los clientes junto con sus publicaciones ACTIVAS
 * \param arrayClientes Array de clientes
 * \param lenCli limite array de clientes
 * \param arrayPublicaciones Array de publicaciones
 * \param lenPub Limite del array de publicaciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int info_imprimirClientesConPublicacionesActivas(Cliente* arrayClientes, int lenCli, Publicacion* arrayPublicaciones, int lenPub)
{
	int retorno = -1;
	int i;
	int idCliente;
	int cantPubActivas = 0;

	if(arrayClientes != NULL && lenCli > 0 && arrayPublicaciones != NULL && lenPub > 0)
	{
		for(i=0;i<lenCli;i++)
		{
			if (arrayClientes[i].isEmpty == 0)
			{
				idCliente = arrayClientes[i].id;
				cantPubActivas = pub_contadorPublicacionesActivas(arrayPublicaciones,lenPub,idCliente);
				printf("\n-ID CLIENTE: %d - NOMBRE: %s - APELLIDO: %s - CUIT: %s - PUBLICACIONES ACTIVAS: %d",arrayClientes[i].id,arrayClientes[i].nombre,arrayClientes[i].apellido,arrayClientes[i].cuit, cantPubActivas);
			}

		}retorno = 0;
	}
	return retorno;
}

/**
 * \brief Imprime las publicaciones junto con el CUIT del cliente a quien corresponde
 * \param arrayPublicaciones Array de publicaciones
 * \param lenPub Limite del array de publicaciones
 * \param arrayClientes Array de clientes
 * \param lenCli limite array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int info_imprimirPublicacionesConCuit(Publicacion* arrayPublicaciones,int lenPub, Cliente* arrayClientes,int lenCli)
{
	int retorno = -1;
	int i;
	int j;

	if(arrayPublicaciones != NULL && lenPub > 0 && arrayClientes != NULL && lenCli > 0)
	{
		for(i=0;i<lenPub;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0)
			{
				for(j=0;j<lenCli;j++)
				{
					if(arrayClientes[j].isEmpty == 0 && arrayPublicaciones[i].idCliente == arrayClientes[j].id)
					{
						printf("\n-ID PUBLICACION: %d - ID CLIENTE: %d - RUBRO: %d - ESTADO: %s - TEXTO: %s - ",arrayPublicaciones[i].id,arrayPublicaciones[i].idCliente,arrayPublicaciones[i].rubro,TXT_ESTADOS[arrayPublicaciones[i].estado],arrayPublicaciones[i].texto);
						printf("CUIT DEL CLIENTE: %s", arrayClientes[j].cuit);
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Imprime cliente con más publicaciones activas
 * \param arrayPublicaciones Array de publicaciones
 * \param lenPub Limite del array de publicaciones
 * \param arrayClientes Array de clientes
 * \param lenCli limite array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int info_imprimirClientesConMasPublicActivas(Cliente* arrayClientes,int lenCli,Publicacion* arrayPublicaciones,int lenPub)
{
	int i;
	int cantPubActivas;
	int maxPubActivas=0;
	int indiceCliente;
	int retorno = -1;


	if(arrayClientes != NULL && lenCli > 0 && arrayPublicaciones != NULL && lenPub > 0)
	{
		for(i=0;i<lenCli;i++)
		{
			cantPubActivas = pub_contadorPublicacionesActivas(arrayPublicaciones,lenPub,i);

			if(arrayClientes[i].isEmpty == 0 && cantPubActivas > maxPubActivas)
			{
					maxPubActivas = cantPubActivas;
					indiceCliente = i;
					retorno = 0;
			}
		}
		printf("El cliente con más publicaciones activas es: %s %s - CUIT: %s / Cantidad publicaciones activas: %d\n", arrayClientes[indiceCliente].nombre, arrayClientes[indiceCliente].apellido, arrayClientes[indiceCliente].cuit,maxPubActivas);
	}
	return retorno;
}

/**
 * \brief Imprime cliente con más publicaciones pausadas
 * \param arrayPublicaciones Array de publicaciones
 * \param lenPub Limite del array de publicaciones
 * \param arrayClientes Array de clientes
 * \param lenCli limite array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int info_imprimirClientesConMasPublicPausadas(Cliente* arrayClientes,int lenCli,Publicacion* arrayPublicaciones,int lenPub)
{
	int i;
	int cantPubPausadas;
	int maxPubPausadas=0;
	int indiceCliente;
	int retorno = -1;


	if(arrayClientes != NULL && lenCli > 0 && arrayPublicaciones != NULL && lenPub > 0)
	{
		for(i=0;i<lenCli;i++)
		{
			cantPubPausadas = pub_contadorPublicacionesPausadas(arrayPublicaciones,lenPub,i);

			if(arrayClientes[i].isEmpty == 0 && cantPubPausadas > maxPubPausadas)
			{
					maxPubPausadas = cantPubPausadas;
					indiceCliente = i;
					retorno = 0;
			}
		}
		printf("El cliente con más publicaciones pausadas es: %s %s - CUIT: %s / Cantidad publicaciones pausadas: %d\n", arrayClientes[indiceCliente].nombre, arrayClientes[indiceCliente].apellido, arrayClientes[indiceCliente].cuit,maxPubPausadas);
	}
	return retorno;
}

/**
 * \brief Imprime cliente con más publicaciones en total
 * \param arrayPublicaciones Array de publicaciones
 * \param lenPub Limite del array de publicaciones
 * \param arrayClientes Array de clientes
 * \param lenCli limite array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int info_imprimirClientesConMasPublicaciones(Cliente* arrayClientes,int lenCli,Publicacion* arrayPublicaciones,int lenPub)
{
	int retorno = -1;
	int i;
	int cantPubActivas;
	int cantPubPausadas;
	int cantPubTotal;
	int maxPub = 0;
	int indiceCliente;

	if(arrayClientes != NULL && lenCli > 0 && arrayPublicaciones != NULL && lenPub > 0)
	{
		for(i=0;i<lenCli;i++)
		{
			cantPubActivas = pub_contadorPublicacionesActivas(arrayPublicaciones,lenPub,arrayClientes[i].id);
			cantPubPausadas = pub_contadorPublicacionesPausadas(arrayPublicaciones,lenPub,arrayClientes[i].id);
			cantPubTotal = cantPubActivas + cantPubPausadas;

			if(arrayClientes[i].isEmpty == 0 && cantPubTotal > maxPub)
			{
				maxPub = cantPubTotal;
				indiceCliente = arrayClientes[i].id;
				retorno = 0;
			}
		}
		printf("El cliente con más publicaciones es: %s %s - CUIT: %s / Cantidad publicaciones totales: %d\n", arrayClientes[indiceCliente].nombre, arrayClientes[indiceCliente].apellido, arrayClientes[indiceCliente].cuit,maxPub);
	}
	return retorno;
}
