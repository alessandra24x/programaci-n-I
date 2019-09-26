#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "estudiante.h"

#define QTY_TIPO 3

int main()
{
    int opcion;
    int contadorIdestudiante=0;

    eEstudiante arrayEstudiante[QTY_TIPO];

    eCarrera arrayCarrera[QTY_TIPO]={
    {1,"TSP",0},
    {2,"TSAS",0}
    };

    estudiante_Inicializar(arrayEstudiante,QTY_TIPO);


    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                estudiante_alta(arrayEstudiante,QTY_TIPO,&contadorIdestudiante);                   //cambiar
                break;

            case 2: //Modificar
                estudiante_modificar(arrayEstudiante,QTY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                estudiante_baja(arrayEstudiante,QTY_TIPO);                   //cambiar
                break;

            case 4://Listar
                estudiante_listar(arrayEstudiante,QTY_TIPO, arrayCarrera, QTY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                estudiante_ordenarPorString(arrayEstudiante,QTY_TIPO);                   //cambiar
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
