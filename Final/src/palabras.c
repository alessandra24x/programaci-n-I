#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "palabras.h"
#include "LinkedList.h"
#include "utn.h"

Palabra *palabra_new()
{ //reservo espacio en memoria de manera dinámica para cada struct
	return (Palabra *)malloc(sizeof(Palabra));
}

Palabra* palabra_newParametros(char* letras) {
	Palabra* aux;
	aux = palabra_new();
	if(aux != NULL) {
		int setLetras = palabra_setLetras(aux, letras);

		if (setLetras != 0){
			printf("Problema al cargar letras\n");
			return NULL;
		}
	}
	return aux;
}

int palabra_delete(Palabra *this)
{
	int ret = -1;
	if (this != NULL)
	{
		free(this);
		ret = 0;
	}
	return ret;
}

int palabra_setLetras(Palabra *this, char *letras)
{
	int ret = -1;
	if (this != NULL)
	{
		strncpy(this->letras, letras, sizeof(this->letras));
		ret = 0;
	}
	return ret;
}

int palabra_getLetras(Palabra *this, char *letras)
{
	int ret = -1;
	if (this != NULL && letras != NULL)
	{
		strcpy(letras, this->letras);
		ret = 0;
	}
	return ret;
}

int palabra_sortLetras(void* pLetraA,void* pLetraB) {
	int ret = 0;
	if(strcmp(((Palabra*)pLetraA)->letras,((Palabra*)pLetraB)->letras) > 0) {
		ret = 1;
	}
	if(strcmp(((Palabra*)pLetraA)->letras,((Palabra*)pLetraB)->letras) < 0) {
		ret = -1;
	}

	return ret;
}

int palabra_sortLongitudLetras(void* pLetraA, void* pLetraB) {
	int ret = 0;
	if(strlen(((Palabra*) pLetraA)->letras) > (strlen(((Palabra*) pLetraB)->letras))) {
		ret = 1;
	}
	if(strlen(((Palabra*) pLetraA)->letras) == (strlen(((Palabra*) pLetraB)->letras))) {
		ret = palabra_sortLetras(((Palabra*)pLetraA)->letras,((Palabra*)pLetraB)->letras);
	}

	return ret;
}

void* contadorLetrasDistintas(void* pPalabra) {
	Palabra* retval = (Palabra*) pPalabra;
	char palabra[1024];
	strcpy(palabra, pPalabra);
	
	int contadorLetras = 0;
	char letras_sin_repeticion[strlen(palabra)];

	for(int i = 0; i < strlen(palabra); i++) {
		int encontrado = 0;
		for(int j = 0; j < contadorLetras; j++) {
			if(palabra[i] == letras_sin_repeticion[j]) {
				encontrado = 1;
			}
		}
		if(encontrado == 0) {
			letras_sin_repeticion[contadorLetras] = palabra[i];
			contadorLetras++;
		}
	}
	letras_sin_repeticion[contadorLetras] = '\0';

    strcpy(retval->letrasSinRepeticiones, letras_sin_repeticion);
    strcpy(retval->letras, palabra);
    retval->numLetras = contadorLetras;

    return retval;
}

int comparaPalabras(void* pPalabra1, void* pPalabra2)
{
    Palabra *palabra1 = (Palabra *) pPalabra1;
    Palabra *palabra2 = (Palabra *) pPalabra2;

    if(palabra1->numLetras == palabra2->numLetras) {
        return strcmp(palabra1->letras, palabra2->letras);
    }

    return palabra1->numLetras > palabra2->numLetras;
}