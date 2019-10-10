#include<stdio.h>
#include<string.h>
typedef struct{
    char nombre[20];
    int nota;
}eAlumno;

int main ()
{
int i;
eAlumno Alumno[3];
eAlumno* pArrayAlumno;

pArrayAlumno = Alumno;


strcpy((pArrayAlumno[0]).nombre,"Ana");
(pArrayAlumno[0]).nota= 8;

strcpy(pArrayAlumno[1].nombre,"Juan");
pArrayAlumno[1].nota= 7;

strcpy((pArrayAlumno[2]).nombre,"Pepe");
(pArrayAlumno[2]).nota= 9;


for (i=0;i<3;i++)
{
    printf("\n->Valor Nombre: %s", pArrayAlumno->nombre);
    printf("\n->Valor Nota: %d", pArrayAlumno->nota);
    pArrayAlumno++;
}


  return 0;

}
