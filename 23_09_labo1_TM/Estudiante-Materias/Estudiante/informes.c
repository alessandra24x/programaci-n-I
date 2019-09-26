#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "informes.h"
#include "estudiante.h"  //cambiar por nombre entidad

/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA eEstudiante Array de eEstudiante
* \param arrayB eEstudiante Array de eEstudiante
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarPorCriterio(eEstudiante arrayA[],eCurso arrayB[], int sizeI, int sizeJ, char* criterio)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    int encontrado;

     if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0 && criterio!=NULL)
    {
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty==1)
             {
                continue;
             }
            if(strcmp(arrayA[i].nombre,criterio)==0)
            {
                for(j=0;j<sizeJ;j++)
                {
                    encontrado=-1;
                    encontrado=estudiante_buscarIDCurso(arrayB,sizeJ,arrayA[i].idEstudiante,j);
                    if(encontrado==0)
                    {
                        printf("\nListado ID Estudiante: %d  ID Materia: %d ", arrayA[i].idEstudiante,arrayB[j].idMateria);
                    }
                }
            }
        }
        retorno=0;
    }
    return retorno;
}
