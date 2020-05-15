/*
 * Producto.h
 *
 *  Created on: Apr 23, 2020
 *      Author: Mauro
 */

#ifndef FANTASMA_H_
#define FANTASMA_H_

#define campoCharA_LEN 50
#define campoCharB_LEN 100
#define campoCharC_LEN 20

typedef struct
{
	char campoCharA[campoCharA_LEN]; //nombre
	char campoCharB[campoCharB_LEN]; //descripcion
	char campoCharC[campoCharC_LEN]; //dni
	float campoFloatA;
	int isEmpty;
	int id;
}Fantasma;

int fan_imprimir(Fantasma* auxProducto);
int fan_inicializarArray(Fantasma* array,int limite);
int fan_altaArray(Fantasma* array,int limite, int indice, int* id);
int fan_getEmptyIndex(Fantasma* array,int limite);
int fan_imprimirArray(Fantasma* array,int limite);
int fan_buscarId(Fantasma array[], int limite, int valorBuscado);
int fan_ordenarPorNombre(Fantasma* array,int limite);
int fan_modificarArray(Fantasma* array,int limite, int indice);
int fan_bajaArray(Fantasma* array,int limite, int indice);

#endif /* FANTASMA_H_ */
