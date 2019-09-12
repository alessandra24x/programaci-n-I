#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_Array.h"
#include "UTN_Inputs.h"

#define CANT_EL 4

int cargarSetDatos(char pArrayNombre[][50], int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite);
int mostrarEstudiante(char pArrayNombre[50],int aLegajo, char aSexo, int aEdad, int aNota1P,int aNota2P, float aPromedio);
int mostrarEstudiantes(char pArrayNombre[][50],int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite);
int ordenarLegajoEstudiantes(char pArrayNombre[][50],int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite, int orden);
int ordenarPromedioEstudiantes(char pArrayNombre[][50],int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite);


int main()
{
int legajo[CANT_EL];
char sexo[CANT_EL];
int edad[CANT_EL];
int nota1P[CANT_EL];
int nota2P[CANT_EL];
float promedio[CANT_EL];
char arrayNombres[CANT_EL][50];


    cargarSetDatos(arrayNombres, legajo, sexo, edad, nota1P, nota2P, promedio, CANT_EL);
    //Mostrar ordenar y mostrar
    mostrarEstudiantes(arrayNombres,legajo, sexo, edad, nota1P, nota2P, promedio, CANT_EL);
    //orden=1 ascendente, orden=2 descendente
    ordenarLegajoEstudiantes(arrayNombres,legajo, sexo, edad, nota1P, nota2P, promedio, CANT_EL, 2);
    mostrarEstudiantes(arrayNombres,legajo, sexo, edad, nota1P, nota2P, promedio, CANT_EL);
    //Si el promedio se repita, ordeno por nombre de manera ascendente
    ordenarPromedioEstudiantes(arrayNombres,legajo, sexo, edad, nota1P, nota2P, promedio, CANT_EL);
    mostrarEstudiantes(arrayNombres,legajo, sexo, edad, nota1P, nota2P, promedio, CANT_EL);

    return 0;
}


int cargarSetDatos(char pArrayNombre[][50], int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite)
{
    int i;
    int buffer;
    char auxNombre[50];
    for (i=0; i<limite; i++)
    {
        fflush(stdin);
        getString("Ingrese Nombre del Alumno ",auxNombre);
        //arrayNombres[i]=arrayNombres;  NOOO
        strcpy(pArrayNombre[i],auxNombre);

        //printf("Ingrese el legajo del alumno: ");
        //scanf("%d", &aLegajo[i]);
        fflush(stdin);
        if(getInt(&buffer, "+Ingrese el legajo del alumno: ", "Error. ", 1, 100, 2) == 0)
        {
                aLegajo[i]=buffer;
        }else
            {
                aLegajo[i]=0;
            }
        printf("Ingrese el sexo del alumno: ");
        fflush(stdin);
        scanf("%c",&aSexo[i]);
        fflush(stdin);
        printf("Ingrese la edad del alumno: ");
        scanf("%d", &aEdad[i]);
        printf("Ingrese la nota 1er Parcial del alumno: ");
        scanf("%d", &aNota1P[i]);
        printf("Ingrese la nota 2do Parcial del alumno: ");
        scanf("%d", &aNota2P[i]);
        aPromedio[i] = (((float)aNota1P[i]+aNota2P[i])/2);
       }
    return 0;
}
int mostrarEstudiante(char pArrayNombre[50], int aLegajo, char aSexo, int aEdad, int aNota1P,int aNota2P, float aPromedio)
{
    printf("\n%s            %d        %c     %d       %d         %d           %.2f",pArrayNombre, aLegajo, aSexo, aEdad, aNota1P, aNota2P, aPromedio);

    return 0;
}
int mostrarEstudiantes(char pArrayNombre[][50],int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite)
{
    int i;
    printf("\nnombre     legajo    sexo   edad   nota1P     nota2P    promedio");
    for (i=0; i<limite; i++)
    {
        mostrarEstudiante(pArrayNombre[i], aLegajo[i], aSexo[i], aEdad[i], aNota1P[i], aNota2P[i], aPromedio[i]);
    }

    return 0;
}
int ordenarLegajoEstudiantes(char pArrayNombre[][50], int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite, int aOrden)
{
    int i;
    int aux;
    char auxS;
    float auxF;
    char auxNom[50];
    int flag=-1;


    while(flag==-1)
    {
        flag=0;
        for (i=0; i<limite-1; i++)
        {
            if(aOrden==1)
            {
                if(aLegajo[i]>aLegajo[i+1])
                {
                    aux= aLegajo[i];
                    aLegajo[i]=aLegajo[i+1];
                    aLegajo[i+1]=aux;

                    auxS= aSexo[i];
                    aSexo[i]=aSexo[i+1];
                    aSexo[i+1]=auxS;

                    aux= aEdad[i];
                    aEdad[i]=aEdad[i+1];
                    aEdad[i+1]=aux;

                    aux= aNota1P[i];
                    aNota1P[i]=aNota1P[i+1];
                    aNota1P[i+1]=aux;

                    aux= aNota2P[i];
                    aNota2P[i]=aNota2P[i+1];
                    aNota2P[i+1]=aux;

                    auxF= aPromedio[i];
                    aPromedio[i]=aPromedio[i+1];
                    aPromedio[i+1]=auxF;

                    strcpy(auxNom, pArrayNombre[i]);
                    strcpy(pArrayNombre[i], pArrayNombre[i+1]);
                    strcpy(pArrayNombre[i+1],auxNom);
                    flag=-1;
                }
            }
            if(aOrden==2)
            {
                 if(aLegajo[i]<aLegajo[i+1])
                {
                    aux= aLegajo[i];
                    aLegajo[i]=aLegajo[i+1];
                    aLegajo[i+1]=aux;

                    auxS= aSexo[i];
                    aSexo[i]=aSexo[i+1];
                    aSexo[i+1]=auxS;

                    aux= aEdad[i];
                    aEdad[i]=aEdad[i+1];
                    aEdad[i+1]=aux;

                    aux= aNota1P[i];
                    aNota1P[i]=aNota1P[i+1];
                    aNota1P[i+1]=aux;

                    aux= aNota2P[i];
                    aNota2P[i]=aNota2P[i+1];
                    aNota2P[i+1]=aux;

                    auxF= aPromedio[i];
                    aPromedio[i]=aPromedio[i+1];
                    aPromedio[i+1]=auxF;

                    strcpy(auxNom, pArrayNombre[i]);
                    strcpy(pArrayNombre[i], pArrayNombre[i+1]);
                    strcpy(pArrayNombre[i+1],auxNom);

                    flag=-1;
                }
            }
        }
    }
    return 0;
}
int ordenarPromedioEstudiantes(char pArrayNombre[][50],int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite)
{
    int i;
    int aux;
    char auxS;
    float auxF;
    char auxNom[50];
    int flag=-1;

    while(flag==-1)
    {
        flag=0;
        for (i=0; i<limite-1; i++)
        {
            if(aPromedio[i]>aPromedio[i+1])
            {
                aux= aLegajo[i];
                aLegajo[i]=aLegajo[i+1];
                aLegajo[i+1]=aux;

                auxS= aSexo[i];
                aSexo[i]=aSexo[i+1];
                aSexo[i+1]=auxS;

                aux= aEdad[i];
                aEdad[i]=aEdad[i+1];
                aEdad[i+1]=aux;

                aux= aNota1P[i];
                aNota1P[i]=aNota1P[i+1];
                aNota1P[i+1]=aux;

                aux= aNota2P[i];
                aNota2P[i]=aNota2P[i+1];
                aNota2P[i+1]=aux;

                auxF= aPromedio[i];
                aPromedio[i]=aPromedio[i+1];
                aPromedio[i+1]=auxF;

                strcpy(auxNom, pArrayNombre[i]);
                strcpy(pArrayNombre[i], pArrayNombre[i+1]);
                strcpy(pArrayNombre[i+1],auxNom);
                flag=-1;
                }
                if(aPromedio[i]==aPromedio[i+1])
                {
                    if(strcmp(pArrayNombre[i],pArrayNombre[i+1])>0)
                    {
                            strcpy(auxNom, pArrayNombre[i]);
                            strcpy(pArrayNombre[i], pArrayNombre[i+1]);
                            strcpy(pArrayNombre[i+1],auxNom);

                            aux= aLegajo[i];
                            aLegajo[i]=aLegajo[i+1];
                            aLegajo[i+1]=aux;

                            auxS= aSexo[i];
                            aSexo[i]=aSexo[i+1];
                            aSexo[i+1]=auxS;

                            aux= aEdad[i];
                            aEdad[i]=aEdad[i+1];
                            aEdad[i+1]=aux;

                            aux= aNota1P[i];
                            aNota1P[i]=aNota1P[i+1];
                            aNota1P[i+1]=aux;

                            aux= aNota2P[i];
                            aNota2P[i]=aNota2P[i+1];
                            aNota2P[i+1]=aux;

                            //auxF= aPromedio[i];
                            //aPromedio[i]=aPromedio[i+1];
                            //aPromedio[i+1]=auxF;
                            flag=-1;
                    }
                }
            }
        }
    return 0;
}
