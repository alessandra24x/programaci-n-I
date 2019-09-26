#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array pantalla Array of pantalla
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int pantalla_Inicializar(Pantalla array[], int size)                                    //cambiar pantalla
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}
int publicidad_Inicializar(Publicidad array[], int size)                                    //cambiar pantalla
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}
//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int pantalla_buscarEmpty(Pantalla array[], int size, int* posicion)                    //cambiar pantalla
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

int pantalla_buscarEmptyPublicidad(Publicidad array[], int size, int* posicion)                    //cambiar pantalla
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
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pantalla_buscarID(Pantalla array[], int size, int valorBuscado, int* posicion)                    //cambiar pantalla
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPantalla==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int publicidad_buscarID(Publicidad array[], int size, int valorBuscado, int* posicion)                    //cambiar pantalla
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPantalla==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int publicidad_buscarCUIT(Publicidad array[], int size,char* valorBuscado, int* posicion)                    //cambiar pantalla
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].cuit,valorBuscado)==0)                                                   //cambiar campo ID
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
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*int pantalla_buscarInt(Pantalla array[], int size, int valorBuscado, int* posicion)                    //cambiar pantalla
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
*/
//String
/** \brief Busca un string en un array
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*
int pantalla_buscarString(Pantalla array[], int size, char* valorBuscado, int* indice)                    //cambiar pantalla
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].varString,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
*/
//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int pantalla_alta(Pantalla array[], int size, int* contadorID)                          //cambiar pantalla
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(pantalla_buscarEmpty(array,size,&posicion)==-1)                          //cambiar pantalla
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idPantalla=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getTexto("Tipo Pantalla\n: ","\nError Tipo Pantalla",1,TEXT_TIPO,2,array[posicion].tipo);
            utn_getName("Nombre \n: ","\nError Nombre",1,TEXT_SIZE,2,array[posicion].nombre);
            utn_getTexto("Calle\n: ","\nError Calle",1,TEXT_SIZE,2,array[posicion].calle);
            utn_getFloat("\nPrecio x Dia: ","\nError Precio",1,sizeof(float),0,1,1,&array[posicion].precioDia);             //mensaje + cambiar campo varFloat

            printf("\n Posicion: %d\n ID: %d\n Tipo: %s\n Nombre: %s\n Calle: %s\n varFloat: %2.f",
                   posicion, array[posicion].idPantalla,array[posicion].tipo,array[posicion].nombre,array[posicion].calle,array[posicion].precioDia);
            retorno=0;
        }
    }
    return retorno;
}

//++++++++++++++++++++++++++++++++++++++
int pantalla_contratar(Publicidad array[], int size)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0)
    {
        if(pantalla_buscarEmptyPublicidad(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {

            array[posicion].isEmpty=0;
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


//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int pantalla_baja(Pantalla array[], int sizeArray)                                      //cambiar pantalla
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(pantalla_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idPantalla=0;                                                                   //cambiar campo id
            strcpy(array[posicion].tipo,"");
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].calle,"");
            array[posicion].precioDia=0;
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
/*
int pantalla_bajaValorRepetidoInt(Pantalla array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].varInt=0;                                                               //cambiar campo varInt
                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].varString,"");                                                   //cambiar campo varString
                strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}
*/


//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
/*int pantalla_modificar(Pantalla array[], int sizeArray)                                //cambiar pantalla
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(pantalla_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
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
            retorno=0;
        }
    }
    return retorno;
}
*/
//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
/*
int pantalla_ordenarPorString(Pantalla array[],int size)                              //cambiar pantalla
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo varString
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
    float bufferFloat;                                          //cambiar buffer varFloat
    char bufferLongString[TEXT_SIZE];                           //cambiar campo varLongString

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].varString);                      //cambiar campo varString
            bufferId=array[i].idUnico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].varInt;                                //cambiar campo varInt
            bufferFloat=array[i].varFloat;                            //cambiar campo varFloat
            strcpy(bufferLongString,array[i].varLongString);          //cambiar campo varLongString


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].varString)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].varString,array[j].varString);          //cambiar campo varString
                array[j + 1].idUnico=array[j].idUnico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].varInt=array[j].varInt;                        //cambiar campo varInt
                array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
                strcpy(array[j + 1].varLongString,array[j].varLongString);  //cambiar campo varLongString

                j--;
            }
            strcpy(array[j + 1].varString,bufferString);                     //cambiar campo varString
            array[j + 1].idUnico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].varInt=bufferInt;                                                        //cambiar campo varInt
            array[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            strcpy(array[j + 1].varLongString,bufferLongString);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}
*/
//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int pantalla_listar(Pantalla array[], int size)                      //cambiar pantalla
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            printf("\nID: %d\n Tipo: %s\n Nombre: %s\n Calle: %s\n Precio: %2.f\n",
                   array[i].idPantalla,array[i].tipo,array[i].nombre,array[i].calle,array[i].precioDia);
                //printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                //       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);
        }
        retorno=0;
    }
    return retorno;
}
int publicidad_listar(Publicidad array[], int size)                      //cambiar pantalla
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            printf("\n C.U.I.T: %s\n ID Pantalla: %d\n Cant. Dias: %d\n Archivo: %s",
                   array[i].cuit, array[i].idPantalla,array[i].cantDias,array[i].archivo);
                //printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                //       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);
        }
        retorno=0;
    }
    return retorno;
}

int publicidad_listarPorCuit(Publicidad array[],int size,char* aCuit)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            if(strcmp(array[i].cuit,aCuit)==0)
                {
                    printf("\n C.U.I.T: %s\n ID Pantalla: %d\n Cant. Dias: %d\n Archivo: %s",
                     array[i].cuit, array[i].idPantalla,array[i].cantDias,array[i].archivo);
                }
        }

        retorno=0;
    }
    return retorno;
}

int publicidad_modificar(Publicidad array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int posicionId;
    int idPantalla;
    char vCuit[TEXT_CUIT];                                                                                         //cambiar si no se busca por ID
    if(array!=NULL && sizeArray>0)
    {
        utn_getTexto("\n C.U.I.T a modificar: ","\nError C.U.I.T",1,TEXT_SIZE,2,vCuit);
        if(publicidad_buscarCUIT(array,sizeArray,vCuit,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este CUIT");                                                          //cambiar si no se busca por ID
        }
        else
        {
            publicidad_listarPorCuit(array,sizeArray,vCuit);
            printf("\nIngrese Id de la pantalla a modificar: ");
            scanf("\n%d", &idPantalla);
            fflush(stdin);
            if(publicidad_buscarID(array,sizeArray,idPantalla,&posicionId)==0)
            {
                utn_getUnsignedInt("Modificar Cantidad Dias: ","\nError Modificar Cantidad Dias",1,sizeArray,1,sizeArray,2,&array[posicionId].cantDias);
                retorno=0;
            }
        }
    }
    return retorno;
}
int publicidad_consultaFacturacion(Pantalla arrayPantalla[],int sizePantalla,Publicidad arrayPublicidad[],int sizePublicidad)
{
    int retorno=-1;
    int posicion;
    //int posicionId;
    //int idPantalla;
    char vCuit[TEXT_CUIT];
                                                                                         //cambiar si no se busca por ID
    if(arrayPublicidad!=NULL && sizePublicidad>0)
    {
        utn_getTexto("\n C.U.I.T a consultar: ","\nError C.U.I.T",1,TEXT_SIZE,2,vCuit);
        if(publicidad_buscarCUIT(arrayPublicidad,sizePublicidad,vCuit,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este CUIT");                                                          //cambiar si no se busca por ID
        }
        else
        {
            publicidad_calcularFacturacion(arrayPantalla, sizePantalla, arrayPublicidad, sizePublicidad,vCuit);
                retorno=0;
        }
    }
    return retorno;
}
int publicidad_calcularFacturacion(Pantalla arrayPantalla[],int sizePantalla,Publicidad arrayPublicidad[],int sizePublicidad,char* aCuit)
{
   int retorno=-1;
    int i;
    int total;
    int posicionPantalla;

    for(i=0; i<sizePublicidad;i++)
    {
        if(strcmp(arrayPublicidad[i].cuit,aCuit)==0)
        {
            pantalla_buscarID(arrayPantalla, sizePantalla,arrayPublicidad[i].idPantalla,&posicionPantalla);
            total=arrayPublicidad[i].cantDias*arrayPantalla[posicionPantalla].precioDia;

            printf("\nPagar %d por pantalla %d ", total, arrayPublicidad[i].idPantalla);
            retorno = 0;
        }
    }
    return retorno;
}
