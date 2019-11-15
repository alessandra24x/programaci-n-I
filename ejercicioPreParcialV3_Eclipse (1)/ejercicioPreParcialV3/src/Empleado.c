#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "utn.h"

static int lastId = 0;

void employe_idInit(int id) {
    lastId = id+1;
}

int employee_idGenerator() {
   return lastId++;
}

Empleado* employee_new() {
	return (Empleado*)malloc(sizeof(Empleado));
}

Empleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr) {
	Empleado* aux;
	aux = employee_new();
	if(aux != NULL) {
		if(employee_setIdStr(aux,idStr)||
                employee_setNombre(aux,nombreStr)||
                employee_setHorasTrabajadasStr(aux,horasTrabajadasStr)||
                employee_setSueldoStr(aux,sueldoStr)) {
                employee_delete(aux);
                aux = NULL;
              }
	}
	return aux;
}


int employee_delete(Empleado* this) {
	int ret = -1;
	if(this != NULL) {
		free(this);
		ret = 0;
	}
	return ret;
}


int employee_setIdStr(Empleado* this,char* idStr) {
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

int employee_setId(Empleado* this,int id) {
    int ret = -1;
    if(this != NULL && id >= 0) {
      this->id = id;
      ret = 0;
    }
    return ret;
}

int employee_getId(Empleado* this,int* id) {
    int ret = -1;
    if(this != NULL && id != NULL) {
      *id = this->id;
      ret = 0;
    }
    return ret;
}

int employee_setNombre(Empleado* this,char* nombre) {
    int ret = -1;
    if(this != NULL && isValidName(nombre) == 0) {
      strncpy(this->nombre,nombre,sizeof(this->nombre));
      ret = 0;
    }
    return ret;
}

int employee_getNombre(Empleado* this,char* nombre) {
    int ret = -1;
    if(this != NULL && nombre != NULL) {
      strcpy(nombre,this->nombre);
      ret = 0;
    }
    return ret;
}

int employee_setHorasTrabajadasStr(Empleado* this,char* horasTrabajadasStr) {
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

int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas) {
    int ret = -1;
    if(this != NULL && horasTrabajadas >= 0) {
      this->horasTrabajadas = horasTrabajadas;
      ret = 0;
    }
    return ret;
}

int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas) {
  int ret = -1;
  if(this != NULL && horasTrabajadas != NULL) {
    *horasTrabajadas = this->horasTrabajadas;
    ret = 0;
  }
  return ret;
}

int employee_setSueldoStr(Empleado* this,char* sueldoStr) {
  int ret = -1;
  int auxSueldo;
  if(this != NULL && sueldoStr != NULL) {
      if(isValidNumber(sueldoStr) == 0) {
        auxSueldo = atoi(sueldoStr);
        if(employee_setSueldo(this, auxSueldo) == 0) {
          ret = 0;
        }
      }
    }
    return ret;
}

int employee_setSueldo(Empleado* this,int sueldo) {
  int ret = -1;
  if(this != NULL && sueldo > 0) {
    this->sueldo = sueldo;
    ret = 0;
  }
  return ret;
}

int employee_getSueldo(Empleado* this,int* sueldo) {
  int ret = -1;
  if(this != NULL && sueldo != NULL) {
    *sueldo = this->sueldo;
    ret = 0;
  }
  return ret;
}


int employee_compareNombre(void* pEmployeeA,void* pEmployeeB) {
    int ret = 0;
    if(strcmp(((Empleado*)pEmployeeA)->nombre,((Empleado*)pEmployeeB)->nombre) > 0) {
        ret = 1;
    }
    if(strcmp(((Empleado*)pEmployeeA)->nombre,((Empleado*)pEmployeeB)->nombre) < 0) {
        ret = -1;
    }
    return ret;
}

void em_calcularSueldo(void* empleado) {
	// recibo elemento empleado como void.
	// hacer calculo de sueldo y escribirlo en campo sueldo del empleado
	int sueldo, i, horasTrabajadas;
	int valorBasic, valorExtra, valorExtraAdicional;
	/*Los valores de horas varian entre 80 y 240.
	    - Las primeras 120 horas la hora vale $180
	    - De 120 a 160 horas, la hora vale $240
	    - De 160 a 240 horas, la hora vale $350*/
	if(empleado != NULL) {
		employee_getHorasTrabajadas(empleado, &horasTrabajadas);
		valorBasic = horasTrabajadas * 180;

		if(horasTrabajadas > 120 && horasTrabajadas <= 160) {
			horasTrabajadas = horasTrabajadas - 120;
			valorExtra = horasTrabajadas * 240;
		} else if(horasTrabajadas > 160 && horasTrabajadas <= 240) {
			horasTrabajadas = horasTrabajadas - 160;
			valorExtraAdicional = horasTrabajadas * 350;
		}
		sueldo = valorBasic + valorExtra + valorExtraAdicional;
		employee_setSueldo(empleado, sueldo);
	}
}

