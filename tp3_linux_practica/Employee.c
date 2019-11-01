#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

Employee* employee_new() {
	return (Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr) {
	Employee* aux;
	aux = employee_new();
	if(aux != NULL) {
		/*if(employee_setIdStr(aux,idStr)||
                employee_setNombre(aux,nombreStr)||
                employee_setHorasTrabajadasStr(aux,horasTrabajadasStr)||
                employee_setSueldoStr(aux,sueldoStr)) {
                	employee_delete(aux);
                	aux = NULL;
                }*/
	}
	return aux;
}

int employee_delete(Employee* this) {
	int ret = -1;
	if(this != NULL) {
		free(this);
		ret = 0;
	}
	return ret;
}


int employee_setIdStr(Employee* this,char* idStr) {
    int ret = -1;
    int auxId;
    if(this != NULL && idStr != NULL) {
        if(isValidNumber(idStr) == 0) {
            auxId = atoi(idStr);
            if(employee_setId(this, auxId) == 0) {
                ret = 0;
            }
        }
    }
    return ret;
}

int employee_setId(Employee* this,int id) {
	int ret = -1;
	if(this != NULL && id >= 0) {
		this->id = id;
		ret = 0;
	}
	return ret;
}

int employee_getId(Employee* this,int* id) {
	int ret = -1;
	if(this != NULL && id != NULL) {
		*id = this->id;
	}
	return ret;
}
