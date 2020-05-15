/*
 ============================================================================
 Name        : clase10matrices2.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

#define FIL 20
#define COL 25

int main(void)
{
	setbuf(stdout,NULL);
	int i,j,x,lmax=0,imax;
	char mat[FIL][COL],aux[COL];

	for(i=0;i<FIL;i++)
	{
		printf("Ingrese nombre: ");
		gets(mat[i]);
	}

	// Ordeno alfabeticamente la matriz
	for(i=0;i<FIL-1;i++)
	{
		for(j=i+1;j<FIL;j++)
		{
			if((strcmp(mat[i],mat[j]))>0)
			{
				strcpy(aux,mat[i]);
				strcpy(mat[i],mat[j]);
				strcpy(mat[j],aux);
			}
		}
	}
	// Busqueda del nombre mas largo
	for(i=0;i<FIL;i++)
	{
		x=strlen(mat[i]);
		if(x>lmax)
		{
			lmax=x;
			imax=i;
		}
	} printf("El nombre mas largo es %s",mat[imax]);

	return 0;
}
