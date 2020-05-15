/*
 ============================================================================
 Name        : proyecto3.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//Pedir 5 numeros y dar como resultado maximo y minimo

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
	setbuf(stdout,NULL);

    int maximo;
    int minimo;
    int i;
    int bufferInt;
    int flag = TRUE;

    for(i=0;i<5;i++)                                 // 1) FOR
    {
        printf("Ingrese un numero: %d \n",i+1);
        scanf("%d", &bufferInt);

        if(flag == TRUE)                             // 2) IF(flag==TRUE) PARA DECIR QUE EL PRIMERO
        {                                            //                      INGRESADO ES MAX Y MIN
            maximo = bufferInt;
            minimo = bufferInt;
            flag = FALSE;
        }
        else                                         //3) ELSE PARA SABER CUAL ES MAX Y MIN
        {
            if(bufferInt > maximo)
            {
                maximo = bufferInt;
            }
            if(bufferInt < minimo)
            {
                minimo = bufferInt;
            }
        }
    } // CIERRE DEL FOR

    printf("\nEl valor minimo es: %d y el valor maximo es: %d",minimo,maximo);

    return 0;
}


