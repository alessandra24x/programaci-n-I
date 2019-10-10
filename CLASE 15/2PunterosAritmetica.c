#include<stdio.h>

int main ()
{
  char a;
  char *p;
  int b=2;
  int *pEntero;

  a = 'm';
  p = &a;

  //Aritmetica de Punteros

  printf("->La variable a es %c\n", a );
  printf("->*p es %c\n", *p );
  printf("->p es %p\n", p );

  //Incrementar el valor (dir de memoria) del puntero
  p = p + 2; //nueva dir de p = dir de p + (2*sizeof(char))
  printf("\n->Sumo 2 -> p ahora es %p\n", p );
//  system("pause");
//  printf("\n->Contenido de la variable a la que apunta p %c\n", *p );



  p = &a; //vuelvo a asignar la dir de memoria de a

  p++; //nueva dir de p = dir de p + (1*sizeof(char))
  printf("\n -> p con ++ -> ahora es %p\n", p );

  //Incrementar el contenido de un puntero
  //b=2;
  pEntero=&b;

  printf("\nIndireccion de puntero ->*pEntero es %d\n", *pEntero );

  *pEntero=*pEntero+2;

  printf("\n->*pEntero sumado ahora es %d\n", *pEntero );

  printf("\n-> b=2 Modificado desde el puntero ->ahora es %d\n", b );


    return 0;

}
