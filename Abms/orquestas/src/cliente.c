#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int customer_init(Customer array[], int size) {
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

/** \brief Busca el primer lugar vacio en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param position int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int customer_searchEmpty(Customer array[], int size, int* position) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0 && position != NULL) {
        for(i = 0; i < size; i++) {
            if(array[i].isEmpty == 0) {
                retorno = 0;
                *position = i;
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
int customer_searchID(Customer array[], int size, int searchValue, int* position) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0;i < size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else if(array[i].customerCode == searchValue) {
                retorno = 0;
                *position = i;
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
int customer_searchInt(Customer array[], int size, int searchValue, position) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0; i < size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else if(array[i].phone == searchValue) {
                retorno = 0;
                *position = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un string en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int customer_searchString(Customer array[], int size, char* searchValue, int* index) {
    int retorno = -1;
    int i;
    if(array != NULL && size >= 0) {
        for(i = 0; i < size; i++) {
            if(array[i].isEmpty == 0)
                continue;
            else if(strcmp(array[i].sex,searchValue) == 0)
                *index = i;
                retorno = 0;
                break;
        }
    }
    return retorno;
}

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int customer_add(Customer array[], int size, int* countID) {
    int retorno = -1;
    int position;
    if(array != NULL && size > 0 && contadorID != NULL) {
        if(customer_searchEmpty(array,size,&position) == -1) {
            printf("\nNo hay lugares vacios");
        }
        else {
            (*countID)++;
            array[position].customerCode = *countID;
            array[position].isEmpty = 1;
            utn_getTelephone("\n Ingrese un numero de telefono: ","\nError, ingrese un número valido",1,sizeof(int),1,1,1,&array[position].phone);
            utn_getName("Ingrese su nombre\n: ","\nError, ingrese un nombre valido",1,TEXT_SIZE,1,array[position].name);
            utn_getText("Ingrese su apellido\n: ","\nError, ingrese un apellido valido",1,TEXT_SIZE,1,array[position].lastName);
            utn_getSex("Ingrese su sexo (M/F)\n: ","\nError, ingrese un sexo valido",1,1,1,array[position].sex);
            utn_getText("Ingrese su domicilio\n: ","\nError, ingrese un domicilio valido",1,TEXT_SIZE,1,array[position].adress);
            printf("\n Posicion: %d\n Código: %d\n Nombre: %s\n Apellido: %s\n Sexo: %s\n Telefono: %d\n Domicilio:",
                   position, array[position].customerCode,array[position].name,array[position].lastName,array[position].sex,array[position].phone, array[position].adress);
            retorno = 0;
        }
    }
    return retorno;
}

int customer_modify(Customer array[], int size) {
    int retorno = -1;
    int position;
    int id;
    char option;
    if(array != NULL && size > 0) {
        utn_getUnsignedInt("\nCódigo a modificar: ","\nError, ingrese un código valido",1,sizeof(int),1,size,1,&id);
        if(customer_searchID(array,size,id,&position) == -1) {
            printf("\nNo existe este Código de cliente");
        } else {
            do {
            	printf("\n Posicion: %d\n Código: %d\n Nombre: %s\n Apellido: %s\n Sexo: %s\n Telefono: %d\n Domicilio:",
            	                   position, array[position].customerCode,array[position].name,array[position].lastName,array[position].sex,array[position].phone, array[position].adress);
                utn_getChar("\nModificar: A B C S(salir)","\nError, ingrese una opción valida",'A','Z',1,&option);
                switch(option) {
                    case 'A':
                        utn_getName("\n Ingrese nombre: ","\nError, ingrese un nombre valido",1,TEXT_SIZE,1,array[position].name);
                        break;
                    case 'B':
                        utn_getText("\n Ingrese domicilio: ","\nError, ingrese un domicilio valido",1,TEXT_SIZE,1,array[position].adress);
                        break;
                    case 'C':
                    	utn_getTelephone("\n Ingrese un numero de telefono: ","\nError, ingrese un número valido",1,sizeof(int),1,1,1,&array[position].phone);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(option != 'S');
            retorno = 0;
        }
    }
    return retorno;
}
