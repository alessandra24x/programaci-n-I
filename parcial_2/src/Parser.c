#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "perro.h"

int parser_parsePerros(FILE* fileName, LinkedList* listaPerros) {
	int ret = 0;
	char auxId[4096];
	char auxNombre[4096];
	char auxDias[4096];
	char auxRaza[4096];
	char auxReservado[4096];
	char auxSexo[4096];
	Perro* pPerro;

		if(fileName != NULL && listaPerros != NULL) {
			fscanf(fileName, "[^\n]\n");
			while(!feof(fileName)) {
				fscanf(fileName, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,
	                    auxNombre,
	                    auxDias,
						auxRaza,
						auxReservado,
						auxSexo);
				pPerro = perro_newParametros(auxId, auxNombre, auxDias, auxRaza, auxReservado, auxSexo);

				if(pPerro != NULL) {
					if(ll_add(listaPerros, pPerro) == 0) {
						ret++;
					}
				} else {
					printf("NULL");
				}
			}
		}
    return ret;
}
