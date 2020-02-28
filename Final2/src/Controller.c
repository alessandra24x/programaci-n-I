#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libro.h"
#include "LinkedList.h"
#include "utn.h"
#include "Parser.h"

/** \brief Carga los datos desde el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPerro LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList *pListaLibro) {
	int ret = -1;
	char path[20];
	printf("Ingrese el nombre del archivo:\n");
	gets(path);

	FILE *pFile;
	pFile = fopen(path, "r"); //se abre el archivo en modo lectura
	if (parser_parseLibro(pFile, pListaLibro)) {
		ret = 0;
		printf("Lista cargada exitosamente");
	} else {
		printf("No se pudo cargar la lista");
	}
	fclose(pFile);
	return ret;
}

int controller_PrintLibro(LinkedList *pListaLibro, int index) {
	int ret = -1;
	Libro *auxLibro;
	int auxId;
	char auxTitulo[1024];
	char auxAutor[1024];
	int auxPrecio;
	char auxEditorial[1024];
	float auxPrecioConDescuento;

	if (pListaLibro != NULL) {
		auxLibro = ll_get(pListaLibro, index);
		libro_getId(auxLibro, &auxId);
		libro_getTitulo(auxLibro, auxTitulo);
		libro_getAutor(auxLibro, auxAutor);
		libro_getPrecio(auxLibro, &auxPrecio);
		libro_getEditorial(auxLibro, auxEditorial);
		libro_getPrecioConDescuento(auxLibro, &auxPrecioConDescuento);
		printf("Id:%d\n Titulo:%s\n Autor:%s\n Precio:%d\n Editorial:%s\n Precio con descuento:%.2f\n",
				auxId, auxTitulo, auxAutor, auxPrecio, auxEditorial, auxPrecioConDescuento);
		ret = 0;
	}
	return ret;
}

/** \brief Lista los elementos
 *
 * \param path char*
 * \param pListaVendedores LinkedList*
 * \return int
 *
 */
int controller_ListLibro(LinkedList *pListaLibro) {
	int ret = -1;
	int i, len;
	if (pListaLibro != NULL) {
		if (ll_len(pListaLibro) > 0) {
			len = ll_len(pListaLibro);
			for (i = 0; i < len; i++) {
				controller_PrintLibro(pListaLibro, i);
			}
			ret = 0;
		} else {
			printf("No existen registros cargados");
		}
		return ret;
	}
	return ret;
}

/** \brief Guarda los datos en el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pListaVendedores LinkedList*
 * \return int
 *
 */
int controller_saveLibroAsText(FILE *pFile, LinkedList *pListaLibro) {
	int ret = 0;
	Libro *auxLibro;
	int auxId;
	char auxTitulo[1024];
	char auxAutor[1024];
	int auxPrecio;
	char auxEditorial[1024];
	float auxPrecioConDescuento;
	int i, len;

	if (pListaLibro != NULL && pFile != NULL) {
		fprintf(pFile, "id,titulo, autor, precio, editorial, precio con descuento\n");
		len = ll_len(pListaLibro);

		for (i = 0; i < len; i++) {
			auxLibro = ll_get(pListaLibro, i);
			libro_getId(auxLibro, &auxId);
			libro_getTitulo(auxLibro, auxTitulo);
			libro_getAutor(auxLibro, auxAutor);
			libro_getPrecio(auxLibro, &auxPrecio);
			libro_getEditorial(auxLibro, auxEditorial);
			libro_getPrecioConDescuento(auxLibro, &auxPrecioConDescuento);
			fprintf(pFile,"%d,%s,%s,%d,%s,%.2f\n",
					auxId, auxTitulo, auxAutor, auxPrecio, auxEditorial, auxPrecioConDescuento);
			ret++;
		}
		fclose(pFile);
	}
	return ret;
}

int controller_saveAsText(char *fileName, LinkedList *pListaLibro) {
	FILE *pArchivo;
	int retorno = -1;

	if (fileName != NULL && pListaLibro != NULL) {
		pArchivo = fopen(fileName, "w"); //abre el archivo en modo de escritura
		if (pArchivo != NULL
				&& controller_saveLibroAsText(pArchivo, pListaLibro)) {
			printf("\nGuardado exitoso en Texto");
			retorno = 0;
		} else {
			printf("\nNo se pudo abrir el archivo");
		}
	}
	return retorno;
}
