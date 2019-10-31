#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Employee.h"

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
	ret = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
	fclose(pFile);
	return ret;
}

/** \brief Obtiene el mayor id del LinkedList y lo carga en la estructura empleado.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_lastIdEmployee(LinkedList* pArrayListEmployee)
{
    Employee* bufferEmployee;
    int bufferId;
    int auxId = -1;
    int ret = -1;
    int i;
    int len;
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            bufferEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(bufferEmployee,&bufferId);
            if(bufferId>auxId)
            {
                auxId=bufferId;
            }
        }
        employe_idInit(auxId);
        ret = 0;
    }
    return ret;
}

/** \brief Obtiene el mayor id del LinkedList y lo carga en la estructura empleado.
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \param index int*
 * \return int
 *
 */

int controller_searchEmployeeById(LinkedList* pArrayListEmployee,int id,int* index)
{
    Employee* bufferEmployee;
    int bufferId;
    int ret = -1;
    int i;
    int len;
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            bufferEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(bufferEmployee,&bufferId);
            if(bufferId==id)
            {
                *index=i;
                ret = 0;
            }
        }
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
int controller_addEmployee(LinkedList* pArrayListEmployee) {
    int ret = -1;
    char bufferNombre[128];
    int  bufferHorasTrabajadas;
    int bufferSueldo;
    Employee* bufferEmployee;
    bufferEmployee = employee_new();
    if(pArrayListEmployee != NULL && bufferEmployee != NULL) {
      if(utn_getName("Ingrese el nombre", "Nombre invalido", 1, 127, 2, bufferNombre) == 0 && utn_getUnsignedInt("Ingrese las horas trabajadas", "Valor de horas invalido", 0, sizeof(int), 0, 80, 2, &bufferHorasTrabajadas) == 0 && utn_getUnsignedInt("Ingrese el sueldo", "Sueldo invalido", 1, sizeof(int), 12000, 80000, 2, &bufferSueldo) == 0) {
          employee_setId(bufferEmployee,employee_idGenerator());
          employee_setNombre(bufferEmployee,bufferNombre);
          employee_setHorasTrabajadas(bufferEmployee,bufferHorasTrabajadas);
          employee_setSueldo(bufferEmployee,bufferSueldo);

          ll_add(pArrayListEmployee,bufferEmployee);
      } else {
        employee_delete(bufferEmployee);
      }
    }
    return ret;
}
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee) {
    int ret = -1;
    if(pArrayListEmployee != NULL) {
      if(ll_len(pArrayListEmployee)) {
          char bufferNombre[128];
          int bufferHorasTrabajadas;
          int bufferSueldo;
          Employee* bufferEmployee;
          int option;
          int auxIndex;
          int auxId;
          if(!utn_getUnsignedInt("Ingrese el ID del empleado", "ID invalido", 0, sizeof(int), 0, 80, 2, &auxId) && !controller_searchEmployeeById(pArrayListEmployee,auxId,&auxIndex)) {
            do {
              bufferEmployee = (Employee*)ll_get(pArrayListEmployee, auxIndex);
              controller_PrintEmployee(pArrayListEmployee, auxIndex);
              printf("4. Salir");
              utn_getUnsignedInt("Ingrese el ID del empleado", "ID invalido", 0, sizeof(int), 0, 80, 2, &option);
              switch(option) {
                case 1:
                  if(!utn_getName("Ingrese el nombre", "Nombre invalido", 1, 127, 2, bufferNombre)) {
                    employee_setNombre(bufferEmployee, bufferNombre);
                  }
                  break;
                case 2:
                  if(!utn_getUnsignedInt("Ingrese las horas trabajadas", "Valor de horas invalido", 0, sizeof(int), 0, 80, 2, &bufferHorasTrabajadas)) {
                    employee_setHorasTrabajadas(bufferEmployee, bufferHorasTrabajadas);
                }
                  break;
                case 3:
                  if(utn_getUnsignedInt("Ingrese el sueldo", "Sueldo invalido", 0, sizeof(int), 12000, 80000, 2, &bufferSueldo)) {
                    employee_setSueldo(bufferEmployee, bufferSueldo);
                  }
                  break;
              }
            }
            while(option != 4);
            ret = 0;
          } else {
            printf("Id invalido");
          }
      } else {
        printf("No existen registros cargados");
      }
    }
    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee) {
    int ret = -1;
    if(pArrayListEmployee != NULL) {
      if(ll_len(pArrayListEmployee) > 0) {
        Employee* bufferEmployee;
        int option;
        int auxIndex;
        int auxId;
        if(!utn_getUnsignedInt("Ingrese el ID del empleado", "ID invalido", 0, sizeof(int), 0, 80, 2, &auxId) && !controller_searchEmployeeById(pArrayListEmployee,auxId,&auxIndex)) {
          do {
            bufferEmployee = (Employee*)ll_get(pArrayListEmployee, auxIndex);
            printf("¿Desea eliminar el siguiente registro?\n");
            controller_PrintEmployee(pArrayListEmployee, auxIndex);
            utn_getUnsignedInt("[1. Aceptar / 2.Cancelar]: ", "Valor invalido", 0, sizeof(int), 0, 2, 2, &option);

            switch(option) {
              case 1:
                employee_delete(bufferEmployee);
                ll_remove(pArrayListEmployee, auxIndex);
                printf("Registro eliminado");
                break;
              case 2:
                printf("Operacion cancelada");
                break;
            }

          }
          while(option != 1 && option != 2);
          ret = 0;
        } else {
          printf("Id invalido");
        }
      } else {
        printf("No existen registros cargados");
      }
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
int controller_PrintEmployee(LinkedList* pArrayListEmployee, int index) {
  Employee* bufferEmployee;
  int bufferId;
  char bufferNombre[4096];
  int  bufferHorasTrabajadas;
  int bufferSueldo;
  int ret = -1;

  if(pArrayListEmployee != NULL && index >= 0 && index < ll_len(pArrayListEmployee)) {

      bufferEmployee = (Employee*)ll_get(pArrayListEmployee, index);
      employee_getId(bufferEmployee,&bufferId);
      employee_getNombre(bufferEmployee,bufferNombre);
      employee_getHorasTrabajadas(bufferEmployee,&bufferHorasTrabajadas);
      employee_getSueldo(bufferEmployee,&bufferSueldo);
      printf("ID: %d\n1.Nombre: %s\n2.Horas trabajadas: %d\n3.Sueldo: %d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
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
