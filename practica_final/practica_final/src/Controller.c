#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logs.h"
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
int controller_loadFromText(char* path , LinkedList* pListaLogs) {
	int ret = -1;
	FILE* pFile;
	pFile = fopen(path, "r");
	if(parser_parseLogs(pFile, pListaLogs)) {
		ret = 0;
		printf("Lista cargada exitosamente");
	} else {
		printf("No se pudo cargar la lista");
	}
	fclose(pFile);
	return ret;
}

int controller_saveLogsAsText(FILE* pFile, LinkedList* pListaLogs) {
	int ret = 0;
	LogEntry* auxLogEntry;
	char auxDate[4096];
	char auxTime[4096];
	int auxServiceId;
	int auxGravedad;
	char auxMsg[4096];
	int i, len;

	if(pListaLogs != NULL && pFile != NULL) {
		fprintf(pFile,"date,time,serviceId,gravedad,msg\n");
		len = ll_len(pListaLogs);

		for(i = 0; i < len; i++) {
			auxLogEntry = ll_get(pListaLogs, i);
			logEntry_getDate(auxLogEntry,auxDate);
			logEntry_getTime(auxLogEntry,auxTime);
			logEntry_getServiceId(auxLogEntry,&auxServiceId);
			logEntry_getGravedad(auxLogEntry,&auxGravedad);
			logEntry_getMsg(auxLogEntry,auxMsg);

			fprintf(pFile,"%s,%s,%d,%d,%s\n", auxDate, auxTime, auxServiceId, auxGravedad, auxMsg);
			ret++;
		}
		fclose(pFile);
	}
	return ret;
}

int controller_saveAsText(char* fileName, LinkedList* listaLogs) {
	FILE* pArchivo;
	int retorno = -1;

	if(fileName != NULL && listaLogs != NULL) {
		pArchivo = fopen(fileName, "w");
		if(pArchivo != NULL && controller_saveLogsAsText(pArchivo, listaLogs)) {
			printf("\nGuardado exitoso en Texto");
			retorno = 0;
		} else {
			printf("\nNo se pudo abrir el archivo");
		}
	}
	return retorno;
}
