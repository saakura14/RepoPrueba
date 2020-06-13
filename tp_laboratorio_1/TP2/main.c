#include <stdio.h>
#include <stdlib.h>
#define MENUOPCIONES_H_INCLUDED
#define GETVALUES_H_INCLUDED

#define OPCIONESMENUPRINCIPAL 5
#define OPCIONESMENUMODIFICAR 6
#define OPCIONESMENUINFORMAR 2
#define MAXIMOEMPLEADOS 1000
#define TRUE 1
#define FALSE 0

int main()
{
	Employee listaEmpleados[MAXIMOEMPLEADOS];
	Employee auxEmployee;
	Employee listaEmpleadosOrden[MAXIMOEMPLEADOS];
	int lastEmployeeId;
	int salir = 0;

	char opcionesMenuPrincipal[OPCIONESMENUPRINCIPAL][30] = {"ALTAS","MODIFICAR","BAJA","INFORMAR","SALIR"};
	char opcionesMenuModificar[OPCIONESMENUMODIFICAR][30] = {"Modificar nombre","Modificar apellido", "Modificar salario", "Modificar sector", "Guardar", "Salir"};
	char opcionesMenuInformar[OPCIONESMENUINFORMAR][30] = {"Invertir orden empleados","Volver al men� anterior"};

	int opcionIngresada;
	int opcionModificacion;
	int opcionInformar;
	int auxId;
	int auxIndex;
	int retornoFuncion;
	int continuarModificacion;
	int ordenListarEmpleados;
	double salarioTotal;
	double salarioPromedio;
	int empleadosSuperanSalarioPromedio;

	int cantidadEmpleados;

	//Inicializamos lista empleados, hardcodeamos y contamos.
	initEmployees(listaEmpleados,MAXIMOEMPLEADOS);
	//hardcodearEmployees(listaEmpleados,MAXIMOEMPLEADOS); //Hardcodeamos 10 empleados para realizar pruebas.
	cantidadEmpleados = countEmployees(listaEmpleados,MAXIMOEMPLEADOS);
	lastEmployeeId = getMaxIDEmployee(listaEmpleados, MAXIMOEMPLEADOS);

	do
	{
		system("clear");
		opcionIngresada = menuOptionGet("Men� principal",opcionesMenuPrincipal,OPCIONESMENUPRINCIPAL);

		if (cantidadEmpleados == 0 && (opcionIngresada == 2 || opcionIngresada == 3 || opcionIngresada == 4))
		{
			pausa("Debe cargar un empleado antes de ingresar a la opci�n seleccionada.");
			continue;
		}
		system("clear");
		switch(opcionIngresada)
		{
			case 1:
				printMenuHeader("Alta empleado");
				//Generamos nuevo ID Empleado y solicitamos los datos al usuario
				lastEmployeeId++;
				auxEmployee = inputEmployeeData(lastEmployeeId);

				//Una vez ingresados los datos, ejecutamos addEmployee con lo ingresado y lo cargamos en la lista de empleados.
				retornoFuncion = addEmployee(listaEmpleados, MAXIMOEMPLEADOS,auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);

				if (retornoFuncion == 0)
				{
					cantidadEmpleados++;

					pausa("Empleado dado de alta correctamente. Pulse <Enter> para continuar...");
				}
				else
				{
					pausa("L�mite de empleados alcanzado. Pulse <Enter> para continuar...");
				}

			break;
			//TODO OK

			case 2:
				printMenuHeader("Modificaci�n empleado");
				printMenuHeader("B�squeda empleado");
				printEmployees(listaEmpleados,MAXIMOEMPLEADOS);
				auxId = getInt("Ingrese ID de empleado que desea modificar: ");
				auxIndex = findEmployeeById(listaEmpleados,MAXIMOEMPLEADOS, auxId);
				if (auxIndex == -1)
				{
					pausa("ID inexistente.");
				}
				else
				{
					auxEmployee = listaEmpleados[auxIndex];

					do
					{
						system("clear");
						continuarModificacion = TRUE;
						printMenuHeader("Modificaci�n empleado");
						printf("\nEmpleado guardado:");
						printEmployeeHeader();
						printEmployee(listaEmpleados[auxIndex]);
						printf("\n\nModificaciones realizadas:");
						printEmployeeHeader();
						printEmployee(auxEmployee);
						printf("\n\n");
						opcionModificacion = menuOptionGet("Men� modificaci�n",opcionesMenuModificar,OPCIONESMENUMODIFICAR);

						switch (opcionModificacion)
						{
							case 1:
								auxEmployee = inputEmployeeName(auxEmployee);
							break;

							case 2:
								auxEmployee = inputEmployeeLastName(auxEmployee);
							break;

							case 3:
								auxEmployee = inputEmployeeSalary(auxEmployee);
							break;

							case 4:
								auxEmployee = inputEmployeeSector(auxEmployee);
							break;

							case 5: //GUARDAR
								if (equalEmployees(auxEmployee,listaEmpleados[auxIndex]))
								{
									pausa("No hay modificaciones para guardar.");
								}
								else
								{
									if (msjConfirmar("Se sobrescribir�n los datos del empleado, �est� seguro?"))
									{
										listaEmpleados[auxIndex] = auxEmployee;
										pausa("Modificaciones guardadas correctamente!");
									}
									else
									{
										pausa("No se han aplicado modificaciones a�n.");
									}
								}

							break;

							case 6: //SALIR
								if (equalEmployees(auxEmployee,listaEmpleados[auxIndex]))
								{
									continuarModificacion = FALSE;
								}
								else
								{
									if (msjConfirmar("Se perder�n los cambios no guardados, �est� seguro?"))
									{
										continuarModificacion = FALSE;
									}
								}
							break;
						}

					}while(continuarModificacion == TRUE);
				}


			break;
			//TODO OK
			case 3: //Baja Empleado
				printMenuHeader("B�squeda empleado");
				printEmployees(listaEmpleados,MAXIMOEMPLEADOS);
				auxId = getInt("Ingrese ID de empleado que desea eliminar: ");
				auxIndex = findEmployeeById(listaEmpleados,MAXIMOEMPLEADOS, auxId);
				if (auxIndex == -1)
				{
					pausa("ID inexistente.");
				}
				else
				{
					printf("\nEmpleado encontrado:");
					printEmployeeHeader();
					printEmployee(listaEmpleados[auxIndex]);

					if (msjConfirmar("Se eliminar� el empleado del sistema, no hay vuelta atr�s para esta operaci�n. �Desea continuar?"))
					{
						listaEmpleados[auxIndex].isEmpty = TRUE;
						cantidadEmpleados--;
						pausa("Empleado eliminado correctamente.");
					}
					else
					{
						pausa("No se ha eliminado al empleado.");
					}
				}
			break;
			//TODO OK
			case 4: //Informar
				ordenListarEmpleados = 1;

				//Calcular total y promedio salario.
				salarioTotal = acumSalaryEmployee(listaEmpleados,MAXIMOEMPLEADOS);
				salarioPromedio = getProm(salarioTotal,cantidadEmpleados); //Si cantidad empleados es 0, no se puede ingresar a esta opcion -> no hay division por 0 posible.
				//Calcular cuantos empleados superan el promedio.
				empleadosSuperanSalarioPromedio = countEmployeesSalarioMayorA(listaEmpleados,MAXIMOEMPLEADOS,salarioPromedio);

				//Listar empleados ordenados
				do
				{
					system("clear");
					copyEmployeesList(listaEmpleados,listaEmpleadosOrden,MAXIMOEMPLEADOS);
					sortEmployees(listaEmpleadosOrden,MAXIMOEMPLEADOS,ordenListarEmpleados);
					printEmployees(listaEmpleadosOrden,MAXIMOEMPLEADOS);
					printf("\n");
					printf("\nSuma total de salarios: %.2f",salarioTotal);
					printf("\nPromedio salarios: %.2f",salarioPromedio);
					printf("\nCantidad de empleados con salario mayor al promedio: %d",empleadosSuperanSalarioPromedio);
					printf("\n");

					opcionInformar = menuOptionGet("Men� Informar",opcionesMenuInformar,OPCIONESMENUINFORMAR);
					if (opcionInformar == 1)
					{
						ordenListarEmpleados = !ordenListarEmpleados;
					}

				}while (opcionInformar != 2);

			break;
			case 5:
				if (msjConfirmar("�Est� seguro que desea salir del programa?"))
				{
					salir = 1;
				}
			break;
		}

	}while (!salir); //El men� no tiene opci�n de salir en enunciado. Por lo tanto se deja bucle infinito.

	return 0;
}
