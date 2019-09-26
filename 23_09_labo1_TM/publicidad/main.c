#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h"  //cambiar por nombre entidad


#define QTY_TIPO 3

int main()
{
    int opcion;
    int contadorIdpantalla=0;                   //cambiar

    Pantalla arrayPantalla[QTY_TIPO];
    pantalla_Inicializar(arrayPantalla,QTY_TIPO);

    Publicidad arrayPublicidad[QTY_TIPO];
    publicidad_Inicializar(arrayPublicidad,QTY_TIPO);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta Pantalla \n2) Modificar Pantalla \n3) Baja Pantalla \n4) Listar Pantallas \n5) Contratar Publicidad \n6) Ordenar \n7) Listar Publicidades \n8) Modificar Publicidad \n9) Consulta Facturacion \n10) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                pantalla_alta(arrayPantalla,QTY_TIPO,&contadorIdpantalla);
                                  //cambiar
                break;

            case 2: //Modificar
                //pantalla_modificar(arrayPantalla,QTY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                pantalla_baja(arrayPantalla,QTY_TIPO);                   //cambiar
                break;

            case 4://Listar pantalla
                pantalla_listar(arrayPantalla,QTY_TIPO);                   //cambiar
                break;

            case 5://Contratar publicidad
                pantalla_listar(arrayPantalla,QTY_TIPO);                   //cambiar
                pantalla_contratar(arrayPublicidad,QTY_TIPO);                   //cambiar
                break;

            case 6://Ordenar
                //pantalla_ordenarPorString(arrayPantalla,QTY_TIPO);                   //cambiar
                break;

            case 7://Listar Publicidades
                publicidad_listar(arrayPublicidad,QTY_TIPO);
                break;

            case 8://Modificar Publicidad
                publicidad_modificar(arrayPublicidad, QTY_TIPO);
                break;

            case 9://Consultar Facturacion
                publicidad_consultaFacturacion(arrayPantalla, QTY_TIPO, arrayPublicidad, QTY_TIPO);
                break;

            case 10://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=10);
    return 0;
}
