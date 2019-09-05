/*
 ============================================================================
 Name        : Clase_05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define QTY_EDADES 12

int initArrayInt(int *pArray , int limite, int valor);
int printArrayInt(int *pArray , int limite);
int getArrayInt(	int *pArray,
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos);
int getInt(	int *pResultado,
		char *pMensaje,
		char *pMensajeError,
		int minimo,
		int maximo,
		int reintentos);
int printNumeroMinimoyMaximo(int *pArray , int limite);
int printPromedio(int *pArray , int limite);
int printSuma(int *pArray, int limite);


int main(void)
{
	int edades[QTY_EDADES] = {12,25,32,11,56,65,21,32,33,38,14,45};
	//int cantidadUsuario;
	//initArrayInt(edades,QTY_EDADES,22);
	//cantidadUsuario = getArrayInt(edades,QTY_EDADES,"Edad?\n","Error\n",0,200,2);

	//printArrayInt(edades,cantidadUsuario);
	printNumeroMinimoyMaximo(edades, QTY_EDADES);
	printPromedio(edades, QTY_EDADES);
	printSuma(edades, QTY_EDADES);
	return EXIT_SUCCESS;
}

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

int getArrayInt(	int *pArray,
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
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

			if(	getInt(	&buffer,
						pMensaje,
						pMensajeError,
						minimo,
						maximo,
						reintentos) == 0)
			{
				pArray[i] = buffer;
				i++;
				if(i == limite)
				{
					break;
				}
			}

			printf("Continuar (s/n)? \n");
			__fpurge(stdin); // fflush(stdin)
			scanf("%c",&respuesta);
		}while(respuesta != 'n');
		retorno = i;
	}
	return retorno;
}

int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = -1;
	int buffer;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}

int printNumeroMinimoyMaximo(int *pArray , int limite)
{
	int retorno = -1;
	int numMinimo = pArray[0];
	int numMaximo = pArray[0];
	int i;
	printf("\nDEBUG\n");
	if(pArray != NULL)
	{
		for(i=1;i<limite;i++)
		{
			if(pArray[i] < numMinimo) {
				numMinimo = pArray[i];

			}
			if(pArray[i] > numMaximo) {
				numMaximo = pArray[i];
			}


		}
		printf("\nNumero Minimo:\n%i",numMinimo);
		printf("\nNumero Maximo:\n%i",numMaximo);
		retorno = 0;
	}
	return retorno;
}

int printPromedio(int *pArray , int limite)
{
	int retorno = -1;
	int acumulador = 0;
	int promedio;
	int i;
	if(pArray != NULL)
	{
		for(i=0;i<limite;i++)
		{
			acumulador = acumulador + pArray[i];

		}
		promedio = acumulador / limite;
		printf("\nPromedio:\n%i",promedio);
		retorno = 0;
	}
	return retorno;
}

int printSuma(int *pArray, int limite)
{
	int retorno = -1;
	int suma = 0;
	int i;
	if(pArray != NULL)
	{
		for(i=0;i<limite;i++)
		{
			suma += pArray[i];

		}
		printf("\nSuma:\n%i",suma);
		retorno = 0;
	}
	return retorno;
}

