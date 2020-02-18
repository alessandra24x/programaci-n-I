#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "vendedor.h"
#include "LinkedList.h"

//Un parser o analizador sintáctico, se encarga de analizar una cadena de caracteres conforme a ciertas reglas

int parser_parseVendedores(FILE* fileName, LinkedList* listaVendedores) {
  int ret = 0;
  char auxId[4096];
  char auxNombre[4096];
  char auxNivel[4096];
  char auxCantidad_ventas[4096];
  char auxMonto[4096];
  char auxComisiones[4096];
  Vendedor* pVendedor;

  int lineNumber = 1;
  if(fileName != NULL && listaVendedores != NULL) {
	fscanf(fileName, "%*[^\n]\n"); //skipeo la primera linea del archivo

    while(!feof(fileName)) { //mientras no haya llegado al final del archivo
      // fscanf Recibe como primer parametro el puntero al archivo
      //leemos del archivo una cadena de caracteres. "Agarra cualquier caracter que no sea la ,"
      //Cada llamada a fscanf() lee una línea del archivo.
      fscanf(fileName, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId,
                               auxNombre,
                               auxNivel,
                               auxCantidad_ventas,
                               auxMonto);
      strcpy(auxComisiones, "");
      pVendedor = vendedor_newParametros(auxId, auxNombre, auxNivel, auxCantidad_ventas, auxMonto, auxComisiones);
      // Construye un nuevo vendedor, le setea los valores y devuelve un puntero de tipo void

      if(pVendedor != NULL && ll_add(listaVendedores, pVendedor) == 0) {
          ret++; //retorna la cantidad de Vendedores "agregados" a LinkedList
      } else {
        printf("NULL | LINE_NUMBER = %d", lineNumber);
      }

      lineNumber++;
    }
  }
  return ret;
}
