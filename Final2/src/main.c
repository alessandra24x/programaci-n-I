#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "libro.h"
#include "utn.h"

int main(void) {
	int option = 0;

	LinkedList *listaLibro;
	LinkedList *listaLibrosConDescuentos;

	listaLibro = ll_newLinkedList();

	do {
		printf(
				"/****************************************************\
	          	    	  \nMenu:\
	          	    	  \n1. Cargar Archivo\
	          	    	  \n2. Ordenar Lista\
	          	    	  \n3. Imprimir\
	          	    	  \n4. Calcular Descuentos\
						  \n5. Generar Archivo con descuentos\
	          	    	  \n6. Salir\
	          	    	  \n*****************************************************/");

		utn_getUnsignedInt("\nSeleccione opcion: ", "Opcion invalida", 1,
				sizeof(int), 1, 6, 1, &option);

		switch (option) {
		case 1:
			controller_loadFromText(listaLibro);
			break;
		case 2:
			ll_sort(listaLibro, libro_sortAutor, 1);
			break;
		case 3:
			controller_ListLibro(listaLibro);
			break;
		case 4:
			listaLibrosConDescuentos = ll_map(listaLibro, calcularDescuentos);
			controller_ListLibro(listaLibrosConDescuentos);
			break;
		case 5:
			if (controller_saveAsText("mapeado.csv", listaLibrosConDescuentos)== 0) {
				printf("\nArchivo generado correctamente\n");
			} else {
				printf("Error generando archivo\n");
			}
			break;
		case 6:
			break;
		default:
			printf("Opcion invalida");
		}
	} while (option != 6);

	return 0;
}
