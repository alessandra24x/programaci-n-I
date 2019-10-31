#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"
/**
* \brief Solicita un texto al usuario y lo devuelve
* \param msg Mensaje a ser mostrado
* \param msgError Mensaje a ser mostrado en caso de error
* \param min Cantidad minima de elementos que recibirá el string
* \param max Cantidad máxima de elementos que recibirá el string
* \param reintentos Cantidad de reintentos que el usuario tendrá
* \param resultado Array donde se cargará el texto ingresado
* \return 0 si el texto contiene solo letras
*/
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL) {
        do {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max) {
                strncpy(resultado,bufferStr,max);
                retorno = 0;
                break;
            }
            printf("%s",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}

/**
* \brief Solicita un entero al usuario y lo devuelve
* \param msg Mensaje a ser mostrado
* \param msgError Mensaje a ser mostrado en caso de error
* \param minSize cantidad minimo de elementos que tendrá el array
* \param maxSize cantidad máxima de elementos que tendrá el array
* \param min Cantidad minima de elementos que recibirá el string
* \param max Cantidad máxima de elementos que recibirá el string
* \param reintentos Cantidad de reintentos que el usuario tendrá
* \param input Array donde se cargará el texto ingresado
* \return 0 si efectivamente el numero es un entero
*/
int utn_getUnsignedInt(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr) == 0) //==0 sin errores !0
            {
                if(isValidNumber(bufferStr) == 0)
                {
                    *input=atoi(bufferStr);     // unsigned long int strtoul(const char *str, char **end, int base)?
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

/**
* \brief Recibe un string y verifica que esté en el rango numerico del teclado (0-9)
* \param stringRecibido string a verificar
* \return 0 si el string esta en un rango numerico
*/
int isValidNumber(char* stringRecibido) {
    int retorno = 0;
    int i;
    for(i = 0; stringRecibido[i]!='\0'; i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno = 1;
            break;
        }
    }
    return retorno;
}

/**
* \brief Solicita un texto al usuario y lo devuelve
* \param msg Mensaje a ser mostrado
* \param msgError Mensaje a ser mostrado en caso de error
* \param min Cantidad minima de elementos que recibirá el string
* \param max Cantidad máxima de elementos que recibirá el string
* \param reintentos Cantidad de reintentos que el usuario tendrá
* \param resultado Array donde se cargará el texto ingresado
* \return 0 si el texto es un nombre valido
*/
int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[max];

    if(msg != NULL && msgError != NULL && min <= max && reintentos >= 0 && resultado != NULL)
    {
        do
        {
            if(getString(msg,msgError,min,max,&reintentos,bufferStr) == 0) //==0
            {
                if(isValidName(bufferStr) == 0)
                {
                    strncpy(resultado,bufferStr,max);
                    retorno = 0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

/**
* \brief Recibe un string y verifica que esté en un rango del teclado (A-Z, a-z)
* \param stringRecibido string a verificar
* \return 0 si el string esta en un rango valido (A-Z, a-z)
*/
int isValidName(char* stringRecibido) {
    int retorno = 0;
    int i;
    for(i = 0; stringRecibido[i] != '\0'; i++) {
        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z') {
            retorno = 1;
            break;
        }
    }
    return retorno;
}

/**
* \brief Solicita un texto al usuario y lo devuelve
* \param msg Mensaje a ser mostrado
* \param msgError Mensaje a ser mostrado en caso de error
* \param minSize Cantidad minima de elementos que recibirá el string
* \param maxSize Cantidad máxima de elementos que recibirá el string
* \param reintentos Cantidad de reintentos que el usuario tendrá
* \param input Array donde se cargará el texto ingresado
* \return 0 si el texto es un texto valido
*/
int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input) {
    int retorno = -1;
    char bufferStr[maxSize];

    if(msg != NULL && msgError != NULL && minSize < maxSize && reintentos >= 0 && input != NULL) {
        do {
            if(getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr) == 0) {
                if(isValidTexto(bufferStr) == 0) {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

/**
* \brief Recibe un string y verifica que esté en un rango del teclado ("" o > z)
* \param stringRecibido string a verificar
* \return 0 si el string esta en un rango valido ("" o > z)
*/
int isValidTexto(char* stringRecibido) {
    int retorno = 0;
    int i;
    for(i = 0; stringRecibido[i]!='\0'; i++)
    {
        if(stringRecibido[i] < ' ' || stringRecibido[i] > 'z') {
            retorno = 1;
            break;
        }
    }
    return retorno;
}

/**
* \brief Solicita un float al usuario y lo devuelve
* \param msg Mensaje a ser mostrado
* \param msgError Mensaje a ser mostrado en caso de error
* \param minSize cantidad minimo de elementos que tendrá el array
* \param maxSize cantidad máxima de elementos que tendrá el array
* \param min Cantidad minima de elementos que recibirá el string
* \param max Cantidad máxima de elementos que recibirá el string
* \param reintentos Cantidad de reintentos que el usuario tendrá
* \param input Array donde se cargará el float ingresado
* \return 0 si efectivamente el numero es un float
*/
int utn_getFloat(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input) {
    int retorno = -1;
    char bufferStr[maxSize];

    if(msg != NULL && msgError != NULL && minSize < maxSize && min < max && reintentos >= 0 && input != NULL) {
        do {
            if(getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr) == 0) {
                if(isValidFloatNumber(bufferStr) == 0) {
                    *input=atof(bufferStr); // atof array to float
                    retorno=0;
                    break;
                }
                else {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

/**
* \brief Recibe un string y verifica que esté en el rango numerico del teclado
* \param stringRecibido string a verificar
* \return 0 si el string esta en un rango numerico
*/
int isValidFloatNumber(char* stringRecibido)
{
    int retorno = 0;
    int i;
    for(i = 0; stringRecibido[i]!='\0'; i++) {
        if((stringRecibido[i] < '0' || stringRecibido[i] > '9') && (stringRecibido[i] != '.')) {
            retorno = 1;
            break;
        }
    }
    return retorno;
}

/**
* \brief Solicita un texto al usuario y lo devuelve
* \param msg Mensaje a ser mostrado
* \param msgError Mensaje a ser mostrado en caso de error
* \param min Cantidad minima de elementos que recibirá el string
* \param max Cantidad máxima de elementos que recibirá el string
* \param reintentos Cantidad de reintentos que el usuario tendrá
* \param resultado Array donde se cargará el texto ingresado
* \return 0 si el texto es un texto valido
*/
int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado) {
    int retorno = -1;
    char bufferChar[256];

    if(msg != NULL && msgError != NULL && min <= max && reintentos >= 0 && resultado != NULL) {
        do {
            if(getString(msg,msgError,1,3,&reintentos,bufferChar) == 0) {
                if(isValidChar(bufferChar[0]) == 0) {
                    printf("OK");
                    *resultado=bufferChar[0];
                    retorno = 0;
                    break;
                }
                else {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

/**
* \brief Recibe un string y verifica que esté en un rango del teclado (A-Z, a-z)
* \param stringRecibido string a verificar
* \return 0 si el string esta en un rango valido (A-Z, a-z)
*/
int isValidChar(char charRecibido) {
    int retorno = 0;
    if(charRecibido < 'A' || (charRecibido > 'Z' && charRecibido < 'a') || charRecibido> 'z') {
        retorno = 1;
    }
    return retorno;
}
