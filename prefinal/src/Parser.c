#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bike.h"
#include "LinkedList.h"

//Un parser o analizador sintáctico, se encarga de analizar una cadena de caracteres conforme a ciertas reglas

int parser_parseBikes(FILE* fileName, LinkedList* listaBikes) {
  int ret = 0;
  char auxId[4096];
  char auxNombre[4096];
  char auxTipo[4096];
  char auxTiempo[4096];
  char auxVelocidadP[4096];
  Bike* pBike;

  int lineNumber = 1;
  if(fileName != NULL && listaBikes != NULL) {
	fscanf(fileName, "%*[^\n]\n"); //skipeo la primera linea del archivo

    while(!feof(fileName)) { //mientras no haya llegado al final del archivo
      // fscanf Recibe como primer parametro el puntero al archivo
      //leemos del archivo una cadena de caracteres. "Agarra cualquier caracter que no sea la ,"
      //Cada llamada a fscanf() lee una línea del archivo.
      fscanf(fileName, "%[^,],%[^,],%[^,],%[^\n]\n", auxId,
                               auxNombre,
                               auxTipo,
                               auxTiempo);
      strcpy(auxVelocidadP, "");
      pBike = bike_newParametros(auxId, auxNombre, auxTipo, auxTiempo, auxVelocidadP);
      // se llena con los valores recibidos de bike_newParametros

      if(pBike != NULL) {
        if(ll_add(listaBikes, pBike) == 0) {
          //retorna la cantidad de Bikes agregadas a LinkedList
          ret++;
        }
      } else {
        printf("NULL | LINE_NUMBER = %d", lineNumber);
      }

      lineNumber++;
    }
  }
  return ret;
}
