void crearMazo(Carta arrayDeCartas[]) {
	const char *palos[] = {"COPA", "ORO", "BASTO", "ESPADA"};
	int numero,j;
	int indice;

	for(j = 0; j < 4; j++) {
		for(numero = 1; numero < 13; numero++) {
			indice = numero + (12 * j);
			arrayDeCartas[indice].numero = numero;
			strcpy(arrayDeCartas[indice].palo, palos[j]);
			if(numero == 8 || numero == 9) {
				arrayDeCartas[indice].valor = 0;
			} else if(numero < 8) {
				arrayDeCartas[indice].valor = numero;
			} else {
				arrayDeCartas[indice].valor = 0.5;
			}
		}
	}
}

void mezclarMazo(Carta arrayDeCartas[]) {
	int i,j;
	Carta auxiliar;

	getNumeroAleatorio(0, 1, 1);
	for(i = 0; i < CANTIDAD_CARTAS; i++) {
		for(j = i+1; j < CANTIDAD_CARTAS; j++) {
			auxiliar = arrayDeCartas[i];
			arrayDeCartas[i] = arrayDeCartas[j];
			arrayDeCartas[j] = auxiliar;
		}
	}
}
