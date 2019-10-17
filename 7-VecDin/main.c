#include <stdio.h>
#include <stdlib.h>
int main()
{
 int i;
 int* vec;
 int* vaux;
 vec=(int*)malloc(sizeof(int)*5);  //DECLARAR UN VECTOR DINAMICAMENTE
 if (vec!=NULL)
 {
     for (i=0;i<5;i++)
     {
         *(vec+i)=i;  //CARGA SECUENCIAL
     }
 }   //MOSTRAR CON NOTACION ARITMETICA Y VECTORIAL
     for (i=0;i<5;i++)
     {
        printf("\n Notacion Aritmetica Contenido %d posicion %d", *(vec+i), i);
        printf("\n Notacion Vectorial Contenido %d posicion %d", vec[i], i);
     }
    //AGRANDAR EL VECTOR A 10
    vaux = (int*)realloc(vec,sizeof(int)*10); //AGRANDAR SU TAMAÑO DINAMICAMENTE
        if (vaux!=NULL)
        {
            vec = vaux;
        }
    //CARGAR LOS ELEMENTOS RESTANTES SECUENCIALMENTE
    for(i=5;i<10;i++)
        {
         *(vec+i)=i;
    }
    //MOSTRAR CON NOTACION ARITMETICA
     for (i=0;i<10;i++)
     {
        printf("\n Notacion Aritmetica Contenido %d posicion %d", *(vec+i), i);
     }
     free(vec); //LIBERAR ESPACIO
     free (vaux); //LIBERAR ESPACIO
    return 0;
}
