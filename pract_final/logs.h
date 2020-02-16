#ifndef LOGS_H_INCLUDED
#define LOGS_H_INCLUDED

struct S_LogEntry
{
 char date[128];
 char time[128];
 int serviceId;
 int gravedad;
 char msg[128];
};
typedef struct S_LogEntry LogEntry;

LogEntry* logEntry_new();
LogEntry* logEntry_newParametros(char* date,char* time,char* serviceIdStr, char* gravedadStr, char* msg);
int logEntry_delete(LogEntry* this);

int logEntry_setDate(LogEntry* this,char* date);
int logEntry_getDate(LogEntry* this,char* date);

int logEntry_setTime(LogEntry* this,char* time);
int logEntry_getTime(LogEntry* this,char* time);

int logEntry_setServiceIdStr(LogEntry* this,char* serviceIdStr);
int logEntry_setServiceId(LogEntry* this,int serviceId);
int logEntry_getServiceId(LogEntry* this,int* serviceId);

int logEntry_setGravedadStr(LogEntry* this,char* gravedadStr);
int logEntry_setGravedad(LogEntry* this,int gravedad);
int logEntry_getGravedad(LogEntry* this,int* gravedad);

int logEntry_setMsg(LogEntry* this,char* msg);
int logEntry_getMsg(LogEntry* this,char* msg);

#endif // LOGS_H_INCLUDED