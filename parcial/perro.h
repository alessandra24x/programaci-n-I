#ifndef PERRO_H_INCLUDED
#define PERRO_H_INCLUDED

struct S_Perro
{
  int id;
  char nombre[128];
  int dias;
  char raza[128];
  char reservado[64];
  char sexo[64];
};
typedef struct S_Perro Perro;

Perro* perro_new();
Perro* perro_newParametros(char* idStr,char* nombreStr,char* diasStr, char* razaStr, char* reservadoStr, char* sexoStr);
int perro_delete(Perro* this);

int perro_setIdStr(Perro* this,char* idStr);
int perro_setId(Perro* this,int id);
int perro_getId(Perro* this,int* id);

int perro_setNombre(Perro* this,char* nombre);
int perro_getNombre(Perro* this,char* nombre);

int perro_setDiasStr(Perro* this,char* diasStr);
int perro_setDias(Perro* this,int dias);
int perro_getDias(Perro* this,int* dias);

int perro_setRaza(Perro* this,char* raza);
int perro_getRaza(Perro* this,char* raza);

int perro_setReservado(Perro* this,char* reservado);
int perro_getReservado(Perro* this,char* reservado);

int perro_setSexo(Perro* this,char* sexo);
int perro_getSexo(Perro* this,char* sexo);

int filtrarMenores45Dias(void* perro);
int filtrarMachos(void* perro);
int filtrarRazas(void* perro);


#endif // PERRO_H_INCLUDED
