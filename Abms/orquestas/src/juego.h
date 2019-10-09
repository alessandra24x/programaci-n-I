#define TEXT_SIZE 20
#define TEXT_TIPO 4

typedef struct {
    int codigo;
    char descripcion[TEXT_SIZE];
    int importe;
    int idCategoria;
    int isEmpty;
}Juego;

typedef struct {
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    char fecha[TEXT_SIZE];
    int isEmpty;
}Alquileres;
