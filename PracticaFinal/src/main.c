#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vendedor.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"

int main(void)
{
	int option = 0;
	int optionNivel = -1;
	char answer[32];

	LinkedList *listaVendedores;
	LinkedList *listaJuniors;
	LinkedList *listaStandards;
	LinkedList *listaExpertos;

	listaVendedores = ll_newLinkedList();

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

		utn_getUnsignedInt("\nSeleccione opcion: ", "Opcion invalida", 1, sizeof(int), 1, 6, 1, &option);

		switch (option)
		{
		case 1:
			controller_loadFromText(listaVendedores);
			//ll_map(listaBikes,bike_calcularVelocidadP);
			break;
		case 2:
			controller_ListVendedores(listaVendedores);
			break;
		case 3:
			ll_map(listaVendedores, calcularComisiones);
			printf("Comisiones generadas correctamente, ¿desea ver la lista?\n S/N\n");
			scanf("%s",answer);
			if (strcpy(answer, "S"))
			{
				controller_ListVendedores(listaVendedores);
			}
			break;
		case 4:
			do
			{

				printf("/****************************************************\
	          	    	  \nSeleccione el nivel por el cual desea filtrar:\
	          	    	  \n0 -> Junior\
	          	    	  \n1 -> Standard\
	          	    	  \n2 -> Experto\
						  \n3 -> Salir\
	          	    	  \n*****************************************************/");
				utn_getUnsignedInt("\nSeleccione opcion: ", "Opcion invalida", 1, sizeof(int), 1, 3, 1, &optionNivel);
				switch (optionNivel)
				{
				case 0:
					listaJuniors = ll_filter(listaVendedores, filtrarJuniors);
					if (controller_saveAsText("juniors.csv", listaJuniors) == 0)
					{
						printf("\nArchivo generado correctamente\n");
					}
					else
					{
						printf("Error generando archivo\n");
					}
					break;
				case 1:
					listaStandards = ll_filter(listaVendedores, filtrarStandards);
					if (controller_saveAsText("standards.csv", listaStandards) == 0)
					{
						printf("\nArchivo generado correctamente\n");
					}
					else
					{
						printf("Error generando archivo\n");
					}
					break;
				case 2:
					listaExpertos = ll_filter(listaVendedores, filtrarExpertos);
					if (controller_saveAsText("expertos.csv", listaExpertos) == 0)
					{
						printf("\nArchivo generado correctamente\n");
					}
					else
					{
						printf("Error generando archivo\n");
					}
					break;
				default:
					printf("Opción invalida");
				}
			} while (optionNivel != 3);
			break;
		case 5:
			break;
		default:
			printf("Opcion invalida");
		}
	} while (option != 5);

	return 0;
}
