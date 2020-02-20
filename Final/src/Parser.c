#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palabras.h"
#include "LinkedList.h"

//Un parser o analizador sintáctico, se encarga de analizar una cadena de caracteres conforme a ciertas reglas

int parser_parsePalabra(FILE *fileName, LinkedList *listaPalabra)
{
  int ret = 0;
  char auxLetras[128];
  Palabra *pPalabra;

  int lineNumber = 1;
  if (fileName != NULL && listaPalabra != NULL)
  {
    //fscanf(fileName,"%*[^\n]\n"); //skipeo la primera linea del archivo

    while (!feof(fileName))
    { //mientras no haya llegado al final del archivo
      //fscanf Recibe como primer parametro el puntero al archivo
      //leemos del archivo una cadena de caracteres. "Agarra cualquier caracter que no sea la ,"
      //Cada llamada a fscanf() lee una línea del archivo.
      fscanf(fileName, "%[^\n]\n",
             auxLetras);
      pPalabra = palabra_newParametros(auxLetras);
      // Construye un nuevo vendedor, le setea los valores y devuelve un puntero de tipo void

      if (pPalabra != NULL && ll_add(listaPalabra, pPalabra) == 0)
      {
        ret++; //retorna la cantidad de Vendedores "agregados" a LinkedList
      }
      else
      {
        printf("NULL | LINE_NUMBER = %d", lineNumber);
      }

      lineNumber++;
    }
  }
  return ret;
}
