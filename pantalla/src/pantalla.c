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
            utn_getTexto("Tipo Pantalla\n: ","\nError Tipo Pantalla",1,TEXT_TIPO,2,array[posicion].direccion);
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
            array[posicion].isEmpty = 1;
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

int pantalla_modificar(Pantalla array[], int sizeArray) {
    int retorno = -1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array != NULL && sizeArray > 0) {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(pantalla_buscarID(array,sizeArray,id,&posicion) == -1) {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else {
            do {       //copiar printf de alta
            	printf("\nID: %d\n Tipo: %s\n Nombre: %s\n Dirección: %s\n Precio: %2.f\n",
            			array[posicion].idPantalla,array[posicion].tipo,array[posicion].nombre,array[posicion].direccion,array[posicion].precioPorDia);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getTexto("\nTipo: ","\nError",1,TEXT_SIZE,1,array[posicion].tipo);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                    	utn_getName("Nombre \n: ","\nError Nombre",1,TEXT_SIZE,2,array[posicion].nombre);             //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                    	utn_getFloat("\nPrecio x Dia: ","\nError Precio",1,sizeof(float),0,1,1,&array[posicion].precioPorDia);                      //mensaje + cambiar campo varString
                        break;
                    case 'D':
                        utn_getTexto("\nDireccion: ","\nError",1,TEXT_SIZE,1,array[posicion].direccion);             //mensaje + cambiar campo varLongString
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno = 0;
        }
    }
    return retorno;
}

int pantalla_ordenarPorString(Pantalla array[],int size) {
    int retorno = -1;
    int i, j;
    char bufferTipo[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;
    char bufferNombre[TEXT_SIZE];
    float bufferPrecioPorDia;
    char bufferDireccion[TEXT_SIZE];
    if(array != NULL && size >= 0) {
        for (i = 1; i < size; i++) {
            strcpy(bufferTipo,array[i].tipo);                      //cambiar campo varString
            bufferId=array[i].idPantalla;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;
            strcpy(bufferNombre,array[i].nombre);                                //cambiar campo varInt
            bufferPrecioPorDia=array[i].precioPorDia;                            //cambiar campo varFloat
            strcpy(bufferDireccion,array[i].direccion);          //cambiar campo varLongString
            j = i - 1;
            while ((j >= 0) && strcmp(bufferNombre,array[j].nombre) < 0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].tipo,array[j].tipo);          //cambiar campo varString
                array[j + 1].idPantalla=array[j].idPantalla;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;
                strcpy(array[j + 1].nombre,array[j].nombre);                        //cambiar campo varInt
                array[j + 1].precioPorDia=array[j].precioPorDia;                    //cambiar campo varFloat
                strcpy(array[j + 1].direccion,array[j].direccion);  //cambiar campo varLongString
                j--;
            }
            strcpy(array[j + 1].tipo,bufferTipo);                     //cambiar campo varString
            array[j + 1].idPantalla=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;
            strcpy(array[j + 1].nombre,bufferNombre);                                                        //cambiar campo varInt
            array[j + 1].precioPorDia=bufferPrecioPorDia;                                                   //cambiar campo varFloat
                                                  //cambiar campo varFloat
            strcpy(array[j + 1].direccion,bufferDireccion);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}

int publicidad_ordenarPorCuit(Publicidad array[],int size) {
  int retorno = -1;
  int i, j;
  Publicidad bufferCuit;

  if(array != NULL && size >= 0) {
    for(i = 0; i < size; i++) {
      for(j = i+1; j < size; j++) {
        if(strcmp(array[i].cuit, array[j].cuit) > 0) {
          bufferCuit = array[i];
          array[i] = array[j];
          array[j] = bufferCuit;
          }
        }
      }
      retorno = 0;
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
            printf("\n C.U.I.T: %s\n ID Pantalla: %d\n Cant. Dias: %d\n Archivo: %s\n",
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
                    printf("\n C.U.I.T: %s\n ID Pantalla: %d\n Cant. Dias: %d\n Archivo: %s\n",
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
    int contadorPublicacionesPorCuit = 0;
    //int posicionId;
    //int idPantalla;
    char vCuit[TEXT_CUIT];

    if(arrayPublicidad != NULL && sizePublicidad > 0) {
        utn_getTexto("\n C.U.I.T a consultar: ","\nError C.U.I.T",1,TEXT_SIZE,2,vCuit);
        if(publicidad_buscarCUIT(arrayPublicidad,sizePublicidad,vCuit,&posicion) == -1) {
            printf("\nNo existe este CUIT");                                                          //cambiar si no se busca por ID
        } else {
            publicidad_calcularFacturacion(arrayPantalla, sizePantalla, arrayPublicidad, sizePublicidad,vCuit, &contadorPublicacionesPorCuit);
                retorno = 0;
        }
    }
    return retorno;
}

int publicidad_calcularFacturacion(Pantalla arrayPantalla[],int sizePantalla,Publicidad arrayPublicidad[],int sizePublicidad,char* aCuit, int *contadorPublicaciones) {
    int retorno = -1;
    int i;
    int total;
    int posicionPantalla;
    int aux = 0;

  if(arrayPublicidad !=NULL && sizePublicidad > 0) {
    for(i = 0; i < sizePublicidad; i++) {
        if(strcmp(arrayPublicidad[i].cuit,aCuit) == 0) {
            aux++;
            pantalla_buscarID(arrayPantalla, sizePantalla,arrayPublicidad[i].idPantalla,&posicionPantalla);
            total = arrayPublicidad[i].cantDias  * arrayPantalla[posicionPantalla].precioPorDia;

            printf("\nPagar %d por pantalla %d ",total, arrayPublicidad[i].idPantalla);
            retorno = 0;
        }
    }
  }
    *contadorPublicaciones = aux;
    return retorno;
}

void setPantalla(Pantalla arrayPantalla[], int buscarEmpty, int idPantallAux, char tipoAux[], char nombreAux[], float precioPorDiaAux, char direccionAux[]) {
  arrayPantalla[buscarEmpty].idPantalla = idPantallAux;
  strcpy(arrayPantalla[buscarEmpty].tipo, tipoAux);
  strcpy(arrayPantalla[buscarEmpty].nombre, nombreAux);
  arrayPantalla[buscarEmpty].precioPorDia = precioPorDiaAux;
  strcpy(arrayPantalla[buscarEmpty].direccion, direccionAux);
  arrayPantalla[buscarEmpty].isEmpty = 1;
}

void setPublicidad(Publicidad arrayPublicidad[], int buscarEmpty,char cuitAux[],int idPantallaAux, int cantDiasAux, char archivoAux[]) {
  strcpy(arrayPublicidad[buscarEmpty].cuit, cuitAux);
  arrayPublicidad[buscarEmpty].idPantalla = idPantallaAux;
  arrayPublicidad[buscarEmpty].cantDias = cantDiasAux;
  strcpy(arrayPublicidad[buscarEmpty].archivo, archivoAux);
  arrayPublicidad[buscarEmpty].isEmpty = 1;
}
