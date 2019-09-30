#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h"

int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado) {

    int retorno = -1;
    char bufferStr[max+10];

    if(msg != NULL && msgError != NULL && min <= max && reintentos >= 0 && resultado != NULL) {
        do {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr) >= min && strlen(bufferStr) < max) {
                strncpy(resultado,bufferStr,max);
                retorno = 0;
                break;
            }
            printf("%s 1",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}

int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado) {
    int retorno = -1;
    char bufferStr[max];

    if(msg != NULL && msgError != NULL && min <= max && reintentos >= 0 && resultado != NULL) {
        do {
            if(getString(msg,msgError,min,max,&reintentos,bufferStr) == 0) {
                if(isValidName(bufferStr) == 0) {
                    strncpy(resultado,bufferStr,max);
                    retorno=0;
                    break;
                }
                else {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidName(char* stringRecibido) {
    int retorno = 0;
    int i;
    for(i = 0; stringRecibido[i] != '\0'; i++) {
        //printf("%d",i);
        if(stringRecibido[i] < 'A' || (stringRecibido[i] > 'Z' && stringRecibido[i] < 'a') || stringRecibido[i] > 'z') {
            retorno = 1;
            break;
        }
    }
    return retorno;
}

int utn_getUnsignedInt(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input) {

    int retorno = -1;
    char bufferStr[maxSize];

    if(msg != NULL && msgError != NULL && minSize < maxSize && min < max && reintentos >= 0 && input != NULL) {
        do {
            if(getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr) == 0) {
                if(isValidNumber(bufferStr) == 0) {
                    *input = atoi(bufferStr);
                    retorno = 0;
                    break;
                }
                else {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos >= 0);
    }
    return retorno;
}

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

int utn_getSignedInt(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, int* input) {
    int retorno = -1;
    char bufferStr[maxSize];

    if(msg != NULL && msgError != NULL && minSize < maxSize && min < max && reintentos >= 0 && input != NULL) {
        do {
            if(getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr) == 0) {
                if(isValidSignedNumber(bufferStr) == 0) {
                    *input=atoi(bufferStr); // atoi array to int
                    retorno = 0;
                    break;
                }
                else {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidSignedNumber(char* stringRecibido)
{
    int retorno = 0;
    int i;
    for(i = 0; stringRecibido[i] != '\0'; i++)
    {
        if((stringRecibido[i] < '0' || stringRecibido[i] > '9') && (stringRecibido[0] != '+' && stringRecibido[0] != '-')) {
            retorno = 1;
            break;
        }
    }
    return retorno;
}

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
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

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
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

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

int utn_getTelefono(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, char* input) {
    int retorno = -1;
    char bufferStr[maxSize];

    if(msg != NULL && msgError != NULL && minSize < maxSize && min < max && reintentos >= 0 && input != NULL) {
        do {
            if(getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr) == 0) {
                if(isValidTelephone(bufferStr) == 0) {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidTelephone(char* stringRecibido) {
    int retorno = 0;
    int i;
    for(i = 0; stringRecibido[i] != '\0'; i++) {
        if((stringRecibido[i] < '0' || stringRecibido[i] > '9') && (stringRecibido[i] != '-' || stringRecibido[i] != ' ')) {
            retorno = 1;
            break;
        }
    }
    return retorno;
}

int utn_getDNI(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input) {
    maxSize = 11; //con puntos
    minSize = 8;  // sin puntos
    int retorno = -1;
    char bufferStr[maxSize];

    if(msg != NULL && msgError != NULL && minSize < maxSize && reintentos >= 0 && input != NULL) {
        do {
            if(getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr) == 0) {
                if(isValidDNI(bufferStr) == 0) {
                    strncpy(input,bufferStr,maxSize);
                    retorno = 0;
                    break;
                }
                else {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidDNI(char* stringRecibido) {
    int retorno = 0;
    int i;
    for(i = 0; stringRecibido[i] != '\0'; i++) {
        if((stringRecibido[i] < '0' || stringRecibido[i] > '9') && (stringRecibido[i] != '.')) {
            retorno = 1;
            break;
        }
    }
    return retorno;
}

int utn_getCUIT(char* msg, char* msgError, int reintentos, char* input) {
    int maxSize = 14; //con guiones 13 elementos
    int minSize = 11;  // sin puntos
    int retorno = -1;
    char bufferStr[maxSize];

    if(msg != NULL && msgError != NULL && minSize < maxSize && reintentos >= 0 && input != NULL) {
        do {
            if(getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr) == 0) {
                if(isValidCUIT(bufferStr) == 0) {
                    strncpy(input,bufferStr,maxSize);
                    retorno = 0;
                    break;
                }
                else {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidCUIT(char* stringRecibido) {
    int retorno = 0;
    int i;
    int j;
    char buffer[14];
    strncpy(buffer,stringRecibido,14);

    for(i = 0 ; buffer[i] != '\0'; i++) {
        if((buffer[i] < '0' || buffer[i] > '9') && (buffer[i] != '-')) {
            retorno = 1;
            break;
        }

        if(buffer[i] == '-') {
            for(j = i; buffer[j] != '\0'; j++) {
                strncpy(&buffer[j],&buffer[j+1],1);
            }
        }
    }

    int digitos[10]={2,3,4,5,6,7,2,3,4,5};
    int acumulado = 0;
    int verificador;

    for(i = 0; i < strlen(buffer-1); i++)
    {
        acumulado+=buffer[i]*digitos[i];
    }

    verificador = 11-(acumulado%11);
	if(verificador == 11) {
		verificador = 0;
	}

	if(buffer[11] != verificador) {
        retorno = 1;
    }

    //if(stringRecibido[2]!='-' || stringRecibido[11]!='-' || stringRecibido[0]!='2' || stringRecibido[1]!='0' || stringRecibido[1]!='3' || stringRecibido[1]!='4' || stringRecibido[1]!='7')
    return retorno;
}

int utn_getEmail(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input) {
    int retorno = -1;
    char bufferStr[maxSize];

    if(msg != NULL && msgError != NULL && minSize < maxSize && reintentos >= 0 && input != NULL) {
        do {
            if(getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr) == 0) {
                if(isValidEmail(bufferStr) == 0) {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidEmail(char* stringRecibido) {
    int retorno = 0;
    int i;
    for(i = 0; stringRecibido[i] != '\0'; i++) {
        if((stringRecibido[i] < '-' && stringRecibido[i] != '+') || (stringRecibido[i] > '9' && stringRecibido[i] < '@') ||
           (stringRecibido[i] > 'Z' && stringRecibido[i] != '_' && stringRecibido[i] < 'a')|| stringRecibido[i] > 'z') {
            retorno = 1;
            break;
        }
    }
    return retorno;
}

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
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidChar(char charRecibido) {
    int retorno = 0;
    if(charRecibido < 'A' || (charRecibido> 'Z' && charRecibido <'a') || charRecibido> 'z') {
        retorno = 0;
    }
    return retorno;
}

int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input) {
    int retorno = -1;
    char bufferStr[maxSize];

    if(msg != NULL && msgError != NULL && minSize<maxSize && reintentos >= 0 && input != NULL) {
        do {
            if(getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr) == 0) {
                if(isValidAlphanumeric(bufferStr) == 1) {
                    strncpy(input,bufferStr,maxSize);
                    retorno = 0;
                    break;
                }
                else {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidAlphanumeric(char* stringRecibido) {
    int retorno = 0;
    int i;
    for(i = 0; stringRecibido[i] != '\0'; i++) {
        if(stringRecibido[i] < '0' || (stringRecibido[i] > '9' && stringRecibido[i] < 'A') || (stringRecibido[i] > 'Z' && stringRecibido[i] < 'a') || stringRecibido[i] > 'z' ) {
            retorno = 1;
            break;
        }
    }
    return retorno;
}



