#ifndef PALABRAS_H_INCLUDED
#define PALABRAS_H_INCLUDED

struct S_Palabra
{
  char letras[1024];
}; typedef struct S_Palabra Palabra;

Palabra* palabra_new();
Palabra* palabra_newParametros(char* letras);
int palabra_delete(Palabra* this);

//char
int palabra_setLetras(Palabra* this,char* letras);
int palabra_getLetras(Palabra* this,char* letras);
int palabra_sortLetras(void* pLetraA,void* pLetraB);
int palabra_sortLongitudLetras(void* pLetraA, void* pLetraB);
int contadorLetrasDistintas(void* pLetra);



#endif // PALABRAS_H_INCLUDED
