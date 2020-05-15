#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Publicacion.h"
#include "utn.h"

static const char TXT_ESTADOS[2][8]={"ACTIVA","PAUSADA"};

/**
 * \brief Imprime los datos de una publicacion
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimir(Publicacion* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\n-ID PUBLICACIÓN: %d - RUBRO: %d - ID CLIENTE: %d - TEXTO: %s - ESTADO: %s",pElemento->id,pElemento->rubro,pElemento->idCliente,pElemento->texto,TXT_ESTADOS[pElemento->estado]);
	}
	return retorno;
}

/**
 * \brief Imprime el array de publicaciones
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimirArray(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			pub_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_inicializarArray(Publicacion* array,int limite)
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
 * \brief Da de alta una publicacion en una posicion del array
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_altaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente)
{
	int respuesta = -1;
	Publicacion bufferPublicacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)
	{
		if(	!utn_getNumero(&bufferPublicacion.rubro,"Ingrese número de rubro: ", "\nError",0,100000,2) &&
			!utn_getApellido(bufferPublicacion.texto,TEXTO_LEN,"Ingrese el texto de la publicación [máximo 64 caracteres]: ", "\nError",2))
		{
			respuesta = 0;
			bufferPublicacion.idCliente = idCliente;
			bufferPublicacion.id = *idPublicacion;
			bufferPublicacion.isEmpty = 0;
			bufferPublicacion.estado = 0;
			array[indice] = bufferPublicacion;
			(*idPublicacion)++;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta una publicacion en una posicion del array de manera forzada
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int pub_altaForzadaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente,char* texto, int estado, int rubro)
{
	int respuesta = -1;
	Publicacion bufferPublicacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)
	{
		strncpy(bufferPublicacion.texto,texto,TEXTO_LEN);
		bufferPublicacion.rubro = rubro;
		bufferPublicacion.estado = estado;
		bufferPublicacion.idCliente = idCliente;
		respuesta = 0;
		bufferPublicacion.id = *idPublicacion;
		bufferPublicacion.isEmpty = 0;
		array[indice] = bufferPublicacion;
		(*idPublicacion)++;

	}
	return respuesta;
}

/**
 * \brief Actualiza una publicacion del array
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_bajaArray(Publicacion* array,int limite, int indice)
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
* \param array Array de publicacion
* \param limite int TamaÃ±o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pub_buscarId(Publicacion array[], int limite, int valorBuscado)
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
 * \param array Array de publicaciones
 * \param limite Limite del array de publicaciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int pub_getEmptyIndex(Publicacion* array,int limite)
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
 * \brief Se listan todas las publicaciones de un cliente
 * \param array Array de publicaciones a imprimir
 * \param limite Limite del array de publicaciones
 * \param auxIdCliente id del cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimirPublicacionesPorIdCliente(Publicacion* arrayPublicaciones, int lenPub, int auxIdCliente)
{
	int retorno = -1;
	int i;
	if(arrayPublicaciones != NULL && lenPub > 0 && auxIdCliente >= 0)
	{
		for(i=0;i<lenPub;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].idCliente == auxIdCliente)
			{
				retorno = 0;
				printf("ID PUBLICACION: %d - RUBRO: %d - ID CLIENTE: %d - ESTADO: %s - TEXTO: %s\n",arrayPublicaciones[i].id,arrayPublicaciones[i].rubro,arrayPublicaciones[i].idCliente,TXT_ESTADOS[arrayPublicaciones[i].estado],arrayPublicaciones[i].texto);
			}
		}
	}
	return retorno;
}

/**
 * \brief Da de baja una publicacion
 * \param arrayPublicaciones Array de publicaciones
 * \param lenPub Limite del array de publicaciones
 * \param auxIdCliente id del cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_bajaPublicacion(Publicacion* arrayPublicaciones, int lenPub, int auxIdCliente)
{

	int retorno = -1;
	int i;
	int idPublicacion;
	int indicePublicacion;
	if(arrayPublicaciones != NULL && lenPub > 0 && auxIdCliente >= 0 && auxIdCliente < lenPub)
	{
		for(i=0;i<lenPub;i++)
		{
			if(arrayPublicaciones[i].idCliente == auxIdCliente)
			{
				idPublicacion = arrayPublicaciones[i].id;
				indicePublicacion = pub_buscarId(arrayPublicaciones,lenPub,idPublicacion);
				arrayPublicaciones[indicePublicacion].isEmpty = 1;
			}
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Cambia el estado de una publicacion a PAUSADA
 * \param arrayPublicaciones Array de publicaciones
 * \param lenPub Limite del array de publicaciones
 * \param auxiliarIdPub id del cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_pausarPublicacion(Publicacion* arrayPublicaciones, int lenPub, int auxiliarIdPub)
{
	int retorno = -1;
	int indicePublicacion;
	if(arrayPublicaciones != NULL && lenPub > 0 && auxiliarIdPub >= 0 && auxiliarIdPub < lenPub)
	{
		indicePublicacion = pub_buscarId(arrayPublicaciones,lenPub,auxiliarIdPub);
		arrayPublicaciones[indicePublicacion].estado = 1;
		printf("El estado de su publicación ha sido cambiado a PAUSADA.\n");
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Cambia el estado de una publicacion a ACTIVA
 * \param arrayPublicaciones Array de publicaciones
 * \param lenPub Limite del array de publicaciones
 * \param auxiliarIdPub id del cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_reanudarPublicacion(Publicacion* arrayPublicaciones, int lenPub, int auxiliarIdPub)
{
	int retorno = -1;
	int indicePublicacion;
	if(arrayPublicaciones != NULL && lenPub > 0 && auxiliarIdPub >= 0 && auxiliarIdPub < lenPub)
	{
		indicePublicacion = pub_buscarId(arrayPublicaciones,lenPub,auxiliarIdPub);
		arrayPublicaciones[indicePublicacion].estado = 0;
		printf("El estado de su publicación ha sido cambiado a ACTIVA.\n");
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Cuenta las publicaciones activas de un cliente
 * \param arrayPublicaciones Array de publicaciones
 * \param lenPub Limite del array de publicaciones
 * \param auxiliarIdPub id del cliente
 * \return Retorna la cantidad de publicaciones activas o -1 (ERROR)
 *
 */
int pub_contadorPublicacionesActivas(Publicacion* arrayPublicaciones, int lenPub, int auxIdCliente)
{
	int retorno = -1;
	int i;
	int contadorPubActivas = 0;

	if(arrayPublicaciones != NULL && lenPub > 0 && auxIdCliente >= 0)
	{
		for(i=0;i<lenPub;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].estado == 0 && arrayPublicaciones[i].idCliente == auxIdCliente)
			{
				contadorPubActivas++;
			}
		}
		retorno = contadorPubActivas;
	}
	return retorno;
}

int pub_contadorPublicacionesPausadas(Publicacion* arrayPublicaciones, int lenPub, int auxIdCliente)
{
	int retorno = -1;
	int i;
	int contadorPubPausadas = 0;

	if(arrayPublicaciones != NULL && lenPub > 0 && auxIdCliente >= 0)
	{
		for(i=0;i<lenPub;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].estado == 1 && arrayPublicaciones[i].idCliente == auxIdCliente)
			{
				contadorPubPausadas++;
			}
		}
		retorno = contadorPubPausadas;
	}
	return retorno;
}



int pub_imprimirRubros(Publicacion* arrayPublicaciones, int lenPub)
{
	int retorno = -1;
	int listaRubros[lenPub];
	int i;
	int j;
	int indiceRubroLibre = 0;
	int flagExisteRubro;


	for(i=0;i<lenPub;i++)
	{
		flagExisteRubro = 0;
		if(arrayPublicaciones[i].isEmpty == 0)
		{
			for(j=0;j<indiceRubroLibre;j++)
			{
				if(arrayPublicaciones[i].rubro == listaRubros[j])
				{
					flagExisteRubro = 1;
					break;
				}
			}
			if(flagExisteRubro == 0)
			{
				listaRubros[indiceRubroLibre] = arrayPublicaciones[i].rubro;
				indiceRubroLibre++;
			}
		}
	}

	for(j=0;j<indiceRubroLibre;j++)
	{
		printf("Número de rubro: %d\n",listaRubros[j]);
	}
	return retorno;
}

int pub_imprimirPubActivasPorRubro(Publicacion* arrayPublicaciones, int lenPub, int* rubro)
{
	int retorno = -1;
	int i;
	int contadorPubActivasPorRubro = 0;

	for(i=0;i<lenPub;i++)
	{
		if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].estado == 0 && arrayPublicaciones[i].rubro == *rubro)
		{
			contadorPubActivasPorRubro++;
			retorno = 0;
		}
	}
	printf("La cantidad de publicaciones activas del rubro [%d] es: %d",*rubro,contadorPubActivasPorRubro);
	return retorno;
}

/**
 * \brief Cuenta la cantidad de publicaciones activos por rubro
 * \param arrayPublicaciones Array de publicaciones que va a ser recorido
 * \param limite Limite del array de publicaciones
 * \param rubro rubro en el cual va a contar sus avisos activos
 * \return Retorna -1 (ERROR) o Cantidad de publicaciones activas por rubro
 *
 */
int pub_contadorPubActivasPorRubro(Publicacion* arrayPublicacion, int limitePublicaciones,int* rubro)
{
	int retorno= -1;
	int i;
	int contadorPubPorRubro = 0;

	if(arrayPublicacion != NULL && limitePublicaciones > 0 && rubro != NULL)
	{
		for(i=0;i<limitePublicaciones;i++)
		{
			if(arrayPublicacion[i].isEmpty == 0 && arrayPublicacion[i].rubro == *rubro && arrayPublicacion[i].estado == 0)
			{
				contadorPubPorRubro++;
				retorno = contadorPubPorRubro;
			}
		}
	}
	return retorno;
}

/**
 * \brief Imprime el rubro con más publicaciones activas
 * \param arrayPublicaciones Array de publicaciones que va a ser recorido
 * \param limite Limite del array de publicaciones
 * \return Retorna -1 (ERROR) o 0 (EXITO)
 *
 */
int pub_imprimirRubroConMasPubActivas(Publicacion* arrayPublicaciones, int lenPub)
{
	int retorno = -1;
	int i;
	int maximoPub;
	int auxRubro;
	int pubActivas;

	if(arrayPublicaciones != NULL && lenPub > 0)
	{
		for(i=0;i<lenPub;i++)
		{
			pubActivas = pub_contadorPubActivasPorRubro(arrayPublicaciones, lenPub, &i);
			if( i==0 || (pubActivas > maximoPub))
			{
				retorno = 0;
				maximoPub = pubActivas;
				auxRubro = 	i;
			}
		}
		printf("\nEl rubro con más publicaciones ACTIVAS es: %d",auxRubro);
	}
	return retorno;
}

/**
 * \brief Cuenta la cantidad de publicaciones pausadas por rubro
 * \param arrayPublicaciones Array de publicaciones que va a ser recorido
 * \param limite Limite del array de publicaciones
 * \param rubro rubro en el cual va a contar sus publicaciones pausadas
 * \return Retorna -1 (ERROR) o Cantidad de publicaciones pausadas por rubro
 *
 */
int pub_contadorPubPausadasPorRubro(Publicacion* arrayPublicaciones, int lenPub,int* rubro)
{
	int retorno= -1;
	int i;
	int contadorPubPorRubro = 0;

	if(arrayPublicaciones != NULL && lenPub > 0 && rubro != NULL)
	{
		for(i=0;i<lenPub;i++)
		{
			if(arrayPublicaciones[i].isEmpty == 0 && arrayPublicaciones[i].rubro == *rubro && arrayPublicaciones[i].estado == 1)
			{
				contadorPubPorRubro++;
				retorno = contadorPubPorRubro;
			}
		}
	}
	return retorno;
}

/**
 * \brief Imprime el rubro con menos publicaciones activas
 * \param arrayPublicaciones Array de publicaciones que va a ser recorido
 * \param limite Limite del array de publicaciones
 * \return Retorna -1 (ERROR) o 0 (EXITO)
 *
 */
int pub_imprimirRubroConMenosPubActivas(Publicacion* arrayPublicaciones, int lenPub)
{
	int i;
	int retorno = -1;
	int auxRubro;
	int pubPausadas;
	int maximoPub;
	if(arrayPublicaciones != NULL && lenPub > 0)
	{
		for(i=0;i<lenPub;i++)
		{
			pubPausadas = pub_contadorPubPausadasPorRubro(arrayPublicaciones, lenPub, &i);
			if( i==0 || (pubPausadas > maximoPub))
			{
				retorno = 0;
				maximoPub = pubPausadas;
				auxRubro = 	i;
			}
		}
	printf("\nEl rubro con MENOS publicaciones ACTIVAS es: %d",auxRubro);
	}
	return retorno;
}
