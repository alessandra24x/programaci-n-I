#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utn.h"

#define MAXRECORDS 4//constante para el limite del arrays
typedef struct
{
  char name[20];
  int dni;
  int age;
  int isEmpty;
}Student;


int printMenu();
int buscarPorDni (int dni, Student *array) ;
void mostrar (Student * array);


int main(void) {
	bool running = true;
    Student array[MAXRECORDS];
    int age, dni, i, options;
    char name[20];

    for(i=0; i < MAXRECORDS; ++i) {
        array[i].isEmpty = 0; //La lista al principio está vacia
    }

    while(running) {

        options = printMenu(); //Se guarda en esta variable lo que retorna la función printMenu()
        switch(options) {
            case 1:
            ;int alta = 1;
                for(i = 0; i < MAXRECORDS; i++) {
                	if(array[i].isEmpty == 0 && alta == 1) {
                    printf("///\nIngrese los datos de la persona estudiante///\n");
                    printf("Ingrese nombre: ");
                    fgets(name, sizeof(name), stdin);
                    getInt(&dni, "ingrese dni: ", "ingrese un dni valido", 1, 100000000, 3);
                    getInt(&age, "ingrese edad: ", "ingrese una edad valida", 1, 99, 3);
                    strncpy(array[i].name, name, 20);
                    array[i].dni = dni;
                    array[i].age = age;
                    array[i].isEmpty = 1;
                    alta = 0;
                    printf("\n/// El usuario ha sido dado de alta... ///");
                	}
                }
                	if ((alta = 0)) {
                		printf("/// No hay espacio para más usuarios ///");
                	}
                break;
            case 2:
                getInt(&dni, "ingrese dni para la baja : ", "ingrese un dni valido", 1, 100000000, 3);
                i = buscarPorDni(dni, array);

                if (i == -1)
                {
                    printf ("El DNI ingresado no existe entre los datos. Presione cualquier tecla para continuar... \n");
                }
                else
                {
                	array[i].isEmpty = 0;
                    printf("\n/// El usuario ha sido dado de baja... ///");
                }
                break;
            case 3:
                getInt(&dni, "ingrese dni: ", "ingrese un dni valido", 1, 100000000, 3);  //Se pide el dni a modificar
                i = buscarPorDni(dni, array);

                if (i == -1)
                {
                    printf ("El DNI ingresado no existe entre los datos. Presione cualquier tecla para continuar... \n");
                }
                else
                {
                    printf("\nIngrese nombre: ");
                    fgets(name, sizeof(name), stdin);
                    getInt(&age, "ingrese edad: ", "ingrese una edad valida", 1, 99, 3);
                    strncpy(array[i].name, name, 20);
                    array[i].age = age;
                    printf("\n/// El usuario ha sido modificado... ///");
                }
                break;
            case 4:
                mostrar(array);
                break;
            case 5:
                for(i = 0; i < MAXRECORDS - 1; i++) {
                    for(int j = i+1; j < MAXRECORDS; j++) {
                        //strcmp
                        //menor a cero = izquierda es menor derecha
                        //cero         = izquierda es igual que derecha
                        //mayor a cero = izquierda es mayor derecha
                        if(strcmp(array[i].name,array[j].name) > 0)
                        {
                            Student aux = array[i];
                            array[i] = array[j];
                            array[j] = aux;
                        }
                    }
                }
                printf("\n/// La lista fue ordenada... ///");
                break;
            case 6:
                printf("Saliendo...");
                running = false;
                break;
            default:
                printf("Ingrese una opción valida\n");
        }
    }
    return 0;
}

// imprimo el menu en pantalla y el usuario selecciona la opción deseada
int printMenu()
{
    int opcion;
    printf("\n\n/// Menú ///\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Mostrar\n");
    printf("5- Ordenar\n");
    printf("6- Salir\n");
    printf("Elija una opción: ");
    scanf("%d", &opcion);  //Se guarda la opción elegida por el usuario
    getchar(); //saco del buffer el enter...
    return opcion;    //Se retorna el valor elegido por el usuario
}

/*
con el DNi que ingresa el usuario se recorre el array.
Si lo encuentra retorna la posicion donde lo encontró.
Si no lo encuentra retorna -1 para poder controlar en la llamada a la función que hacer.
*/
int buscarPorDni(int dni, Student * array)
{
int i, indice = -1;

for (i = 0 ; i < MAXRECORDS && indice == -1 ; i++) {
    if (array[i].dni == dni && array[i].isEmpty == 1) {
        indice = i;        //si lo encuentra se guarda el el lugar donde lo encontro. (siemore se queda con el ultimo)
    }
}
return indice;   //si no lo encuentra nunca en la recorrida retorna -1 que es el valor original
}

/*int buscarLibre(int isEmpty, Student * alumnos)
{
int i, indice = -1;

for (i = 0 ; i < MAXRECORDS ; i++)
    if (alumnos[i].isEmpty == 0)
        indice = i;        //si lo encuentra se guarda el el lugar donde lo encontro. (siemore se queda con el ultimo)

return indice;   //si no lo encontro nunca en la recorrida retorna -1 que es el valor original

}*/

void mostrar ( Student * array) {

int i;
printf("\n/// Usuarios cargados ///\n");

for(i = 0; i < MAXRECORDS; i++) {
	if(array[i].isEmpty == 1) {
    printf("Nombre: %s", array[i].name);
    printf("DNI: %d\n", array[i].dni);
    printf("Edad: %d\n\n", array[i].age);
	}
}
printf("\npresione cualquier tecla para continuar...");
getchar(); //agregue esto para que despues de mostrar los datos del array haga una pausa
}
