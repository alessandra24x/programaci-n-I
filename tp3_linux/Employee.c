#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"

static int lastId  = 1000;

void employe_idInit(int id) {
    lastId = id++;
}

int employee_idGenerator() {
    return lastId++;
}

Employee* employee_new() {
    return (Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr) {
    Employee* aux;
    aux = employee_new();
    if(aux != NULL) {
        if( employee_setIdStr(aux,idStr)||
                employee_setNombre(aux,nombreStr)||
                employee_setHorasTrabajadasStr(aux,horasTrabajadasStr)||
                employee_setSueldoStr(aux,sueldoStr))
        {
            employee_delete(aux);
            aux = NULL;
        }
    }
    return aux;
}

int employee_delete(Employee* this) {
    int ret = -1;
    if(this != NULL)
    {
        free(this);
        ret = 0;
    }
    return ret;
}

int employee_setIdStr(Employee* this,char* idStr)
{
    int ret = -1;
    int bufferId;
    if(this != NULL && idStr != NULL) {
        if(isValidNumber(idStr)) {
            bufferId = atoi(idStr);
            if(!employee_setId(this,bufferId)) {
                ret = 0;
            }
        }
    }
    return ret;
}

int employee_setId(Employee* this,int id)
{
    int ret=-1;
    if(this != NULL && id >= 0) {
        this->id = id;
        ret = 0;
    }
    return ret;
}

int employee_getId(Employee* this,int* id)
{
    int ret=-1;
    if(this != NULL && id != NULL) {
        *id = this->id;
        ret=0;
    }
    return ret;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int ret = -1;
    if(this != NULL && isValidName(nombre) == 0)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        ret = 0;
    }
    return ret;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int ret = -1;
    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        ret = 0;
    }
    return ret;
}

int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadasStr)
{
    int ret=-1;
    int bufferHorasTrabajadas;
    if(this!=NULL)
    {
        if(isValidNumber(horasTrabajadasStr))
        {
            bufferHorasTrabajadas = atoi(horasTrabajadasStr);
            if(!employee_setHorasTrabajadas(this,bufferHorasTrabajadas))
            {
                ret=0;
            }
        }
    }
    return ret;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret=-1;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        ret=0;
    }
    return ret;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ret=-1;
    if(this!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        ret=0;
    }
    return ret;
}

int employee_setSueldoStr(Employee* this,char* sueldoStr)
{
    int ret=-1;
    int bufferSueldo;
    if(this!=NULL)
    {
        if(isValidNumber(sueldoStr))
        {
            bufferSueldo = atoi(sueldoStr);
            if(!employee_setHorasTrabajadas(this,bufferSueldo))
            {
                ret=0;
            }
        }
    }
    return ret;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int ret=-1;
    if(this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;
        ret=0;
    }
    return ret;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int ret=-1;
    if(this!=NULL&&sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        ret=0;
    }
    return ret;
}

int employee_compareId(void* pEmployeeA,void* pEmployeeB)
{
    int ret = 0;
    if(((Employee*)pEmployeeA)->id > ((Employee*)pEmployeeB)->id)
    {
        ret = 1;
    }
    if(((Employee*)pEmployeeA)->id < ((Employee*)pEmployeeB)->id)
    {
        ret = -1;
    }
    return ret;
}

int employee_compareHorasTrabajadas(void* pEmployeeA,void* pEmployeeB)
{
    int ret = 0;
    if(((Employee*)pEmployeeA)->horasTrabajadas > ((Employee*)pEmployeeB)->horasTrabajadas)
    {
        ret = 1;
    }
    if(((Employee*)pEmployeeA)->horasTrabajadas < ((Employee*)pEmployeeB)->horasTrabajadas)
    {
        ret = -1;
    }
    return ret;
}

int employee_compareSueldo(void* pEmployeeA,void* pEmployeeB)
{
    int ret = 0;
    if(((Employee*)pEmployeeA)->sueldo > ((Employee*)pEmployeeB)->sueldo)
    {
        ret = 1;
    }
    if(((Employee*)pEmployeeA)->sueldo < ((Employee*)pEmployeeB)->sueldo)
    {
        ret = -1;
    }
    return ret;
}

int employee_compareNombre(void* pEmployeeA,void* pEmployeeB)
{
    int ret = 0;
    if(strcmp(((Employee*)pEmployeeA)->nombre,((Employee*)pEmployeeB)->nombre)>0)
    {
        ret = 1;
    }
    if(strcmp(((Employee*)pEmployeeA)->nombre,((Employee*)pEmployeeB)->nombre)<0)
    {
        ret = -1;
    }
    return ret;
}


