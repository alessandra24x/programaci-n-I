#include<stdio.h>
#include<string.h>

int main ()
{
typedef struct{
    char nombre[20];
    int nota;
}eAlumno;

eAlumno auxiliarAlumno;
eAlumno* punteroAlumno;

punteroAlumno = &auxiliarAlumno;


strcpy((*punteroAlumno).nombre,"Ana");
(*punteroAlumno).nota= 8;

printf("\n->Valor Nombre: %s", (*punteroAlumno).nombre);
printf("\n->Valor Nota: %d", (*punteroAlumno).nota);

//Operador Flecha

strcpy(punteroAlumno->nombre,"Juan");
punteroAlumno->nota= 7;

printf("\n->Valor Nombre: %s", punteroAlumno->nombre);
printf("\n->Valor Nota: %d", punteroAlumno->nota);



  return 0;

}
