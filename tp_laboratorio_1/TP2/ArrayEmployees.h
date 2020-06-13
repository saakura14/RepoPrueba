#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

/**\fn initEmployess
 * \brief	To indicate that all position in the array are empty,
*			this function put the flag (isEmpty) in TRUE in all
*			position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);

int hardcodearEmployees(Employee listaEmpleados[], int sizeEmpleados);
/**\fn addEmployee
 * \brief 	add in a existing list of employees the values received as parameters
* 			in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

Employee inputEmployeeData(int nextEmployeeID);

Employee inputEmployeeName(Employee myEmployee);
Employee inputEmployeeLastName(Employee myEmployee);
Employee inputEmployeeSalary(Employee myEmployee);
Employee inputEmployeeSector(Employee myEmployee);

/*\fn findEmptyEmployee
 * \brief find the first empty position of an Employee array.
 * \param list Employee*: Employee array.
 * \param len int: length of array.
 * \return int Return (-1) if there are no empty elements in the array. Else, return index of first empty element.
 * */
int findEmptyEmployee(Employee* list, int len);


/**\fn findEmployeeById
 * \brief find an Employee by Id and returns the index position in array.
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*/
int findEmployeeById(Employee* list, int len,int id);




/**\fn removeEmployee
* \brief Remove a Employee by Id (put isEmpty Flag in 1)
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*/
int removeEmployee(Employee* list, int len, int id);


/**\fn sortEmployees
* \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortEmployees(Employee* list, int len, int order);

/**\fn orderEmployeesASC
* \brief Sort the elements in the array of employees by lastName & sector ASC
* \param list Employee*
* \param len int
* \return void
*/
void orderEmployeesASC (Employee* list, int len);


/**\fn orderEmployeesDESC
* \brief Sort the elements in the array of employees by lastName & sector DESC
* \param list Employee*
* \param len int
* \return void
*/
void orderEmployeesDESC (Employee* list, int len);

/**\fn printEmployees
* \brief print the content of employees array
* \param list Employee*
* \param length int
* \return int
*/
int printEmployees(Employee* list, int length);

/*\fn printEmployee
 * \brief print a Employee.
 * \param myEmployee Employee
 * \return void
 * */
void printEmployee(Employee myEmployee);

/*\fn printEmployeeHeader
 * \brief prints the headers of an Employee datatype.
 * \param void
 * \return void
 * */
void printEmployeeHeader(void);

/*\fn equalEmployees
 * \brief compare two Employees.
 * \param myEmployee Employee
 * \param otherEmployee Employee
 * \return int: (1) if both Employees are equals, (0) if not.
 * */
int equalEmployees(Employee myEmployee, Employee otherEmployee);

/*\fn countEmployees
 * \brief count Employees of listaEmpleados[] that aren't empty.
 * \param listaEmpleados[] Employee
 * \param sizeEmpleados int
 * \return int: Employees not emptys quantity.
 * */
int countEmployees (Employee listaEmpleados[], int sizeEmpleados);

/*\fn acumSalaryEmployee
 * \brief acum salary's Employees in listaEmpleados[] that aren't empty.
 * \param listaEmpleados[] Employee
 * \param sizeEmpleados int
 * \return double: salary acum
 * */
double acumSalaryEmployee(Employee listaEmpleados[], int sizeEmpleados);

/*\fn countEmployeesSalarioMayorA
 * \brief count Employees of listaEmpleados[] that aren't empty and theirs salarys are more than salarioASuperar.
 * \param listaEmpleados[] Employee
 * \param sizeEmpleados int
 * \param salarioASuperar float
 * \return int: Employees not emptys and salary > salarioASuperar quantity.
 * */
int countEmployeesSalarioMayorA(Employee listaEmpleados[], int sizeEmpleados, float salarioASuperar);

/*\fn copyEmployeesList
 * \brief copy listaEmpleados[] to auxListaEmpleados[].
 * \param listaEmpleados[] Employee
 * \param auxListaEmpleados[] Employee
 * \param sizeEmpleados int
 * \return void
 * */
void copyEmployeesList(Employee listaEmpleados[],Employee auxListaEmpleados[], int sizeEmpleados);

/*\fn getMaxIDEmployee
 * \brief get the max ID of the not emptys employees of listaEmpleados[].
 * \param listaEmpleados[] Employee
 * \param sizeEmpleados int
 * \return int: higher ID of the not emptys employees.
 **/
int getMaxIDEmployee(Employee listaEmpleados[], int sizeEmpleados);

#endif // ARRAYEMPLOYEES_H_INCLUDED
