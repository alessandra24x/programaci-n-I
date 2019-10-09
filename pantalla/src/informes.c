#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"
#include "informes.h"

int informarContrataciones(Publicidad arrayPublicidad[], int sizePublicidad, Pantalla arrayPantalla[], int sizePantalla)
{
  int retorno = -1;
  int i;
  char cuitAux[TEXT_CUIT];
  int cantidadContrataciones = 0;

  if (arrayPublicidad != NULL && sizePublicidad > 0)
  {
    publicidad_ordenarPorCuit(arrayPublicidad, sizePublicidad);
    for (i = 0; i < sizePublicidad; i++)
    {
      if (arrayPublicidad[i].isEmpty == 0)
      {
        continue;
      }
      else if (strcmp(arrayPublicidad[i].cuit, cuitAux) != 0)
      {
        printf("\n\n\nPara el cuit: %s", arrayPublicidad[i].cuit);
        strcpy(cuitAux, arrayPublicidad[i].cuit);
        publicidad_calcularFacturacion(arrayPantalla, sizePantalla, arrayPublicidad, sizePublicidad, cuitAux, &cantidadContrataciones);
        printf("\nLa cantidad de publicaciones es de: %d", cantidadContrataciones);
        //          cliente_importesTotales(arrayPantalla,sizePantalla, arrayPublicidad,sizePublicidad,cuitAux);
      }
    }

    importes_clientes(
        arrayPantalla,
        sizePantalla,
        arrayPublicidad,
        sizePublicidad);

    cantidadContrataciones = 0;
    retorno = 0;
  }
  return retorno;
}

int cliente_importesTotales(
    Pantalla arrayPantalla[],
    int sizePantalla,
    Publicidad arrayPublicidad[],
    int sizePublicidad,
    char *aCuit)
{
  int i;
  int totalAPagar;
  int precio;
  int posicionPantalla;

  if (arrayPublicidad != NULL && sizePublicidad > 0)
  {
    for (i = 0; i < sizePublicidad; i++)
    {
      if (strcmp(arrayPublicidad[i].cuit, aCuit) == 0)
      {
        pantalla_buscarID(arrayPantalla, sizePantalla, arrayPublicidad[i].idPantalla, &posicionPantalla);
        precio = arrayPublicidad[i].cantDias * arrayPantalla[posicionPantalla].precioPorDia;
        totalAPagar += precio;
      }
    }
  }

  // printf("\nEl total a pagar es %d", totalAPagar);
  return totalAPagar;
}

int importes_clientes(
    Pantalla arrayPantalla[],
    int sizePantalla,
    Publicidad arrayPublicidad[],
    int sizePublicidad)
{
  Cliente clientes[20];
  int sizeClientes = 0;
  /**
   * Recorro las publicidades, para cada publicidad pueden ocurrir 2 cosas
   *
   * 1- es un cliente que ya esta en el array
   * 2- es un cliente que no esta en el array
   *
   * Si ya esta en el array, tomamos el indice de ese cliente e incrementamos
   * el importe por el valor de la publicidad
   *
   * Si no esta en el array ingresamos al array un nuevo cliente con el valor
   * de la publicidad
   */
  for (int i = 0; i < sizePublicidad; i++)
  {
    if(arrayPublicidad[i].isEmpty == 0) {
      continue; // recorremos solo las publicidades válidas
    }

    int encontrado = 0;
    for (int j = 0; j < sizeClientes; j++)
    {
      if (strcmp(arrayPublicidad[i].cuit, clientes[j].cuit) == 0)
      {
        encontrado = 1;
        break;
      }
    }

    if (encontrado == 0)
    { // nuevo cliente en el array
      int importe = cliente_importesTotales(
          arrayPantalla,
          sizePantalla,
          arrayPublicidad,
          sizePublicidad,
          arrayPublicidad[i].cuit);

      strcpy(clientes[sizeClientes].cuit, arrayPublicidad[i].cuit);
      clientes[sizeClientes].importe = importe;
      sizeClientes += 1;
    }
  }

  int mayorImporte = 0;
  int indiceMayorImporte = -1;
  for (int i = 0; i < sizeClientes; i++)
  {
    int importe = clientes[i].importe;
    if (importe > mayorImporte)
    {
      mayorImporte = importe;
      indiceMayorImporte = i;
    }
  }

  printf("\nEl mayor importe es %d y pertenece al cliente %s\n", mayorImporte, clientes[indiceMayorImporte].cuit);

  fflush(stdout);
  return mayorImporte;
}
