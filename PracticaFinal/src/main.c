#include <stdio.h>
#include <stdlib.h>

#include "vendedor.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"

int main(void) {
  int option = 0;

  LinkedList* listaVendedores;
  //LinkedList* listaBikesFiltradas;

  listaVendedores = ll_newLinkedList();

  do {
	  printf("/****************************************************\
	          	    	  \nMenu:\
	          	    	  \n1. Cargar Archivo\
	          	    	  \n2. Imprimir Vendedores\
	          	    	  \n\n3. Calcular Comisiones\
	          	    	  \n4. Generar archivo de comisiones para nivel\
	          	    	  \n5. Salir\
	          	    	  \n*****************************************************/");

	  utn_getUnsignedInt("\nSeleccione opcion: ","Opcion invalida",1,sizeof(int),1,6,1,&option);

	  switch(option) {
	  case 1:
		  controller_loadFromText("data.csv", listaVendedores);
		  //ll_map(listaBikes,bike_calcularVelocidadP);
		  break;
	  case 2:
		  controller_ListVendedores(listaVendedores);
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
		  //controller_sortBike(listaBikes);
		  break;
	  case 5:
		  break;
	  default:
		  printf("Opcion invalida");
	  }
  }while(option != 5);

	  return 0;
}
