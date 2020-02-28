int controller_loadFromText(LinkedList *pListaLibro);
int controller_PrintLibro(LinkedList *pListaLibro, int index);
int controller_ListLibro(LinkedList *pListaLibro);
int controller_saveLibroAsText(FILE *pFile, LinkedList *pListaLibro);
int controller_saveAsText(char *fileName, LinkedList *pListaLibro);
