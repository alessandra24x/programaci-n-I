#include <stdio.h>
#include <stdlib.h>

#include "palabras.h"
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
int controller_loadFromText(char* path , LinkedList* pListaBikes) {
	int ret = -1;
	FILE* pFile;
	pFile = fopen(path, "r"); //se abre el archivo en modo lectura
	if(parser_parsePalabra(pFile, pListaBikes)) {
		ret = 0;
		printf("Lista cargada exitosamente");
	} else {
		printf("No se pudo cargar la lista");
	}
	fclose(pFile);
	return ret;
}

int controller_PrintPalabra(LinkedList *pListaPalabra, int index)
{
	int ret = -1;
	Palabra *auxPalabra;
	char auxLetras[4096];

	if (pListaPalabra != NULL)
	{
		auxPalabra = ll_get(pListaPalabra, index);
		palabra_getLetras(auxPalabra, auxLetras);

		printf("Letras: %s\n",
			   auxLetras);
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
int controller_ListPalabra(LinkedList *pListaPalabra)
{
	int ret = -1;
	int i, len;
	if (pListaPalabra != NULL)
	{
		if (ll_len(pListaPalabra) > 0)
		{
			len = ll_len(pListaPalabra);
			for (i = 0; i < len; i++)
			{
				controller_PrintPalabra(pListaPalabra, i);
			}
			ret = 0;
		}
		else
		{
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
int controller_savePalabraAsText(FILE *pFile, LinkedList *pListaPalabra)
{
	int ret = 0;
	Palabra *auxPalabra;
	char auxLetras[4096];
	int i, len;

	if (pListaPalabra != NULL && pFile != NULL)
	{
		//fprintf recibe como primer parametro puntero de archivo al archivo donde se escribirá la salida formateada.
		//escribe datos formateados en el archivo
		fprintf(pFile, "letras\n");
		len = ll_len(pListaPalabra);

		for (i = 0; i < len; i++)
		{
			auxPalabra = ll_get(pListaPalabra, i);

			palabra_getLetras(auxPalabra, auxLetras);

			fprintf(pFile, "%s\n", auxLetras);
			ret++;
		}
		fclose(pFile);
	}
	return ret;
}

int controller_saveAsText(char *fileName, LinkedList *listaPalabra)
{
	FILE *pArchivo;
	int retorno = -1;

	if (fileName != NULL && listaPalabra != NULL)
	{
		pArchivo = fopen(fileName, "w"); //abre el archivo en modo de escritura
		if (pArchivo != NULL && controller_savePalabraAsText(pArchivo, listaPalabra))
		{
			printf("\nGuardado exitoso en Texto");
			retorno = 0;
		}
		else
		{
			printf("\nNo se pudo abrir el archivo");
		}
	}
	return retorno;
}
