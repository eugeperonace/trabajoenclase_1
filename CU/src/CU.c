/*
 ============================================================================
 Name        : CU.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);

	char pResultado;

	utn_getCuit(&pResultado,"mensaje","mensajeError",0,0,5);
	return EXIT_SUCCESS;
}
