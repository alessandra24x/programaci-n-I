typedef struct {
    int customerCode;
    char name[TEXT_SIZE];
    char lastName[TEXT_SIZE];
    char sex[TEXT_SIZE];
    int phone;
    char adress[TEXT_SIZE];
    int isEmpty;
}Customer;

int customer_init(Cliente array[], int size);
int customer_searchEmpty(Cliente array[], int size, int* position);
int customer_searchID(Cliente array[], int size, int valorBuscado, int* position);
int customer_searchInt(Cliente array[], int size, int valorBuscado, int* position);
int customer_searchString(Cliente array[], int size, char* valorBuscado, int* indice);
int customer_add(Cliente array[], int size, int* contadorID);
