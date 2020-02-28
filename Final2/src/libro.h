#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

struct S_Libro {
	int id;
	char titulo[1024];
	char autor[1024];
	int precio;
	char editorial[1024];
	float precioConDescuento;
};
typedef struct S_Libro Libro;

Libro* libro_new();
Libro* libro_newParametros(char *idStr, char *titulo, char *autor,
		char *precioStr, char *editorial, char *precioConDescuentoStr);
int libro_delete(Libro *this);

int libro_setIdStr(Libro *this, char *idStr);
int libro_setId(Libro *this, int id);
int libro_getId(Libro *this, int *id);

int libro_setTitulo(Libro *this, char *titulo);
int libro_getTitulo(Libro *this, char *titulo);

int libro_setAutor(Libro *this, char *autor);
int libro_getAutor(Libro *this, char *autor);

int libro_setPrecioStr(Libro *this, char *precioStr);
int libro_setPrecio(Libro *this, int precio);
int libro_getPrecio(Libro *this, int *precio);

int libro_setEditorial(Libro *this, char *editorial);
int libro_getEditorial(Libro *this, char *editorial);

int libro_setPrecioConDescuentoStr(Libro* this,char* precioConDescuentoStr);
int libro_setPrecioConDescuento(Libro* this,float precioConDescuento);
int libro_getPrecioConDescuento(Libro* this,float* precioConDescuento);

int libro_sortAutor(void* pAutor1,void* pAutor2);
void* calcularDescuentos(void *pLibro);

#endif // LIBRO_H_INCLUDED
