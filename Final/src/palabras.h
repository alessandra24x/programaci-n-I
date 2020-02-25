#ifndef PALABRAS_H_INCLUDED
#define PALABRAS_H_INCLUDED

struct S_Palabra
{
  char letras[1024];
  char letrasSinRepeticiones[1024];
  int numLetras;
}; typedef struct S_Palabra Palabra;

Palabra* palabra_new();
Palabra* palabra_newParametros(char* letras);
int palabra_delete(Palabra* this);

//char
int palabra_setLetras(Palabra* this,char* letras);
int palabra_getLetras(Palabra* this,char* letras);

int palabra_sortLetras(void* pLetraA,void* pLetraB);
int palabra_sortLongitudLetras(void* pLetraA, void* pLetraB);

void* contadorLetrasDistintas(void* pLetra);
int comparaPalabras(void* pPalabra1, void* pPalabra2);

#endif // PALABRAS_H_INCLUDED
