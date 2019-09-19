/*Estructuras - Operador Punto (acceso a los campos)
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

        strcpy(agenda.nombre, "Yanina");
        strcpy(agenda.apellido, "Scudero");
        strcpy(agenda.calle ,"Avenida Mitre");
        agenda.numero = 750;

        printf("El nombre es: %s ", agenda.nombre);
        printf("\nEl apellido es: %s ", agenda.apellido);


    return 0;
}
