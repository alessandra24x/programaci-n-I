/*
 ============================================================================
 Name        : ejercicio_arrays.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utn.h>

typedef struct Student
{
  int dni;
  char name[30];
  int age;
};
typedef struct S_Student Student;


int main(void) {
	Student array[100];
	int age, dni;
	char name[30];

	getInt(&age, "ingrese edad", "", "", "", "");
	getInt(&dni, "ingrese dni", "", "", "", "");
	getString(name, "ingrese nombre", "", "", "", "");

	array[0].age = age;
	array[0].dni = dni;

	strncpy(array[0].name, name, 30);


	return EXIT_SUCCESS;
}
