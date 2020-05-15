/*
 ============================================================================
 Name        : sabado2proyecto2.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//FUNCIONES

#include <stdio.h>
#include <stdlib.h>

// ambito - scope - alcance


// declaracion fx
// prototipo - firma

//tipo_retorno nombre(listaParametros);

int esPar(int);

int main()
{
   //llamada o invocacion
   int siEs;

   siEs = esPar(2);

   if(siEs==1)
   {
        printf("Es par");
   }
   else
   {
       printf("No es par");
   }


    return 0;
}

// Implementacion
int esPar(int numero)
{
    int siEs = 0;

    if(numero%2 == 0)
    {
        siEs = 1;
    }

    return siEs;
}


