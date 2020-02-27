#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palabras.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"

int main(void)
{
	int option = 0;

	LinkedList *listaPalabra;
	LinkedList *palabrasOrdenadas;

	listaPalabra = ll_newLinkedList();

	do
	{
		printf("/****************************************************\
	          	    	  \nMenu:\
	          	    	  \n1. Cargar Archivo\
	          	    	  \n2. \
	          	    	  \n\n3. \
	          	    	  \n4. \
						  \n5. \
	          	    	  \n6. Salir\
	          	    	  \n*****************************************************/");

		utn_getUnsignedInt("\nSeleccione opcion: ", "Opcion invalida", 1, sizeof(int), 1, 6, 1, &option);

		switch (option)
		{
		case 1:
			controller_loadFromText("examen.txt",listaPalabra);
			break;
		case 2:
			//ll_sort(listaPalabra,palabra_sortLetras,1);
			//controller_ListPalabra(listaPalabra);
			break;
		case 3:
			//ll_sort(listaPalabra,palabra_sortLetras,0);
			//controller_ListPalabra(listaPalabra);
			break;
		case 4:
			//ll_sort(listaPalabra,palabra_sortLongitudLetras,1);
			//controller_ListPalabra(listaPalabra);
			break;
		case 5:
			//palabrasOrdenadas = ll_map(listaPalabra, contadorLetrasDistintas);
			//ll_sort(palabrasOrdenadas, comparaPalabras, 1);
			//controller_ListPalabra(palabrasOrdenadas);
			break;
		case 6:
			break;
		default:
			printf("Opcion invalida");
		}
	} while (option != 6);

	return 0;
}
