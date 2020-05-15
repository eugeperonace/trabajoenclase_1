/*
 * alumno.h
 *
 *  Created on: 25 abr. 2020
 *      Author: Santiago
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

typedef struct{
    int legajo;
    char nombre[20];
    int primeraNota;
    int segundaNota;
    float promedio;
}eAlumno;


void MostrarAlumno(eAlumno parametroAlumno);
eAlumno CargarUnAlumno();
void MostrarListadoAlumnos(eAlumno [],int);
void CargarListadoAlumnos(eAlumno [],int);
void MostrarAlumnosPromocionados(eAlumno[], int);
void MostrarAlumnosPorNombre(eAlumno[], int, char*);


#endif /* ALUMNO_H_ */
