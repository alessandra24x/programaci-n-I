#define TEXT_SIZE 20

typedef struct {
    int idPantalla;
    char tipo;
    char nombre[TEXT_SIZE];
    int precioPorDia;
    char direccion;
    int isEmpty;
}ePantalla;

int inicializar(ePantalla pantalla[], int size);
int pantalla_alta(ePantalla pantalla[], int size, int* contadorID);
