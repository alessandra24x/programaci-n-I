#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee) {
	int ret = 0;
	FILE* pFile;
	pFile = fopen(path, "r");
	ret = parser_EmployeeFromText(pFile, pArrayListEmployee);
	fclose(pFile);
	return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee) {
	int ret = 0;
	FILE* pFile;
	pFile = fopen(path, "rb");
	ret = parser_EmployeeFromText(pFile, pArrayListEmployee);
	fclose(pFile);
	return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee) {
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee) {
	int ret = -1;
	int i, len;
	if(pArrayListEmployee != NULL) {
		if(ll_len(pArrayListEmployee) > 0) {
			len = ll_len(pArrayListEmployee);
			for(i = 0; i < len; i++) {
				controller_PrintEmployee(pArrayListEmployee, i);
			}
			ret = 0;
		} else {
			printf("No existen registros cargados");
		}
		return ret;
	}

    return ret;
}

/** \brief Imprime un empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param index int
 * \return int
 *
 */

int print_Employee(LinkedList* pArrayListEmployee, index) {
	int ret = -1;
	Employee* auxEmployee;
	int auxId;
	char auxNombre[4096];
	int auxHorasTrabajadas;
	int auxSueldo;

	if(pArrayListEmployee != NULL && index >= 0 && index < ll_len(pArrayListEmployee)) {
		employee_getId(auxEmployee, &auxId);
		employee_getNombre(auxEmployee, auxNombre);
		employee_getHorasTrabajadas(auxEmployee, auxHorasTrabajadas);
		employee_getSueldo(auxEmployee, auxSueldo);
		ret = 0;
	}
	return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

