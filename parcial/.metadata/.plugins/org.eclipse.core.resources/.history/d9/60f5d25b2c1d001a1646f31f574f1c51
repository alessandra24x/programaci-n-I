#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "perro.h"
#include "Parser.h"
#include "utn.h"


int main()
{
	int option = 0;

    LinkedList* listaPerros;
    LinkedList* listaPerrosFiltrados;
    LinkedList* listaPerrosMachosFiltrados;
    LinkedList* listaPerrosCallejerosFiltrados;

    listaPerros = ll_newLinkedList();

    do{
    	printf("/****************************************************\
        	    	  \nMenu:\
        	    	  \n1. Cargar Archivo\
        	    	  \n2. Imprimir lista\
        	    	  \n\n3. Filtrar Menores de 45 Dias\
        	    	  \n4. Filtrar Machos\
        	    	  \n5. Generar Listado de ´Callejeros´\
        	    	  \n6. Salir\
        	    	  \n*****************************************************/");

    	utn_getUnsignedInt("\nSeleccione opcion: ","Opcion invalida",1,sizeof(int),1,11,1,&option);

    	switch(option) {
    			case 1:
                    controller_loadFromText("cachorros.csv",listaPerros);
                    //controller_lastIdPerro(listaPerros);
                    break;
                case 2:
                	controller_ListPerros(listaPerros);
                    break;
                case 3:
                	listaPerrosFiltrados = ll_filter(listaPerros,filtrarMenores45Dias);
                    printf("Calculando\n");

                    if(listaPerrosFiltrados != NULL) {
						if(controller_saveAsText("cachorrosFiltrados2.csv",listaPerrosFiltrados) == 0) {
							printf("\nArchivo generado correctamente\n");
						} else {
							printf("Error generando archivo\n");
						}
                    }
                	break;
                case 4:
                	listaPerrosMachosFiltrados = ll_filter(listaPerros,filtrarMachos);
                	if(controller_saveAsText("cachorrosMachosFiltrados.csv",listaPerrosMachosFiltrados) == 0) {
                		printf("\nArchivo generado correctamente\n");
                	} else {
                		printf("Error generando archivo\n");
                	}
                	break;
                case 5:
                	listaPerrosCallejerosFiltrados = ll_filter(listaPerros,filtrarRazas);
                	controller_ListPerros(listaPerrosCallejerosFiltrados);
                	break;
                case 6:
                    break;
                default:
                	printf("Opcion invalida");
            }
        }while(option != 6);

        return 0;
}
