#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "utn.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en una LinkedList de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca LinkedList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

//int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);

int main() {
	int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	printf("/****************************************************\
        	    	  \nMenu:\
        	    	  \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\
        	    	  \n\n2. Alta de empleado\
        	    	  \n3. Modificar datos de empleado\
        	    	  \n4. Baja de empleado\
        	    	  \n5. Listar empleados\
        	    	  \n6. Ordenar empleados\
        	    	  \n\n7. Guardar los datos de los empleados en el archivo data.csv (modo texto).\
        	    	  \n\n9. Salir\
        	    	  \n*****************************************************/");

        	utn_getUnsignedInt("\nSeleccione opcion: ","Opcion invalida",1,sizeof(int),1,10,1,&option);
            switch(option) {
                case 1:
                    controller_loadFromText("data.csv",listaEmpleados);
                    controller_lastIdEmployee(listaEmpleados);
                    break;
                case 2:
                	controller_addEmployee(listaEmpleados);
                	break;
                case 3:
                	controller_editEmployee(listaEmpleados);
                	break;
                case 4:
                	controller_removeEmployee(listaEmpleados);
                    break;
                case 5:
                	controller_ListEmployee(listaEmpleados);
                    break;
                case 6:
                    controller_sortEmployee(listaEmpleados);
                	break;
                case 7:
                    controller_saveAsText("data.csv", listaEmpleados);
                	break;
                default:
                	printf("Ingrese una opcion valida");
            }
        }while(option != 10);
        return 0;

    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados("data.csv",listaEmpleados) == 0) {
        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");
        //al_map(listaEmpleados,em_calcularSueldo(listaEmpleados));

        // Generar archivo de salida
        /*if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");

        al_filter(listaEmpleados,em_filtrarporalguncriterio); //por ej salarios mayores a x cantidad
    }
    else
        printf("Error leyendo empleados\n");*/


    return 0;
}
}

//int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados) {
  //  return 1;
//}
