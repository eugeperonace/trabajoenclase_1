/*
 ============================================================================
 Name        : proyecto5.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/* CUESTIONANIO CLASE 2:
 Solicitar al usuario que ingrese una serie de números la cual finaliza al introducir el 999
 (el 999 no debe ser tenido en cuenta para dicho cálculo). Una vez finalizado el ingreso de números
 el programa deberá mostrar el promedio de dichos números por pantalla.

*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main()
{
	setbuf(stdout,NULL);

	int numero;
	int acumulador=0;
	int contador=0;
	float promedio;

	while(1)
	{
		printf("Ingrese un numero (999 FINALIZA EL INGRESO):\n");
		scanf("%d", &numero);

		if(numero != 999)
		{
			contador++;
			acumulador+=numero;
		}
		else
		{
			break;
		}
	}

	promedio=(float)acumulador/contador;
	printf("El promedio es: %.2f", promedio);


	return EXIT_SUCCESS;
} // CIERRE MAIN
