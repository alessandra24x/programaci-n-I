#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
/*
    char texto[]="Nona mama";
    char conjuntoCaracteres[]={'N','o','n','a'};
    char caracteres[]={'N','o','n','a',' ','m','a','\0'};

    //Cuenta un caracter de mas
    printf("Texto:%s Tamanio: %d \n", texto, sizeof(texto));
    printf("Longitud de la cadena= %d \n", strlen(texto));

    //Imprime cualquier cosa, printf no sabe donde termina porque no
    //encuentra el \0
    printf("\nConjuntoCaracteres:%s Tamanio: %d \n", conjuntoCaracteres, sizeof(conjuntoCaracteres));
    printf("Longitud de la cadena= %d \n", strlen(conjuntoCaracteres));

    //Ok
    printf("\ncaracteres:%s Tamanio: %d \n", caracteres, sizeof(caracteres));
    printf("Longitud de la cadena= %d \n", strlen(caracteres));
*/

/*
    char texto1[20], texto2[20], texto3[30];

    printf("ingrese texto 1: \n"); //Ingresar Mamma Mia
    fflush(stdin);
    scanf("%s", texto1);
    printf("ingresaste: %s \n", texto1);

    printf("\ningrese texto 2: \n"); //Ingresar Mamma Mia
    fflush(stdin); //comentar y probar
    gets(texto2);
    printf("ingresaste: %s \n", texto2);

    printf("\ningrese texto 3: \n"); //Ingresar Mamma Mia
    gets(texto3);
    printf("ingresaste: %s \n \n", texto3);

*/

    //FUNCIONES CON CARACTERES - #include <stdlib.h>
    // atoi()/atol()//atof = Convierte un string a un número.
    //La conversión se detiene en cuanto se encuentra un carácter
    //no aceptable. Si no se puede convertir la cadena, devuelve 0.
/*
    char letras[] = "123";//"12.3" // "AAA"
    int numeroentero;
    numeroentero = atoi(letras);
    printf("Texto convertido en numeroentero %d \n", numeroentero);

    long numerolong;
    numerolong = atol(letras);
    printf("Texto convertido en numerolong %ld \n", numerolong);

    float numerodecimal;
    numerodecimal = atof(letras);
    printf("Texto convertido en numerodecimal %.2f \n", numerodecimal);
*/
    // itoa() = Convierte un número a una cadena de texto.
    //La cadena contendrá tantos carácteres como dígitos tenga el resultado.
    //El parámetro base especifica la base utilizada para convertir el valor,
    //esta deberá ser entre 2 y 36, inclusive.
    int numero=1234;
    char cadena[20];
    itoa(numero, cadena, 10);

    printf("Numero convertido en texto %s \n", cadena);

    //islower() #include <ctype.h>
    //Comprueba sin un carácter es de tipo minúscula.
    //verifica si pertenece al rango de caracteres de letras minúsculas,
    //que por defecto son los que están en el rango a a z.
    //El valor de retorno será no nulo si es un carácter en minúscula.
    char letra;

    letra='t';
    printf("Letra %c islower(): %d", letra, islower(letra));
    letra='D';
    printf("\nLetra %c islower(): %d", letra, islower(letra));
    letra = 'f';
    if (islower(letra)==0){
        printf("\n NO es minuscula");
    }
    else
    {
        printf("\n ES minuscula");
    }

    //isupper() #include
    //Comprueba sin un carácter es de tipo MAYUSCULAS.
    char letra1;

    letra1='t';
    printf("\nLetra1 %c isupper(): %d", letra1, isupper(letra1));
    letra1='D';
    printf("\nLetra1 %c isupper(): %d", letra1, isupper(letra1));
    letra1 = 'F';
    if (isupper(letra1)==0){
        printf("\n NO es mayuscula");
    }
    else
    {
        printf("\n ES mayuscula");
    }

    //isdigit()
    //Indica si un carácter es numérico
    //Valor devuelto: Verdadero (!=0) o falso (0)
    //Devuelve "verdadero" (un valor distinto de cero) si el carácter es numérico (0 a 9)
    char valor1;
    valor1='5';
    printf("\n\nLetra2 %c isdigit(): %d", valor1, isdigit(valor1));

    if (isdigit(valor1)==0){
        printf("\n NO es un numero");
    }
    else
    {
        printf("\n ES un numero ");
    }

   //isalpha()
   //Comprueba sin un carácter es alfabético.
   //verifica si pertenece al rango de letras (A a Z o a a z).
    char letra2 = '9';
    printf("\n\nletra2 %c isalpha(): %d", letra2, isalpha(letra2));

    if (isalpha(letra2)==0){
        printf("\n NO es un caracter alfabetico \n\n");
    }
    else
    {
        printf("\n ES un caracter alfabetico \n\n");
    }


    return 0;
}
