#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "perro.h"
#include "utn.h"
#include "Parser.h"


/** \brief Carga los datos de los Perros desde el archivo cachorros.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPerro LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pListaPerros) {
	int ret = -1;
	FILE* pFile;
	pFile = fopen(path, "r");
	if(parser_parsePerros(pFile, pListaPerros)) {
		ret = 0;
		printf("Lista cargada exitosamente");
	} else {
		printf("No se pudo cargar la lista");
	}
	fclose(pFile);
	return ret;
}

int controller_PrintPerros(LinkedList* pListaPerros, int index) {
	int ret = -1;
	Perro* auxPerro;
	int auxId;
	char auxNombre[4096];
	int auxDias;
	char auxRaza[4096];
	char auxReservado[4096];
	char auxSexo[4096];

	if(pListaPerros != NULL) {
		auxPerro = ll_get(pListaPerros, index);
		perro_getId(auxPerro, &auxId);
		perro_getNombre(auxPerro, auxNombre);
		perro_getDias(auxPerro, &auxDias);
		perro_getRaza(auxPerro, auxRaza);
		perro_getReservado(auxPerro, auxReservado);
		perro_getSexo(auxPerro, auxSexo);

		printf("ID: %d\n1.Nombre: %s\n2.Dias: %d\n3.Raza: %s\n4.¿Esta reservado?: %s\n5.Sexo: %s\n",
				auxId,auxNombre,auxDias,auxRaza, auxReservado, auxSexo);
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
int controller_ListPerros(LinkedList* pListaPerros) {
	int ret = -1;
	int i, len;
	if(pListaPerros != NULL) {
		if(ll_len(pListaPerros) > 0) {
			len = ll_len(pListaPerros);
			for(i = 0; i < len; i++) {
				controller_PrintPerros(pListaPerros, i);
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
int controller_savePerrosAsText(FILE* pFile , LinkedList* pListaPerros) {
    int ret = 0;
	Perro* auxPerro;
    int auxId;
    char auxNombre[4096];
    int auxDias;
    char auxRaza[4096];
	char auxReservado[4096];
	char auxSexo[4096];
    int i, len;

    if(pListaPerros != NULL && pFile != NULL) {
    	fprintf(pFile,"id,nombre,dias,raza,reservado,sexo\n");
    	len = ll_len(pListaPerros);

    	for(i = 0; i < len; i++) {
    		auxPerro = (Perro*)ll_get(pListaPerros, i);
    		perro_getId(auxPerro, &auxId);
    		perro_getNombre(auxPerro, auxNombre);
    		perro_getDias(auxPerro, &auxDias);
    		perro_getRaza(auxPerro, auxRaza);
    		perro_getReservado(auxPerro, auxReservado);
    		perro_getSexo(auxPerro, auxSexo);


    		fprintf(pFile,"%d,%s,%d,%s,%s,%s\n", auxId, auxNombre, auxDias, auxRaza, auxReservado, auxSexo);
    		ret++;
    	}
	fclose(pFile);
    }
    return ret;
}

int controller_saveAsText(char* fileName,LinkedList* listaPerros) {
	FILE*pArchivo;
	int retorno = -1;

	    if(fileName != NULL && listaPerros != NULL) {
	        pArchivo=fopen(fileName,"w");
	        if(pArchivo != NULL && controller_savePerrosAsText(pArchivo,listaPerros)) {
	            //fclose(pArchivo);
	            printf("\nGuardado exitoso en Texto");
	            retorno = 0;
	        } else {
	            printf("\nNo se pudo abrir el archivo");
	        }
	    }
	    return retorno;
}

