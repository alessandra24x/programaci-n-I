/*
 ============================================================================
 Name        : pre_parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"

#define QTY_TIPO 3

int main() {
	 int opcion;
	 int contadorId = 0;
	 ePantalla arrayPantalla[QTY_TIPO];
	 inicializar(arrayPantalla,QTY_TIPO);

	 do {

		 utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n", "\nError",1,sizeof(int),1,50,1,&opcion);
	        switch(opcion)
	        {
	            case 1: //Alta
	                fantasma_alta(arrayFantasma,QTY_TIPO,&contadorIdfantasma);                   //cambiar
	                break;

	            case 2: //Modificar
	                fantasma_modificar(arrayFantasma,QTY_TIPO);                   //cambiar
	                break;

	            case 3: //Baja
	                fantasma_baja(arrayFantasma,QTY_TIPO);                   //cambiar
	                break;

	            case 4://Listar
	                fantasma_listar(arrayFantasma,QTY_TIPO);                   //cambiar
	                break;

	            case 5://Ordenar
	                fantasma_ordenarPorString(arrayFantasma,QTY_TIPO);                   //cambiar
	                break;

	            case 6://Salir
	                break;
	            default:
	                printf("\nOpcion no valida");
	        }
	    }
	    while(opcion!=6);
	    return 0;
	}
}
