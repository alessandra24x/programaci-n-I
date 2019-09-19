/*Estructuras - Estructuras Anidadas
uso de la Propiedad ASIGNACION*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct direccion{
    char calle[20];
    int numero;
};

struct datosPersonales{
    char nombre[20];
    char apellido[20];
    struct direccion domicilio;

};

int main()
{
    struct datosPersonales vecAgenda[3];
    //struct direccion vecDir[3];
    int i;

   ///*
   for(i=0;i<3;i++){
        printf("\nIngrese nombre ");
        gets(vecAgenda[i].nombre);
        printf("\nIngrese apellido ");
        gets(vecAgenda[i].apellido);
        printf("\nIngrese calle ");
        gets(vecAgenda[i].domicilio.calle);
        printf("\nIngrese numero ");
        scanf("%d", &vecAgenda[i].domicilio.numero);
        fflush(stdin);
    }
    //Mostrar elementos de la estructura
    for(i=0;i<3;i++){
        printf("\n Nombre: %s ", vecAgenda[i].nombre);
        printf("\nApellido: %s ", vecAgenda[i].apellido);
        printf("\nCalle: %s ", vecAgenda[i].domicilio.calle);
        printf("\nNumero: %d ", vecAgenda[i].domicilio.numero);
    }
//  */
/*

    //Cargando datos con la propiedad ASIGNACION
    for(i=0;i<3;i++){
        printf("\nIngrese nombre ");
        gets(vecAgenda[i].nombre);
        printf("\nIngrese apellido ");
        gets(vecAgenda[i].apellido);

        printf("\nIngrese calle ");
        gets(vecDir[i].calle);
        printf("\nIngrese numero ");
        scanf("%d", &vecDir[i].numero);
        fflush(stdin);
    }
    //Mostrar elementos de la ambas estructuras
    printf("\n Muestro ambas estructuras");
    for(i=0;i<3;i++){
        printf("\n Nombre: %s ", vecAgenda[i].nombre);
        printf("\nApellido: %s ", vecAgenda[i].apellido);
        printf("\nCalle: %s ", vecDir[i].calle);
        printf("\nNumero: %d ", vecDir[i].numero);
    }
    //Asignar los valores de la estructura vecDir a vecAgenda
    for(i=0;i<3;i++){
        vecAgenda[i].domicilio = vecDir[i];
    }
    //Mostrar elementos de la estructura Agenda
    printf("\n Muestro la estructuras Agenda con Domicilio asignado");
    for(i=0;i<3;i++){
        printf("\n Nombre: %s ", vecAgenda[i].nombre);
        printf("\nApellido: %s ", vecAgenda[i].apellido);
        printf("\nCalle: %s ", vecAgenda[i].domicilio.calle);
        printf("\nNumero: %d ", vecAgenda[i].domicilio.numero);
    }

*/

}
