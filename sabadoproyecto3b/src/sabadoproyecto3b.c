/*
 ============================================================================
 Name        : sabadoproyecto3b.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "alumno.h"
#include <stdio.h>
#define CANT_ELEMENTOS 5

int main()
{
    printf("\n\tRepaso estructuras\n");


    eAlumno listadoAlumnos[CANT_ELEMENTOS]={{100,"Maria",7,7,7},
                                            {101,"Juan",5,4,4.5},
                                            {102,"Pedro",7,6,6.5},
                                            {103,"Ana",8,8,8},
                                            {104,"Juan",3,4,3.5}};

    printf("LISTADO DE ALUMNOS\n");
    MostrarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
    printf("LISTADO DE ALUMNOS PROMOCIONADOS\n");
    MostrarAlumnosPromocionados(listadoAlumnos, CANT_ELEMENTOS);
    //CargarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
    //MostrarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
   printf("LISTADO DE ALUMNOS QUE SE LLAMAN JUAN\n");
   MostrarAlumnosPorNombre(listadoAlumnos, CANT_ELEMENTOS, "Juan");

     printf("LISTADO DE ALUMNOS ORDENADOS POR NOMBRE\n");
    OrdenarListadoPorNombre(listadoAlumnos, CANT_ELEMENTOS);
    MostrarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);


    return 0;
}







