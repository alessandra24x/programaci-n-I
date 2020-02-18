#include <stdio.h>
#include <stdlib.h>
#include "logs.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"
#include "Parser.h"

int main(void) {
	int option = 0;

	LinkedList* listaLog;
	LinkedList* listaGravedad;
	listaLog = ll_newLinkedList();
	do {
		  printf("/****************************************************\
		          	    	  \nMenu:\
		          	    	  \n1. Cargar Archivo\
		          	    	  \n2. Procesar Información\
		          	    	  \n\n3. Filtrar\
		          	    	  \n4. Ordenar\
		          	    	  \n5. Salir\
		          	    	  \n*****************************************************/");

		  utn_getUnsignedInt("\nSeleccione opcion: ","Opcion invalida",1,sizeof(int),1,6,1,&option);

		  switch(option) {
		  case 1:
			  controller_loadFromText("log.txt", listaLog);
			  //ll_map(listaBikes,bike_calcularVelocidadP);
			  break;
		  case 2:
			  listaGravedad = ll_filter(listaLog,filtrarGravedad);
			  if(controller_saveAsText("warnings.txt",listaGravedad) == 0) {
				  printf("\nArchivo generado correctamente\n");
			  } else {
				  printf("Error generando archivo\n");
			  }
			  break;
		  case 3:
			  /*listaBikesFiltradas = ll_filter(listaBikes,filtrar);
			  if(controller_saveAsText("bikesFiltradas.csv",listaBikesFiltradas) == 0) {
				  printf("\nArchivo generado correctamente\n");
			  } else {
				  printf("Error generando archivo\n");
			  }*/
			  break;
		  case 4:
			  break;
		  default:
			  printf("Opcion invalida");

		  }
	  }while(option != 5);

	return 0;
}
