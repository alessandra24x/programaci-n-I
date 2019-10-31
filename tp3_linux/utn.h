int utn_getUnsignedInt(  char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input);
int isValidNumber(char* stringRecibido);

int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);

int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int isValidName(char* stringRecibido);

int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int isValidTexto(char* stringRecibido);

int utn_getFloat(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input);
int isValidFloatNumber(char* stringRecibido);

int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int isValidChar(char charRecibido);
