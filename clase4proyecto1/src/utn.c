/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: Santiago
 */

#include <stdio.h>
#include <stdlib.h>

int dividir (int operador1, int operador2, float* pResultado)
{
	float resultado;
	int retorno = -1;
	if (pResultado != NULL && operador2 != 0)         // pResultado :esa direccion de memoria está apuntando a alfun lado? es una direccion de memoria?
	{
		resultado = (float) operador1 / operador2;   //*pResultado : *EVALÚO LO QUE TIENE RESULTADO. como ahora sí sé que es una direccion de memoria, quiero saber qué resultado tiene guardado. Poniendo * escribe en la dirección de memoria.
		*pResultado = resultado;
		retorno = 0;
	}
		return retorno;
}
