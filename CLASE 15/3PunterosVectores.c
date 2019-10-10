#include<stdio.h>

int main ()
{
  int vec[8]={10,11,12,13,14,15,16,17};
  int *pVec;
  int i;

  pVec = &vec[0];//ASI NO // Igual pVec = vec


  for (i=0;i<8;i++)
  {
      printf("\n->Posicion %d ->Valor %d", i, vec[i]);
  }

  //Acceder al 5to elemento con notación vectorial
  printf("\n->5ta Posicion notacion vectorial %d", vec[4]);

  //Acceder al 5to elemento con aritmetica de punteros
  printf("\n->5ta Posicion aritmetica %d", *(pVec+4));


  //Acceder al 5to elemento con notacion vectorial desde el puntero
  printf("\n->5ta Posicion vectorial desde puntero %d", pVec[4]);


  //Recorrido con Aritmetica de Punteros
 for (i=0;i<8;i++)
  {
      printf("\n->Aritmetica: Posicion %d ->Valor %d", i, *(pVec+i));
      //direccion_actual_del_puntero + (i * sizeof(tipo))
  }


  //Moviendo posiciones con Aritmetica de Punteros
  i=0;
 while (i < 8)  //while(*punteroCadena != '\0')  Si fuera un puntero a Char
  {
      printf("\n->Moviendo con Aritmetica: ->Dir   %p", pVec);
      printf("\n->Moviendo con Aritmetica: ->Valor %d", *pVec);
      pVec++;  //direccion_actual_del_puntero + (1 * sizeof(tipo))
      i++;
  }


  return 0;

}
