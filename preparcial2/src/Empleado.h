#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

void employe_idInit(int id);
int employee_idGenerator();

Empleado* employee_new();
Empleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
int employee_delete(Empleado* this);

int employee_setIdStr(Empleado* this,char* idStr);
int employee_setId(Empleado* this,int id);
int employee_getId(Empleado* this,int* id);

int employee_setNombre(Empleado* this,char* nombre);
int employee_getNombre(Empleado* this,char* nombre);

int employee_setHorasTrabajadasStr(Empleado* this,char* horasTrabajadasStr);
int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int employee_setSueldoStr(Empleado* this,char* sueldoStr);
int employee_setSueldo(Empleado* this,int sueldo);
int employee_getSueldo(Empleado* this,int* sueldo);

int employee_compareNombre(void* pEmployeeA,void* pEmployeeB);
int employee_compareHorasTrabajadas(void* pEmployeeA,void* pEmployeeB);

void em_calcularSueldo(void* empleado);
int filtrarPorSueldo(void* empleado);

#endif // EMPLEADO_H_INCLUDED
