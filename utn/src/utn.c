float getFloat(char mensaje []) {
	float auxiliar;
	printf("%s",mensaje);
	scanf("%f", &auxiliar);
	return auxiliar;
}

int getInt(char mensaje []) {
	float auxiliar;
	printf("%s",mensaje);
	scanf("%d", &auxiliar);
	return auxiliar;
}

char getChar(char mensaje []) {
	float auxiliar;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c", &auxiliar);
	return auxiliar;
}
