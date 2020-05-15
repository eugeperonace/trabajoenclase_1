/*
 ============================================================================
 Name        : clase3proyecto3.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//PUNTEROS

#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h> //para ffpurge LINUX

int dividir(int operador1, int operador2,float* direccionDeVariableDeRetorno);

int main(void)
{
	setbuf(stdout,NULL);
	int a=30;
	int b=2;
	float resultado;                  //printf("La direccion de resultado en el main es: %d\n",&resultado);
	int retHuboError;

	retHuboError = dividir(a,b,&resultado);

	if(retHuboError==1)
	{
		printf("no se puede dividir");
	}
	else
	{
		printf("resultado:%.2f",resultado);
	}

    return 0;
}

int dividir(int operador1, int operador2, float* direccionDeVariableDeRetorno)
{
	float resul;                //printf("la direccion de resultado en funcion dividir es: %d",direccionDeVariableDeRetorno);
	int huboError;

	if(operador2!=0)
	{
		resul = (float)operador1 / operador2;   // escribir en la direccion direccionDeVariableDeRetorno
		(*direccionDeVariableDeRetorno) = resul;    //el resultado de la division "resul"
		huboError=0;//no hubo error                //escribimeEnLamemoriaEsto(direccionDeVariableDeRetorno,resul);
	}
	else
	{
		huboError=1;//hubo error
	}
	return huboError;
}
