#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int parser_parseLogs(FILE* fileName, LinkedList* listaLogs);
int parser_parseServices(FILE* fileName, LinkedList* listaServices);

#endif // PARSER_H_INCLUDED
