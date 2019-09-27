#define TEXT_SIZE 20
#define TEXT_TIPO 4
#define TEXT_CUIT 20

typedef struct {
    int idPantalla;
    char tipo[TEXT_TIPO];
    char nombre[TEXT_SIZE];
    int precioPorDia;
    char direccion;
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

int publicidad_Inicializar(Publicidad array[], int size);
int publicidad_buscarEmpty(Publicidad array[], int size, int* posicion);
