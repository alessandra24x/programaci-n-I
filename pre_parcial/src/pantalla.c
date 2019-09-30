#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h"

/** \brief Indica que todas las posiciones en el array estan vacias, para eso se pone un FLAG (isEmpty) en TRUE en todas las posiciones del array
* \param array pantalla es el array de la estructura pantalla
* \param int size es la longitud del array
* \return Esta función devuelve -1 si hay algún error [Invalid length or NULL pointer], 0 si está OK.
*/
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
    if(array != NULL && size >= 0 && posicion != NULL) {
        for(i = 0; i<size; i++) {
            if(array[i].isEmpty == 0) {
                retorno = 0;
                *posicion = i;
                break;
            }
        }
    }
    return retorno;
}

int publicidad_buscarEmpty(Publicidad array[], int size, int* posicion) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0 && posicion != NULL) {
        for(i = 0; i < size; i++) {
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

int publicidad_buscarID(Publicidad array[], int size, int valorBuscado, int* posicion) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for( i= 0; i < size; i++) {
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

int publicidad_buscarCUIT(Publicidad array[], int size,char* valorBuscado, int* posicion) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0; i < size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else if(strcmp(array[i].cuit,valorBuscado) == 0) {
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
    if(array != NULL && size > 0 && contadorID != NULL) {
        if(pantalla_buscarEmpty(array,size,&posicion) == -1) {
            printf("\nNo hay lugares vacios");
        }
        else {
            (*contadorID)++;
            array[posicion].idPantalla = *contadorID;
            array[posicion].isEmpty = 1;
            utn_getTexto("Tipo Pantalla\n: ","\nError Tipo Pantalla",1,TEXT_TIPO,2,array[posicion].tipo);
            utn_getName("Nombre \n: ","\nError Nombre",1,TEXT_SIZE,2,array[posicion].nombre);
            utn_getTexto("Calle\n: ","\nError Calle",1,TEXT_SIZE,2,array[posicion].direccion);
            utn_getFloat("\nPrecio x Dia: ","\nError Precio",1,sizeof(float),0,1,1,&array[posicion].precioPorDia);
            printf("\n PANTALLA DADA DE ALTA");
            retorno = 0;
        }
    }
    return retorno;
}

int pantalla_contratar(Publicidad array[], int size)
{
    int retorno = -1;
    int posicion;
    if(array != NULL && size > 0) {
        if(publicidad_buscarEmpty(array,size,&posicion) == -1) {
            printf("\nNo hay lugares vacios");
        }
        else {
            array[posicion].isEmpty = 0;
            utn_getTexto("C.U.I.T\n: ","\nError C.U.I.T",1,TEXT_SIZE,2,array[posicion].cuit);
            utn_getUnsignedInt("ID Pantalla\n: ","\nError ID Pantalla",1,size,1,size,2,&array[posicion].idPantalla);
            utn_getUnsignedInt("Cantidad Dias\n: ","\nError Cantidad Dias",1,size,1,size,2,&array[posicion].cantDias);
            utn_getTexto("Archivo\n: ","\nError Archivo",1,TEXT_TIPO,2,array[posicion].archivo);

            printf("\n C.U.I.T: %s\n ID Pantalla: %d\n Cant. Dias: %d\n Archivo: %s",
                   array[posicion].cuit, array[posicion].idPantalla,array[posicion].cantDias,array[posicion].archivo);
            retorno=0;
        }
    }
    return retorno;
}

int pantalla_baja(Pantalla array[], int sizeArray) {
    int retorno = -1;
    int posicion;
    int id;
    if(array != NULL && sizeArray > 0) {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(pantalla_buscarID(array,sizeArray,id,&posicion) == -1) {
            printf("\nNo existe este ID");
        }
        else {
            array[posicion].isEmpty = 0;
            array[posicion].idPantalla = 0;
            strcpy(array[posicion].tipo,"");
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].direccion,"");
            array[posicion].precioPorDia = 0;
            retorno=0;
        }
    }
    return retorno;
}

int pantalla_listar(Pantalla array[], int size) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0; i<size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else
            	printf("\nID: %d\n Tipo: %s\n Nombre: %s\n Dirección: %s\n Precio: %2.f\n",
            	                   array[i].idPantalla,array[i].tipo,array[i].nombre,array[i].direccion,array[i].precioPorDia);
                //printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                //       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);
        }
        retorno = 0;
    }
    return retorno;
}

int publicidad_listar(Publicidad array[], int size) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0; i < size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else
            printf("\n C.U.I.T: %s\n ID Pantalla: %d\n Cant. Dias: %d\n Archivo: %s",
                   array[i].cuit, array[i].idPantalla,array[i].cantDias,array[i].archivo);
                //printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                //       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);
        }
        retorno = 0;
    }
    return retorno;
}

int publicidad_listarPorCuit(Publicidad array[],int size,char* aCuit) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0; i < size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else
            if(strcmp(array[i].cuit,aCuit) == 0) {
                    printf("\n C.U.I.T: %s\n ID Pantalla: %d\n Cant. Dias: %d\n Archivo: %s",
                     array[i].cuit, array[i].idPantalla,array[i].cantDias,array[i].archivo);
                }
        }

        retorno = 0;
    }
    return retorno;
}

int publicidad_modificar(Publicidad array[], int sizeArray) {
    int retorno = -1;
    int posicion;
    int posicionId;
    int idPantalla;
    char vCuit[TEXT_CUIT];                                                                                         //cambiar si no se busca por ID
    if(array != NULL && sizeArray > 0) {
        utn_getTexto("\n C.U.I.T a modificar: ","\nError C.U.I.T",1,TEXT_SIZE,2,vCuit);
        if(publicidad_buscarCUIT(array,sizeArray,vCuit,&posicion) == -1) {
            printf("\nNo existe este CUIT");
        }
        else {
            publicidad_listarPorCuit(array,sizeArray,vCuit);
            printf("\nIngrese Id de la pantalla a modificar: ");
            scanf("\n%d", &idPantalla);
            fflush(stdin);
            if(publicidad_buscarID(array,sizeArray,idPantalla,&posicionId) == 0)
            {
                utn_getUnsignedInt("Modificar Cantidad Dias: ","\nError Modificar Cantidad Dias",1,sizeArray,1,sizeArray,2,&array[posicionId].cantDias);
                retorno = 0;
            }
        }
    }
    return retorno;
}

int publicidad_consultaFacturacion(Pantalla arrayPantalla[],int sizePantalla,Publicidad arrayPublicidad[],int sizePublicidad) {
    int retorno = -1;
    int posicion;
    //int posicionId;
    //int idPantalla;
    char vCuit[TEXT_CUIT];

    if(arrayPublicidad != NULL && sizePublicidad > 0) {
        utn_getTexto("\n C.U.I.T a consultar: ","\nError C.U.I.T",1,TEXT_SIZE,2,vCuit);
        if(publicidad_buscarCUIT(arrayPublicidad,sizePublicidad,vCuit,&posicion) == -1) {
            printf("\nNo existe este CUIT");                                                          //cambiar si no se busca por ID
        } else {
            publicidad_calcularFacturacion(arrayPantalla, sizePantalla, arrayPublicidad, sizePublicidad,vCuit);
                retorno = 0;
        }
    }
    return retorno;
}

int publicidad_calcularFacturacion(Pantalla arrayPantalla[],int sizePantalla,Publicidad arrayPublicidad[],int sizePublicidad,char* aCuit) {
   int retorno = -1;
    int i;
    int total;
    int posicionPantalla;

    for(i = 0; i < sizePublicidad; i++) {
        if(strcmp(arrayPublicidad[i].cuit,aCuit) == 0) {
            pantalla_buscarID(arrayPantalla, sizePantalla,arrayPublicidad[i].idPantalla,&posicionPantalla);
            total = arrayPublicidad[i].cantDias  * arrayPantalla[posicionPantalla].precioPorDia;

            printf("\nPagar %d por pantalla %d ", total, arrayPublicidad[i].idPantalla);
            retorno = 0;
        }
    }
    return retorno;
}
