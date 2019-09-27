#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h"

int inicializar(Pantalla array[], int size) {
    int retorno = -1;
    int i;
    if(array != NULL && size > 0) {
        for(i = 0; i < size; i++) {
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int publicidad_Inicializar(Publicidad array[], int size) {
    int retorno = -1;
    int i;
    if(array !=  NULL && size > 0) {
        for(i = 0; i < size; i++) {
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}


int pantalla_buscarEmpty(Pantalla array[], int size, int* posicion) {
    int retorno = -1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty == 0)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int publicidad_buscarEmpty(Publicidad array[], int size, int* posicion) {
    int retorno = -1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL) {
        for(i=0;i<size;i++) {
            if(array[i].isEmpty == 0) {
                retorno = 0;
                *posicion = i;
                break;
            }
        }
    }
    return retorno;
}

int pantalla_buscarID(Pantalla array[], int size, int valorBuscado, int* posicion) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0; i < size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else if(array[i].idPantalla == valorBuscado) {
                retorno = 0;
                *posicion = i;
                break;
            }
        }
    }
    return retorno;
}

int pantalla_alta(Pantalla array[], int size, int* contadorID) {
    int retorno = -1;
    int posicion;
    if(array != NULL && size > 0 && contadorID != NULL)
    {
        if(pantalla_buscarEmpty(array,size,&posicion) == -1) {
            printf("\nNo hay lugares vacios");
        }
        else {
            (*contadorID)++;
            array[posicion].idPantalla = *contadorID;
            array[posicion].isEmpty = 1;
            utn_getTexto("Tipo Pantalla\n: ","\nError Tipo Pantalla",1,TEXT_TIPO,2,array[posicion].tipo);
            utn_getName("Nombre \n: ","\nError Nombre",1,TEXT_SIZE,2,array[posicion].nombre);
            //utn_getTexto("Calle\n: ","\nError Calle",1,TEXT_SIZE,2,array[posicion].calle);
            //utn_getFloat("\nPrecio x Dia: ","\nError Precio",1,sizeof(float),0,1,1,&array[posicion].precioDia);
            printf("\n PANTALLA DADA DE ALTA");
            retorno = 0;
        }
    }
    return retorno;
}

int pantalla_listar(Pantalla array[], int size) {
    int retorno = -1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i = 0; i<size; i++)
        {
            if(array[i].isEmpty == 0)
                continue;
            else
            printf("\nID: %d\n Tipo: %s\n Nombre: %s\n",
                   array[i].idPantalla,array[i].tipo,array[i].nombre);
                //printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                //       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);
        }
        retorno = 0;
    }
    return retorno;
}
