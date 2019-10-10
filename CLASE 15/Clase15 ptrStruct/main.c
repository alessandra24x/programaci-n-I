#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}EFecha;

typedef struct{
    long int dni;
    char nombre[31];
    EFecha fechaNac;
}EPersona;

int main()
{
    EPersona per, *ptrPer, pers[2], *ptrPers;
    int i;

    ptrPer = &per;

    ptrPers = pers;

    printf("\n\nESTRUCTURA SIMPLE:");

    printf("DNI: ");
    scanf("%ld", &per.dni);

    printf("\nNOMBRE: ");
    fflush(stdin);
    //setbuf(stdin, NULL);
    //scanf("%[^\n]", &per.nombre);
    gets(per.nombre);
    //scanf("%s", per.nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &per.fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &per.fechaNac.mes);

    printf("\nANIO: ");
    scanf("%d", &per.fechaNac.anio);

    printf("\n%s - %ld - %d/%d/%d", per.nombre, per.dni, per.fechaNac.dia, per.fechaNac.mes, per.fechaNac.anio);


    printf("\n\nPUNTERO A ESTRUCTURA OPERADOR FLECHA:");

    printf("DNI: ");
    scanf("%ld", &ptrPer->dni);

    printf("\nNOMBRE: ");
    fflush(stdin);
    scanf("%[^\n]", ptrPer->nombre);
    //scanf("%s", ptrPer->nombre);
    //[...]: it matches a nonempty sequence of characters from the scanset
    //^ means that the scanset is "negated": it is given by its complement.
    //^\n: the scanset is all characters except \n.

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &ptrPer->fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &ptrPer->fechaNac.mes);

    printf("\nANIO: ");
    scanf("%d", &ptrPer->fechaNac.anio);

    printf("\n%s - %ld - %d/%d/%d", ptrPer->nombre, ptrPer->dni, ptrPer->fechaNac.dia, ptrPer->fechaNac.mes, ptrPer->fechaNac.anio);


    printf("\n\nPUNTERO A ESTRUCTURA NOTACION PUNTERO:");

    printf("DNI: ");
    scanf("%ld", &(*ptrPer).dni);

    printf("\nNOMBRE: ");
    fflush(stdin);
    scanf("%[^\n]", (*ptrPer).nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &(*ptrPer).fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &(*ptrPer).fechaNac.mes);

    printf("\nANIO: ");
    scanf("%d", &(*ptrPer).fechaNac.anio);

    printf("\n%s - %ld - %d/%d/%d", (*ptrPer).nombre, (*ptrPer).dni, (*ptrPer).fechaNac.dia, (*ptrPer).fechaNac.mes, (*ptrPer).fechaNac.anio);

    //
    printf("\n\nPUNTERO A ARRAY DE ESTRUCTURA:");

    for(i=0; i<2; i++){
        printf("DNI: ");
        scanf("%ld", &(*(ptrPers+i)).dni);

        printf("\nNOMBRE: ");
        fflush(stdin);
        scanf("%[^\n]", (*(ptrPers+i)).nombre);

        printf("FECHA NACIMIENTO\n");

        printf("\nDIA: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.dia);

        printf("\nMES: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.mes);

        printf("\nANIO: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.anio);
    }

    for(i=0; i<2; i++){
         printf("\n%s - %ld - %d/%d/%d", (*(ptrPers+i)).nombre, (*(ptrPers+i)).dni, (*(ptrPers+i)).fechaNac.dia, (*(ptrPers+i)).fechaNac.mes, (*(ptrPers+i)).fechaNac.anio);

        //printf("\n\n%s - %ld - %d/%d/%d", (ptrPers+i)->nombre, (ptrPers+i)->dni, (ptrPers+i)->fechaNac.dia, (ptrPers+i)->fechaNac.mes, (ptrPers+i)->fechaNac.anio);
    }

    return 0;
}
