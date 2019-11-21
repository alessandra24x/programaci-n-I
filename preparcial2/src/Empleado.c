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

Empleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr) {
	Empleado* aux;
	aux = employee_new();
  printf("newParam1\nId:%s\nNombre: %s\nHoras: %s\n\n", idStr, nombreStr, horasTrabajadasStr);
	if(aux != NULL) {
    int setId = employee_setIdStr(aux, idStr);
    int setNombre = employee_setNombre(aux, nombreStr);
    int setHoras = employee_setHorasTrabajadasStr(aux, horasTrabajadasStr);

    if (setId != 0) {
      printf("Problema al cargar id\n");
      return NULL;
    }

    if (setNombre != 0) {
      printf("Problema al cargar nombre\n");
      return NULL;
    }

    if (setHoras != 0) {
      printf("Problema al cargar horas\n");
      return NULL;
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
        	employee_setHorasTrabajadas(this, auxHorasTrabajadas);
          ret = 0;
        }
      }
    }
    return ret;
}

int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas) {
    int ret = -1;
    if(this != NULL && horasTrabajadas > 0) {
      this->horasTrabajadas = horasTrabajadas;
      ret = 0;
    } else {
    printf("error");
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
        	employee_setSueldo(this,auxSueldo);
          ret = 0;
        } else {
        	printf("algo esta mal");
        }
      }
    }
    return ret;
}

int employee_setSueldo(Empleado* this,int sueldo) {
	//printf("valor sueldo: %d\n", sueldo);
  int ret = -1;
  if(this != NULL && sueldo > 0) {
    this->sueldo = sueldo;
    ret = 0;
  } else {
	  //printf("Error");
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
	int sueldo, horasTrabajadas;
	/*Los valores de horas varian entre 80 y 240.
	    - Las primeras 120 horas la hora vale $180
	    - De 120 a 160 horas, la hora vale $240
	    - De 160 a 240 horas, la hora vale $350*/
	if(empleado != NULL) {
		employee_getHorasTrabajadas(empleado, &horasTrabajadas);

		if(horasTrabajadas <= 120) {
			sueldo = horasTrabajadas * 180;
		} else if(horasTrabajadas > 120 && horasTrabajadas <= 160) {
			horasTrabajadas = horasTrabajadas - 120;
			sueldo = horasTrabajadas * 240 + (120 * 180);
		} else if(horasTrabajadas > 160 && horasTrabajadas <= 240) {
			horasTrabajadas = horasTrabajadas - 160;
			sueldo = horasTrabajadas * 350 + (40 * 240) + (120 * 180);
		}
		employee_setSueldo(empleado, sueldo);
	}
}

int filtrarPorSueldo(void* empleado) {
	int returnAux = -1;
	int sueldo;
	if(empleado != NULL) {
		employee_getSueldo(empleado, &sueldo);
		if(sueldo > 28000) {
			returnAux = 0;
		}
	}
	return returnAux;
}
