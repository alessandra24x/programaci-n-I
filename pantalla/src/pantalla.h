#define TEXT_SIZE 20
#define TEXT_TIPO 4
#define TEXT_CUIT 20

typedef struct {
    int idPantalla;
    char tipo[TEXT_TIPO];
    char nombre[TEXT_SIZE];
    float precioPorDia;
    char direccion[TEXT_SIZE];
    int isEmpty;
}Pantalla;

typedef struct {
    char cuit[TEXT_CUIT];
    int idPantalla;
    int cantDias;
    char archivo[TEXT_SIZE];
    int isEmpty;
}Publicidad;

int inicializar(Pantalla array[], int size);
int pantalla_buscarEmpty(Pantalla array[], int size, int* posicion);
int pantalla_buscarID(Pantalla array[], int size, int valorBuscado, int* posicion);
int pantalla_alta(Pantalla array[], int size, int* contadorID);
int pantalla_listar(Pantalla array[], int size);
int pantalla_modificar(Pantalla array[], int sizeArray);
int pantalla_baja(Pantalla array[], int sizeArray);
int pantalla_contratar(Publicidad array[], int size);
int pantalla_ordenarPorString(Pantalla array[],int size);

int publicidad_Inicializar(Publicidad array[], int size);
int publicidad_buscarEmpty(Publicidad array[], int size, int* posicion);
int publicidad_buscarID(Publicidad array[], int size, int valorBuscado, int* posicion);
int publicidad_buscarCUIT(Publicidad array[], int size, char* valorBuscado, int* posicion);
int publicidad_listar(Publicidad array[], int size);
int publicidad_listarPorCuit(Publicidad array[],int size,char* aCuit);
int publicidad_modificar(Publicidad array[], int sizeArray);
int publicidad_consultaFacturacion(Pantalla arrayPantalla[],int sizePantalla,Publicidad arrayPublicidad[],int sizePublicidad);
int publicidad_calcularFacturacion(Pantalla arrayPantalla[],int sizePantalla,Publicidad arrayPublicidad[],int sizePublicidad,char* aCuit);

