int controller_loadLogsFromText(char* path , LinkedList* pListaLog);
int controller_loadServicesFromText(char* path , LinkedList* pListaServices);
int controller_saveLogsAsText(FILE* pFile , LinkedList* pListaLogs);
int controller_saveAsText(char* fileName,LinkedList* listaLog);
int controller_saveServicesAsText(FILE* pFile , LinkedList* pListaServices);
int controller_saveServAsText(char* fileName,LinkedList* listaServices);
