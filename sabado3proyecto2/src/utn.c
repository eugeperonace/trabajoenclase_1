/*
 * utn.c
 *
 *  Created on: 14 abr. 2020
 *      Author: Santiago
 */


int getInt(char mensaje[], char mensajeError[], int minimo, int maximo)
{
    int valorDeRetorno;
    int flagError;
    flagError=0;
    do{

        if(flagError==0)
        {
             printf("%s",mensaje);
             flagError=1;
        }else
        {
             printf("%s",mensajeError);
        }
        scanf("%d",&valorDeRetorno);
    }while(valorDeRetorno<minimo || valorDeRetorno>maximo);
    return valorDeRetorno;

}

int esPositivo(int numeroPorParametro)
{
    return numeroPorParametro>0;
}

float promediarNumeros(int acumulador,int contador)
{
    return (float)acumulador/contador;
}




