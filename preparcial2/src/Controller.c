#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "utn.h"
#include "Parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pListaEmpleados) {
	int ret = 0;
	FILE* pFile;
	pFile = fopen(path, "r");
	ret = parser_parseEmpleados(pFile, pListaEmpleados);
	fclose(pFile);
	return ret;
}

/** \brief Obtiene el mayor id del LinkedList y lo carga en la estructura empleado.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_lastIdEmployee(LinkedList* pListaEmpleados) {
	int ret = -1;
	Empleado* auxEmployee;
	int  bufferId;
	int auxId = -1;
	int i, len;

	if(pListaEmpleados != NULL) {
		len = ll_len(pListaEmpleados);
		for(i = 0; i < len; i++) {
			auxEmployee = (Empleado*)ll_get(pListaEmpleados, i);
			employee_getId(auxEmployee,&bufferId);
			if(bufferId > auxId) {
				auxId = bufferId;
			}
		}
		employe_idInit(auxId);
		ret = 0;
	}
	return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_addEmployee(LinkedList* pListaEmpleados) {
  int ret = -1;
  char auxNombre[128];
  int auxHorasTrabajadas;
  int auxSueldo;
  Empleado* auxEmployee;
  auxEmployee = employee_new();
  if(pListaEmpleados != NULL && auxEmployee != NULL) {

    if(utn_getName("Ingrese el nombre: ", "Error. Ingrese un nombre valido: ", 1, 127, 2, auxNombre) == 0 && utn_getUnsignedInt("Ingrese la cantidad de horas trabajadas: ", "Error. Ingrese un valor valido: ", 1, 10, 0, 200, 2, &auxHorasTrabajadas) == 0 && utn_getUnsignedInt("Ingrese el sueldo: ", "Error. Ingrese un valor valido: ", 1, 10, 1, 50000, 2, &auxSueldo) == 0) {
      employee_setId(auxEmployee, employee_idGenerator());
      employee_setNombre(auxEmployee, auxNombre);
      employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas);
      employee_setSueldo(auxEmployee, auxSueldo);

      ll_add(pListaEmpleados, auxEmployee);
    }
  }
    return ret;
}

int controller_searchEmployeeById(LinkedList* pListaEmpleados, int id, int* index) {
	int ret = -1;
	Empleado* auxEmployee;
	int auxId;
	int i, len;

	if(pListaEmpleados != NULL) {
		len = ll_len(pListaEmpleados);
			for(i = 0; i < len; i++) {
				auxEmployee = (Empleado*)ll_get(pListaEmpleados, i);
				employee_getId(auxEmployee,&auxId);
				if(auxId == id) {
					*index = i;
					ret = 0;
				}
			}
		}
	return ret;
	}

int controller_PrintEmployee(LinkedList* pListaEmpleados, int index) {
	int ret = -1;
	Empleado* auxEmployee;
	int auxId;
	char auxNombre[4096];
	int auxHorasTrabajadas;
	int auxSueldo;

	if(pListaEmpleados != NULL) {
		auxEmployee = ll_get(pListaEmpleados, index);
		employee_getId(auxEmployee, &auxId);
		employee_getNombre(auxEmployee, auxNombre);
		employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas);
		employee_getSueldo(auxEmployee, &auxSueldo);
		printf("ID: %d\n1.Nombre: %s\n2.Horas trabajadas: %d\n3.Sueldo: %d\n", auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
		ret = 0;
	}
	return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pListaEmpleados) {
	int ret = -1;
	int i, len;
	if(pListaEmpleados != NULL) {
		if(ll_len(pListaEmpleados) > 0) {
			len = ll_len(pListaEmpleados);
			for(i = 0; i < len; i++) {
				controller_PrintEmployee(pListaEmpleados, i);
			}
			ret = 0;
		} else {
			printf("No existen registros cargados");
		}
		return ret;
	}
	return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveEmployeesAsText(FILE* pFile , LinkedList* pListaEmpleados) {
    int ret = 0;
	Empleado* auxEmployee;
    int auxId;
    char auxNombre[4096];
    int auxHorasTrabajadas;
    int auxSueldo;
    int i, len;

    if(pListaEmpleados != NULL && pFile != NULL) {
    	fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
    	len = ll_len(pListaEmpleados);
    	for(i = 0; i < len; i++) {
    		auxEmployee = (Empleado*)ll_get(pListaEmpleados, i);
    		employee_getId(auxEmployee, &auxId);
    		employee_getNombre(auxEmployee, auxNombre);
    		employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas);
    		employee_getSueldo(auxEmployee, &auxSueldo);
    		fprintf(pFile,"%d,%s,%d,%d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
    		ret++;
    	}
	fclose(pFile);
    }
    return ret;
}

int controller_saveAsText(char* fileName,LinkedList* listaEmpleados) {
	FILE*pArchivo;
	int retorno=-1;

	    if(fileName != NULL && listaEmpleados !=NULL)
	    {
	        pArchivo=fopen(fileName,"w");
	        if(pArchivo != NULL && controller_saveEmployeesAsText(pArchivo,listaEmpleados) == 0)
	        {
	            fclose(pArchivo);
	            printf("\nGuardado exitoso en Texto");
	            retorno=0;
	        }
	        else
	        {
	            printf("\nNo se pudo abrir el archivo");
	        }
	    }
	    return retorno;
}
