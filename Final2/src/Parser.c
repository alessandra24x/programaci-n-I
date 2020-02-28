#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libro.h"
#include "LinkedList.h"

//Un parser o analizador sintáctico, se encarga de analizar una cadena de caracteres conforme a ciertas reglas

int parser_parseLibro(FILE *fileName, LinkedList *listaLibro) {
	int ret = 0;
	char auxId[1024];
	char auxTitulo[1024];
	char auxAutor[1024];
	char auxPrecio[1024];
	char auxEditorial[1024];
	char auxPrecioConDescuento[1024];
	Libro *pLibro;

	int lineNumber = 1;
	if (fileName != NULL && listaLibro != NULL) {
		fscanf(fileName, "%*[^\n]\n"); //skipeo la primera linea del archivo

		while (!feof(fileName)) {
			fscanf(fileName, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId,
					auxTitulo, auxAutor, auxPrecio, auxEditorial);
			strcpy(auxPrecioConDescuento, "");
			pLibro = libro_newParametros(auxId, auxTitulo, auxAutor,
					auxPrecio, auxEditorial, auxPrecioConDescuento);

			if (pLibro != NULL && ll_add(listaLibro, pLibro) == 0) {
				ret++;
			} else {
				printf("NULL | LINE_NUMBER = %d", lineNumber);
			}

			lineNumber++;
		}
	}
	return ret;
}
