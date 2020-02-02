#include <stdio.h>
#include <stdlib.h>

#include "bike.h"
#include "LinkedList.h"
#include "utn.h"
#include "Parser.h"


/** \brief Carga los datos de los Perros desde el archivo cachorros.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPerro LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pListaBikes) {
	int ret = -1;
	FILE* pFile;
	pFile = fopen(path, "r");
	if(parser_parseBikes(pFile, pListaBikes)) {
		ret = 0;
		printf("Lista cargada exitosamente");
	} else {
		printf("No se pudo cargar la lista");
	}
	fclose(pFile);
	return ret;
}

int controller_PrintBikes(LinkedList* pListaBikes, int index) {
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

/** \brief Listar Perros
 *
 * \param path char*
 * \param pArrayListPerro LinkedList*
 * \return int
 *
 */
int controller_ListBikes(LinkedList* pListaBikes) {
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
}

/** \brief Guarda los datos de los Perros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPerro LinkedList*
 * \return int
 *
 */
int controller_saveBikesAsText(FILE* pFile , LinkedList* pListaBikes) {
    int ret = 0;
	Bike* auxBike;
    int auxId;
    char auxNombre[4096];
    char auxTipo[4096];
	int auxTiempo;
	float auxVelocidadP;
    int i, len;

    if(pListaBikes != NULL && pFile != NULL) {
    	fprintf(pFile,"id,nombre,tipo,tiempo, velocidadP\n");
    	len = ll_len(pListaBikes);

    	for(i = 0; i < len; i++) {
    		auxBike = (Bike*)ll_get(pListaBikes, i);
    		bike_getId(auxBike, &auxId);
    		bike_getNombre(auxBike, auxNombre);
    		bike_getTipo(auxBike, auxTipo);
    		bike_getTiempo(auxBike, &auxTiempo);
    		bike_getVelocidadP(auxBike, &auxVelocidadP);

    		fprintf(pFile,"%d,%s,%s,%d,%f\n", auxId, auxNombre, auxTipo, auxTiempo, auxVelocidadP);
    		ret++;
    	}
	fclose(pFile);
    }
    return ret;
}

int controller_saveAsText(char* fileName,LinkedList* listaBikes) {
	FILE*pArchivo;
	int retorno = -1;

	    if(fileName != NULL && listaBikes != NULL) {
	        pArchivo = fopen(fileName,"w");
	        if(pArchivo != NULL && controller_saveBikesAsText(pArchivo,listaBikes)) {
	            //fclose(pArchivo);
	            printf("\nGuardado exitoso en Texto");
	            retorno = 0;
	        } else {
	            printf("\nNo se pudo abrir el archivo");
	        }
	    }
	    return retorno;
}

int controller_mapBikes(LinkedList* pListaBikes) {
    int ret = -1;
    if(pListaBikes != NULL) {
    	if(ll_len(pListaBikes) > 0) {
    		ll_map(pListaBikes,bike_map);
    	}
    		ret = 0;
    	} else {
    		printf("Algo salio mal");
    	}
    return ret;
}

/** \brief Ordenar bikes
 *
 * \param path char*
 * \param pArrayListBikes LinkedList*
 * \return int
 *
 */
int controller_sortBike(LinkedList* pArrayListBikes) {
    int ret = -1;
    int option;
    if(pArrayListBikes != NULL) {
    	if(ll_len(pArrayListBikes) > 0) {
    		utn_getUnsignedInt("\nSeleccione el criterio de ordenamiento deseado:\n 1- Ascendente\n 2- Descendente\n","Opcion invalida",1,sizeof(int),1,11,1,&option);
    		switch(option) {
    			case 1:
					ll_sort(pArrayListBikes,bike_compareTipo,1);
					break;
    			case 2:
    				ll_sort(pArrayListBikes,bike_compareTipo,-1);
    				break;
    			default:
    				printf("Opción invalida");
    		}
    	}
    		ret = 0;
    		printf("Operacion completada");
    	} else {
    		printf("No hay registros cargados");
    	}
    return ret;
}
