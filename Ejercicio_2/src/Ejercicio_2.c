/*
 ============================================================================
 Name        : Ejercicio_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float pedirNumero();
float calcularAreaCirculo(float radio);

int main() {
	float auxiliar;
	float area;

	auxiliar = pedirNumero();
	area = calcularAreaCirculo(auxiliar);
	printf("El area del circulo es: %f\n", area);
	return 0;
}

/**
 *\brief Pide un numero al usuario y lo retorna
 *\return Numero ingresado por el usuario
 */

float pedirNumero()
{
	float numero;
	printf("Ingrese un numero: ");
	fflush(stdout);
	scanf("%f", &numero);
	return numero;
}

/**
 *\brief Recibe el radio y calcula el area del circulo
 *\param Radio correspondiente al radio del circulo
 *\return El area del circulo
 */

float calcularAreaCirculo(float radio)
{
	float resultado;
	resultado = 3.14 * radio * radio;
	return resultado;
}
