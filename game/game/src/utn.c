#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * \brief Pide un numero al usuario
 * \param recibe un mensaje como parametro
 * \return numero ingresado por el usuario
 */

int getInt(char mensaje[])
{
	int number;
	printf("%s", mensaje);
	fflush(stdout);
	scanf("%d", &number);
	return number;
}

/**
 * \brief Pide un numero flotante al usuario
 * \param recibe un mensaje como parametro
 * \return numero ingresado por el usuario
 */

float getFloat(char mensaje[])
{
	float number;
	printf("%s", mensaje);
	fflush(stdout);
	scanf("%f", &number);
	return number;
}

/**
 * \brief Pide un caracter al usuario
 * \param recibe un mensaje como parametro
 * \return caracter ingresado por el usuario
 */

char getChar(char mensaje[])
{
	char auxiliar[20];
	printf("%s", mensaje);
	fgets(auxiliar, 20, stdin);
	return auxiliar;
}

char getRandomNumber(int from, int until, int init)
{
	if(init)
		srand(time(NULL));
	return from + (rand() % (until + 1 - from));
}
