#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
	char options;
	float operator1, operator2;
	printf("Bienvenide a la calculadora, ingrese la opci�n que desea realizar:\n");
	printf("Suma: +\n");
	printf("Resta: -\n");
	printf("Multiplicaci�n: *\n");
	printf("Divisi�n: /\n");
	printf("Factorial: !\n");
	scanf("%c", &options);

	printf("Ingrese el 1er n�mero: %f\n", operator1);
	printf("Ingrese el segundo n�mero: %f\n", operator2);
	scanf("%f %f", &operator1, &operator2);

	switch(options) {
		case '+':
			float resultado = sum(float a, float b);
			printf("El resultado de la suma es: %f", resultado);
			break;
		case '-':
			float resultado = subtraction(float a, float b);
			printf("El resultado de la resta es: %f", resultado);
			break;
		case '*':
			float resultado = multiplication(float a, float b);
			printf("El resultado de la multiplicaci�n es: %f", resultado);
			break;
		default:
			printf("Ingrese una opci�n valida\n");
	}

	return 0;
}
