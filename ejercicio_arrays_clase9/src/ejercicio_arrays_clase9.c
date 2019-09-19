#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

typedef struct
{
  int dni;
  char name[20];
  int age;
}Student;

int main() {
	Student array[5];
	//struct Student arraySort[5], aux;
	int age, dni, i, options;
	char name[20];

	while(1) {


	    switch(options) {
	    	case 1:
	    		for(i = 0; i < 6; i++) {
	    			printf("///Ingrese los datos de la persona estudiante///\n");
	    			getInt(&age, "ingrese edad: ", "ingrese una edad valida", 1, 99, 3);
	    			getInt(&dni, "ingrese dni: ", "ingrese un dni valido", 1, 100000000, 3);
	    			printf("Ingrese nombre: ");
	    			fgets(name, sizeof(name), stdin);
	    			array[i].age = age;
	    			array[i].dni = dni;
	    			strncpy(array[i].name, name, 20);
	    		}
	    		printMenu();
	    		break;
	    	case 2:

	    		break;
	    	/*case 3:
	    		getInt(&age, "ingrese edad", "ingrese una edad valida", 1, 99, 3);
	    		getInt(&dni, "ingrese dni", "ingrese un dni valido", 1, 100000000, 3);
	    		printf("\nIngrese nombre ");
	    		fgets(name, sizeof(name), stdin);
	    		for(i = 0; i < 6; i++) {
	    			array[i].age = age;
	    			array[i].dni = dni;
	    			strncpy(array[i].name, name, 20);
	    		}
	    		break;*/
	    	case 4:
	    		for(i = 0; i < 6; i++){
	    			printf("\n Nombre: %s ", array[i].name);
	    			printf("\n Edad: %d ", array[i].age);
	    			printf("\n DNI: %d ", array[i].dni);
	    		}
	    		break;
	    	/*case 5:
	    		for(i = 0; i < 5; i++) {
	    			for(j = i+1; j < 6; j++) {
	    				//strcmp
	    		        //menor a cero = izquierda es menor derecha
	    		        //cero         = izquierda es igual que derecha
	    		        //mayor a cero = izquierda es mayor derecha
	    				if((strcmp(arraySort[i].name,arraySort[j].name))>0)
	    		        {
	    					aux = arraySort[i];
	    		            arraySort[i] = arraySort[j];
	    		            arraySort[j] = aux;
	    		        }
	    			}
	    		}*/
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

int printMenu(int options)
{
	printf("1- Alta\n");
	printf("2- Baja\n");
	printf("3- Modificar\n");
	printf("4- Mostrar\n");
	printf("5- Ordenar\n");
	printf("6- Salir\n");
	scanf("%d", &options);
	return 0;
}

int findFirst(array[])
{
	int i;
	for(i = 0; < countOfElements; i++)
	{
		if(array[i].isEmpty == value) {

		}
	}
}
