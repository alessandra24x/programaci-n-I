#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logs.h"
#include "LinkedList.h"

//Un parser o analizador sintáctico, se encarga de analizar una cadena de caracteres conforme a ciertas reglas
int parser_parseLogs(FILE* fileName, LinkedList* listaLogs) {
  int ret = 0;
  char auxDate[4096];
  char auxTime[4096];
  char auxServiceId[4096];
  char auxGravedad[4096];
  char auxMsg[4096];
  LogEntry* pLogEntry;

  int lineNumber = 1;
  if(fileName != NULL && listaLogs != NULL) {
	//fscanf(fileName, "%*[^\n]\n"); //skipeo la primera linea del archivo

    while(!feof(fileName)) { //mientras no haya llegado al final del archivo
      // fscanf Recibe como primer parametro el puntero al archivo
      //leemos del archivo una cadena de caracteres. "Agarra cualquier caracter que no sea ;"
      //Cada llamada a fscanf() lee una línea del archivo.
      fscanf(fileName, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", auxDate,
                               auxTime,
                               auxServiceId,
                               auxGravedad,
                               auxMsg);
      //printf("\n\n%s,%s,%s,%s,%s", auxDate, auxTime, auxServiceId, auxGravedad, auxMsg);
      pLogEntry = logEntry_newParametros(auxDate,auxTime, auxServiceId, auxGravedad, auxMsg);
      // Construye un nuevo log, le setea los valores y devuelve un puntero de tipo void

      if(pLogEntry != NULL && ll_add(listaLogs, pLogEntry) == 0) {
          ret++; //retorna la cantidad de logs "agregados" a LinkedList
      } else {
        printf("NULL | LINE_NUMBER = %d", lineNumber);
      }

      lineNumber++;
    }
  }
  return ret;
}
