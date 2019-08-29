/*
 ============================================================================
 Name        : Clase_03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANT_ITERA 5
int calculaNumMaximoyNumMinimo(int cantidadNumeros, int *maximo, int *minimo);
int main(void)
{
	 int maximo;
	 int minimo;
	 if(calculaNumMaximoyNumMinimo(CANT_ITERA, &maximo, &minimo) == 0)
	 {
	 printf("\nNumero Maximo = %d\n", maximo);
	 printf("\nNumero Minimo = %d\n", minimo);
	 }
	 return 0;
}

int calculaNumMaximoyNumMinimo(int cantidadNumeros, int *maximo, int *minimo)
{
	int numero;
	int numMaximo;
	int numMinimo;
	int i;
	int retorno = -1;
	if(cantidadNumeros > 0 && *maximo != NULL && *minimo != NULL)
	{
		for(i = 0; i <= cantidadNumeros; i++) {
			printf("Ingrese un numero: \n");
			scanf("%d",&numero);
			if(i == 0 || numero > numMaximo)
			{
			  numMaximo = numero;
			}
			if(i == 0 || numero < numMinimo)
			{
			  numMinimo = numero;
			}
		}
		*maximo = numMaximo;
		*minimo = numMinimo;
		retorno = 0;
	}
	return retorno;
}
