#include <stdio.h>
#include <stdlib.h>

int main(void) {
	Carta arrayDeCartas[49];
	int opcion;
	float puntosAcumulados;
	int i;
	char jugar = 's';

	crearMazo(arrayDeCartas);

	while(jugar == 's') {
		puntosAcumulados = 0;
		mezclarMazo(arrayDeCartas);
		for(i = 0; i < CANTIDAD_CARTAS; i++) {
			printf("Su carta es &d de %s\n", arrayDeCartas[i].numero, arrayDeCartas[i].palo);
			puntosAcumulados = puntosAcumulados + arrayDeCartas[i].valor;
			if(puntosAcumulados == 7.5) {
				printf("GANO!!!!!\n");
				break;
			} else if(puntosAcumulados > 7.5) {
				printf("PERDIO!!!!!!\n");
				break;
			} else {
				printf("Su puntaje es %0.1f\n", puntosAcumulados);
				opcion = getInt("Plantarse (1) - Otra carta (2)");
				if (opcion == 1) {
					break;
				}
			}
		}
		jugar = getChar("Para jugar nuevamente pulse (s) \n");
	}
	return 0;
}
