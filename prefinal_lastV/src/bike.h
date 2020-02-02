#ifndef BIKE_H_INCLUDED
#define BIKE_H_INCLUDED

struct S_Bike
{
  int id;
  char nombre[128];
  char tipo[128];
  int tiempo;
  float velocidadP;
};
typedef struct S_Bike Bike;

Bike* bike_new();
Bike* bike_newParametros(char* idStr,char* nombreStr,char* tipoStr, char* tiempoStr, char* velocidadPStr);
int bike_delete(Bike* this);

int bike_setIdStr(Bike* this,char* idStr);
int bike_setId(Bike* this,int id);
int bike_getId(Bike* this,int* id);

int bike_setNombre(Bike* this,char* nombre);
int bike_getNombre(Bike* this,char* nombre);

int bike_setTipo(Bike* this,char* tipo);
int bike_getTipo(Bike* this,char* tipo);

int bike_setTiempoStr(Bike* this,char* tiempoStr);
int bike_setTiempo(Bike* this,int tiempo);
int bike_getTiempo(Bike* this,int* tiempo);

int bike_setVelocidadPStr(Bike* this,char* velocidadPStr);
int bike_setVelocidadP(Bike* this,float velocidadP);
int bike_getVelocidadP(Bike* this,float* velocidadP);

void* bike_calcularVelocidadP(void* pBike);
int filtrar(void* pBike);

int bike_compareTipo(void* pTipoA,void* pTipoB);
int bike_compareTiempo(int tiempoA, int tiempoB);

#endif // BIKE_H_INCLUDED
