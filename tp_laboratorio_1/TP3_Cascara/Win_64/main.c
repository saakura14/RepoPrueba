#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"



int main()
{
    int option = 0;

    int flag = 0;
    int respuesta;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        utn_getUnsignedInt("\n ----MENU ----\n\n\n1) Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2) Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n3) Alta de empleado\n4) Listar Empleados\n5) Modificar Empleado\n6) Eliminar Empleado\n7) Ordenar empleados por nombre\n8) Guardar el archivo en modo binario\n9) Guardar el archivo en modo texto\n10) Salir\n", "ERROR: Ingrese un numero valido.", 0, 3, 0, 10, 1, &option);
        fflush(stdin);
        switch(option)
        {
        case 1:
            if(!flag)
            {
                controller_loadFromText("data.csv",listaEmpleados);
            }
            else
            {
                utn_getUnsignedInt("Ya se han cargado los datos. Desea volver a cargarlos?. \n 1) Si - 2) No", "ERROR: Ingrese un numero valido.", 0, 3, 0, 10, 1, &respuesta);

                fflush(stdin);
                if(respuesta == 1)
            {
                ll_clear(listaEmpleados);
                    controller_loadFromText("data.csv",listaEmpleados);
                }
            }
            break;
        case 2:
            if(!flag)
            {
                controller_loadFromBinary("data.bin", listaEmpleados);
            }
            else
            {
                utn_getUnsignedInt("Ya se han cargado los datos. Desea volver a cargarlos? \n 1) Si - 2) No", "ERROR: Ingrese un numero valido.", 0, 3, 0, 10, 1, &respuesta);

                fflush(stdin);
                if(respuesta == 1)
            {
                ll_clear(listaEmpleados);
                    controller_loadFromText("data.csv",listaEmpleados);
                }
            }
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            controller_ListEmployee(listaEmpleados);
            break;
        case 5:
            controller_editEmployee(listaEmpleados);
            break;
        case 6:
            controller_removeEmployee(listaEmpleados);
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            controller_saveAsBinary("data.bin", listaEmpleados);
            break;
        case 9:
            controller_saveAsText("data.csv", listaEmpleados);
            break;
        }
    }
    while(option != 10);
    return 0;
}
