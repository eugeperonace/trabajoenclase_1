/*
 ============================================================================
 Name        : sabado5proyecto1b.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "alumno.h"
#include <stdio.h>


int main()
{
	setbuf(stdout,NULL);
    printf("\n\tRepaso estructuras\n");

    //int nota;
    //int=3
    //eAlumno=3;

    eAlumno algunAlumno;
    eAlumno otroAlumno;

    algunAlumno=CargarUnAlumno();


    MostrarAlumno(algunAlumno);
    MostrarAlumno(otroAlumno);


    otroAlumno=algunAlumno;


      printf("\n algunAlumno");
    MostrarAlumno(algunAlumno);
     printf("\n otroAlumno");
    MostrarAlumno(otroAlumno);

    return 0;
}
