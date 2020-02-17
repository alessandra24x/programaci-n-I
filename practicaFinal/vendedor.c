#include "vendedor.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"

Vendedor* vendedor_new() { //reservo espacio en memoria de manera dinámica para cada Vendedor
	return (Vendedor*)malloc(sizeof(Vendedor));
}

//Construye una nueva Vendedor, le setea los valores y devuelve un puntero de tipo void
Vendedor* vendedor_newParametros(char* idStr,char* nombre,char* nivelStr, char* cantidad_ventasStr, char* montoStr, char* comisionesStr) {
	Vendedor* aux;
	aux = vendedor_new();
	if(aux != NULL) {
		int setId = vendedor_setIdStr(aux, idStr);
		int setNombre = vendedor_setNombre(aux, nombre);
		int setNivel = vendedor_setNivelStr(aux, nivelStr);
		int setCantidad_ventas = vendedor_setCantidad_ventasStr(aux, cantidad_ventasStr);
		int setMonto = vendedor_setMontoStr(aux, montoStr);
		int setComisiones = vendedor_setComisionesStr(aux, comisionesStr);

		if (setId != 0) {
		  printf("Problema al cargar id\n");
		  return NULL;
		}

		if (setNombre != 0) {
		  printf("Problema al cargar nombre\n");
		  return NULL;
		}

		if (setNivel != 0) {
		  printf("Problema al cargar nivel\n");
		  return NULL;
		}

		if (setCantidad_ventas != 0) {
		  printf("Problema al cargar cantidad de ventas\n");
		  return NULL;
		}

		if (setMonto != 0) {
			printf("Problema al cargar el monto\n");
			return NULL;
		}

		if(setComisiones != 0) {
			printf("Problema al cargar las comisiones\n");
		}

	}
	return aux;
}

int vendedor_delete(Vendedor* this) {
	int ret = -1;
	if(this != NULL) {
		free(this);
		ret = 0;
	}
	return ret;
}

int vendedor_setIdStr(Vendedor* this,char* idStr) {
    int ret = -1;
    int auxId;
    if(this != NULL && idStr != NULL) {
        if(isValidNumber(idStr) == 0) {
            auxId = atoi(idStr);
            if(vendedor_setId(this, auxId) == 0) {
                ret = 0;
            }
        }
    }
    return ret;
}

int vendedor_setId(Vendedor	* this,int id) {
    int ret = -1;
    if(this != NULL && id >= 0) {
      this->id = id;
      ret = 0;
    }
    return ret;
}

int vendedor_getId(Vendedor* this,int* id) {
    int ret = -1;
    if(this != NULL && id != NULL) {
      *id = this->id;
      ret = 0;
    }
    return ret;
}

int vendedor_setNombre(Vendedor* this,char* nombre) {
    int ret = -1;
    if(this != NULL && isValidName(nombre) == 0) {
      strncpy(this->nombre,nombre,sizeof(this->nombre));
      ret = 0;
    }
    return ret;
}

int vendedor_getNombre(Vendedor* this,char* nombre) {
    int ret = -1;
    if(this != NULL && nombre != NULL) {
      strcpy(nombre,this->nombre);
      ret = 0;
    }
    return ret;
}

int vendedor_setNivelStr(Vendedor* this,char* nivelStr) {
    int ret = -1;
    int auxNivel;
    if(this != NULL && nivelStr != NULL) {
        if(isValidNumber(nivelStr) == 0) {
            auxNivel = atoi(nivelStr);
            if(vendedor_setNivel(this, auxNivel) == 0) {
                ret = 0;
            }
        }
    }
    return ret;
}

int vendedor_setNivel(Vendedor* this,int nivel) {
    int ret = -1;
    if(this != NULL && nivel >= 0) {
      this->nivel = nivel;
      ret = 0;
    }
    return ret;
}

int vendedor_getNivel(Vendedor* this,int* nivel) {
    int ret = -1;
    if(this != NULL && nivel != NULL) {
      *nivel = this->nivel;
      ret = 0;
    }
    return ret;
}

int vendedor_setCantidad_ventasStr(Vendedor* this,char* cantidad_ventasStr) {
    int ret = -1;
    int auxCantidad_ventas;
    if(this != NULL && cantidad_ventasStr != NULL) {
        if(isValidNumber(cantidad_ventasStr) == 0) {
            auxCantidad_ventas = atoi(cantidad_ventasStr);
            if(vendedor_setCantidad_ventas(this, auxCantidad_ventas) == 0) {
                ret = 0;
            }
        }
    }
    return ret;
}

int vendedor_setCantidad_ventas(Vendedor* this,int cantidad_ventas) {
    int ret = -1;
    if(this != NULL && cantidad_ventas >= 0) {
      this->cantidad_ventas = cantidad_ventas;
      ret = 0;
    }
    return ret;
}

int vendedor_getCantidad_ventas(Vendedor* this,int* cantidad_ventas) {
    int ret = -1;
    if(this != NULL && cantidad_ventas != NULL) {
      *cantidad_ventas = this->cantidad_ventas;
      ret = 0;
    }
    return ret;
}

int vendedor_setMontoStr(Vendedor* this,char* montoStr) {
    int ret = -1;
    int auxMonto;
    if(this != NULL && montoStr != NULL) {
        if(isValidNumber(montoStr) == 0) {
            auxMonto = atof(montoStr);
            if(vendedor_setMonto(this, auxMonto) == 0) {
                ret = 0;
            }
        }
    }
    return ret;
}

int vendedor_setMonto(Vendedor* this,float monto) {
    int ret = -1;
    if(this != NULL && monto >= 0) {
      this->monto = monto;
      ret = 0;
    }
    return ret;
}

int vendedor_getMonto(Vendedor* this,float* monto) {
    int ret = -1;
    if(this != NULL && monto != NULL) {
      *monto = this->monto;
      ret = 0;
    }
    return ret;
}

int vendedor_setComisionesStr(Vendedor* this,char* comisionesStr) {
    int ret = -1;
    int auxComisiones;
    if(this != NULL && comisionesStr != NULL) {
        if(isValidNumber(comisionesStr) == 0) {
            auxComisiones = atof(comisionesStr);
            if(vendedor_setComisiones(this, auxComisiones) == 0) {
                ret = 0;
            }
        }
    }
    return ret;
}

int vendedor_setComisiones(Vendedor* this,float comisiones) {
    int ret = -1;
    if(this != NULL && comisiones >= 0) {
      this->comisiones = comisiones;
      ret = 0;
    }
    return ret;
}

int vendedor_getComisiones(Vendedor* this,float* comisiones) {
    int ret = -1;
    if(this != NULL && comisiones != NULL) {
      *comisiones = this->comisiones;
      ret = 0;
    }
    return ret;
}















/*







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
}*/
