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

Ingresar n�meros hasta que el usuario lo decida. Los n�meros tienen que estar
comprendidos entre -100 y 100. Determinar:
a. Cantidad de n�meros positivos
b. Cantidad de n�meros negativos.
c. Promedio de n�meros.
d. De los positivos el m�ximo.

Aplicar las siguientes funciones:
a. int getInt(char[], char[], int, int) para el ingreso y validaci�n de datos de tipo entero.
b. int esPositivo(int) retorna 1 en caso de que el n�mero recibido como par�metro sea positivo, 0 en caso contrario.
c. float promediarNumeros(int,int): recibe el acumulador y el contador de n�meros y retorna el promedio.
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
            // d. De los positivos el m�ximo.
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








