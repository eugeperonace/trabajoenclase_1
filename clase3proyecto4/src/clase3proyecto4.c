/*
 ============================================================================
 Name        : clase3proyecto4.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//CUESTIONARIO CLASE 3
//A continuación se muestra una función que permite dividir dos números float e indica si pudo
//realizarse la operación correctamente.


#include <stdio.h>
#include <stdlib.h>

int dividir (float a, float b, float* pResultado);

int main(void)
{
	float num1=10;
	float num2=0;
	float resultado;

	if(dividir(num1,num2,&resultado)==1)
	{
		printf("El resultao de la div es: %.2f", resultado);
	}

	return 0;
}

int dividir (float a, float b, float* pResultado)
{
	int ret= -1;

	if(b!=0)
	{
		*pResultado = a/b;
		ret=1;
	}
	return ret;
}
