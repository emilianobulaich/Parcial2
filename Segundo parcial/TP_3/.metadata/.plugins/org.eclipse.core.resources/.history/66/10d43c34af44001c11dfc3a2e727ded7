#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* newEmployee;
    newEmployee = (Employee*)malloc(sizeof(Employee));

    if(newEmployee != NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre, " ");
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo = 0;
    }

    return newEmployee;
}
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee;
    newEmployee = employee_new();

    int id;
    int horas;
    int sueldo;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL && newEmployee != NULL  ){
		id= atoi(idStr);
		horas= atoi(horasTrabajadasStr);
		sueldo= atoi(sueldoStr);


    	employee_setId(newEmployee, id);
        employee_setNombre(newEmployee, nombreStr);
        employee_setSueldo(newEmployee, sueldo);
        employee_setHorasTrabajadas(newEmployee, horas);

    }

    return newEmployee;
}
void employee_delete(Employee* this){

	if(this!=NULL){
		free(this);
	}

}
int employee_setId(Employee* this,int id){
	int retorno;
	retorno = -1;
	if(this!= NULL){
        this->id = id;
        retorno = 0;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id){
	int retorno;
	retorno = -1;
	if(this!= NULL && id!= NULL){
	       *id = this->id;
	        retorno = 0;
		}
	return retorno;
}
int employee_setNombre(Employee* this,char* nombre){
	int retorno;
	retorno = -1;
	if(this!= NULL){

	      strcpy(this->nombre , nombre);
	      this->nombre[0] = toupper(this->nombre[0]);

	      retorno = 0;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre){
	int retorno;
	retorno = -1;
	if(this!= NULL && nombre!= NULL){
		  strcpy(nombre, this->nombre);
		  retorno = 0;
		}
	return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno;
	retorno = -1;
	if(this!= NULL){
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno;
	retorno = -1;
	if(this!= NULL && horasTrabajadas!=NULL){
	 *horasTrabajadas = this->horasTrabajadas ;
		retorno = 0;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){
	int retorno;
	retorno = -1;
	if(this!= NULL){
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo){
	int retorno;
	retorno = -1;
	if(this!= NULL&& sueldo!= NULL){
		*sueldo  = this->sueldo ;
		retorno = 0;
	}

	return retorno;
}

int employee_orderById(void* firstId, void* secondId){
	int retorno = 0;
		int primerId;
		int segundoId;
		if(firstId != NULL && secondId != NULL){
			employee_getId(firstId,&primerId);
			employee_getId(secondId,&segundoId);

			if(primerId > segundoId){
                retorno = 1;
			}
			else if (primerId < segundoId){
				retorno = -1;
			}
		}

		return retorno;
}
int employee_orderByName(void* firstName, void* secondName){
	int retorno = -2;
	char primerNombre[100];
    char segundoNombre[100];


    if(firstName != NULL && secondName != NULL){
    	employee_getNombre(firstName,  primerNombre);
		employee_getNombre(secondName, segundoNombre);
		retorno = strcmp(primerNombre, segundoNombre);
    }

    return retorno;
}
int employee_orderBySalary(void* firstSalary, void* secondSalary){
	int retorno = 0;
	int primerSalario;
	int segundoSalario;
	if(firstSalary != NULL && secondSalary != NULL){
		employee_getSueldo(firstSalary,&primerSalario);
		employee_getSueldo(secondSalary,&segundoSalario);

		if(primerSalario > segundoSalario){
			retorno = 1;
		}
		else if (primerSalario < segundoSalario){
			retorno = -1;
		}
	}

			return retorno;
    return retorno;
}
int employee_orderByHours(void* firstHours, void* secondHours){
    int primerHora;
    int segundaHora;
    int retorno = 0;

    employee_getHorasTrabajadas(firstHours, &primerHora);
    employee_getHorasTrabajadas(secondHours, &segundaHora);

    if(primerHora > segundaHora){
        retorno = 1;
    }
    else if(primerHora < segundaHora){
        retorno = -1;
    }
    return retorno;
}
