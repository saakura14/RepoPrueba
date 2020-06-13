#ifndef MENUOPCIONES_H_INCLUDED
#define MENUOPCIONES_H_INCLUDED

/*\fn printMenu
* \brief print the title and options of a menú.
* \param titulo char[]
* \param opciones char[][30]
* \param length int
* \return void
*/
void printMenu(char titulo[], char opciones[][30], int length);

/*\fn printMenuHeader
* \brief print the title of a menú.
* \param header char[]
* \return void
*/
void printMenuHeader(char header[]);

/*\fn printMenu
* \brief print the title and options of a menú. Get the option selected by user validated.
* \param titulo char[]
* \param opciones char[][30]
* \param length int
* \return int: Option selected by user validated between 1 and length.
*/
int menuOptionGet(char titulo[], char opciones[][30], int length);

/*\fn pausa
 * \brief Show a message and make a pause until the user press <Enter>.
 * \param mensaje[]
 * \return void
 * */
void pausa (char mensaje[]);



#endif // MENUOPCIONES_H_INCLUDED
