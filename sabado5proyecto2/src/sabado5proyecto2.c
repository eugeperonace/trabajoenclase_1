/*
 ============================================================================
 Name        : sabado5proyecto2.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//ARRAY - ESTRUCTURA

#include "alumno.h"
#include <stdio.h>
#define CANT_ELEMENTOS 3

int main()
{
    printf("\n\tRepaso estructuras");
    int edades[CANT_ELEMENTOS];
    eAlumno listadoAlumnos[CANT_ELEMENTOS];

    MostrarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
    CargarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
    MostrarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
    return 0;
}






