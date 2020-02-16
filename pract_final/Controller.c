#include <stdio.h>
#include <stdlib.h>

#include "logs.h"
#include "services.h"
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
int controller_loadLogsFromText(char* path , LinkedList* pListaLog) {
	printf("hhhhh");
	int ret = -1;
	FILE* pFile;
	pFile = fopen(path, "r"); //se abre el archivo en modo lectura
	printf("llegue acaaa");
	if(parser_parseLogs(pFile, pListaLog)) {
		ret = 0;
		printf("Lista cargada exitosamente");
	} else {
		printf("No se pudo cargar la lista");
	}
	fclose(pFile);
	return ret;
}

/** \brief Carga los datos desde el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPerro LinkedList*
 * \return int
 *
 */
int controller_loadServicesFromText(char* path , LinkedList* pListaServices) {
	int ret = -1;
	FILE* pFile;
	pFile = fopen(path, "r"); //se abre el archivo en modo lectura
	if(parser_parseServices(pFile, pListaServices)) {
		ret = 0;
		printf("Lista cargada exitosamente");
	} else {
		printf("No se pudo cargar la lista");
	}
	fclose(pFile);
	return ret;
}

/*int controller_PrintBikes(LinkedList* pListaBikes, int index) {
	int ret = -1;
	Bike* auxBike;
	int auxId;
	char auxNombre[4096];
	char auxTipo[4096];
	int auxTiempo;
	float auxVelocidadP;

	if(pListaBikes != NULL) {
		auxBike = ll_get(pListaBikes, index);
		bike_getId(auxBike, &auxId);
		bike_getNombre(auxBike, auxNombre);
		bike_getTipo(auxBike, auxTipo);
		bike_getTiempo(auxBike, &auxTiempo);
		bike_getVelocidadP(auxBike, &auxVelocidadP);

		printf("ID: %d\n1.Nombre: %s\n2.Tipo: %s\n3.Tiempo: %d\n4.Velocidad Promedio: %.2f\n",
				auxId,auxNombre,auxTipo,auxTiempo, auxVelocidadP);
		ret = 0;
	}
	return ret;
}

/** \brief Lista los elementos
 *
 * \param path char*
 * \param pListaBikes LinkedList*
 * \return int
 *
 */
/*int controller_ListBikes(LinkedList* pListaBikes) {
	int ret = -1;
	int i, len;
	if(pListaBikes != NULL) {
		if(ll_len(pListaBikes) > 0) {
			len = ll_len(pListaBikes);
			for(i = 0; i < len; i++) {
				controller_PrintBikes(pListaBikes, i);
			}
			ret = 0;
		} else {
			printf("No existen registros cargados");
		}
		return ret;
	}
	return ret;
}/*

/** \brief Guarda los datos en el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pListaBikes LinkedList*
 * \return int
 *
 */
int controller_saveLogsAsText(FILE* pFile , LinkedList* pListaLogs) {
    int ret = 0;
	LogEntry* auxLogEntry;
    char auxDate[4096];
  	char auxTime[4096];
  	int auxServiceId;
  	int auxGravedad;
  	char auxMsg[64];
    int i, len;

    if(pListaLogs != NULL && pFile != NULL) {
    	//fprintf recibe como primer parametro puntero de archivo al archivo donde se escribirá la salida formateada.
    	//escribe datos formateados en el archivo
    	fprintf(pFile,"date, time, serviceId, gravedad, msg\n");
    	len = ll_len(pListaLogs);

    	for(i = 0; i < len; i++) {
    		auxLogEntry = ll_get(pListaLogs, i);
			logEntry_getDate(auxLogEntry, auxDate);
			logEntry_getTime(auxLogEntry, auxTime);
			logEntry_getServiceId(auxLogEntry, &auxServiceId);
			logEntry_getGravedad(auxLogEntry, &auxGravedad);
			logEntry_getMsg(auxLogEntry, auxMsg);

    		fprintf(pFile,"%s,%s,%d,%d,%s\n", auxDate, auxTime, auxServiceId, auxGravedad, auxMsg);
    		ret++;
    	}
	fclose(pFile);
    }
    return ret;
}

int controller_saveAsText(char* fileName,LinkedList* listaLog) {
	FILE*pArchivo;
	int retorno = -1;

	    if(fileName != NULL && listaLog != NULL) {
	        pArchivo = fopen(fileName,"w"); //abre el archivo en modo de escritura
	        if(pArchivo != NULL && controller_saveLogsAsText(pArchivo,listaLog)) {
	            //fclose(pArchivo);
	            printf("\nGuardado exitoso en Texto");
	            retorno = 0;
	        } else {
	            printf("\nNo se pudo abrir el archivo");
	        }
	    }
	    return retorno;
}

/** \brief Guarda los datos en el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pListaBikes LinkedList*
 * \return int
 *
 */

int controller_saveServicesAsText(FILE* pFile , LinkedList* pListaServices) {
	int ret = 0;
	Service* auxServices;
	int auxId;
  	char auxName[4096];
  	char auxEmail[4096];
	int i, len;

	if(pListaServices != NULL && pFile != NULL) {
		fprintf(pFile, "id, name, email\n");
		len = ll_len(pListaServices);
		for(i = 0; i < len; i++) {
			auxServices = ll_get(pListaServices, i);
			service_getId(auxServices, &auxId);
			service_getName(auxServices, auxName);
			service_getEmail(auxServices, auxEmail);

			fprintf(pFile, "%d,%s,%s", auxId, auxName, auxEmail);
			ret++;
		}
	fclose(pFile);
	}
	return ret;
}

int controller_saveServAsText(char* fileName,LinkedList* listaServices) {
	FILE*pArchivo;
	int retorno = -1;

	    if(fileName != NULL && listaServices != NULL) {
	        pArchivo = fopen(fileName,"w"); //abre el archivo en modo de escritura
	        if(pArchivo != NULL && controller_saveServicesAsText(pArchivo,listaServices)) {
	            //fclose(pArchivo);
	            printf("\nGuardado exitoso en Texto");
	            retorno = 0;
	        } else {
	            printf("\nNo se pudo abrir el archivo");
	        }
	    }
	    return retorno;
}