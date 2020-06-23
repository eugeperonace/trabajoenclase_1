#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaClonada;
    LinkedList* listaFiltrada;
    LinkedList* subLista;
    int from;
    int to;
    int contadorEmp;


    do{
    	utn_getNumero(&option,
    			"\nElija una opción:\n"
    			"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    			"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
    			"3. Alta de empleado.\n"
    			"4. Modificar datos de empleado.\n"
    			"5. Baja de empleado.\n"
    			"6. Listar empleados.\n"
    			"7. Ordenar empleados.\n"
    			"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    			"9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    			"10. Ordenar empleados.\n"
    			"11. Ordenar empleados.\n"
    			"12. Ordenar empleados.\n"
    			"13. Ordenar empleados.\n"
    			"14. Crear una sublista de empleados.\n"
    			"15. Clonar lista de empleados.\n"
    			"16. Listar empleados con sueldo superior a $50.000,00.\n"
    			"17. Cantidad de empleados con sueldo superior a $50.000,00.\n"
    			"18. Salir.\n","Error\n",1,18,2);

        switch(option)
        {
            case 1:
            	controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	controller_loadFromBinary("dataBin.csv",listaEmpleados);
               break;
            case 3:
            	controller_addEmployee(listaEmpleados);
                break;
            case 4:
            	controller_editEmployee(listaEmpleados);
                break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
                break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
                break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
                break;
            case 8:
            	controller_saveAsText("data.csv",listaEmpleados);
            	break;
            case 9:
            	controller_saveAsBinary("dataBin.csv",listaEmpleados);
                break;
            case 10:

                break;
            case 11:

                break;
            case 12:

                break;
            case 13:

                break;
            case 14:
            	if( !utn_getNumero(&from,"¿Desde qué índice desea que comience la sublist?","Index inválido.\n",0,ll_len(listaEmpleados),2) &&
            	    !utn_getNumero(&to,"¿Hasta qué índice desea que abarque la sublist?","Index inválido.\n",0,ll_len(listaEmpleados),2));

            	if( ll_subList(listaEmpleados,from,to) != NULL)
            	{
            		subLista = ll_subList(listaEmpleados,from,to);
            		printf("\n---SUBLISTA DE EMPLEADOS DESDE INDEX %d hasta el INDEX %d---\n",from,to);
            		ll_map(subLista,employee_imprimirEmp);
            	}

            	break;
            case 15:
            	listaClonada = ll_clone(listaEmpleados);
            	if(listaClonada != NULL)
            	{
            		printf("La lista ha sido clonada exitosamente.\n\n");
            		ll_map(listaClonada,employee_imprimirEmp);
            	}
                break;

            case 16:
            	listaFiltrada = ll_filter(listaEmpleados,calcularEmpleadosSueldoMayorA50000);
            	if(listaFiltrada != NULL)
            	{
            		printf("---LISTA DE EMPLEADOS CON SUELDO SUPERIOR A $50.000,00---\n\n");
            		ll_map(listaFiltrada,employee_imprimirEmp);
            	}
                 break;

            case 17:
            	contadorEmp = ll_count(listaEmpleados,calcularEmpleadosSueldoMayorA50000);
            	printf("La lista cuenta con %d empleados quienes tienen sueldo igual o superior a $45.000,00.\n", contadorEmp);
            	break;
        }
    }while(option != 18);
    return 0;
}

