/*
 ============================================================================
 Name        : clase3proyecto1.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//CREAR UNA FUNCION QUE SOLO SUME HASTA 100, SI EL RESULTADO ES MÁS DE 100 QUE DEVULVA 100

#include <stdio.h>
#include <stdlib.h>

//int variableGlobal; // no usar, recursan la materia

// prototipos de funciones
int sumarConLimite(int operador1,int operador2); // prototipo

int main(void)
{
	setbuf(stdout,NULL); // SIEMPRE!!!

    int num1;
    int num2;
    int suma;

    printf("ingrese un numero: \n");
    scanf("%d",&num1);
    printf("ingrese otro numero: \n");
    scanf("%d",&num2);

    suma = sumarConLimite(num1,num2);
    printf("La suma es %d",suma);

	return EXIT_SUCCESS;
}
// funciones auxiliares de mi programa
//definicion de la funcion sumarConLimite
//TIPO  NOMBRE_FUNCION (void)
//TIPO  NOMBRE_FUNCION (TIPO NOMBRE_ARG,...)

int sumarConLimite(int operador1,int operador2) // prototipo
{
	int resultado; // variable local de la funcion

	resultado=operador1 + operador2;
	if(resultado>100)
	{                                                //operador1:33
	   resultado=100;                               //operador2:27
	}                                              // codigo de mi funcion
		return resultado;                 // retornar valor

}



