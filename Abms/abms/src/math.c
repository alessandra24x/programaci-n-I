#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abm.h"
#include "math.h"

/** \brief Cuenta la cantidad de empleados activos
* \param Employee* list es el array de la estructura Employee
* \param int len es la longitud del array
* \return
*/
int countEmployees(Employee* list, int len) {
  int i;
  int countEmp = 0;
  if(list != NULL && len > 0) {
    for(i = 0; i < len; i++) {
      if(list[i].isEmpty == 0) {
        continue;
      } else {
        countEmp++;
      }
    }
  } else {
    printf("ERROR");
  }
  return countEmp;
}

int getTotalSalary(Employee* list, int len) {
  float total = 0;
  int i;
  if(list != NULL && len > 0) {
    for(i = 0; i < len; i++) {
        if(list[i].isEmpty == 0) {
          continue;
      } else {
        total += list[i].salary;
      }
    }
  } else {
    printf("ERROR");
  }
    return total;
}

float getAverageSalary(int countEmp, float total) {
  float average = 0;
  if(countEmp > 0 && total > 0) {
    average = total/countEmp;
  } else {
    printf("ERROR");
  }
  return average;
}

int getCountEmployeesMoreAverageSalary(Employee* list, int len, float average) {
  int i;
  int countEmp = 0;
  if(list != NULL && len > 0 && average > 0) {
    for(i = 0; i < len; i++) {
      if(list[i].isEmpty == 0) {
      continue;
    } else if(list[i].salary > average) {
      countEmp++;
      }
    }
  } else {
    printf("ERROR AH RE");
  }
   return countEmp;
}

void printSalaryInformation(Employee* list, int len) {
  int count =  countEmployees(list,  len);
  float totalSalary = getTotalSalary(list, len);
  float averageSalary = totalSalary/count;
  int countEmployeesMoreAverageSalary = getCountEmployeesMoreAverageSalary(list, len, averageSalary);
  printf("\nReporte de sueldos:\n");
  printf("El total invertido en sueldos es de: $ %.2f \n", totalSalary);
  printf("El sueldo promedio es de: $ %.2f \n", averageSalary);
  printf("%d empleados superan el sueldo promedio \n\n", countEmployeesMoreAverageSalary);
}
