/*Descr: Solicita un entero por teclado
Param1: Valor devuelto validado
Param2: Mensaje para el ingreso del valor
Param3: Mensaje de error si ingresa un valor no valido
Param4: Rango mínimo valido para el ingreso
Param5: Rango mínimo valido para el ingreso
Param6: Cantidad de veces que puede ingresarlo con error
Para3: Valor con el que se inicializa
*/
int getInt(	int *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);
