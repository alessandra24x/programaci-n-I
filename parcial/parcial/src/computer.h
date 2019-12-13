#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED

struct S_computer
{
  int id;
  char descripcion[128];
  int precio;
  int idTipo;
  char oferta[128];
};
typedef struct S_computer Computer;

Computer* computer_new();
Computer* computer_newParametros(char* idStr,char* descripcionStr,char* precioStr, char* idTipoStr, char* oferta);
int computer_delete(Computer* this);

int computer_setIdStr(Computer* this,char* idStr);
int computer_setId(Computer* this,int id);
int computer_getId(Computer* this,int* id);

int computer_setDescripcion(Computer* this,char* descripcion);
int computer_getDescripcion(Computer* this,char* descripcion);

int computer_setPrecioStr(Computer* this,char* precioStr);
int computer_setPrecio(Computer* this,int precio);
int computer_getPrecio(Computer* this,int* precio);

int computer_setIdTipoStr(Computer* this,char* idTipoStr);
int computer_setIdTipo(Computer* this,int idTipo);
int computer_getIdTipo(Computer* this,int* idTipo);

int computer_setOfertaStr(Computer* this,char* ofertaStr);
int computer_setOferta(Computer* this,char* oferta);
int computer_getOferta(Computer* this,char* oferta);

int computer_compareIdTipo(void* pComputerA,void* pComputerB);
void computer_mapIdTipo(void* pComputer);
int filtrar(void* computer);


#endif // COMPUTER_H_INCLUDED
