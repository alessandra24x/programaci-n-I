#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

#define TEXT_SIZE 30
#define TEXT_TIPO 4
#define TEXT_CUIT 20


typedef struct
{
    int idPantalla;
    //-----------------
    char tipo[TEXT_TIPO];
    char nombre[TEXT_SIZE];
    char calle[TEXT_SIZE];
    float precioDia;
    int isEmpty;

}Pantalla;

typedef struct
{
    char cuit[TEXT_CUIT];
    int idPantalla;
    //-----------------
    int cantDias;
    char archivo[TEXT_SIZE];
    int isEmpty;

}Publicidad;


#endif // PANTALLA_H_INCLUDED

int pantalla_Inicializar(Pantalla array[], int size);
int publicidad_Inicializar(Publicidad array[], int size);                                   //cambiar pantalla
int pantalla_buscarEmpty(Pantalla array[], int size, int* posicion);
int pantalla_buscarEmptyPublicidad(Publicidad array[], int size, int* posicion) ;
int pantalla_buscarID(Pantalla array[], int size, int valorBuscado, int* posicion);
int publicidad_buscarID(Publicidad array[], int size, int valorBuscado, int* posicion);
int publicidad_buscarCUIT(Publicidad array[], int size, char* valorBuscado, int* posicion);
int pantalla_buscarInt(Pantalla array[], int size, int valorBuscado, int* posicion);                    //cambiar pantalla
int pantalla_buscarString(Pantalla array[], int size, char* valorBuscado, int* indice);                    //cambiar pantalla
int pantalla_alta(Pantalla array[], int size, int* contadorID);
int pantalla_contratar(Publicidad array[], int size);
int pantalla_baja(Pantalla array[], int sizeArray);                                      //cambiar pantalla
int pantalla_bajaValorRepetidoInt(Pantalla array[], int sizeArray, int valorBuscado);
int pantalla_modificar(Pantalla array[], int sizeArray);                                //cambiar pantalla
int pantalla_ordenarPorString(Pantalla array[],int size);                              //cambiar pantalla
int pantalla_listar(Pantalla array[], int size);                      //cambiar pantalla
int publicidad_listar(Publicidad array[], int size);
int publicidad_listarPorCuit(Publicidad array[],int size,char* aCuit);
int publicidad_modificar(Publicidad array[], int sizeArray);
int publicidad_consultaFacturacion(Pantalla arrayPantalla[],int sizePantalla,Publicidad arrayPublicidad[],int sizePublicidad);
int publicidad_calcularFacturacion(Pantalla arrayPantalla[],int sizePantalla,Publicidad arrayPublicidad[],int sizePublicidad,char* aCuit);
