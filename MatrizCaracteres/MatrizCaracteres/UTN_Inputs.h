/**
 * \brief Solicita un numero dentro de un rango al usuario y lo devuelve
 * \brief pResultado Valor devuelto validado
 * \param mensaje Mensaje para el ingreso del valor
 * \param mensajeError Mensaje de error si ingresa un valor no valido
 * \param minimo Rango mínimo valido para el ingreso
 * \param maximo Rango maximo valido para el ingreso
 * \param reintentos Cantidad de veces que puede ingresarlo con error
 * \return void
 */
int getInt(	int *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);
