/*
 ============================================================================
 Name        : game.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
	int hiddenNumber;
	int numberEntered;
	char keyEntered;
	int play;

	keyEntered = 's';
	while(keyEntered == 's')
	{
		hiddenNumber = getRandomNumber(1, 100, 1);

		play = 1;
		while(play == 1)
		{
			numberEntered = getInt("Ingrese un numero (0 - 99) \n");
			if(numberEntered < 0)
			{
				play = 0;
			}
			else if(numberEntered == hiddenNumber)
			{
				printf("FELICITACIONES GANASTE!!! \n");
				play = 0;
			}
			else if(numberEntered > hiddenNumber)
			{
				printf("EL NUMERO QUE INGRESASTE ES GRANDE!!! \n");
				fflush(stdout);
			}
			else if(numberEntered < hiddenNumber)
			{
				printf("EL NUMERO INGRESADO ES CHICO!!! \n");
				fflush(stdout);
			}
		}

		keyEntered = getChar("Desea jugar nuevamente? (s/n)\n");
	}

	return 0;
}
