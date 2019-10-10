#include<stdio.h>

int main ()
{
  long edad, aux;
  long *p;
  long *p1;
  long *pAux;

  edad = 50;
  p = &edad;
  //Asignacion de punteros
  p1=p;


  printf("La edad es %ld\n", edad );
  printf("Direccion de memoria de edad: %p",&edad);
  printf("p es %p\n", p );
  printf("p1 es %p\n", p1 );
  printf("*p es %d\n", *p );
  printf("*p1 es %d\n", *p1 );

  //Modificar el valor de la variable apuntada desde el puntero
  *p = *p / 2;
  printf("\n\nLa edad es %ld\n", edad );
  printf("p es %p\n", p );
  printf("p1 es %p\n", p1 );


  //Comparacion de Punteros c/puntero
  pAux = &aux;
  printf("\n\npAux es %p\n", pAux );

  if (p<pAux)
    printf("\nEl puntero p apunta a una direccion mas baja que pAux");
  else if (p>pAux)
    printf("\nEl puntero pAux apunta a una direccion mas baja que p");


    //Comparacion de punteros c/direccion de una variable

  printf("\n\n&edad es %p\n", &edad );

  if (&edad<pAux)
    printf("\nLa dir de memoria de edad apunta a una direccion mas baja que pAux");
  else if (&edad>pAux)
    printf("\nEl puntero pAux apunta a una direccion mas baja que la dir de memoria de edad");

    //Comparacion de punteros con valor literal

  if (p<00600000)
    printf("\n\nLa dir de memoria de p apunta a una direccion mas baja que el literal");
  else if (p>00600000)
    printf("\n\nEl literal apunta a una direccion mas baja que p");

    return 0;

}
