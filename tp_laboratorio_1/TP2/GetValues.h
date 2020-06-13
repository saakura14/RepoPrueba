#ifndef GETVALUES_H_INCLUDED
#define GETVALUES_H_INCLUDED
/*\fn arrayLength
 * \brief Retornar longitud de un array
 * \param arrayChar[] char
 * \return int Retorna la longitud del array pasado como parámetro.
 * */
int arrayLength(char arrayChar[]);

/*\fn InputArray
 * \brief Solicita al usuario ingresar un valor tipo char []
 * \param arrayChar char []
 * \param longitudMaxima int
 * \param mensajeIngreso[] char []
 * \return void
 * */
void inputArray (char arrayChar[],int longitudMaxima, char mensajeIngreso[]);

/*\fn quitarSaltosArray
 * \brief reemplaza los \n de un array por \0
 * \param arrayChar char[]
 * \param longitudMaxima int
 * \param mensajeIngreso char[]
 * \return void
 * */
void quitarSaltosArray(char arrayChar[], int length);

/*\fn getInt
 * \brief muestra un mensaje en pantalla y solicita al usuario ingresar un entero
 * \param mensajeIngreso char []
 * \return int: Retorna número ingresado
 * */
int getInt(char mensajeIngreso[]);

/*\fn getIntValidacion
 * \brief muestra un mensaje en pantalla y solicita al usuario ingresar un entero, valida que el mismo esté entre un mínimo y máximo
 * \param mensajeIngreso char []
 * \param errorIngreso char []
 * \param minimo int
 * \param maximo int
 * \return int: Retorna número ingresado validado
 * */
int getIntValidacion(char mensajeIngreso[], char errorIngreso[], int minimo, int maximo);


/**
 * \fn void ArrayToLower(char arrayChar[])
 * \brief Transforma todo caracter de un array a lower case.
 * \param char arrayChar[]: array a modificarse.
 * \return void
 */
void ArrayToLower(char arrayChar[]);

/**
 * \fn void UpperPrimerasLetras(char arrayChar[])
 * \brief Se hace una capitalización de la primer letra de cada string en un array.
 * \param char arrayChar[]: array a modificarse.
 * \return void
 */
void UpperPrimerasLetras(char arrayChar[]);


/**
 * \fn float getFloatConMinimo(char mensaje[], char mensajeError[], float minimo)
 * \brief Nos permite obtener un número flotante mayor a "minimo"
 * \param char mensaje[]: Mensaje de ingreso de dato
 * \param char mensajeError[]: Mensaje de ingreso de dato en caso de error en intento anterior
 * \param float minimo: valor mínimo permitido para ingresar.
 * \return float: retorna número ingresado validado.
 *  */
float getFloatConMinimo(char mensaje[], char mensajeError[], float minimo);

/* \fn msjConfirmar(char mensaje[])
 * \brief Nos muestra un mensaje para responder con S o N.
 * \param char mensaje[]: Mensaje de solicitud de confirmación
 * \return int: (1) si la respuesta es S. (0) si la respuesta es N.
 * */
int msjConfirmar(char mensaje[]);

/* \fn getProm(double value, int quantity)
 * \brief Calcula promedio de value sobre quantity.
 * \param double value: dividendo del promedio.
 * \param int quantity: divisor del promedio.
 * \return double: resultado de la division.
 * */
double getProm(double value, int quantity);


#endif // GETVALUES_H_INCLUDED
