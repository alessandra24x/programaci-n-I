#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_Array.h"
#include "UTN_Inputs.h"

#define QTY_CLIENTES 4
#define MSG_INGRESONOM "Ingrese un nombre: "
#define MSG_INGRESOAP "Ingrese un apellido: "

int main()
{
    int i;
    char arrayNombres[QTY_CLIENTES][50];
    char arrayApellidos[QTY_CLIENTES][50];
    char auxNombre[50];
    char auxApellido[50];

    //Cargar los nombre
    for(i=0;i<QTY_CLIENTES;i++)
    {
        getString(MSG_INGRESONOM,auxNombre);
        //arrayNombres[i]=arrayNombres;  NOOO
        strcpy(arrayNombres[i],auxNombre);
    }
    printArrayStr(arrayNombres,QTY_CLIENTES);

    //Cargar los apellidos
    for(i=0;i<QTY_CLIENTES;i++)
    {
        getString(MSG_INGRESOAP,auxApellido);
        //arrayNombres[i]=arrayNombres;  NOOO
        strcpy(arrayApellidos[i],auxApellido);
    }
    printArrayStr(arrayApellidos,QTY_CLIENTES);
    //Si quiero que el legajo coincida con el indice OJO no podría ordenarlo
    for(i=0;i<QTY_CLIENTES;i++)
    {
        printf("\n%s - %s - %d",arrayNombres[i],arrayApellidos[i],i);
    }
    //Ordenar 2 arrays
    Ordenar2ArrayStr(arrayNombres,arrayApellidos,QTY_CLIENTES);
    //Lo muestro ordenado
    printf("\n*ORDENADO*");
    for(i=0;i<QTY_CLIENTES;i++)
    {
        printf("\n%s - %s - %d",arrayNombres[i],arrayApellidos[i],i);
    }


    return 0;
}
