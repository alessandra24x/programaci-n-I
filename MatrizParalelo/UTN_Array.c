#include <stdio.h>
#include <stdlib.h>
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
