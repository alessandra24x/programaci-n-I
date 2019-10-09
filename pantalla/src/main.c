#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"
#include "informes.h"

int main() {
	 int opcion;
	 int contadorId = 0;
	 Pantalla arrayPantalla[QTY_TIPO];
	 inicializar(arrayPantalla,QTY_TIPO);
	 Publicidad arrayPublicidad[QTY_TIPO];
	 publicidad_Inicializar(arrayPublicidad, QTY_TIPO);

   setPantalla(arrayPantalla, 1, 1,  "lcd", "samsung10", 22, "salta 567");
   setPantalla(arrayPantalla, 2, 2, "led", "lg32", 48, "chile 757");
   setPantalla(arrayPantalla, 3, 3, "lcd", "samsung28", 25, "ramallo 2567");
   setPantalla(arrayPantalla, 4, 4, "lcd", "philips28", 15, "cabildo 1567");
   setPantalla(arrayPantalla, 5, 5, "led", "sony16", 32, "santa fe 4567");

   setPublicidad(arrayPublicidad, 1, "258", 1, 25, "jld");
   setPublicidad(arrayPublicidad, 2, "158", 2, 45, "jud");
   setPublicidad(arrayPublicidad, 3, "298", 3, 31, "jld");
   setPublicidad(arrayPublicidad, 4, "957", 2, 13, "jud");
   setPublicidad(arrayPublicidad, 5, "158", 2, 80, "jld");

	 do {

		 utn_getUnsignedInt("\n\n1) Alta Pantalla \n2) Modificar Pantalla \n3) Baja Pantalla \n4) Listar Pantallas \n5) Contratar Publicidad \n6) Ordenar \n7) Listar Publicidades \n8) Modificar Publicidad \n9) Consulta Facturacion \n10) Informes \n11) Salir\n",                   //cambiar
                 "\nError",1,sizeof(int),1,11,1,&opcion);
	        switch(opcion) {
	            case 1: //Alta
	                pantalla_alta(arrayPantalla,QTY_TIPO,&contadorId);
	                break;

	            case 2: //Modificar
	                pantalla_modificar(arrayPantalla,QTY_TIPO);
	                break;

	            case 3: //Baja
	                pantalla_baja(arrayPantalla,QTY_TIPO);
	                break;

	            case 4://Listar pantalla
	                pantalla_listar(arrayPantalla,QTY_TIPO);
	                break;

	            case 5://Contratar publicidad
	                pantalla_listar(arrayPantalla,QTY_TIPO);
	                pantalla_contratar(arrayPublicidad,QTY_TIPO);
	                break;

	            case 6://Ordenar
	                pantalla_ordenarPorString(arrayPantalla,QTY_TIPO);
	                break;

	            case 7://Listar Publicidades
	                 publicidad_listar(arrayPublicidad,QTY_TIPO);
	                 break;

	            case 8://Modificar Publicidad
	                 publicidad_modificar(arrayPublicidad, QTY_TIPO);
	                 break;

	            case 9://Consultar Facturacion
	                 publicidad_consultaFacturacion(arrayPantalla, QTY_TIPO, arrayPublicidad, QTY_TIPO);
	                 break;
            
              case 10://informes
                  informarContrataciones(arrayPublicidad,QTY_TIPO,arrayPantalla,QTY_TIPO);
                  break;

	            case 11://Salir
	                 printf("\nSaliendo...");
	                 break;
	            default:
	                 printf("\nOpcion no valida");
                   break;
	        }
	    }
	    while(opcion != 11);
	    return 0;
	}
