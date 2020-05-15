/*
 ============================================================================
 Name        : clase3proyecto2.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// EJERCICIO
// 1 programa que pida un numero al usuario, despues que pida una operacion (+ - / * )
// y despues que pida otro numero. Segun la operacion ingresada, se llamará a una funcion
// que ejecute la operacion (sumar() restar() multiplicar() dividir())
// y luego mostrar al usuario el resultado. El mostrar resultado NOOOOO puede estar dentro de
// las funciones que crean para hacer la operacion. En la funcion dividir, validar no dividir por
// cero

#include <stdio.h>
#include <stdlib.h>

int multiplicar(int operador1,int operador2); // PROTOTIPO
int sumar(int operador1,int operador2);
int restar(int operador1,int operador2);
float dividir(int operador1,int operador2);

int main(void) {

	setbuf(stdout,NULL);

	int numero1;
	int numero2;
	char operacion;
	int multiplicacion;
	int suma;
	int resta;
	float division;

	printf("Ingrese un numero: \n");
	scanf("%d",&numero1);

	printf("Indique la operacion a realizar: \n");
	fflush(stdin);
	scanf("%c", &operacion);

	printf("Ingrese otro numero: \n");
	fflush(stdin);
	scanf("%d",&numero2);

	switch (operacion)
	{
	case 's':
		suma = sumar(numero1,numero2);
		printf("El resultado de la suma es %d \n",suma);
		break;

	case 'm':
		multiplicacion = multiplicar(numero1,numero2);
		printf("El resultado de la multiplicación es %d \n",multiplicacion);
		break;

	case 'r':
		resta = restar(numero1,numero2);
		printf("El resultado de la resta es %d \n",resta);
		break;

	case 'd':
		division = dividir(numero1,numero2);
		printf("El resultado de la división es %.2f \n",division);
		break;
	}
	return 0;
}

//FUNCIONES CREADAS PARA LAS OPERACIONES

int multiplicar(int operador1,int operador2) // PROTOTIPO
{
	int resultado;
	resultado=operador1 * operador2;
	return resultado;
}

int sumar(int operador1,int operador2) // PROTOTIPO
{
	int resultado;
	resultado=operador1 + operador2;
	return resultado;
}

int restar(int operador1,int operador2) // PROTOTIPO
{
	int resultado;
	resultado=operador1 - operador2;
	return resultado;
}

 float dividir(int operador1,int operador2) // PROTOTIPO //CADA OPERADOR RECIBE UN INT
{
	float resultado;

	if(operador2 != 0)
	{
		resultado=(float)operador1 / operador2;
	}
	else
	{
		printf("Ingrese un num valido, no se puede dividir por 0 \n");
	}

	return resultado;//NO PUEDE DEVOLVER UN ERROR LA FUNCION
}
