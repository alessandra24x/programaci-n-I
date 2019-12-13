#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "computer.h"

int parser_parseComputers(FILE* fileName, LinkedList* listaComputers) {
	int ret = 0;
	char auxId[4096];
	char auxDescripcion[4096];
	char auxPrecio[4096];
	char auxIdTipo[4096];
	char auxOferta[4096];
	Computer* pComputer;

		if(fileName != NULL && listaComputers != NULL) {
			fscanf(fileName, "[^\n]\n");
			while(!feof(fileName)) {
				fscanf(fileName, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,
	                    auxDescripcion,
	                    auxPrecio,
						auxIdTipo,
						auxOferta);
				pComputer = computer_newParametros(auxId, auxDescripcion,auxPrecio,auxIdTipo,auxOferta);

				if(pComputer != NULL) {
					if(ll_add(listaComputers, pComputer) == 0) {
						ret++;
					}
				} else {
					printf("NULL");
				}
			}
		}
    return ret;
}
