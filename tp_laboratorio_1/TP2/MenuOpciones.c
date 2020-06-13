#include <stdio.h>
#include <stdio_ext.h>


void printMenu(char titulo[], char opciones[][30], int length)
{
	int i;

	printMenuHeader(titulo);
	for (i=0;i<length;i++)
	{
		printf("\n%d. %s",i+1,opciones[i]);
	}
	printf("\n");
}

void printMenuHeader(char header[])
{
	printf("=======================\n");
	printf("%s\n",header);
	printf("=======================\n");
}

int menuOptionGet(char titulo[], char opciones[][30], int length)
{
	int opcionRetorno;
	printMenu(titulo,opciones,length);
	opcionRetorno = getIntValidacion("Ingrese opción: ","Opción incorrecta, vuelva a intentarlo: ",1,length);
	return opcionRetorno;
}

void pausa (char mensaje[])
{

	printf("\n%s",mensaje);
	__fpurge(stdin); //Se realiza fpurge para limpiar el buffer y evitar saltar la pausa automaticamente por contenido basura.
	getchar();
}
