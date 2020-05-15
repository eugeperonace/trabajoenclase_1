/*
 ============================================================================
 Name        : proyecto4.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// Pedir numeros hasta que el us quiera, si pone 888 se termina y dar como resultado maximo y minimo

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
	setbuf(stdout, NULL);

    int maximo;
    int minimo;

    int bufferInt;
    int flag = TRUE;

    do
    {
        printf("INGRESE NUMERO: (\"888\" FINALIZA EL INGRESO): \n");
        scanf("%d", &bufferInt);

        if(flag == TRUE)
        {
            maximo = bufferInt;
            minimo = bufferInt;
            flag = FALSE;
        }
        else
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
    }
    while(bufferInt != 888);

    printf("\nEl valor minimo es: %d y el valor maximo es: %d",minimo,maximo);

    return 0;
}




