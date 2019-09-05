float sum(float a, float b) {
	float total;
	total = a + b;
	return total;
}

float subtraction(float a, float b) {
	float total;
	total = a - b;
	return total;
}

float multiplication(float a, float b) {
	float total;
	total = a * b;
	return total;
}

float division(float a, float b) {
	float total;
	if(b <= 0) {
		printf("No es posible dividir por cero");
	}
	total = a / b;
	return total;
}

float factorialA(float a) {
	int i, factorial = 1;
	    for (i = 1; i <= a; i++){
	        factorial = factorial * i;
	    }
	    return factorial;
}

float factorialB(float b) {
	int i, factorial = 1;
	    for (i = 1; i <= b; i++){
	        factorial = factorial * i;
	    }
	    return factorial;
}
