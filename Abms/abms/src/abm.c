#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "abm.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array fantasma Array of fantasma
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int inicializar(Fantasma array[], int size) {
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

//*****************************************
/**
 * Inicializo el segundo array
 */
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

//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int fantasma_buscarEmpty(Fantasma array[], int size, int* posicion) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0 && posicion != NULL) {
        for(i = 0;i < size; i++) {
            if(array[i].isEmpty == 0) {
                retorno = 0;
                *posicion = i;
                break;
            }
        }
    }
    return retorno;
}
/**
 * BuscarEmpty del segundo array
 */
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

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarID(Fantasma array[], int size, int valorBuscado, int* posicion) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0;i < size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else if(array[i].idUnico == valorBuscado) {
                retorno = 0;
                *posicion = i;
                break;
            }
        }
    }
    return retorno;
}
/**
 * BuscarId del segundo array
 */
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

/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarInt(Fantasma array[], int size, int valorBuscado, int* posicion) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0; i < size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else if(array[i].varInt == valorBuscado) { //cambiar campo varInt
                retorno = 0;
                *posicion = i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarString(Fantasma array[], int size, char* valorBuscado, int* indice) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0; i < size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else if(strcmp(array[i].varString,valorBuscado) == 0) //cambiar campo varString
                *indice = i;
                retorno = 0;
                break;
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

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int fantasma_alta(Fantasma array[], int size, int* contadorID) {
    int retorno = -1;
    int posicion;
    if(array != NULL && size > 0 && contadorID != NULL) {
        if(fantasma_buscarEmpty(array,size,&posicion) == -1) {
            printf("\nNo hay lugares vacios");
        }
        else {
            (*contadorID)++;
            array[posicion].idUnico = *contadorID; //campo ID
            array[posicion].isEmpty = 1;
            utn_getUnsignedInt("\ngetUnsignedInt: ","\nError",1,sizeof(int),1,1,1,&array[posicion].varInt); //mensaje + cambiar campo varInt
            utn_getFloat("\ngetFloat: ","\nError",1,10,0,1,1,&array[posicion].varFloat);  //mensaje + cambiar campo varFloat
            utn_getName("getName\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);  //mensaje + cambiar campo varString
            utn_getTexto("getTexto\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString); //mensaje + cambiar campo varLongString
            printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                   posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * Alta de datos del segundo array
 */
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

//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_baja(Fantasma array[], int sizeArray) {
    int retorno = -1;
    int posicion;
    int id;
    if(array != NULL && sizeArray > 0) {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(fantasma_buscarID(array,sizeArray,id,&posicion) == -1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else {
            array[posicion].isEmpty = 0;
            array[posicion].idUnico = 0;                                                                   //cambiar campo id
            array[posicion].varInt = 0;                                                               //cambiar campo varInt
            array[posicion].varFloat = 0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].varString,"");                                                   //cambiar campo varString
            strcpy(array[posicion].varLongString,"");                                               //cambiar campo varLongString
            retorno = 0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_bajaValorRepetidoInt(Fantasma array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno = -1;
    int i;
    if(array != NULL && sizeArray > 0) {
        for(i = 0; i < sizeArray; i++) {
            if(array[i].idUnico == valorBuscado)  //cambiar si no se busca por ID
            {
                array[i].isEmpty = 0;
                array[i].idUnico = 0;                                                                   //cambiar campo id
                array[i].varInt = 0;                                                               //cambiar campo varInt
                array[i].varFloat = 0;                                                             //cambiar campo varFloat
                strcpy(array[i].varString,"");                                                   //cambiar campo varString
                strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno = 0;
    }
    return retorno;
}

//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int fantasma_modificar(Fantasma array[], int sizeArray) {
    int retorno = -1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array != NULL && sizeArray > 0) {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(fantasma_buscarID(array,sizeArray,id,&posicion) == -1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else {
            do {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion) {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        utn_getFloat("\n: ","\nError",1,10,0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);             //mensaje + cambiar campo varLongString
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

//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/

/** \brief Ordena los elementos del array primeramente por apellido, como segundo criterio por sector
* \param Employee* list es el array de la estructura Employee
* \param int len es la longitud del array
* \return Esta función devuelve -1 si hay algún error [Invalid length or NULL pointer], 0 si está OK.
*/
int sort(Fantasma* list, int len) {
  int retorno = -1;
  int i, j;
  Employee bufferList;

  if(list != NULL && len >= 0) {
    for(i = 0; i < len; i++) {
      for(j = i+1; j < len; j++) {
        if(strcmp(list[i].lastName, list[j].lastName) > 0) {
          bufferList = list[i];
          list[i] = list[j];
          list[j] = bufferList;
          } else if(strcmp(list[i].lastName, list[j].lastName) == 0) {
            if(list[i].sector > list[j].sector) {
              bufferList = list[i];
              list[i] = list[j];
              list[j] = bufferList;
              }
            }
          }
        }
        retorno = 0;
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

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int fantasma_listar(Fantasma array[], int size) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0; i < size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else
                printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);      //cambiar todos
        }
        retorno = 0;
    }
    return retorno;
}
/**
 * Listar por cuit
 */
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

/**
 * funcion para copiar datos y no tener que andar probando
 */

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
            publicidad_calcularFacturacion(arrayPantalla, sizePantalla, arrayPublicidad, sizePublicidad,vCuit, contadorContratacionesPorCuit);
                retorno = 0;
        }
    }
    return retorno;
}

int publicidad_calcularFacturacion(Pantalla arrayPantalla[],int sizePantalla,Publicidad arrayPublicidad[],int sizePublicidad,char* aCuit, int *cantidadContrataciones) {
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

            printf("\nPagar %d por pantalla %d ", total, arrayPublicidad[i].idPantalla);
            retorno = 0;
        }
    }
  }
    *cantidadContrataciones = aux;
    return retorno;
}

/** \brief Valida que el array este vacio o con datos ya cargados
 * \param list Employee*
 * \param length int
 * \return Esta función devuelve -1 si el array ya contiene data, 0 si está vacio.
 */
int validateData(Employee* list, int len) {
    int retorno;
    int i;
    if(list != NULL && len >= 0) {
        for(i = 0; i < len; i++) {
            if(list[i].isEmpty == 1) {
                retorno = 0;
                break;
            } else {
            	retorno = -1;

            }
        }
    }
    return retorno;
}
