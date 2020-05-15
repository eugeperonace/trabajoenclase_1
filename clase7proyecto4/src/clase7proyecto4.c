/*
 ============================================================================
 Name        : clase7proyecto4.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * Ejercicio 4:
 * Completar la funcion getFloat() para que devuelva un numero float ingresado por el usuario
 */
#include <stdio.h>
#include <stdlib.h>

static int validarFloat(char* buff);


static int getFloat(float* pResultado)
{
	char buffer[128];

	fgets();


	if(validarFloat(buffer)==1)
	{

	}

}



int main(void) {

	float precio;
	printf("Ingrese un precio:");
	if(getFloat(&precio)==1)
	{
		printf("El precio es valido:%f",precio);
	}
	else
	{
		printf("Valor incorrecto");
	}

	return EXIT_SUCCESS;
}

static int validarFloat(char* buff)
{
	int ret=-1;
	int i=0;
	int contadorPuntos=0;
	while(buff[i]!='\0')
	{
		if(buff[i]<'0' || buff[i]>'9')
		{
			if(buff[i]!='.')
			{
				break;
			}
			else
			{
				contadorPuntos++;
				if(contadorPuntos>1)
					break;
			}
		}
		i++;
	}
	if(buff[i]=='\0')
		ret=1;
	return ret;
}


