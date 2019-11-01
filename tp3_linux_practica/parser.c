#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee) {
	int ret = 0;
	char auxId[4096];
	char auxNombre[4096];
	char auxHorasTrabajadas[4096];
	char auxSueldo[4096];
	Employee* pEmployee;

	if(pFile != NULL && pArrayListEmployee != NULL) {
		fscanf(pFile, "[^\n]\n");
		while(!feof(pFile)) {
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",auxId,
                    auxNombre,
                    auxHorasTrabajadas,
                    auxSueldo);
			pEmployee = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

			if(pEmployee != NULL) {
				if(!ll_add(pArrayListEmployee, pEmployee)) {
					ret++;
				}
			}
		}
	}
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee) {
	int ret = 0;
	Employee* pEmployee;

	if(pFile != NULL && pArrayListEmployee != NULL) {
		do {
			pEmployee = employee_new();

			if(pEmployee != NULL) {
				fread(pEmployee, sizeof(Employee), 1, pFile);
				if(!ll_add(pArrayListEmployee, pEmployee)) {
					ret++;
				}

			} else {
				employee_delete(pEmployee);
			}
		} while(!feof(pFile));
	}

    return ret;
}
