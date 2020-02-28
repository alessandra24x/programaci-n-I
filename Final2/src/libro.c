#include "libro.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "utn.h"

Libro* libro_new() { //reservo espacio en memoria de manera dinámica para cada struct
	return (Libro*) malloc(sizeof(Libro));
}

Libro* libro_newParametros(char *idStr, char *titulo, char *autor,
		char *precioStr, char *editorial, char *precioConDescuentoStr) {
	Libro *aux;
	aux = libro_new();
	if (aux != NULL) {
		int setId = libro_setIdStr(aux, idStr);
		int setTitulo = libro_setTitulo(aux, titulo);
		int setAutor = libro_setAutor(aux, autor);
		int setPrecio = libro_setPrecioStr(aux, precioStr);
		int setEditorial = libro_setEditorial(aux, editorial);
		int setPrecioConDescuento = libro_setPrecioConDescuentoStr(aux,
				precioConDescuentoStr);

		if (setId != 0) {
			printf("Problema al cargar id\n");
			return NULL;
		}
		if (setTitulo != 0) {
			printf("Problema al cargar titulo\n");
			return NULL;
		}
		if (setAutor != 0) {
			printf("Problema al cargar autor\n");
			return NULL;
		}
		if (setPrecio != 0) {
			printf("Problema al cargar precio\n");
			return NULL;
		}
		if (setEditorial != 0) {
			printf("Problema al cargar editorial\n");
			return NULL;
		}
		if (setPrecioConDescuento != 0) {
			printf("Problema al cargar precio con descuento\n");
			return NULL;
		}
	}
	return aux;
}

int libro_delete(Libro *this) {
	int ret = -1;
	if (this != NULL) {
		free(this);
		ret = 0;
	}
	return ret;
}
//char

//int
int libro_setIdStr(Libro *this, char *idStr) {
	int ret = -1;
	int auxId;
	if (this != NULL && idStr != NULL) {
		if (isValidNumber(idStr) == 0) {
			auxId = atoi(idStr);
			if (libro_setId(this, auxId) == 0) {
				ret = 0;
			}
		}
	}
	return ret;
}

int libro_setId(Libro *this, int id) {
	int ret = -1;
	if (this != NULL && id >= 0) {
		this->id = id;
		ret = 0;
	}
	return ret;
}

int libro_getId(Libro *this, int *id) {
	int ret = -1;
	if (this != NULL && id != NULL) {
		*id = this->id;
		ret = 0;
	}
	return ret;
}

int libro_setTitulo(Libro *this, char *titulo) {
	int ret = -1;
	if (this != NULL) {
		strncpy(this->titulo, titulo, sizeof(this->titulo));
		ret = 0;
	}
	return ret;
}

int libro_getTitulo(Libro *this, char *titulo) {
	int ret = -1;
	if (this != NULL && titulo != NULL) {
		strcpy(titulo, this->titulo);
		ret = 0;
	}
	return ret;
}

int libro_setAutor(Libro *this, char *autor) {
	int ret = -1;
	if (this != NULL) {
		strncpy(this->autor, autor, sizeof(this->autor));
		ret = 0;
	}
	return ret;
}

int libro_getAutor(Libro *this, char *autor) {
	int ret = -1;
	if (this != NULL && autor != NULL) {
		strcpy(autor, this->autor);
		ret = 0;
	}
	return ret;
}

int libro_setPrecioStr(Libro *this, char *precioStr) {
	int ret = -1;
	int auxPrecio;
	if (this != NULL && precioStr != NULL) {
		if (isValidNumber(precioStr) == 0) {
			auxPrecio = atoi(precioStr);
			if (libro_setPrecio(this, auxPrecio) == 0) {
				ret = 0;
			}
		}
	}
	return ret;
}

int libro_setPrecio(Libro *this, int precio) {
	int ret = -1;
	if (this != NULL && precio >= 0) {
		this->precio = precio;
		ret = 0;
	}
	return ret;
}

int libro_getPrecio(Libro *this, int *precio) {
	int ret = -1;
	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		ret = 0;
	}
	return ret;
}

int libro_setEditorial(Libro *this, char *editorial) {
	int ret = -1;
	if (this != NULL) {
		strncpy(this->editorial, editorial, sizeof(this->editorial));
		ret = 0;
	}
	return ret;
}

int libro_getEditorial(Libro *this, char *editorial) {
	int ret = -1;
	if (this != NULL && editorial != NULL) {
		strcpy(editorial, this->editorial);
		ret = 0;
	}
	return ret;
}

int libro_setPrecioConDescuentoStr(Libro *this, char *precioConDescuentoStr) {
	int ret = -1;
	int auxPrecioConDescuento;

	if (this != NULL && precioConDescuentoStr != NULL) {
		if (isValidNumber(precioConDescuentoStr) == 0) {
			auxPrecioConDescuento = atof(precioConDescuentoStr);
			if (libro_setPrecioConDescuento(this, auxPrecioConDescuento) == 0) {
				ret = 0;
			}
		}
	}
	return ret;
}

int libro_setPrecioConDescuento(Libro *this, float precioConDescuento) {
	int ret = -1;
	if (this != NULL && precioConDescuento >= 0) {
		this->precioConDescuento = precioConDescuento;
		ret = 0;
	}
	return ret;
}

int libro_getPrecioConDescuento(Libro *this, float *precioConDescuento) {
	int ret = -1;
	if (this != NULL && precioConDescuento != NULL) {
		*precioConDescuento = this->precioConDescuento;
		ret = 0;
	}
	return ret;
}

int libro_sortAutor(void *pAutor1, void *pAutor2) {
	Libro *libro1 = (Libro*) pAutor1;
	Libro *libro2 = (Libro*) pAutor2;

	return strcmp(libro1->autor, libro2->autor);
}

void* calcularDescuentos(void *pLibro) {
	Libro *libro = (Libro*) pLibro;
	char editorial[1024];
	float precio, descuento, precioConDescuento;
	strcpy(editorial, libro->editorial);
	precio = libro->precio;

	if (precio <= 200 && strcmp(editorial, "SIGLO XXI EDITORES") == 0) {
		descuento = precio * 0.10;
		precioConDescuento = precio - descuento;
		libro->precioConDescuento = precioConDescuento;
	} else if (precio >= 300 && strcmp(editorial, "Planeta") == 0) {
		descuento = precio * 0.20;
		precioConDescuento = precio - descuento;
		libro->precioConDescuento = precioConDescuento;
	}
	else {
		libro->precioConDescuento = precio;
	}
	return libro;

}
