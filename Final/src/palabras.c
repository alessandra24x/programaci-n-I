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


/*int palabra_delete(Palabra *this)
{
	int ret = -1;
	if (this != NULL)
	{
		free(this);
		ret = 0;
	}
	return ret;
}*/

int palabra_setLetras(Palabra *this, char *letras)
{
	int ret = -1;
	if (this != NULL == 0)
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
