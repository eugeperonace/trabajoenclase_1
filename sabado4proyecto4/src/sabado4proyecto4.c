/*
 ============================================================================
 Name        : sabado4proyecto4.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //tiene funciones que permiten manipular las cadenas de caracteres

int main(void)
{
	setbuf(stdout,NULL);
	char cadena1[15] = "hola";  //cadena1="hola; "//no está preparado para hacer la comparacion de una variable y un literal
	char cadena2[15];

	printf("Ingrese un numero: \n");
	fflush(stdin);
	//scanf("%s", cadena1);// si pongo "el perro" solo muestra "el", no me sirve para guardar en la cadena espacios, los interpreta como un \0
	//gets(cadena1):
	fgets(cadena1,15,stdin); //lee hasta el \n

	//int strlen(char*)

	//len = strlen(cadena1);

	//cadena1[len-1] = '\0';

	//len = strlen(cadena1);

	//printf("El largo: %d\n", len);

	//puts(cadena1);


	//char* strcpy(char*, const char*);  //un puntero char y una constante char. Una constante char es un literal "hola mundo"
	strcpy(cadena2, "hola mundo")

	//puts(cadena2);

	//int strcmp//devuelve un entero y recibe como parametro 2 constantes a puntero a char


	int main(void)
	{
		setbuf(stdout,NULL);
		char cadena1[15] = "casamiento";  //cadena1="hola; "//no está preparado para hacer la comparacion de una variable y un literal
		char cadena2[15] = "casados"
		int len;
		int comp;

		int strcmp(const char*, const char*); //ES SENSIBLE A LAS MAYUSUCLAS Y MINUSCULAS
		comp = strcmp(cadena1,cadena2); // si devuelve 0, significa que las dos cadenas son iguales. Si me devuelve cualquier otra cosa significa que son distintos. Compara letra con letra, resta codigo ascii con codigo ascii.

		comp = strcasecmp(cadena1,cadena2); //NO ES SENSIBLE A MAYUSCULAS Y MINS
		strupr(palabra2); //CONVIERTE A MAYUSCULA
		strlwr(palabra2); //CONVIERTE A MINUSCULA

		strcmp("hola","hola"); //devuelve 0

		if(strcmp(cadena1,"hola")==0)
		{

		}

		puts(cadena2);

	return 0;
}
