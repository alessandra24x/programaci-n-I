#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

static int lastId = 0;

int employee_idGenerator(int id) {
   lastId = id++;
   return lastId++;
}

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
      ret = 0;
    }
    return ret;
}

int employee_setNombre(Employee* this,char* nombre) {
    int ret = -1;
    if(this != NULL && isValidName(nombre) == 0) {
      strncpy(this->nombre,nombre,sizeof(this->nombre));
      ret = 0;
    }
    return ret;
}

int employee_getNombre(Employee* this,char* nombre) {
    int ret = -1;
    if(this != NULL && nombre != NULL) {
      strncpy(nombre,this->nombre,sizeof(this->nombre));
      *nombre = this->id;
      ret = 0;
    }
    return ret;
}

int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadasStr) {
    int ret = -1;
    int auxHorasTrabajadas;
    if(this != NULL && horasTrabajadasStr != NULL) {
      if(isValidNumber(horasTrabajadasStr) == 0) {
        auxHorasTrabajadas = atoi(horasTrabajadasStr);
        if(employee_setHorasTrabajadas(this, auxHorasTrabajadas) == 0) {
          ret = 0;
        }
      }
    }
    return ret;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas) {
    int ret = -1;
    if(this != NULL && horasTrabajadas >= 0) {
      this->horasTrabajadas = horasTrabajadas;
      ret = 0;
    }
    return ret;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas) {
  int ret = -1;
  if(this != NULL && horasTrabajadas != NULL) {
    *horasTrabajadas = this->horasTrabajadas;
    ret = 0;
  }
  return ret;
}

int employee_setSueldoStr(Employee* this,char* sueldoStr) {
  int ret = -1;
  int auxSueldo;
  if(this != NULL && sueldoStr != NULL) {
      if(isValidNumber(sueldoStr) == 0) {
        auxSueldo = atoi(sueldoStr);
        if(employee_setsueldo(this, auxSueldo) == 0) {
          ret = 0;
        }
      }
    }
    return ret;
}

int employee_setSueldo(Employee* this,int sueldo) {
  int ret = -1;
  if(this != NULL && sueldo > 0) {
    this->sueldo = sueldo;
    ret = 0;
  }
  return ret;
}

int employee_getSueldo(Employee* this,int* sueldo) {
  int ret = -1;
  if(this != NULL && sueldo != NULL) {
    *sueldo = this->sueldo;
    ret = 0;
  }
  return ret;
}
