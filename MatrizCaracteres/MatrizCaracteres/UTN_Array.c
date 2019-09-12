#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_Inputs.h"


//Inicializa
int initArrayInt(int *pArray , int limite, int valor)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i]=valor;
		}
		retorno = 0;
	}
	return retorno;
}
//Imprime
int printArrayInt(int *pArray , int limite)
{
	int retorno = -1;
	int i;
	printf("\nDEBUG\n");
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			printf("\n\t%i",pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}
//Imprime Texto
int printArrayStr(char pArray[][50], int limite)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			printf("%s", pArray[i]);
			printf("\n");
		}
		retorno = 0;
	}
	return retorno;
}
//Ordena
//Imprime Texto
int Ordenar2ArrayStr(char pArrayNombre[][50],char pArrayApellido[][50],int limite)
{
	int flagDesordenado = -1;
	int i;
	char auxiliarNombreStr[50];
	char auxiliarApellidoStr[50];

    while (flagDesordenado==-1)
    {
      flagDesordenado=0;
      for(i=0;i<limite-1;i++)
       {
         if(strcmp(pArrayApellido[i],pArrayApellido[i+1])>0)
             {
                strcpy(auxiliarNombreStr,pArrayNombre[i]);
                strcpy(pArrayNombre[i],pArrayNombre[i+1]);
                strcpy(pArrayNombre[i+1],auxiliarNombreStr);

                strcpy(auxiliarApellidoStr,pArrayApellido[i]);
                strcpy(pArrayApellido[i],pArrayApellido[i+1]);
                strcpy(pArrayApellido[i+1],auxiliarApellidoStr);

                flagDesordenado = -1;
             }
       }
    }
	return 0;
}

//Carga
int getArrayInt(int *pArray,int limite,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int buffer;
	int i=0;
	char respuesta;
	printf("\nDEBUG\n");
	if(pArray != NULL && limite > 0)
	{
		do
		{

			if(	getInt(	&buffer, pMensaje, pMensajeError, minimo, maximo, reintentos) == 0)
			{
				pArray[i] = buffer;
				i++;
				if(i == limite)
				{
					break;
				}
			}

			printf("Continuar (s/n)? \n");
			fflush(stdin); // __fpurge(stdin)
			scanf("%c",&respuesta);
		}while(respuesta != 'n');
		retorno = i;
	}
	return retorno;
}
//Minimo y Maximo
int minMaxArrayInt(int* pArray,int limite,int* minimo,int* maximo)
{
    int min=*minimo;
    int max=*maximo;
    int i;

    for (i=0; i<limite; i++)
    {
        if(i==0){
            min=pArray[i];
            max=pArray[i];
        }
        else
        {
            if (pArray[i]<min){
                min=pArray[i];
            }
            if (pArray[i]>max){
                max=pArray[i];
            }
        }
    }
    *minimo = min;
    *maximo = max;

   return 0;
}

//Suma
int sumaArrayInt(int* pArray,int limite,int* resultado)
{
    int res=0;
    int i;

    for (i=0; i<limite; i++)
    {
        res=res+pArray[i] ;
    }

    *resultado = res;

   return 0;
}

//Promedio
int promedioArrayInt(int* pArray,int limite,int* resultadoProm)
{
    int res=0;
    int i;

    for (i=0; i<limite; i++)
    {
        res=res+pArray[i] ;
    }

    *resultadoProm = res/limite;

   return 0;
}
//Ordena
int OrdenaArrayInt(int* pArray,int limite)
{
    int i, aux, flagOrdenado=-1;
    int* arrayAux = pArray;


    while(flagOrdenado==-1)
    {
        flagOrdenado=0;
        //1PASADA
        for(i=0; i<(limite-1);i++)
        {
           if(arrayAux[i]>arrayAux[i+1]){
            //swap
            aux = arrayAux[i];
            arrayAux[i]=arrayAux[i+1];
            arrayAux[i+1]=aux;
            flagOrdenado=-1;
           }
        }

    }

    pArray = arrayAux;

   return 0;
}
