#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define GETVALUES_H_INCLUDED


int arrayLength(char arrayChar[])
{
    int length;
    length = strlen(arrayChar);
    return length;
}

void inputArray (char arrayChar[],int longitudMaxima, char mensajeIngreso[])
{
    int length;
    printf("\n%s",mensajeIngreso);
    __fpurge(stdin);
    fgets(arrayChar,longitudMaxima,stdin);
    length = arrayLength(arrayChar);
    quitarSaltosArray(arrayChar,length);
}

void quitarSaltosArray(char arrayChar[], int length)
{
    int i;
    for (i = 0; i<length;i++)
    {
        if (arrayChar[i] == '\n')
        {
            arrayChar[i] = '\0';
        }
    }
}

int getInt(char mensajeIngreso[])
{
	int numero;

	printf("\n%s",mensajeIngreso);
	__fpurge(stdin);
	scanf("%d",&numero);

	return numero;
}

int getIntValidacion(char mensajeIngreso[], char errorIngreso[], int minimo, int maximo)
{
	int numero;
	numero = getInt(mensajeIngreso);

	while (numero < minimo || numero > maximo)
	{
		numero = getInt(errorIngreso);
	}

	return numero;
}


void ArrayToLower(char arrayChar[])
{
   int length;
   int i;
   length = arrayLength(arrayChar);
   for (i = 0; i < length; i++)
   {
       arrayChar[i]=tolower(arrayChar[i]);
   }

}

void UpperPrimerasLetras(char arrayChar[])
{
    int length;
    int i;

    ArrayToLower(arrayChar);
    length = arrayLength(arrayChar);
    arrayChar[0] = toupper(arrayChar[0]);
    for (i=0; i<length-1;i++)
    {
        if (arrayChar[i] == ' ')
        {
            arrayChar[i+1]=toupper(arrayChar[i+1]);
        }

    }
}

float getFloatConMinimo(char mensaje[], char mensajeError[], float minimo)
{
	float valor;

	printf("\n%s",mensaje);
	__fpurge(stdin);
	scanf("%f", &valor);

	while(valor < minimo){
		printf("\n%s",mensajeError);
		__fpurge(stdin);
		scanf("%f", &valor);
	}

	return valor;
}


int msjConfirmar(char mensaje[])
{
	int retorno = 0;
	char respuesta;

	do{
		printf("\n%s (S/n)",mensaje);
		__fpurge(stdin);
		scanf("%c",&respuesta);

	}while (respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n');

	if (respuesta == 'S' || respuesta == 's')
	{
		retorno = 1;
	}

	return retorno;
}

double getProm(double value, int quantity)
{
	double retorno;

	retorno = value / quantity;

	return retorno;
}

