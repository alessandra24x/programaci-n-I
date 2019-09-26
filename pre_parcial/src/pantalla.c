int inicializar(ePantalla pantalla[], int size) {
    int retorno = -1;
    int i;
    if(pantalla != NULL && size > 0) {
        for(i = 0; size > 0; i++) {
            pantalla[size-1].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int pantalla_alta(ePantalla pantalla[], int size, int* contadorID) {
    int retornov= -1;
    int posicion;
    if(pantalla != NULL && size > 0 && contadorID != NULL)
    {
        if(pantalla_buscarEmpty(pantall,size,&posicion) == -1) {
            printf("\nNo hay lugares vacios");
        }
        else {
            (*contadorID)++;
            pantalla[posicion].idPantalla = *contadorID;
            pantalla[posicion].isEmpty = 1;
            utn_getUnsignedInt("\ngetUnsignedInt: ","\nError",1,sizeof(int),1,1,1,&pantalla[posicion].varInt);           //mensaje + cambiar campo varInt
            //utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
            //utn_getName("getName\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
            //utn_getTexto("getTexto\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);                 //mensaje + cambiar campo varLongString
            printf("\n PANTALLA DADA DE ALTA");
            retorno = 0;
        }
    }
    return retorno;
}
