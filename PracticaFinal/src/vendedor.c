#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "vendedor.h"
#include "LinkedList.h"
#include "utn.h"

Vendedor *vendedor_new()
{ //reservo espacio en memoria de manera dinámica para cada struct
	return (Vendedor *)malloc(sizeof(Vendedor));
}

//Construye una nueva struct, le setea los valores y devuelve un puntero de tipo void
Vendedor *vendedor_newParametros(char *idStr, char *nombre, char *nivelStr, char *cantidad_ventasStr, char *montoStr, char *comisionesStr)
{
	Vendedor *aux;
	aux = vendedor_new();
	if (aux != NULL)
	{
		int setId = vendedor_setIdStr(aux, idStr);
		int setNombre = vendedor_setNombre(aux, nombre);
		int setNivel = vendedor_setNivelStr(aux, nivelStr);
		int setCantidad_ventas = vendedor_setCantidad_ventasStr(aux, cantidad_ventasStr);
		int setMonto = vendedor_setMontoStr(aux, montoStr);
		int setComisiones = vendedor_setComisionesStr(aux, comisionesStr);

		if (setId != 0)
		{
			printf("Problema al cargar id\n");
			return NULL;
		}

		if (setNombre != 0)
		{
			printf("Problema al cargar nombre\n");
			return NULL;
		}

		if (setNivel != 0)
		{
			printf("Problema al cargar nivel\n");
			return NULL;
		}

		if (setCantidad_ventas != 0)
		{
			printf("Problema al cargar cantidad de ventas\n");
			return NULL;
		}

		if (setMonto != 0)
		{
			printf("Problema al cargar el monto\n");
			return NULL;
		}

		if (setComisiones != 0)
		{
			printf("Problema al cargar las comisiones\n");
		}
	}
	return aux;
}

int vendedor_delete(Vendedor *this)
{
	int ret = -1;
	if (this != NULL)
	{
		free(this);
		ret = 0;
	}
	return ret;
}

int vendedor_setIdStr(Vendedor *this, char *idStr)
{
	int ret = -1;
	int auxId;
	if (this != NULL && idStr != NULL)
	{
		if (isValidNumber(idStr) == 0)
		{
			auxId = atoi(idStr);
			if (vendedor_setId(this, auxId) == 0)
			{
				ret = 0;
			}
		}
	}
	return ret;
}

int vendedor_setId(Vendedor *this, int id)
{
	int ret = -1;
	if (this != NULL && id >= 0)
	{
		this->id = id;
		ret = 0;
	}
	return ret;
}

int vendedor_getId(Vendedor *this, int *id)
{
	int ret = -1;
	if (this != NULL && id != NULL)
	{
		*id = this->id;
		ret = 0;
	}
	return ret;
}

int vendedor_setNombre(Vendedor *this, char *nombre)
{
	int ret = -1;
	if (this != NULL && isValidName(nombre) == 0)
	{
		strncpy(this->nombre, nombre, sizeof(this->nombre));
		ret = 0;
	}
	return ret;
}

int vendedor_getNombre(Vendedor *this, char *nombre)
{
	int ret = -1;
	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		ret = 0;
	}
	return ret;
}

int vendedor_setNivelStr(Vendedor *this, char *nivelStr)
{
	int ret = -1;
	int auxNivel;
	if (this != NULL && nivelStr != NULL)
	{
		if (isValidNumber(nivelStr) == 0)
		{
			auxNivel = atoi(nivelStr);
			if (vendedor_setNivel(this, auxNivel) == 0)
			{
				ret = 0;
			}
		}
	}
	return ret;
}

int vendedor_setNivel(Vendedor *this, int nivel)
{
	int ret = -1;
	if (this != NULL && nivel >= 0)
	{
		this->nivel = nivel;
		ret = 0;
	}
	return ret;
}

int vendedor_getNivel(Vendedor *this, int *nivel)
{
	int ret = -1;
	if (this != NULL && nivel != NULL)
	{
		*nivel = this->nivel;
		ret = 0;
	}
	return ret;
}

int vendedor_setCantidad_ventasStr(Vendedor *this, char *cantidad_ventasStr)
{
	int ret = -1;
	int auxCantidad_ventas;
	if (this != NULL && cantidad_ventasStr != NULL)
	{
		if (isValidNumber(cantidad_ventasStr) == 0)
		{
			auxCantidad_ventas = atoi(cantidad_ventasStr);
			if (vendedor_setCantidad_ventas(this, auxCantidad_ventas) == 0)
			{
				ret = 0;
			}
		}
	}
	return ret;
}

int vendedor_setCantidad_ventas(Vendedor *this, int cantidad_ventas)
{
	int ret = -1;
	if (this != NULL && cantidad_ventas >= 0)
	{
		this->cantidad_ventas = cantidad_ventas;
		ret = 0;
	}
	return ret;
}

int vendedor_getCantidad_ventas(Vendedor *this, int *cantidad_ventas)
{
	int ret = -1;
	if (this != NULL && cantidad_ventas != NULL)
	{
		*cantidad_ventas = this->cantidad_ventas;
		ret = 0;
	}
	return ret;
}

int vendedor_setMontoStr(Vendedor *this, char *montoStr)
{
	int ret = -1;
	int auxMonto;
	if (this != NULL && montoStr != NULL)
	{
		if (isValidFloatNumber(montoStr) == 0)
		{
			auxMonto = atof(montoStr);
			if (vendedor_setMonto(this, auxMonto) == 0)
			{
				ret = 0;
			}
		}
	}
	return ret;
}

int vendedor_setMonto(Vendedor *this, float monto)
{
	int ret = -1;
	if (this != NULL && monto >= 0)
	{
		this->monto = monto;
		ret = 0;
	}
	return ret;
}

int vendedor_getMonto(Vendedor *this, float *monto)
{
	int ret = -1;
	if (this != NULL && monto != NULL)
	{
		*monto = this->monto;
		ret = 0;
	}
	return ret;
}

int vendedor_setComisionesStr(Vendedor *this, char *comisionesStr)
{
	int ret = -1;
	int auxComisiones;
	if (this != NULL && comisionesStr != NULL)
	{
		if (isValidFloatNumber(comisionesStr) == 0)
		{
			auxComisiones = atof(comisionesStr);
			if (vendedor_setComisiones(this, auxComisiones) == 0)
			{
				ret = 0;
			}
		}
	}
	return ret;
}

int vendedor_setComisiones(Vendedor *this, float comisiones)
{
	int ret = -1;
	if (this != NULL && comisiones >= 0)
	{
		this->comisiones = comisiones;
		ret = 0;
	}
	return ret;
}

int vendedor_getComisiones(Vendedor *this, float *comisiones)
{
	int ret = -1;
	if (this != NULL && comisiones != NULL)
	{
		*comisiones = this->comisiones;
		ret = 0;
	}
	return ret;
}

void *calcularComisiones(void *pVendedor)
{
	Vendedor *seller = (Vendedor *)pVendedor;
	if (pVendedor != NULL)
	{
		float junior = 0.02;
		float standard = 0.035;
		float experto = 0.05;
		float monto = seller->monto;
		int cantidad_ventas = seller->cantidad_ventas;
		int nivel = seller->nivel;

		if (nivel == 0)
		{
			seller->comisiones = monto * junior;
		}
		else if (cantidad_ventas < 100)
		{
			seller->comisiones = monto * standard;
		}
		else
		{
			seller->comisiones = monto * experto;
		}
	}
	return seller;
}

int filtrarJuniors(void *pVendedor)
{
	Vendedor *seller = (Vendedor *)pVendedor;
	int returnAux = 0;
	int nivel;
	if (pVendedor != NULL)
	{
		nivel = seller->nivel;
		if (nivel == 0)
		{
			returnAux = 1;
		}
	}
	return returnAux;
}

int filtrarStandards(void *pVendedor)
{
	Vendedor *seller = (Vendedor *)pVendedor;
	int returnAux = 0;
	int nivel;
	if (pVendedor != NULL)
	{
		nivel = seller->nivel;
		if (nivel == 1)
		{
			returnAux = 1;
		}
	}
	return returnAux;
}

int filtrarExpertos(void *pVendedor)
{
	Vendedor *seller = (Vendedor *)pVendedor;
	int returnAux = 0;
	int nivel;
	if (pVendedor != NULL)
	{
		nivel = seller->nivel;
		if (nivel == 2)
		{
			returnAux = 1;
		}
	}
	return returnAux;
}
