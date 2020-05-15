/*
 * alumno.c
 *
 *  Created on: 25 abr. 2020
 *      Author: Santiago
 */

#include "alumno.h"
//#include <stdio_ext.h> //LINUX
#include <stdio.h>

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

    printf("\nsu legajo es: %d",parametroAlumno.legajo);
    printf("\nsu nombre es: %s",parametroAlumno.nombre);
    printf("\nsu primeraNota es: %d",parametroAlumno.primeraNota);
    printf("\nsu segundaNota es: %d",parametroAlumno.segundaNota);
    printf("\nsu promedio es: %f",parametroAlumno.promedio);

}












