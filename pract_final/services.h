struct S_Service
{
 int id;
 char name[33];
 char email[65];
};
typedef struct S_Service Service;

Service* service_new();
Service* service_newParametros(char* idStr, char* name, char* email);
int service_delete(Service* this);

int service_setIdStr(Service* this,char* idStr);
int service_setId(Service* this,int id);
int service_getId(Service* this,int* id);

int service_setName(Service* this,char* name);
int service_getName(Service* this,char* name);

int service_setEmail(Service* this,char* email);
int service_getEmail(Service* this,char* email);