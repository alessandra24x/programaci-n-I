#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"

int parser_parseEmpleados(FILE* fileName, LinkedList* listaEmpleados) {
	int ret = 0;
	char auxId[4096];
	char auxNombre[4096];
	char auxHorasTrabajadas[4096];
	Empleado* pEmployee;

		if(fileName != NULL && listaEmpleados != NULL) {
			fscanf(fileName, "[^\n]\n");
			while(!feof(fileName)) {
				fscanf(fileName, "%[^,],%[^,],%[^\n]\n",auxId,
	                    auxNombre,
	                    auxHorasTrabajadas);
				pEmployee = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas);

				if(pEmployee != NULL) {
					if(ll_add(listaEmpleados, pEmployee) == 0) {
						ret++;
					}
				} else {
					printf("NULL");
				}
			}
		}
    return ret; // OK
}
