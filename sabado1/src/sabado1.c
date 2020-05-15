/*
 ============================================================================
 Name        : sabado1.c
 Author      : Eugenia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>

int main()
{
    int edad;
    float altura;
    char sexo;
    char nombre[20];
    char apellido[20];
    int contador;
    int contadorAdolescentes;
    int acumuladorEdadMayores;
    int contadorDeMujeres;
    int acumalorEdadesDeMujeres;
    float promedioEdadDeMujeres;
    int contadorDeHombre;
    int acumalorEdadesDeHombre;
    float promedioEdadDeHombre;
    float promedioDeEdadGeneral;
    int acumuladorDeEdadGeneral;
    int edadMayor;
    int edadMenor;

    contadorAdolescentes=0;
    acumuladorEdadMayores=0;
    contadorDeMujeres=0;
    acumalorEdadesDeMujeres=0;
    contadorDeHombre=0;
    acumalorEdadesDeHombre=0;
    acumuladorDeEdadGeneral=0;

    //edad=-2;
    for(contador=0;contador<5;contador++)
    {
        do{
            printf("ingrese edad: ");
            scanf("%d",&edad);
        }while(edad<0 || edad >100);

        fflush(stdin);//para windows
        __fpurge(stdin);//para linux
        do{
            printf("ingrese sexo: ");
            scanf("%c",&sexo);
        }while(sexo!='f' && sexo!='m');

         do{
            printf("ingrese altura: ");
            scanf("%f",&altura);
        }while(altura<100|| altura >250);

        /*
        if(contador==0)
        {
            edadMenor=edad;
            edadMayor=edad;
        }else
        {
            if(edadMayor<edad)
            {
                edadMayor=edad;
            }

            if(edadMenor>edad)
            {
                edadMenor=edad;
            }

        }
        */
        if(contador==0 || edadMayor<edad  )/*NO es lo mismo */
        {
            edadMayor=edad;
        }


        if(edadMenor<edad || contador==0)
        {
            edadMenorr=edad;
        }

        acumuladorDeEdadGeneral=acumuladorDeEdadGeneral+edad;

        if(edad>12 && edad <18)// contar adolescentes
        {
            contadorAdolescentes++;
        }

        if(edad >17)//acumulador de edades de los mayores
        {
            acumuladorEdadMayores=acumuladorEdadMayores+edad;
        }

        if(sexo=='f')
        {
            contadorDeMujeres++;
            acumalorEdadesDeMujeres=acumalorEdadesDeMujeres+edad;
        }

        if(sexo=='m')
        {
            contadorDeHombre++;
            acumalorEdadesDeHombre=acumalorEdadesDeHombre+edad;
        }








        printf("\nsu edad es: %d",edad);
        printf("\nsu altura es: %f",altura);
        printf("\nsu sexo es: %c",sexo);
    }// fin del for






    promedioDeEdadGeneral=acumuladorDeEdadGeneral/contador;
    if(contadorDeHombre>0)
    {
        promedioEdadDeHombre=acumalorEdadesDeHombre/contadorDeHombre;
    }

    if(contadorDeMujeres>0)
    {
        promedioEdadDeMujeres=acumalorEdadesDeMujeres/contadorDeMujeres;
    }


    if(promedioEdadDeMujeres==promedioEdadDeHombre)
    {
          printf("son iguales los promedios");
    }else
    {
        if(promedioEdadDeMujeres>promedioEdadDeHombre)
        {
            printf("las mujeres tiene mayor promedio de edad");
        }else
        {
            printf("los hombres tiene mayor promedio de edad");
        }
    }




    return 0;
}
