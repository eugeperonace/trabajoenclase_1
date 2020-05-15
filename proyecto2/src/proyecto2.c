/*
 ============================================================================
 Name        : proyecto2.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//ejercicio 2: Pedirle al usuario 5 numeros e imprimir el promedio

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	int numero;
	int contador;
	int acumulador=0;
	float promedio;

	for(contador=0;contador<5;contador++)
	{
        printf("ingrese un numero: \n");
        scanf("%d",&numero);
        acumulador += numero;
	}

	promedio = acumulador/contador;
	printf("El promedio es: %.2f", promedio);

    return 0;

}


/*
int main(void)
{
	setbuf(stdout,NULL);
	int numero1;
	int numero2;
	int numero3;
	int numero4;
	int numero5;
	int suma;
	int promedio;

	printf("Ingresar primer numero: \n");
	scanf("%d",&numero1);

	printf("Ingresar segundo numero: \n");
	scanf("%d",&numero2);

	printf("Ingresar tercer numero: \n");
	scanf("%d",&numero3);

	printf("Ingresar cuarto numero: \n");
	scanf("%d",&numero4);

	printf("Ingresar quinto numero: \n");
	scanf("%d",&numero5);

	suma = numero1 + numero2 + numero3 + numero4 + numero5;
	promedio = suma / 5;

	printf("El promedio es %d",promedio);

	return 0;
}

*/




