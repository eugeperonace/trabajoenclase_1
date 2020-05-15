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

#endif /* ALUMNO_H_ */
