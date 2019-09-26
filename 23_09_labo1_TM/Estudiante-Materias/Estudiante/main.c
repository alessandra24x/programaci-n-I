#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "estudiante.h"  //cambiar por nombre entidad
#include "informes.h"


#define QTY_TIPO 3

int main()
{
    int opcion;
    int contadorIdestudiante=0;                   //cambiar
    int contadorIDcurso=0;
    char buscar[50];
    eEstudiante arrayEstudiante[QTY_TIPO];                   //cambiar
    estudiante_Inicializar(arrayEstudiante,QTY_TIPO);                   //cambiar
    eCurso arrayCurso[QTY_TIPO];
    estudiante_InicializarCurso(arrayCurso, QTY_TIPO);                                    //cambiar estudiante


    eMateria arrayMateria[QTY_TIPO]={
        {1,"Programacion I",0},
        {2,"Base de Datos",0},
        {3,"Matematica",0}
        };

    do
    {
        estudiante_listarMaterias(arrayMateria, QTY_TIPO);
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Alta Curso \n7) Listar Cursos \n8) Materias por Alumno \n9) Salir\n",                   //cambiar
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
                estudiante_listar(arrayEstudiante,QTY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                estudiante_ordenarPorString(arrayEstudiante,QTY_TIPO);                   //cambiar
                break;
            case 6://Alta Curso
                estudiante_altaCurso(arrayCurso, QTY_TIPO,arrayEstudiante, QTY_TIPO, &contadorIDcurso);                          //cambiar estudiante
                break;
            case 7://Listar Cursos
                estudiante_listarCursos(arrayCurso, QTY_TIPO);
                break;
            case 8://Materias por Alumno
                utn_getName("\n Nombre del alumno: ","\nError nombre", 1,100,2,buscar);
                Informes_listarPorCriterio(arrayEstudiante, arrayCurso, QTY_TIPO, QTY_TIPO, buscar);
                break;
            case 9://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=9);
    return 0;
}
