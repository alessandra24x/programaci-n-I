#include <stdio.h>
#include <stdlib.h>

#include "computer.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "utn.h"


int main()
{
	int option = 0;

    LinkedList* listaComputers;
    LinkedList* listaComputadorasFiltradas;

    listaComputers = ll_newLinkedList();

    do{
    	printf("/****************************************************\
        	    	  \nMenu:\
        	    	  \n1. Cargar Archivo\
        	    	  \n2. Ordenar lista\
        	    	  \n\n3. Imprimir Lista\
        	    	  \n4. Filtrar Desktops\
        	    	  \n5. Salir\
        	    	  \n*****************************************************/");

    	utn_getUnsignedInt("\nSeleccione opcion: ","Opcion invalida",1,sizeof(int),1,5,1,&option);

    	switch(option) {
    			case 1:
                    controller_loadFromText(listaComputers);
                    break;
                case 2:
                	controller_sortComputers(listaComputers);
                    break;
                case 3:
                	controller_mapComputers(listaComputers);
                	controller_ListComputers(listaComputers);

                	break;
                case 4:
                	listaComputadorasFiltradas = ll_filter(listaComputers,filtrar);
                	printf("Calculando\n");

                	if(listaComputadorasFiltradas != NULL) {
                		if(controller_saveAsText("filtrados.csv",listaComputadorasFiltradas) == 0) {
                			printf("\nArchivo generado correctamente\n");
                		} else {
                			printf("Error generando archivo\n");
                		}
                	}
                	break;

                case 5:
                    break;
                default:
                	printf("Opcion invalida");
            }
        }while(option != 5);

        return 0;
}
