/*
 ============================================================================
 Name        : sabado2proyecto1.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//CADENAS

#include <stdio.h>
#include <stdlib.h>
/*
int %d
float %f
char %c
--------------
cadena $s
*/
int main()
{
    char letra;
    float numero;
    char palabra[20];



    printf("\nIngrese numero :");
    scanf("%f",&numero);

    printf("\nIngrese letra :");
    fflush(stdin);//solo para windows
    //__fpurge(stdin);//solo para linux
    scanf("%c",&letra);

    printf("\nIngrese palabra :");
    fflush(stdin);//solo para windows
    //__fpurge(stdin);//solo para linux
    scanf("%s",palabra);

    system("clear");
    printf("\nel numero es %.2f",numero);
    printf("\nla letra  es %c",letra);
    printf("\nla palabra es %s",palabra);



    /*
    //02 limpeza del buffer
    char letra;
    float numero;

    printf("\nIngrese numero :");
    scanf("%f",&numero);

    printf("\nIngrese letra :");
    //fflush(stdin);//solo para windows
    __fpurge(stdin);//solo para linux
    scanf("%c",&letra);

    */

    /*

    //01 ejemplo de ampersand
    float numero;
    printf("\nIngrese numero :");
    //scanf("%f",numero);// error falta el ampersand &
    scanf("%f",&numero);
    //printf("\nel numero es %.2f",&numero);// error sobra el ampersand &
    printf("\nel numero es %.2f",numero);

    */






    return 0;
}

