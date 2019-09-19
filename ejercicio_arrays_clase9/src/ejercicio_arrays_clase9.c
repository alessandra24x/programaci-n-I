#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
 
#define MAXRECORDS 3  //constante para el limite del arrays
typedef struct
{
  char name[20];
  int dni;
  int age;
  int isEmpty = 0;
  int id = 0;
}Student;
 
 
int printMenu();
int buscarPorDni (int a, Student *s) ;
void mostrarAlumnos (Student * s);
 
 
int main() {
    Student array[MAXRECORDS], aux;
    //struct Student arraySort[5], aux;
    int age, dni, dniaux, i, j, options;
    char name[20];
 
    while(1) {
 
        options = printMenu(); //Se guarda en esta variable lo que retorna la función printMenu()
        switch(options) {
            case 1:
                for(i = 0; i < MAXRECORDS; i++) {
                    printf("///Ingrese los datos de la persona estudiante///\n");
                    printf("Ingrese nombre: ");
                    fgets(name, sizeof(name), stdin);
                    getInt(&dni, "ingrese dni: ", "ingrese un dni valido", 1, 100000000, 3);
                    getInt(&age, "ingrese edad: ", "ingrese una edad valida", 1, 99, 3);
                    strncpy(array[i].name, name, 20);
                    array[i].dni = dni;
                    array[i].age = age;
                    //isEmpty++;
                }
                break;
            case 2:
                getInt(&id, "ingrese id: ", "ingrese un id valido", 1, 1000, 3);
                i = buscarLibre(isEmptyAux, array);
                
                if (i == -1)
                {
                    printf ("El DNI ingresado no existe entre los datos. Presione cualquier tecla para continuar... \n");
                    getchar();
                }
                else
                {
                	array[i].isEmpty = 1;
                    return 0;
                }
                break;
            case 3:
                getInt(&dniaux, "ingrese dni: ", "ingrese un dni valido", 1, 100000000, 3);  //Se pide el dni a modificar
                i = buscarPorDni(dniaux, array);
 
                if (i == -1)
                {
                    printf ("El DNI ingresado no existe entre los datos. Presione cualquier tecla para continuar... \n");
                    getchar();
                }
                else
                {
                    printf("\nIngrese nombre: ");
                    fgets(name, sizeof(name), stdin);
                    getInt(&age, "ingrese edad: ", "ingrese una edad valida", 1, 99, 3);
                    strncpy(array[i].name, name, 20);
                    array[i].age = age;
                }
                break;
            case 4:
                mostrarAlumnos(array);
                break;
            case 5:
                for(i = 0; i < MAXRECORDS - 1; i++) {
                    for(j = i+1; j < MAXRECORDS; j++) {
                        //strcmp
                        //menor a cero = izquierda es menor derecha
                        //cero         = izquierda es igual que derecha
                        //mayor a cero = izquierda es mayor derecha
                        if((strcmp(array[i].name,array[j].name))>0)
                        {
                            aux = array[i];
                            array[i] = array[j];
                            array[j] = aux;
                        }
                    }
                }
                break;
            case 6:
                printf("Saliendo...");
                return 0;
            default:
                printf("Ingrese una opción valida\n");
                break;
        }
        system("clear");
    }
}

// imprimo el menu en pantalla y el usuario selecciona la opción deseada
int printMenu()    
{
    int opcion; 
 
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Mostrar\n");
    printf("5- Ordenar\n");
    printf("6- Salir\n");
    scanf("%d", &opcion);  //Se guarda la opción elegida por el usuario
 
    return opcion;    //Se retorna el valor elegido por el usuario
 
 
/*
con el DNi que ingresa el usuario se recorre el array.
Si lo encuentra retorna la posicion donde lo encontró.
Si no lo encuentra retorna -1 para poder controlar en la llamada a la función que hacer. 
*/
int buscarPorDni(int dni, Student * alumnos)
{
int i, indice = -1;
 
for (i = 0 ; i < MAXRECORDS ; i++)
    if (alumnos[i].dni == dni)
        indice = i;        //si lo encuentra se guarda el el lugar donde lo encontro. (siemore se queda con el ultimo)
 
return indice;   //si no lo encuentra nunca en la recorrida retorna -1 que es el valor original
 
}

int buscarLibre(int isEmpty, Student * alumnos)
{
int i, indice = -1;
 
for (i = 0 ; i < MAXRECORDS ; i++)
    if (alumnos[i].isEmpty == 0)
        indice = i;        //si lo encuentra se guarda el el lugar donde lo encontro. (siemore se queda con el ultimo)
 
return indice;   //si no lo encontro nunca en la recorrida retorna -1 que es el valor original
 
}
 
void mostrarAlumnos ( Student * alumnos)
{
int i;
 
for(i = 0; i < MAXRECORDS; i++)
{
    printf("\n Nombre: %s ", alumnos[i].name);
    printf("\n DNI: %d ", alumnos[i].dni);
    printf("\n Edad: %d ", alumnos[i].age);
}
printf("\npresione cualquier tecla para continuar...");
getchar(); //agregue esto para que despues de mostrar los datos del array haga una pausa
getchar();
}
