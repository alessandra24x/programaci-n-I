#include "logs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"

LogEntry* logEntry_new() { //reservo espacio en memoria de manera dinámica para cada LogEntry
	return (LogEntry*)malloc(sizeof(LogEntry));
}

//Construye una nueva LogEntry, le setea los valores y devuelve un puntero de tipo void
LogEntry* logEntry_newParametros(char* date,char* time,char* serviceIdStr, char* gravedadStr, char* msg) {
	LogEntry* aux;
	aux = logEntry_new();
	if(aux != NULL) {
		int setDate = logEntry_setDate(aux, date);
		int setTime = logEntry_setTime(aux, time);
		int setServiceId = logEntry_setServiceIdStr(aux, serviceIdStr);
		int setGravedad = logEntry_setGravedadStr(aux, gravedadStr);
		int setMsg = logEntry_setMsg(aux, msg);

		if (setDate != 0) {
		  printf("Problema al cargar date\n");
		  return NULL;
		}

		if (setTime != 0) {
		  printf("Problema al cargar time\n");
		  return NULL;
		}

		if (setServiceId != 0) {
		  printf("Problema al cargar serviceId\n");
		  return NULL;
		}

		if (setGravedad != 0) {
		  printf("Problema al cargar gravedad\n");
		  return NULL;
		}

		if (setMsg != 0) {
			printf("Problema al cargar msg");
			return NULL;
		}
	}
	return aux;
}

int logEntry_delete(LogEntry* this) {
	int ret = -1;
	if(this != NULL) {
		free(this);
		ret = 0;
	}
	return ret;
}

int logEntry_setDate(LogEntry* this,char* date) {
    int ret = -1;
    if(this != NULL) {
        strncpy(this->date, date, sizeof(this->date));
        ret = 0;
    }
    return ret;
}

int logEntry_getDate(LogEntry* this,char* date) {
    int ret = -1;
    if(this != NULL && date != NULL) {
        strcpy(date,this->date);
        ret = 0;
    }
    return ret;
}

int logEntry_setTime(LogEntry* this,char* time) {
    int ret = -1;
    if(this != NULL) {
      strncpy(this->time,time,sizeof(this->time));
      ret = 0;
    }
    return ret;
}

int logEntry_getTime(LogEntry* this,char* time) {
    int ret = -1;
    if(this != NULL && time != NULL) {
      strcpy(time,this->time);
      ret = 0;
    }
    return ret;
}

int logEntry_setServiceIdStr(LogEntry* this,char* serviceIdStr) {
  int ret = -1;
  int auxServiceId;

  if(this != NULL && serviceIdStr != NULL) {
	  if(isValidNumber(serviceIdStr) == 0) {
		  auxServiceId = atoi(serviceIdStr);
		  if(logEntry_setServiceId(this, auxServiceId) == 0) {
			  ret = 0;
		  }
	  }
  }
  return ret;
}

int logEntry_setServiceId(LogEntry* this,int serviceId) {
    int ret = -1;
    if(this != NULL && serviceId >= 0) {
      this->serviceId = serviceId;
      ret = 0;
    }
    return ret;
}

int logEntry_getServiceId(LogEntry* this,int* serviceId) {
    int ret = -1;
    if(this != NULL && serviceId != NULL) {
      *serviceId = this->serviceId;
      ret = 0;
    }
    return ret;
}

int logEntry_setGravedadStr(LogEntry* this,char* gravedadStr) {
  int ret = -1;
  int auxGravedad;

  if(this != NULL && gravedadStr != NULL) {
	  if(isValidNumber(gravedadStr) == 0) {
		  auxGravedad = atoi(gravedadStr);
		  if(logEntry_setGravedad(this, auxGravedad) == 0) {
			  ret = 0;
		  }
	  }
  }
  return ret;
}

int logEntry_setGravedad(LogEntry* this,int gravedad) {
    int ret = -1;
    if(this != NULL && gravedad >= 0) {
      this->gravedad = gravedad;
      ret = 0;
    }
    return ret;
}

int logEntry_getGravedad(LogEntry* this,int* gravedad) {
    int ret = -1;
    if(this != NULL && gravedad != NULL) {
      *gravedad = this->gravedad;
      ret = 0;
    }
    return ret;
}

int logEntry_setMsg(LogEntry* this,char* msg) {
    int ret = -1;
    if(this != NULL) {
      strncpy(this->msg,msg,sizeof(this->msg));
      ret = 0;
    }
    return ret;
}

int logEntry_getMsg(LogEntry* this,char* msg) {
    int ret = -1;
    if(this != NULL && msg != NULL) {
      strcpy(msg,this->msg);
      ret = 0;
    }
    return ret;
}

int filtrarGravedad(void* pLogEntry) {
	LogEntry* log = (LogEntry*) pLogEntry;
	int returnAux = -1;
	int gravedad, serviceId;

	if(pLogEntry != NULL) {
		gravedad = log->gravedad;
		serviceId = log->serviceId;
		if(gravedad == 3 && serviceId != 45) {
			returnAux = 0;
		}
	}
	return returnAux;
}











/*
int filtrar(void* plogEntry) {
	logEntry* bk = (logEntry*) plogEntry;
	int returnAux = -1;
	char tipo[64];

	if(plogEntry != NULL) {
		strcpy(tipo, bk->tipo);
		if(strcmp(tipo, "BMX")) {
			returnAux = 0;
		}
	}
	return returnAux;
}

int logEntry_compareTipo(void* pTipoA,void* pTipoB) {
	int ret = 0;
	if(strcmp(((logEntry*)pTipoA)->tipo,((logEntry*)pTipoB)->tipo) > 0) {
		ret = 1;
	}
	if(strcmp(((logEntry*)pTipoA)->tipo,((logEntry*)pTipoB)->tipo) < 0) {
		ret = -1;
	}
	if(strcmp(((logEntry*)pTipoA)->tipo,((logEntry*)pTipoB)->tipo) == 0) {
		ret = logEntry_compareTiempo(((logEntry*)pTipoA)->tiempo,((logEntry*)pTipoB)->tiempo);
	}

	return ret;
}

int logEntry_compareTiempo(int tiempoA, int tiempoB) {
	int ret = 0;
	if(tiempoA  > tiempoB) {
		ret = 1;
	}

	if(tiempoA < tiempoB) {
		ret = -1;
	}

	return ret;
}
*/
