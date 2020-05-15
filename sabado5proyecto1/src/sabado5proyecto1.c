/*
 ============================================================================
 Name        : sabado5proyecto1.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int legajo;
    char nombre[20];
    int primeraNota;
    int segundaNota;
    float promedio;

}eAlumno;

void MostrarAlumno (eAlumno parametroAlumno)


int main()
{
    printf("\n\tRepaso estructuras");

    int nota;
    //int=3
    //eAlumno=3;

    eAlumno algunAlumno;
    eAlumno otroAlumno;
    algunAlumno.legajo=3;

    printf("\nsu legajo es: %d",algunAlumno.legajo);
    printf("\n ingrese legajo");
    scanf("%d",&algunAlumno.legajo);
    /*
     scanf("%d",&algunAlumno.legajo);
      scanf("%d",&algunAlumno.legajo);
      scanf("%d",&algunAlumno.legajo);
   */

    printf("\nsu legajo es: %d",algunAlumno.legajo);
    printf("\nsu nombre es: %s",algunAlumno.nombre);
    printf("\nsu primeraNota es: %d",algunAlumno.primeraNota);
    printf("\nsu segundaNota es: %d",algunAlumno.segundaNota);
    printf("\nsu promedio es: %f",algunAlumno.promedio);

    printf("\nsu legajo es: %d",otroAlumno.legajo);
    printf("\nsu nombre es: %s",otroAlumno.nombre);
    printf("\nsu primeraNota es: %d",otroAlumno.primeraNota);
    printf("\nsu segundaNota es: %d",otroAlumno.segundaNota);
    printf("\nsu promedio es: %f",otroAlumno.promedio);

    return 0;
}

