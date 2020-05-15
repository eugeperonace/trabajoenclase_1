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
    fflush(stdin);
    fgets(auxAlumno.nombre,20,stdin);
    printf("\n ingrese primeraNota:");
    scanf("%d",&auxAlumno.primeraNota);
    printf("\n ingrese segundaNota:");
    scanf("%d",&auxAlumno.segundaNota);
    auxAlumno.promedio=(float)(auxAlumno.primeraNota+auxAlumno.segundaNota)/2;
    return auxAlumno;
}
void MostrarAlumno(eAlumno parametroAlumno){

    printf("%8d %20s %8d %8d %8.2f\n", parametroAlumno.legajo, parametroAlumno.nombre, parametroAlumno.primeraNota,parametroAlumno.segundaNota, parametroAlumno.promedio);

}

void MostrarAlumnosPromocionados(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].primeraNota>=6 && listadoDeAlumnos[i].segundaNota>=6)
        {
            MostrarAlumno(listadoDeAlumnos[i]);
        }
    }

}

void MostrarAlumnosPorNombre(eAlumno listadoDeAlumnos[], int tam, char* nombre)
{
     int i;
    for(i=0; i<tam; i++)
    {
        if(strcmp(nombre, listadoDeAlumnos[i].nombre)==0)
        {
            MostrarAlumno(listadoDeAlumnos[i]);
        }
    }
}

void OrdenarListadoPorNombre(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int j;
    eAlumno auxiliarAlumno;

    for(i=0; i<tam - 1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)>0)
            {
                auxiliarAlumno = listadoDeAlumnos[i];
                listadoDeAlumnos[i] = listadoDeAlumnos[j];
                listadoDeAlumnos[j] =auxiliarAlumno;
            }
        }
    }
}










