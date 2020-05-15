/*
 ============================================================================
 Name        : proyecto1.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * estructuras:
producto: id , nombre , precio , stock
proveedor:id , nombre , localidad

Cada producto puede tener un solo proveedor
Cada proveedor puede tener muchos productos

crear 4 proveedores
crear 10 productos
con la siguiente distribuciÛn

proveedor 1: dos productos
proveedor 2: cuatro productos
proveedor 3: cuatro productos
proveedor 4 : sin productos

---------------------------------------------------------------------------------------------------------
1. Alta de Producto.
2. ModificaciÛn de Producto.
3. Baja Proveedor en cascada.


Listados
a- mostrar todos los proveedores, con sus productos o informar si no tiene ning˙n producto.
b- mostrar el proveedor que tiene m·s productos
 */

#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"
#include "Contratacion.h"
#include "utn.h"
#include "Informes.h"
#define CANTIDAD_PRODUCTOS 		10
#define CANTIDAD_CONTRATACIONES 4

int main(void)
{
	setbuf(stdout,NULL);
	Contratacion arrayContrataciones[CANTIDAD_CONTRATACIONES];
	Producto arrayProductos[CANTIDAD_PRODUCTOS];
	int idProductos=0;
	int idContrataciones=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;
	int auxiliarIdContratacion;
	int auxiliarIndiceContratacion;
	char auxiliarCuit[CUIT_LEN];


	if(prod_inicializarArray(arrayProductos,CANTIDAD_PRODUCTOS) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}

	if(cont_inicializarArray(arrayContrataciones,CANTIDAD_CONTRATACIONES) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}


	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar una pantalla"
							"\n2.Modificar una pantalla"
							"\n3.Eliminar una pantalla"
							"\n4.Contratar una publicidad"
							"\n5.Modificar condiciones de publicacion"
							"\n6.Cancelar Contratacion"
							"\n7.Consulta facturacion"
							"\n8.Imprimir contratacion"
							"\n9.Imprimir lista pantalla"
							"\n10.Informar"

							"\n11.Salir\n\n",

							"\nError opcion invalida",1,11,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = prod_getEmptyIndex(arrayProductos,CANTIDAD_PRODUCTOS);
				if(auxiliarIndice >= 0)
				{
					if(prod_altaArray(arrayProductos,CANTIDAD_PRODUCTOS,auxiliarIndice,&idProductos) == 0)
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
				prod_imprimirArray(arrayProductos,CANTIDAD_PRODUCTOS);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del Panatalla a modificar: ","\nID invalido",0,idProductos,0) == 0)
				{
					auxiliarIndice = prod_buscarId(arrayProductos,CANTIDAD_PRODUCTOS,auxiliarId);
					if(	auxiliarIndice >= 0 &&
							prod_modificarArray(arrayProductos,CANTIDAD_PRODUCTOS,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				prod_imprimirArray(arrayProductos,CANTIDAD_PRODUCTOS);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del Producto a eliminar:","\nID invalido",0,idProductos,0)==0)
				{
					auxiliarIndice = prod_buscarId(arrayProductos,CANTIDAD_PRODUCTOS,auxiliarId);
					if(	auxiliarIndice >= 0 &&
							prod_bajaArray(arrayProductos,CANTIDAD_PRODUCTOS,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:

				auxiliarIndiceContratacion = cont_getEmptyIndex(arrayContrataciones,CANTIDAD_CONTRATACIONES);
				if(auxiliarIndiceContratacion >= 0)
				{
					prod_imprimirArray(arrayProductos,CANTIDAD_PRODUCTOS);
					if(	utn_getNumero(&auxiliarId,"\nId Producto: ","\nError",0,10000,2) == 0 &&
						prod_buscarId(arrayProductos,CANTIDAD_PRODUCTOS,auxiliarId) != -1)
					{
						cont_altaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,auxiliarIndiceContratacion,&idContrataciones,auxiliarId);
					}
					else
					{
						printf("\nEL ID NO EXISTE");
					}
				}
				break;

				/*Se pedir√° que se ingrese el cuit del cliente y se listaran todas las pantallas de
				video que el cliente tiene contratadas mostrando todos sus campos.
				Luego de ingresar el ID de la contratacion, se permitir√° modificar la cantidad de d√≠as
				contratados para la misma.*/
			case 5:
				if(	!utn_getDni(auxiliarCuit,CUIT_LEN,"\n CUIT? ", "\nError", 2) &&
					!info_imprimirProductosContratadasByCuit(arrayContrataciones,CANTIDAD_CONTRATACIONES,arrayProductos,CANTIDAD_PRODUCTOS,auxiliarCuit))
				{

					if(!utn_getNumero(&auxiliarIdContratacion,"\nID CONTRATACION A MODIFICAR? ","\nERROR",0,10000,2))
					{
						auxiliarIndiceContratacion = cont_buscarId(arrayContrataciones,CANTIDAD_CONTRATACIONES,auxiliarIdContratacion);
						if(auxiliarIndiceContratacion != -1)
						{
							cont_modificarArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,auxiliarIndiceContratacion);
						}
					}
				}
				else
				{
					printf("\nCUIT NO ENCONTRADO");
				}
				break;

			case 6:
				if(	!utn_getDni(auxiliarCuit,CUIT_LEN,"\n CUIT? ", "\nError", 2) &&
					!info_imprimirProductosContratadasByCuit(arrayContrataciones,CANTIDAD_CONTRATACIONES,arrayProductos,CANTIDAD_PRODUCTOS,auxiliarCuit))
				{

					if(!utn_getNumero(&auxiliarIdContratacion,"\nID CONTRATACION A CANCELAR? ","\nERROR",0,10000,2))
					{
						auxiliarIndiceContratacion = cont_buscarId(arrayContrataciones,CANTIDAD_CONTRATACIONES,auxiliarIdContratacion);
						if(auxiliarIndiceContratacion != -1)
						{
							cont_bajaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,auxiliarIndiceContratacion);
						}
					}
				}
				else
				{
					printf("\nCUIT NO ENCONTRADO");
				}
				break;

			/*Consulta facturacion: Se deber√° ingresar el cuit del cliente y se deber√° listar el importe
			a pagar por cada contrataci√≥n.*/
			case 7:
				if(	!utn_getDni(auxiliarCuit,CUIT_LEN,"\n CUIT? ", "\nError", 2))
				{
					info_imprimirContratacionesConImporte(arrayContrataciones,CANTIDAD_CONTRATACIONES,arrayProductos,CANTIDAD_PRODUCTOS,auxiliarCuit);
				}
				break;

			case 10:
				info_imprimirContratacionesConImportePorCliente(arrayContrataciones,CANTIDAD_CONTRATACIONES,arrayProductos,CANTIDAD_PRODUCTOS);
				break;
			case 14:
				prod_ordenarPorNombre(arrayProductos,CANTIDAD_PRODUCTOS);
				break;

			case 8:
				cont_imprimirArray(arrayContrataciones,CANTIDAD_CONTRATACIONES);
				break;
			case 9:
				prod_imprimirArray(arrayProductos,CANTIDAD_PRODUCTOS);
				break;

			}
		}
	}while(opcion != 11);

	return EXIT_SUCCESS;
}





