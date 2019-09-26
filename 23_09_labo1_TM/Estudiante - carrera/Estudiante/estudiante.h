#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idEstudiante;
    char nombre[TEXT_SIZE];
    int edad;
    int idCarrera;
    int isEmpty;
}eEstudiante;

typedef struct
{
    int idCarrera;
    char descripcionCarrera[TEXT_SIZE];
    int isEmpty;
}eCarrera;



#endif // ESTUDIANTE_H_INCLUDED

int estudiante_Inicializar(eEstudiante array[], int size);                                    //cambiar estudiante
int estudiante_buscarEmpty(eEstudiante array[], int size, int* posicion);                    //cambiar estudiante
int estudiante_buscarID(eEstudiante array[], int size, int valorBuscado, int* posicion);                    //cambiar estudiante
int estudiante_buscarInt(eEstudiante array[], int size, int valorBuscado, int* posicion);                    //cambiar estudiante
int estudiante_buscarString(eEstudiante array[], int size, char* valorBuscado, int* indice);                    //cambiar estudiante
int estudiante_alta(eEstudiante array[], int size, int* contadorID);                          //cambiar estudiante
int estudiante_baja(eEstudiante array[], int sizeArray);                                      //cambiar estudiante
int estudiante_bajaValorRepetidoInt(eEstudiante array[], int sizeArray, int valorBuscado);
int estudiante_modificar(eEstudiante array[], int sizeArray);                                //cambiar estudiante
int estudiante_ordenarPorString(eEstudiante array[],int size);                              //cambiar estudiante
int estudiante_listar(eEstudiante array[], int size, eCarrera arrayCarrera[], int sizeCarrera);                      //cambiar estudiante
int getDescripcionCarrera(eCarrera arrayCarrera[], int sizeCarrera, int buscar, char* descripcion);

