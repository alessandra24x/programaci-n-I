#include <stdio.h>
#include <stdlib.h>

#include "vendedor.h"
#include "LinkedList.h"
#include "utn.h"
#include "Parser.h"

/** \brief Carga los datos desde el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPerro LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList *pListaVendedores)
{
	int ret = -1;
	FILE *pFile;
	char path[20];
	printf("\nIngrese el nombre y ruta del archivo que desea abrir: ");
	scanf("%s",path);
	pFile = fopen(path, "r"); //se abre el archivo en modo lectura
	if (parser_parseVendedores(pFile, pListaVendedores))
	{
		ret = 0;
		printf("Lista cargada exitosamente");
	}
	else
	{
		printf("No se pudo cargar la lista");
	}
	fclose(pFile);
	return ret;
}

int controller_PrintVendedores(LinkedList *pListaVendedores, int index)
{
	int ret = -1;
	Vendedor *auxVendedor;
	int auxId;
	char auxNombre[4096];
	int auxNivel;
	int auxCantidad_ventas;
	float auxMonto;
	float auxComisiones;

	if (pListaVendedores != NULL)
	{
		auxVendedor = ll_get(pListaVendedores, index);
		vendedor_getId(auxVendedor, &auxId);
		vendedor_getNombre(auxVendedor, auxNombre);
		vendedor_getNivel(auxVendedor, &auxNivel);
		vendedor_getCantidad_ventas(auxVendedor, &auxCantidad_ventas);
		vendedor_getMonto(auxVendedor, &auxMonto);
		vendedor_getComisiones(auxVendedor, &auxComisiones);

		printf("ID: %d\n1.Nombre: %s\n2.Nivel: %d\n3.Cantidad Ventas: %d\n4.Monto: %.2f\n5.Comisiones: %.2f\n",
			   auxId, auxNombre, auxNivel, auxCantidad_ventas, auxMonto, auxComisiones);
		ret = 0;
	}
	return ret;
}

/** \brief Lista los elementos
 *
 * \param path char*
 * \param pListaVendedores LinkedList*
 * \return int
 *
 */
int controller_ListVendedores(LinkedList *pListaVendedores)
{
	int ret = -1;
	int i, len;
	if (pListaVendedores != NULL)
	{
		if (ll_len(pListaVendedores) > 0)
		{
			len = ll_len(pListaVendedores);
			for (i = 0; i < len; i++)
			{
				controller_PrintVendedores(pListaVendedores, i);
			}
			ret = 0;
		}
		else
		{
			printf("No existen registros cargados");
		}
		return ret;
	}
	return ret;
}

/** \brief Guarda los datos en el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pListaVendedores LinkedList*
 * \return int
 *
 */
int controller_saveVendedoresAsText(FILE *pFile, LinkedList *pListaVendedores)
{
	int ret = 0;
	Vendedor *auxVendedor;
	int auxId;
	char auxNombre[4096];
	int auxNivel;
	int auxCantidad_ventas;
	float auxMonto;
	float auxComisiones;
	int i, len;

	if (pListaVendedores != NULL && pFile != NULL)
	{
		//fprintf recibe como primer parametro puntero de archivo al archivo donde se escribirá la salida formateada.
		//escribe datos formateados en el archivo
		fprintf(pFile, "id,nombre,nivel,cantidad_ventas,monto,comisiones\n");
		len = ll_len(pListaVendedores);

		for (i = 0; i < len; i++)
		{
			auxVendedor = ll_get(pListaVendedores, i);
			vendedor_getId(auxVendedor, &auxId);
			vendedor_getNombre(auxVendedor, auxNombre);
			vendedor_getNivel(auxVendedor, &auxNivel);
			vendedor_getCantidad_ventas(auxVendedor, &auxCantidad_ventas);
			vendedor_getMonto(auxVendedor, &auxMonto);
			vendedor_getComisiones(auxVendedor, &auxComisiones);

			fprintf(pFile, "%d,%s,%d,%d,%.2f,%.2f\n", auxId, auxNombre, auxNivel, auxCantidad_ventas, auxMonto, auxComisiones);
			ret++;
		}
		fclose(pFile);
	}
	return ret;
}

int controller_saveAsText(char *fileName, LinkedList *listaVendedores)
{
	FILE *pArchivo;
	int retorno = -1;

	if (fileName != NULL && listaVendedores != NULL)
	{
		pArchivo = fopen(fileName, "w"); //abre el archivo en modo de escritura
		if (pArchivo != NULL && controller_saveVendedoresAsText(pArchivo, listaVendedores))
		{
			printf("\nGuardado exitoso en Texto");
			retorno = 0;
		}
		else
		{
			printf("\nNo se pudo abrir el archivo");
		}
	}
	return retorno;
}
