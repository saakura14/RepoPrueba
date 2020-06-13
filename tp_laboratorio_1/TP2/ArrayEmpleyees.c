#include <stdio.h>
#include <string.h>
#define GETVALUES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#define TRUE 1
#define FALSE 0

int initEmployees(Employee* list, int len)
{
	int retorno = 1;
	int i;
	//si len es válido y list es not null.
	for (i=0;i<len;i++)
	{
		//inicializo y retorno 1 luego
		list[i].isEmpty = TRUE;
	}
	//sino, retorno = 0.
	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int i;
	int retorno = 0;

	i = findEmptyEmployee(list, len); //Buscar primer lugar libre en list

	if (i == -1)
	{
		retorno = i; //Si no hay espacio libre, retorna -1.
	}
	else //Cargar en list[freeIndex].datos los parametros.
	{
		list[i].id = id;
		strcpy(list[i].name,name);
		strcpy(list[i].lastName,lastName);
		list[i].salary = salary;
		list[i].sector = sector;
		list[i].isEmpty = FALSE;
	}

	return retorno;
}

Employee inputEmployeeData(int nextEmployeeID)
{
	Employee newEmployee;
	newEmployee.id	= nextEmployeeID;

	newEmployee	= inputEmployeeName(newEmployee);
	newEmployee	= inputEmployeeLastName(newEmployee);
	newEmployee	= inputEmployeeSalary(newEmployee);
	newEmployee	= inputEmployeeSector(newEmployee);

	return newEmployee;
}

Employee inputEmployeeName(Employee myEmployee)
{
	inputArray(myEmployee.name,51,"Ingrese nombre del empleado: ");
	UpperPrimerasLetras(myEmployee.name);
	return myEmployee;
}

Employee inputEmployeeLastName(Employee myEmployee)
{
	inputArray(myEmployee.lastName,51,"Ingrese apellido del empleado: ");
	UpperPrimerasLetras(myEmployee.lastName);
	return myEmployee;
}

Employee inputEmployeeSalary(Employee myEmployee)
{
	myEmployee.salary = getFloatConMinimo("Ingrese el sueldo: ","Valor inválido, por favor vuelva a intentarlo: ", 0);
	return myEmployee;
}

Employee inputEmployeeSector(Employee myEmployee)
{
	myEmployee.sector = getInt("Ingrese el sector: ");
	return myEmployee;
}


int findEmptyEmployee(Employee* list, int len)
{
	int variableRetorno = -1;
	int i;
	for (i=0;i<len;i++)
	{
		if (list[i].isEmpty == TRUE)
		{
			variableRetorno = i;
			break;
		}
	}

	return variableRetorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int variableRetorno = -1;
	int i;
	for (i=0;i<len;i++)
	{
		if (list[i].isEmpty == FALSE && list[i].id == id)
		{
			variableRetorno = i;
			break;
		}
	}
	return variableRetorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno = 0;
	int index = findEmployeeById(list,len,id);

	if (index == -1)
	{
		retorno = -1;
	}
	else
	{
		list[index].isEmpty = TRUE;
	}

	return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	int i;
	int j;
	Employee auxEmployee;

	for(i=0;i<len-1;i++)
	{
		if (list[i].isEmpty == TRUE)
		{
			continue;
		}

		for(j=i+1;j<len;j++)
		{
			if (list[j].isEmpty == TRUE)
			{
				continue;
			}

			if((order && strcmp(list[i].lastName,list[j].lastName)>0) || (!order && strcmp(list[i].lastName,list[j].lastName)<0) )
			{
				auxEmployee = list[i];
				list[i] = list[j];
				list[j] = auxEmployee;
			}
			else
			{
				if(strcmp(list[i].lastName,list[j].lastName)==0)
				{
					if((order && list[i].sector > list[j].sector) || (!order && list[i].sector < list[j].sector))
					{
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
				}
			}
		}
	}
	return 0;
}



int printEmployees(Employee* list, int length)
{
	int i;
	printEmployeeHeader();
	for(i=0;i<length;i++)
	{
		if (list[i].isEmpty == FALSE)
		{
			printEmployee(list[i]);
		}
	}
	printf("\n\n");
	return 0;
}

void printEmployee(Employee myEmployee)
{

	printf("\n %2d %30s %30s %10.2f %10d",	myEmployee.id,
											myEmployee.name,
											myEmployee.lastName,
											myEmployee.salary,
											myEmployee.sector);
}

void printEmployeeHeader(void)
{
	printf("\n %s %30s %30s %10s %10s\n","ID","Name","LastName","Salary","Sector");
}

int equalEmployees(Employee myEmployee, Employee otherEmployee)
{
	int retorno = 0;
	if (strcmp(myEmployee.name,otherEmployee.name) == 0 && strcmp(myEmployee.lastName,otherEmployee.lastName) == 0  && myEmployee.salary == otherEmployee.salary && myEmployee.sector == otherEmployee.sector)
	{
		retorno = 1;
	}

	return retorno;
}

int hardcodearEmployees(Employee listaEmpleados[], int sizeEmpleados)
{
	int retorno = 0;
	int i;
	if (sizeEmpleados < 10)
	{
		retorno = -1; //No cumple con el máximo de empleados mínimos para hardcodear.
	}

	Employee auxListaEmpleados[10] = { 	{1,"Julian","Rodicio",1000,1,0},
										{2,"Raquel","Correa",1500,3,0},
										{3,"JP","Crocco",2000,2,0},
										{4,"Germán","Kinder",2500,1,0},
										{5,"Diego","Sabella",3000,1,0},
										{6,"Melisa","Bronco",3500,3,0},
										{7,"Jonhy","Melkio",4000,2,0},
										{8,"Javier","Cuevas",4000,2,0},
										{9,"Rodra","Correa",5000,1,0},
										{10,"Remi","Cajallena",10000,1,1}};
	for (i=0;i<10;i++)
	{
		listaEmpleados[i] = auxListaEmpleados[i];
	}
	return retorno;
}

int countEmployees (Employee listaEmpleados[], int sizeEmpleados)
{
	int cantidadEmployees = 0;
	int i;

	for (i=0;i<sizeEmpleados;i++)
	{
		if(listaEmpleados[i].isEmpty == FALSE)
		{
			cantidadEmployees++;
		}
	}

	return cantidadEmployees;
}

double acumSalaryEmployee(Employee listaEmpleados[], int sizeEmpleados)
{
	double acumSalary = 0;
	int i;

	for (i=0;i<sizeEmpleados;i++)
	{
		printf("\nDEBUG SALARIO: %f-\n",acumSalary);
		if (listaEmpleados[i].isEmpty == FALSE)
		{
			acumSalary+=listaEmpleados[i].salary;
			printf("\nDEBUG SALARIO: %f-\n",acumSalary);
		}
	}

	return acumSalary;
}

int countEmployeesSalarioMayorA(Employee listaEmpleados[], int sizeEmpleados, float salarioASuperar)
{
	int i;
	int countEmployees = 0;
	for(i=0;i<sizeEmpleados;i++)
	{
		if(listaEmpleados[i].isEmpty == FALSE && listaEmpleados[i].salary > salarioASuperar)
		{
			countEmployees++;
		}
	}

	return countEmployees;

}


void copyEmployeesList(Employee listaEmpleados[],Employee auxListaEmpleados[], int sizeEmpleados)
{
	int i;

	for (i=0;i<sizeEmpleados;i++)
	{
		auxListaEmpleados[i] = listaEmpleados[i];
	}

}


int getMaxIDEmployee(Employee listaEmpleados[], int sizeEmpleados)
{
	int i;
	int maxID = 0;

	for (i=0;i<sizeEmpleados;i++)
	{
		if (listaEmpleados[i].isEmpty == FALSE && listaEmpleados[i].id > maxID)
		{
			maxID = listaEmpleados[i].id;
		}
	}

	return maxID;
}

