#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldo;
}eEmpleado;

void mostrarEmpleados(eEmpleado** lista, int len);
eEmpleado* new_EmpleadoParam( int leg, char* nombre, char* apellido, float sueldo);
eEmpleado* new_Empleado();
int empleado_setLegajo(eEmpleado* this,int legajo);
int empleado_getLegajo(eEmpleado* this,int* legajo);

int main()
{
     eEmpleado** lista = (eEmpleado**) malloc(sizeof(eEmpleado*));
     eEmpleado** pAuxEmpleado;
     int cont = 0;
     //int cant;
     char resp='s';
     int bufLegajo;
     char bufNombre[20];
     char bufApellido[20];
     float bufSueldo;

     eEmpleado* nuevoEmpleado = new_Empleado();


     printf("\nLegajo    Nombre       Apellido       Sueldo \n");
     printf(" %5d   %10s   %10s  %8.2f\n", nuevoEmpleado->legajo, nuevoEmpleado->nombre, nuevoEmpleado->apellido, nuevoEmpleado->sueldo);
     printf("\n\n");


    while (resp == 's')
    {

        printf("\nIngrese legajo del Empleado: ");
        scanf("%d", &bufLegajo);
        fflush(stdin);

        printf("\nIngrese nombre del Empleado: ");
        gets(bufNombre);

        printf("\nIngrese apellido del Empleado: ");
        gets(bufApellido);

        printf("\nIngrese sueldo del Empleado: ");
        fflush(stdin);
        scanf("%f",&bufSueldo);
        fflush(stdin);

        nuevoEmpleado = new_EmpleadoParam(bufLegajo, bufNombre,bufApellido,bufSueldo);

         // *(lista + cont) = *nuevoEmpleado;
          *(lista + cont) = nuevoEmpleado;
          //lista[cont] = nuevoEmpleado;

        printf("\n Desea ingresar otro Empleado? s/n: ");
        scanf("%c",&resp);
        fflush(stdin);

        if (resp=='s')
        {
            cont++;
            pAuxEmpleado = (eEmpleado**) realloc(lista, sizeof(eEmpleado*) *(cont+1));
            if(pAuxEmpleado == NULL){
                exit(1);
            }
            lista = pAuxEmpleado;
        }
   }

    printf("\nLegajo        Nombre         Apellido     Sueldo \n");
    mostrarEmpleados(lista, cont);

    free(lista);
    free(pAuxEmpleado);
    free(nuevoEmpleado);

    return 0;
}


void mostrarEmpleados(eEmpleado** lista, int len){
int auxleg;
for(int i=0; i <= len; i++){
    empleado_getLegajo(*(lista+i),&auxleg);
    printf(" %5d   %10s   %15s     %8.2f\n", auxleg, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
}
printf("\n\n");

}


eEmpleado* new_Empleado(){

eEmpleado* emp = (eEmpleado*)malloc( sizeof(eEmpleado));

if(emp != NULL){
    emp->legajo = 0;
    strcpy(emp->nombre, "");
    strcpy(emp->apellido, "");
    emp->sueldo = 0;

}
return emp;
}

eEmpleado* new_EmpleadoParam( int leg, char* nombre, char* apellido, float sueldo){

eEmpleado* emp = (eEmpleado*)malloc( sizeof(eEmpleado));

if(emp != NULL){
    empleado_setLegajo(emp,leg);
        //emp->legajo = leg;
        strcpy(emp->nombre, nombre);
        strcpy(emp->apellido, apellido);
        emp->sueldo = sueldo;
    }
    return emp;
}

int empleado_setLegajo(eEmpleado* this,int legajo){

   int todoOk = 0;

   if( this != NULL && legajo > 0 ){

    this->legajo = legajo;
    todoOk = 1;
   }

   return todoOk;
}

int empleado_getLegajo(eEmpleado* this,int* legajo){

    int todoOk = 0;

    if( this != NULL && legajo != NULL){

        *legajo = this->legajo;
        todoOk = 1;
    }

    return todoOk;
}
