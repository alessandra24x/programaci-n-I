#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED

struct S_Vendedor
{
  int id;
  char nombre[128];
  int nivel;
  int cantidad_ventas;
  float monto;
  float comisiones;
}; typedef struct S_Vendedor Vendedor;

Vendedor* vendedor_new();
Vendedor* vendedor_newParametros(char* idStr,char* nombre,char* nivelStr, char* cantidad_ventasStr, char* montoStr, char* comisionesStr);
int vendedor_delete(Vendedor* this);

int vendedor_setIdStr(Vendedor* this,char* idStr);
int vendedor_setId(Vendedor	* this,int id);
int vendedor_getId(Vendedor* this,int* id);

int vendedor_setNombre(Vendedor* this,char* nombre);
int vendedor_getNombre(Vendedor* this,char* nombre);

int vendedor_setNivelStr(Vendedor* this,char* nivelStr);
int vendedor_setNivel(Vendedor* this,int nivel);
int vendedor_getNivel(Vendedor* this,int* nivel);

int vendedor_setCantidad_ventasStr(Vendedor* this,char* cantidad_ventasStr);
int vendedor_setCantidad_ventas(Vendedor* this,int cantidad_ventas);
int vendedor_getCantidad_ventas(Vendedor* this,int* cantidad_ventas);

int vendedor_setMontoStr(Vendedor* this,char* montoStr);
int vendedor_setMonto(Vendedor* this,float monto);
int vendedor_getMonto(Vendedor* this,float* monto);

int vendedor_setComisionesStr(Vendedor* this,char* comisionesStr);
int vendedor_setComisiones(Vendedor* this,float comisiones);
int vendedor_getComisiones(Vendedor* this,float* comisiones);

#endif // VENDEDOR_H_INCLUDED
