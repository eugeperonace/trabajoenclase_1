/*
 ============================================================================
 Name        : clase4proyecto5.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*Solicitar al usuario que ingrese una serie de números mayores o iguales a 0 e inferiores a
 * 1000, la aplicación finaliza al introducir el numero 1000 (IMPORTANTE: El 1000 no debe ser
 * tenido en cuenta para dicho cálculo). Una vez finalizado el ingreso de números el programa
 * deberá mostrar el promedio de dichos números por pantalla. En el caso de ingresar mal un
 * numero el programa debe dar 2 reintentos.*/

//CUESTIONARIO CLASE 4

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define TRUE 1
#define FALSE 0

int main(void)
{
	setbuf(stdout,NULL);
	int numero;
	int contador=0;
	int acumulador=0;
	float promedio;
	int respuesta;

	while(1)
	{
		respuesta = utn_getNumero(&numero,"Ingrese un numero:\n","Error, ingrese un num valido",0,1000,2);
		if(respuesta==0 && numero!=1000)
		{
			contador++;
			acumulador += numero;
		}
		else
		{
			break;
		}
	}

	promedio=(float)acumulador/contador;
	printf("el prom es: %.2f", promedio);
	return 0;
}
