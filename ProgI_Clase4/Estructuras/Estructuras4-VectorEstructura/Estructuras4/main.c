/*Estructuras - Vector de tipo Estructura
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
    struct datosPersonales vecAgenda[3];
    int i;

    for(i=0;i<3;i++){
        printf("\nIngrese nombre ");
        gets(vecAgenda[i].nombre);
        printf("\nIngrese apellido ");
        gets(vecAgenda[i].apellido);
        printf("\nIngrese calle ");
        gets(vecAgenda[i].calle);
        printf("\nIngrese numero ");
        scanf("%d", &vecAgenda[i].numero);
        fflush(stdin);
    }
    //Mostrar elementos de la estructura
    for(i=0;i<3;i++){
        printf("\n Nombre: %s ", vecAgenda[i].nombre);
        printf("\nApellido: %s ", vecAgenda[i].apellido);
        printf("\nCalle: %s ", vecAgenda[i].calle);
        printf("\nNumero: %d ", vecAgenda[i].numero);
    }


}
