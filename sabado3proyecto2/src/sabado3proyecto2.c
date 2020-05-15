/*
 ============================================================================
 Name        : sabado3proyecto2.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/******************************************************************************

Ingresar números hasta que el usuario lo decida. Los números tienen que estar
comprendidos entre -100 y 100. Determinar:
a. Cantidad de números positivos
b. Cantidad de números negativos.
c. Promedio de números.
d. De los positivos el máximo.

Aplicar las siguientes funciones:
a. int getInt(char[], char[], int, int) para el ingreso y validación de datos de tipo entero.
b. int esPositivo(int) retorna 1 en caso de que el número recibido como parámetro sea positivo, 0 en caso contrario.
c. float promediarNumeros(int,int): recibe el acumulador y el contador de números y retorna el promedio.
Crear estas funciones dentro de una biblioteca llamada Repaso2
*******************************************************************************/
#include <stdio.h>
#include "utn.h"

int main()
{
    char respuesta;
    float promedio;
    int ElNumeroEsPositivo;
    int numeroIngresado;
    int cantidadDePositivos;
    int cantidadDeNegativos;
    int contadorDeNumeros;
    int sumaDeNumeros;
    int maximoDeLosPositivos;

    cantidadDePositivos=0;
    cantidadDeNegativos=0;
    sumaDeNumeros=0;
    contadorDeNumeros=0;

    do{

       contadorDeNumeros++;
       numeroIngresado= getInt("Ingrese numero "," no esta entre el maximo y el minimo",-100,100);
       sumaDeNumeros=sumaDeNumeros+numeroIngresado;

       if(esPositivo(numeroIngresado))
       {
           cantidadDePositivos++;
            // d. De los positivos el máximo.
           if(maximoDeLosPositivos<numeroIngresado ||cantidadDePositivos==1)
           {
                maximoDeLosPositivos=numeroIngresado;
           }

       }else
       {
           if(numeroIngresado!=0)
           {
               cantidadDeNegativos++;
           }
       }

        printf("\ndesea continuar : ");
        fflush(stdin);
        scanf("%c",&respuesta);
    }while(respuesta=='s');

    promedio=promediarNumeros(sumaDeNumeros,contadorDeNumeros);


    return 0;
}


   /*test*/
    /*
    numeroIngresado=  getInt("ingrese un numero","reingrese por fa!!!",10,20);
    printf("\n el numero es : %d",numeroIngresado);

    promedio= promediarNumeros(50,3);
     printf("\n%f",promedio);
    respuesta='s';
    printf("\n%c",respuesta);

    ElNumeroEsPositivo=esPositivo(666);
    if(ElNumeroEsPositivo==1)
    {
        printf("\nsi es positivo");
    }else
    {
        printf("\nNO es positivo");
    }


    ElNumeroEsPositivo=esPositivo(0);
    if(ElNumeroEsPositivo==1)
    {
        printf("\nsi es positivo");
    }else
    {
        printf("\nNO es positivo");
    }

    ElNumeroEsPositivo=esPositivo(-555);
    if(ElNumeroEsPositivo==1)
    {
        printf("\nsi es positivo");
    }else
    {
        printf("\nNO es positivo");
    }*/
   /*fin test*/








