int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado) {

    int retorno = -1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL) {
        do {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr) >= min && strlen(bufferStr) < max) {
                strncpy(resultado,bufferStr,max);
                retorno = 0;
                break;
            }
            printf("%s 1",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}

int utn_getUnsignedInt(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input) {

    int retorno = -1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL) {
        do {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) {
                if(isValidNumber(bufferStr) == 1) {
                    *input = atoi(bufferStr);
                    retorno = 0;
                    break;
                }
                else {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos >= 0);
    }
    return retorno;
}
