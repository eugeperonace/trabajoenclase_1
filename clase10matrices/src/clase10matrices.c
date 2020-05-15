/*
 ============================================================================
 Name        : clase10matrices.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#define FIL 10
#define COL 15

//DECLARACION DE UNA MATRIZ

int main(void)
{
	setbuf(stdout,NULL);

	float matriz[2][3];
	int i,j;

	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("M[%d][%d]: ",i,j);
			scanf("%f",&matriz[i][j]);
		}
	}

	return 0;
}
