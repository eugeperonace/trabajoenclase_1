/*
 * alumno.c
 *
 *  Created on: 25 abr. 2020
 *      Author: Santiago
 */

#include "alumno.h"
//#include <stdio_ext.h>
#include <stdio.h>


void MostrarListadoAlumnos(eAlumno arrayAlumnos[],int cantidad){

    int i;
    for(i=0;i<cantidad;i++)
    {
        MostrarAlumno(arrayAlumnos[i]);
    }

}


void CargarListadoAlumnos(eAlumno arrayAlumnos[],int cantidad){

      int i;
    for(i=0;i<cantidad;i++)
    {
       arrayAlumnos[i]=CargarUnAlumno();
    }
}


eAlumno CargarUnAlumno(){

    eAlumno auxAlumno;

    printf("\n ingrese legajo:");
    scanf("%d",&auxAlumno.legajo);
    printf("\n ingrese Nombre:");
    setbuf(stdout,NULL);
    fgets(auxAlumno.nombre,20,stdin);
    printf("\n ingrese primeraNota:");
    scanf("%d",&auxAlumno.primeraNota);
    printf("\n ingrese segundaNota:");
    scanf("%d",&auxAlumno.segundaNota);
    auxAlumno.promedio=(float)(auxAlumno.primeraNota+auxAlumno.segundaNota)/2;
    return auxAlumno;
}
void MostrarAlumno(eAlumno parametroAlumno){

    printf("\nsu legajo es: %d",parametroAlumno.legajo);
    printf("\nsu nombre es: %s",parametroAlumno.nombre);
    printf("\nsu primeraNota es: %d",parametroAlumno.primeraNota);
    printf("\nsu segundaNota es: %d",parametroAlumno.segundaNota);
    printf("\nsu promedio es: %f",parametroAlumno.promedio);

}












