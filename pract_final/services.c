#include "services.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"

Service* service_new() { //reservo espacio en memoria de manera dinámica para cada Service
	return (Service*)malloc(sizeof(Service));
}

//Construye una nueva Service, le setea los valores y devuelve un puntero de tipo void
Service* service_newParametros(char* idStr, char* name, char* email) {
	Service* aux;
	aux = service_new();
	if(aux != NULL) {
		int setId = service_setIdStr(aux, idStr);
		int setName = service_setName(aux, name);
		int setEmail = service_setEmail(aux, email);

		if (setId != 0) {
		  printf("Problema al cargar id\n");
		  return NULL;
		}

		if (setName != 0) {
		  printf("Problema al cargar nombre\n");
		  return NULL;
		}

		if (setEmail != 0) {
		  printf("Problema al cargar email\n");
		  return NULL;
		}
	}
	return aux;
}

int service_delete(Service* this) {
	int ret = -1;
	if(this != NULL) {
		free(this);
		ret = 0;
	}
	return ret;
}

int service_setIdStr(Service* this,char* idStr) {
  int ret = -1;
  int auxId;

  if(this != NULL && idStr != NULL) {
	  if(isValidNumber(idStr) == 0) {
		  auxId = atoi(idStr);
		  if(service_setId(this, auxId) == 0) {
			  ret = 0;
		  }
	  }
  }
  return ret;
}

int service_setId(Service* this,int id) {
    int ret = -1;
    if(this != NULL && id >= 0) {
      this->id = id;
      ret = 0;
    }
    return ret;
}

int service_getId(Service* this,int* id) {
    int ret = -1;
    if(this != NULL && id != NULL) {
      *id = this->id;
      ret = 0;
    }
    return ret;
}

int service_setName(Service* this,char* name) {
    int ret = -1;
    if(this != NULL) {
      strncpy(this->name,name,sizeof(this->name));
      ret = 0;
    }
    return ret;
}

int service_getName(Service* this,char* name) {
    int ret = -1;
    if(this != NULL && name != NULL) {
      strcpy(name,this->name);
      ret = 0;
    }
    return ret;
}

int service_setEmail(Service* this,char* email) {
    int ret = -1;
    if(this != NULL) {
      strncpy(this->email,email,sizeof(this->email));
      ret = 0;
    }
    return ret;
}

int service_getEmail(Service* this,char* email) {
    int ret = -1;
    if(this != NULL && email != NULL) {
      strcpy(email,this->email);
      ret = 0;
    }
    return ret;
}












