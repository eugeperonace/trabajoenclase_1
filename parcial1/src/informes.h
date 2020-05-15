/*
 * informes.h
 *
 *  Created on: 10 may. 2020
 *      Author: Eugenia
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int info_imprimirInfoClientesPorIdPublicacion(Cliente* arrayClientes,int lenCli, Publicacion* arrayPublicaciones,int lenPub, int auxiliarIdPub);
int info_imprimirClientesConPublicacionesActivas(Cliente* arrayClientes, int lenCli, Publicacion* arrayPublicaciones, int lenPub);
int info_imprimirPublicacionesConCuit(Publicacion* arrayPublicaciones,int lenPub, Cliente* arrayClientes,int lenCli);
int info_imprimirClientesConMasPublicActivas(Cliente* arrayClientes,int lenCli,Publicacion* arrayPublicaciones,int lenPub);
int info_imprimirClientesConMasPublicPausadas(Cliente* arrayClientes,int lenCli,Publicacion* arrayPublicaciones,int lenPub);
int info_imprimirClientesConMasPublicaciones(Cliente* arrayClientes,int lenCli,Publicacion* arrayPublicaciones,int lenPub);

#endif /* INFORMES_H_ */
