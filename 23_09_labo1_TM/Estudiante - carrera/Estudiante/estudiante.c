#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "estudiante.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array estudiante Array of estudiante
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int estudiante_Inicializar(eEstudiante array[], int size)                                    //cambiar estudiante
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            array[i].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array estudiante Array de estudiante
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int estudiante_buscarEmpty(eEstudiante array[], int size, int* posicion)                    //cambiar estudiante
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array estudiante Array de estudiante
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int estudiante_buscarID(eEstudiante array[], int size, int valorBuscado, int* posicion)                    //cambiar estudiante
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idEstudiante==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array estudiante Array de estudiante
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int estudiante_buscarInt(eEstudiante array[], int size, int valorBuscado, int* posicion)                    //cambiar estudiante
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].edad==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array estudiante Array de estudiante
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int estudiante_buscarString(eEstudiante array[], int size, char* valorBuscado, int* indice)                    //cambiar estudiante
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array estudiante Array de estudiante
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int estudiante_alta(eEstudiante array[], int size, int* contadorID)                          //cambiar estudiante
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(estudiante_buscarEmpty(array,size,&posicion)==-1)                          //cambiar estudiante
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idEstudiante=*contadorID;                                                       //campo ID
            utn_getUnsignedInt("\nIngrese edad entre 18 y 100: ","\nError ingreso edad",1,sizeof(int),18,100,2,&array[posicion].edad);
            utn_getName("getName\n: ","\nError nombre",1,TEXT_SIZE,2,array[posicion].nombre);                      //mensaje + cambiar campo varString
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nIngrese carrera entre 1 y 2: ","\nError ingreso carrera",1,sizeof(int),1,2,2,&array[posicion].idCarrera);


            //printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
            //       posicion, array[posicion].idEstudiante,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array estudiante Array de estudiante
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int estudiante_baja(eEstudiante array[], int sizeArray)                                      //cambiar estudiante
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(estudiante_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idEstudiante=0;
            array[posicion].idCarrera=0;                                                                   //cambiar campo id
            array[posicion].edad=0;                                                               //cambiar campo varInt
            //array[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo varString
            //strcpy(array[posicion].varLongString,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array estudiante Array de estudiante
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int estudiante_bajaValorRepetidoInt(eEstudiante array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idEstudiante==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idEstudiante=0;                                                                   //cambiar campo id
                array[i].edad=0;                                                               //cambiar campo varInt
                //array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo varString
                //strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array estudiante Array de estudiante
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int estudiante_modificar(eEstudiante array[], int sizeArray)                                //cambiar estudiante
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(estudiante_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                //printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                //       posicion, array[posicion].idEstudiante,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);

                utn_getChar("\nModificar: \nA-Nombre \nB-Edad \nS(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nIngrese el nuevo nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
                        //utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        utn_getUnsignedInt("\nIngrese la nueva edad: ","\nError",1,sizeof(int),18,100,2,&array[posicion].edad);           //mensaje + cambiar campo varInt
                        //utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;
                   /* case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);             //mensaje + cambiar campo varLongString
                        break;*/
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array estudiante Array de estudiante
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int estudiante_ordenarPorString(eEstudiante array[],int size)                              //cambiar estudiante
{

    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo varString
    int bufferId;
    int bufferIsEmpty;
    int bufferInt;                                              //cambiar buffer int
    int bufferCarrera;
    //float bufferFloat;                                          //cambiar buffer varFloat
    //char bufferLongString[TEXT_SIZE];                           //cambiar campo varLongString

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].nombre);                      //cambiar campo varString
            bufferId=array[i].idEstudiante;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;
            bufferInt=array[i].edad;                                //cambiar campo varInt
            bufferCarrera=array[i].idCarrera;
            //bufferFloat=array[i].varFloat;                            //cambiar campo varFloat
            //strcpy(bufferLongString,array[i].varLongString);          //cambiar campo varLongString


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].nombre)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].nombre,array[j].nombre);          //cambiar campo varString
                array[j + 1].idEstudiante=array[j].idEstudiante;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;
                array[j + 1].edad=array[j].edad;                        //cambiar campo varInt
                array[j + 1].idCarrera=array[j].idCarrera;                        //cambiar campo varInt
                //array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
                //strcpy(array[j + 1].varLongString,array[j].varLongString);  //cambiar campo varLongString

                j--;
            }
            strcpy(array[j + 1].nombre,bufferString);                     //cambiar campo varString
            array[j + 1].idEstudiante=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;
            array[j + 1].edad=bufferInt;                                                        //cambiar campo varInt
            array[j + 1].idCarrera=bufferCarrera;                                                        //cambiar campo varInt
            //array[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            //strcpy(array[j + 1].varLongString,bufferLongString);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array estudiante Array de estudiante
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int estudiante_listar(eEstudiante array[], int size, eCarrera arrayCarrera[], int sizeCarrera)                      //cambiar estudiante
{
    int retorno=-1;
    int i;
    char descCarrera[20];
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            {
                getDescripcionCarrera(arrayCarrera,sizeCarrera,array[i].idCarrera, descCarrera);
                printf("\n ID: %d\n edad: %d\n nombre: %s\n Carrera: %d\n descCarrera %s",
                       array[i].idEstudiante,array[i].edad,array[i].nombre, array[i].idCarrera, descCarrera);      //cambiar todos
            }
        }
        retorno=0;
    }
    return retorno;
}
int getDescripcionCarrera(eCarrera arrayCarrera[], int sizeCarrera, int buscar, char* descripcion)
{
    int i;
    for(i=0;i<sizeCarrera;i++)
    {
        if(arrayCarrera[i].idCarrera==buscar)
        {
            strcpy(descripcion,arrayCarrera[i].descripcionCarrera);
        }
    }
    return 0;
}

