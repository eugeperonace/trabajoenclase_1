/*
 ============================================================================
 Name        : project1.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//pedir dos numeros e imprmir la suma , la resta la division y la multiplicacion

int main(void)
{	setbuf(stdout, NULL);

	int numero1;
	int numero2;
	int suma;
	int resta;
	int multiplicacion;
	float dividir;

	printf("ingrese num 1: \n");
	scanf("%d", &numero1);

	printf("ingrese num 2: \n");
	scanf("%d", &numero2);

	suma= numero1 + numero2;
	resta= numero1 - numero2;
	multiplicacion= numero1 * numero2;
	dividir= (float) numero1 / numero2;

	printf("la suma es: %d\n", suma);
	printf("la multiplicacion es: %d\n", multiplicacion);
	printf("la resta es: %d\n", resta);
	printf("la division es: %.2f\n", dividir);

	return 0;

	}


