/*Estructuras - Carga de Datos
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datosPersonales{
    char nombre[20];
    char apellido[20];
    char calle [20];
    int numero;
};

int main()
{
 struct datosPersonales agenda;

        printf("Ingrese el Nombre ");
        gets(agenda.nombre);
        fflush(stdin);

        printf("\nIngrese el apellido ");
        gets(agenda.apellido);
        fflush(stdin);

        printf("\nIngrese calle ");
        gets(agenda.calle);
        fflush(stdin);

        printf("\nIngrese numero de calle ");
        scanf("%d",&agenda.numero);

        //Mostrar datos
        printf("\nDatos Personales");
        printf("\n%s", agenda.nombre);
        printf("\n%s", agenda.apellido);
        printf("\n%s", agenda.calle);
        printf("\n%d", agenda.numero);



    return 0;
}
