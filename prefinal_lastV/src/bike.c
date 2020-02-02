#include "bike.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"

Bike* bike_new() { //reservo espacio en memoria de manera dinámica para cada Bike
	return (Bike*)malloc(sizeof(Bike));
}

//Construye una nueva bike, le setea los valores y devuelve un puntero de tipo void
Bike* bike_newParametros(char* idStr,char* nombreStr,char* tipoStr, char* tiempoStr, char* velocidadPStr) {
	Bike* aux;
	aux = bike_new();
	if(aux != NULL) {
		int setId = bike_setIdStr(aux, idStr);
		int setNombre = bike_setNombre(aux, nombreStr);
		int setTipo = bike_setTipo(aux, tipoStr);
		int setTiempo = bike_setTiempoStr(aux, tiempoStr);
		int setVelocidadP = bike_setVelocidadPStr(aux, velocidadPStr);

		if (setId != 0) {
		  printf("Problema al cargar id\n");
		  return NULL;
		}

		if (setNombre != 0) {
		  printf("Problema al cargar nombre\n");
		  return NULL;
		}

		if (setTipo != 0) {
		  printf("Problema al cargar tipo\n");
		  return NULL;
		}

		if (setTiempo != 0) {
		  printf("Problema al cargar tiempo\n");
		  return NULL;
		}

		if (setVelocidadP != 0) {
			printf("Problema al cargar velocidad promedio");
			return NULL;
		}

	}
	return aux;
}

int bike_delete(Bike* this) {
	int ret = -1;
	if(this != NULL) {
		free(this);
		ret = 0;
	}
	return ret;
}

int bike_setIdStr(Bike* this,char* idStr) {
    int ret = -1;
    int auxId;
    if(this != NULL && idStr != NULL) {
        if(isValidNumber(idStr) == 0) {
            auxId = atoi(idStr);
            if(bike_setId(this, auxId) == 0) {
                ret = 0;
            }
        }
    }
    return ret;
}

int bike_setId(Bike* this,int id) {
    int ret = -1;
    if(this != NULL && id >= 0) {
      this->id = id;
      ret = 0;
    }
    return ret;
}

int bike_getId(Bike* this,int* id) {
    int ret = -1;
    if(this != NULL && id != NULL) {
      *id = this->id;
      ret = 0;
    }
    return ret;
}

int bike_setNombre(Bike* this,char* nombre) {
    int ret = -1;
    if(this != NULL && isValidName(nombre) == 0) {
      strncpy(this->nombre,nombre,sizeof(this->nombre));
      ret = 0;
    }
    return ret;
}

int bike_getNombre(Bike* this,char* nombre) {
    int ret = -1;
    if(this != NULL && nombre != NULL) {
      strcpy(nombre,this->nombre);
      ret = 0;
    }
    return ret;
}

int bike_setTipo(Bike* this,char* tipo) {
    int ret = -1;
    if(this != NULL && isValidName(tipo) == 0) {
      strncpy(this->tipo,tipo,sizeof(this->tipo));
      ret = 0;
    }
    return ret;
}

int bike_getTipo(Bike* this,char* tipo) {
  int ret = -1;
  if(this != NULL && tipo != NULL) {
    strcpy(tipo,this->tipo);
    ret = 0;
  }
  return ret;
}

int bike_setTiempoStr(Bike* this,char* tiempoStr) {
  int ret = -1;
  int auxTiempo;

  if(this != NULL && tiempoStr != NULL) {
	  if(isValidNumber(tiempoStr) == 0) {
		  auxTiempo = atoi(tiempoStr);
		  if(bike_setTiempo(this, auxTiempo) == 0) {
			  ret = 0;
		  }
	  }
  }
  return ret;
}

int bike_setTiempo(Bike* this,int tiempo) {
    int ret = -1;
    if(this != NULL && tiempo >= 0) {
      this->tiempo = tiempo;
      ret = 0;
    }
    return ret;
}

int bike_getTiempo(Bike* this,int* tiempo) {
    int ret = -1;
    if(this != NULL && tiempo != NULL) {
      *tiempo = this->tiempo;
      ret = 0;
    }
    return ret;
}

int bike_setVelocidadPStr(Bike* this,char* velocidadPStr) {
  int ret = -1;
  int auxVelocidadP;

  if(this != NULL && velocidadPStr != NULL) {
	  if(isValidNumber(velocidadPStr) == 0) {
		  auxVelocidadP = atof(velocidadPStr);
		  if(bike_setVelocidadP(this, auxVelocidadP) == 0) {
			  ret = 0;
		  }
	  }
  }
  return ret;
}

int bike_setVelocidadP(Bike* this,float velocidadP) {
    int ret = -1;
    if(this != NULL && velocidadP >= 0) {
      this->velocidadP = velocidadP;
      ret = 0;
    }
    return ret;
}

int bike_getVelocidadP(Bike* this,float* velocidadP) {
    int ret = -1;
    if(this != NULL && velocidadP != NULL) {
      *velocidadP = this->velocidadP;
      ret = 0;
    }
    return ret;
}

void* bike_calcularVelocidadP(void* pBike) {
	Bike* bk = (Bike*) pBike;
	float km = 10.0;

	if(pBike != NULL) {
		float tiempo = bk->tiempo;
		tiempo = tiempo / 60.0;
		bk->velocidadP = km / tiempo;
	}
	return bk;
}

int filtrar(void* pBike) {
	Bike* bk = (Bike*) pBike;
	int returnAux = -1;
	char tipo[64];

	if(pBike != NULL) {
		strcpy(tipo, bk->tipo);
		if(strcmp(tipo, "BMX")) {
			returnAux = 0;
		}
	}
	return returnAux;
}

int bike_compareTipo(void* pTipoA,void* pTipoB) {
	int ret = 0;
	if(strcmp(((Bike*)pTipoA)->tipo,((Bike*)pTipoB)->tipo) > 0) {
		ret = 1;
	}
	if(strcmp(((Bike*)pTipoA)->tipo,((Bike*)pTipoB)->tipo) < 0) {
		ret = -1;
	}
	if(strcmp(((Bike*)pTipoA)->tipo,((Bike*)pTipoB)->tipo) == 0) {
		ret = bike_compareTiempo(((Bike*)pTipoA)->tiempo,((Bike*)pTipoB)->tiempo);
	}

	return ret;
}

int bike_compareTiempo(int tiempoA, int tiempoB) {
	int ret = 0;
	if(tiempoA  > tiempoB) {
		ret = 1;
	}

	if(tiempoA < tiempoB) {
		ret = -1;
	}

	return ret;
}
