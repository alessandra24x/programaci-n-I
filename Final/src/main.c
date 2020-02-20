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

	listaPalabra = ll_newLinkedList();

	do
	{
		printf("/****************************************************\
	          	    	  \nMenu:\
	          	    	  \n1. Cargar Archivo\
	          	    	  \n2. Imprimir Vendedores\
	          	    	  \n\n3. Calcular Comisiones\
	          	    	  \n4. Generar archivo de comisiones para nivel\
	          	    	  \n5. Salir\
	          	    	  \n*****************************************************/");

		utn_getUnsignedInt("\nSeleccione opcion: ", "Opcion invalida", 1, sizeof(int), 1, 5, 1, &option);

		switch (option)
		{
		case 1:
			controller_loadFromText("examen.txt",listaPalabra);
			break;
		case 2:
			controller_ListPalabra(listaPalabra);
			break;
		case 3:
			/*ll_map(listaPalabra, calcularComisiones);
			printf("Comisiones generadas correctamente, ¿desea ver la lista? S/N\n");
			gets(answer);
			if (strcpy(answer, "S"))
			{
				controller_ListPalabra(listaPalabra);
			}*/
			break;
		case 4:
			break;
		default:
			printf("Opcion invalida");
		}
	} while (option != 4);

	return 0;
}
