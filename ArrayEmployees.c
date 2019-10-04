
#include "ArrayEmployees.h"



/** \brief Función encargada de mostrar y dar a elegir opciones del menú
* principal del programa
* \return Retorna la opción elegida por el usuario
*
*/
int menu(){
    int opcion;

    system("cls");
    printf("\n -------- ABM Empleados -------- \n\n");
    printf("1-Alta de empleado\n");
    printf("2-Baja de empleado\n");
    printf("3-Modificar un empleado\n");
    printf("4-Listar empleados\n");
    printf("5- Informes \n");
    printf("6-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

/** \brief Para indicar que todas las posiciones del array están vacías
* Se coloca la bandera isEmpty en TRUE en todas las
* posiciones del array
* \param eEmployee Elist
* \param len la cantidad de datos que contenga el array
* \return Se retorna un 0 si se concluye que todas las posiciones fueron recorridas.
*
*/
int initEmployees(eEmployee Elist[], int len){
    int i;

     for(i = 0; i < len; i++){
        Elist[i].isEmpty = 1;
    }
    return 0;
}

/** \brief Esta función se encarga de buscar un espacio libre
* que pueda ser ocupado por el nuevo dato a ingresar.
* \param Elist corresponde al array donde se trabajará
* \param len Corresponde a la cantidad de elementos del array
* \return Retorna un -1 si hubo errores o 0 si se llegó a lo esperado.
*
*/
int findFreeSpace(eEmployee Elist[], int len){
    int index = -1;
    int i;

     for(i = 0; i < len; i++){
        if(Elist[i].isEmpty == 1){
            index = i;
            break;   //Se corta la búsqueda una vez que se halló un lugar libre.
        }
    }
    return index;
}

/** \brief Toma el espacio libre encontrado con la función anterior y lo
* ocupa pasando los datos recolectados
* \param Elist Corresponde al array sobre el que se trabajará
* \param len Corresponde a la cantidad de empleados
* \param id Corresponde al id de cada empleado
* \param name[] Nombres de los empleados
* \param lastName[] Apellidos de los empleados
* \param salary Salarios de los empleados
* \param sector Sector al que pertenecen los empleados
* \return int Retorna un -1 si hubo erroes y un 0 si pudo finalizar la ejecución
*
*/

int addEmployees(eEmployee Elist[], int id, int len){
    char NameAux[51];
    char LastNameAux[51];
    float SalaryAux;
    int SectorAux;
    int index;
    int FlagOk = 0;

    system("cls");

    printf("\n **** Alta empleado **** \n");

    index = findFreeSpace(Elist, len);

    if(index == -1){
        printf("\n\n **** Espacio de memoria lleno, no es posible ingresar el empleado **** \n");
    }
    else
    {
    printf("Ingrese el nombre del empleado: \n");
    fflush(stdin);
    gets(NameAux);

    printf("Ingrese el apellido del empleado: \n");
    fflush(stdin);
    gets(LastNameAux);

    printf("Ingrese el salario del empleado: \n");
    scanf("%f" ,&SalaryAux);

    printf("Ingrese el sector correspondiente al empleado: \n");
    scanf("%d" ,&SectorAux);

    Elist[index] = newEmployee(id, NameAux, LastNameAux, SalaryAux, SectorAux);
    FlagOk = 1;
    printf("\n **** El alta se realizo con exito!! **** \n");
    }

    return FlagOk;
}

eEmployee newEmployee(
        int id,
        char name[],
        char lastName[],
        float salary,
        int sector
        //int isEmpty
                      )
{
    eEmployee Em;
    Em.id = id;
    strcpy(Em.name, name);
    strcpy(Em.lastName, lastName);
    Em.salary = salary;
    Em.sector = sector;
    Em.isEmpty = 0;

    return Em;
}

/** \brief Encuentra un empleado recibiendo su ID como parámetro
 *
 * \param Elist Corresponde al array que se recorrerá
 * \param len Corresponde a la cantidad de empleados que se recorrerán
 * \param id Corresponde al ID de cada empleado que deberá comparar hasta
 * hallar el ID que sea idéntico al ingresado por teclado
 * \return Retorna la posición del empleado buscado o un -1 en caso de que no logre
 * encontrarlo
 *
 */
int findEmployeeById(eEmployee Elist[], int id, int len){
    int index = -1;
    int i;

    for(i = 0; i < len; i++){
        if(Elist[i].id == id && Elist[i].isEmpty == 0){
            index = i;
            break;
        }
    }
    return index;
}

/** \brief Muestra un empleado recibiendo todos los parámetros de la estructura
 *
 * \param Em Indica dónde se deberá buscar el dato seguido del operador punto
 *
 */
void printEmployee(eEmployee Em){
        printf("\n %d   %s   %s   %.2f   %d    \n" ,Em.id ,Em.name ,Em.lastName ,Em.salary ,Em.sector);
}

/** \brief Imprime el contenido del array de forma encolumnada
 * Cuenta con una bandera que indica si se pudo encontrar algún
 * empleado para ser mostrado o no
 * \param Elist Corresponde al array
 * \param length Corresponde a la cantidad de elementos del array
 * \return Retorna un 0 si se logró encontrar al menos un empleado
 * para mostrar.
 *
 */

int printEmployees(eEmployee Elist[], int length){
    int flag = 0;  //Para informar si no existen datos para mostrar.
    int i;
    system("cls");

     printf("\n**** Listado de empleados ******\n");
     printf("\n ID     Nombre   Apellido   Salario   Sector \n");
    for(i = 0; i < length; i++){
        if(Elist[i].isEmpty == 0){
            printEmployee(Elist[i]);

              flag = 1;
        }
    }
    if(flag == 0){
        system("cls");
        printf("\n****** No hay empleados para mostrar ******\n");
    }
    return 0;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param Elist Corresponde al vector que se recorrerá
 * \param len Corresponde a la cantidad de elementos del array
 * \param id Corresponde al ID de cada empleado
 * \return Retorna un 0 si se pudo remover el empleado exitosamente
 * o un -1 si no logra encontrar el empleado. Si se confirma
 * la baja del empleado y se puede realizar correctamente
 * con el consentimiento del usuario, se devuelve un 1
 *
 */

int removeEmployee(eEmployee Elist[], int len){
   int flagOk = 0;
   int index;
   int id;
   char confirm;

   system("cls");
   printf("\n ****** Baja de empleado ****** \n");
   printf("Ingrese el ID del empleado que desea dar de baja: \n");
   scanf("%d" ,&id);

   index = findEmployeeById(Elist, id, len);

   if(index == -1){
    printf("\n No existe un empleado con ese ID \n");
   }
   else
   {
        printEmployee(Elist[index]);

        printf("¿Confirma la baja del empleado? \n");
        fflush(stdin);
        scanf("%c" ,&confirm);

        if(confirm == 's'){
            Elist[index].isEmpty = 1;
            flagOk = 1;
            printf("La baja se realizo con exito \n");
        }
        else
        {
            printf("\n Se ha cancelado la operacion \n");
        }
   }
   return flagOk;
}

/** \brief Función para modificar un elemento dentro del array, dentro
 * de un ingreso, se podrá modificar un dato (Ejemplo: el nombre
 * dentro de lo que sería un empleado ingresado)
 *
 * \param Elist Corresponde al array en el que se aplicará la función
 * \param len Corresponde a la cantidad de elementos del array
 * \param id Corresponde al ID de cada empleado
 * \return Retorna 0 si se pudo realizar la modificación exitosamente
 * o un -1 si no se pudo hallar el empleado a modificar
 *
 */

int modifyEmployees(eEmployee Elist[], int len){
    int flagOk = 0;
    int id;
    int indexAux;
    float salaryAux;
    int sectorAux;
    char nameAux[51];
    char lastNameAux[51];
    int option;

    system("cls");

    printf("\n ****** Modificar empleados ****** \n ");
    printf("\n Ingrese el ID del empleado que desea modificar \n");
    scanf("%d", &id);

    indexAux = findEmployeeById(Elist, id, len);

    if(indexAux == -1){
        printf("\n No existe ningun empleado con ese ID \n");
    }
    else
    {
        printEmployee(Elist[indexAux]);

        printf("1- Modificar el nombre del empleado \n");
        printf("2- Modificar el apellido del empleado \n");
        printf("3- Modificar el salario del empleado \n");
        printf("4- Modificar el sector del empleado \n");
        printf("5- Cancelar la modificacion \n");
        printf("Ingrese una opcion: \n");
        scanf("%d", &option);

    switch(option){
    case 1:
        printf("Ingrese el nuevo nombre: \n");
        strcpy(nameAux, Elist[indexAux].name);

        flagOk = 1;
        break;
    case 2:
        printf("Ingrese el nuevo apellido: \n");
        strcpy(lastNameAux, Elist[indexAux].lastName);

        flagOk = 1;
        break;
    case 3:
        printf("Ingrese el nuevo salario: \n");
        scanf("&.2f" ,&salaryAux);
        Elist[indexAux].salary = salaryAux;

        flagOk = 1;
        break;
    case 4:
        printf("Ingrese el nuevo sector: \n");
        scanf("&d" ,&sectorAux);
        Elist[indexAux].sector = sectorAux;

        flagOk = 1;
    case 5:
        printf("Se ha cancelado la modificacion \n");
        }
    }
    return flagOk;
}

/** \brief Función que realiza y muestra los informes realizados sobre los datos
 * correspondientes a los índices del array. Se muestra un SubMenú dando a elegir
 * las opciones de ordenamiento y operaciones con los salarios de los empleados
 *
 * \param Elist Corresponde al array en el que se aplicará la función
 * \param len Corresponde a la cantidad de elementos del array
 */
void getInformes(eEmployee Elist[], int len){
    int option;

    printf("\n *****Ordenar empleados***** \n");
    printf("1- Ordenar los empleados por sector de forma ascendente \n");
    printf("2- Ordenar los empleados por sector de forma descendente \n");
    printf("3- Ordenar los empleados por apellido de forma ascendente \n");
    printf("4- Ordenar los empleados por apellido de forma descendente \n");
    printf("5- Promedio de los salarios \n");
    printf("6- Cantidad de empleados que superan el salario promedio \n");
    printf("Ingrese una opcion: \n");
    scanf("%d", &option);

    switch(option){
    case 1:
        printf("***** Empleados ordenados por sector de forma ascendente ****** \n");
        sortEmployeesSec(Elist, len, 1);
    break;
    case 2:
        printf("***** Empleados ordenados por sector de forma descendente ****** \n");
        sortEmployeesSec(Elist, len, 0);
    break;
    case 3:
        printf("***** Empleados ordenados por apellido de forma ascendente ****** \n");
        sortEmployeesLastName(Elist, len, 1);
    break;
    case 4:
        printf("***** Empleados ordenados por apellido de forma descendente ****** \n");
        sortEmployeesLastName(Elist, len, 0);
    break;
    case 5:
        printf("***** Promedio de todos los salarios ****** \n");
        TotEmployees(Elist, len);
    break;
    case 6:
        printf("**** Los empleados que superan el salario promedio **** \n");
        FindHighestSalaries(Elist, len);
    break;
    default:
        printf("Opcion invalida \n");
    }
}

/** \brief Función que ordena los empleados por el sector al cual
 * pertenecen dentro del array, se ordena de forma
 * descendente o ascendente dependiendo del número de órden que se le
 * asigne
 *
 * \param Elist Corresponde al array en el que se aplicará la función
 * \param len Corresponde a la cantidad de elementos del array
 * \param order Corresponde al tipo de ordenamiento que se le asigne a la función
 */
int sortEmployeesSec(eEmployee Elist[],int len, int order){
    int i;
    int j;
    eEmployee auxEmployee;

     if(order == 1){
    for(i = 0; i < len -1; i++){
        for(j = i+1; j < len; j++){
            if(Elist[i].sector > Elist[j].sector && Elist[i].isEmpty == 0 && Elist[j].isEmpty == 0){
                auxEmployee = Elist[i];
                Elist[i] = Elist[j];
                Elist[j] = auxEmployee;
            }
        }
    }
    }
    else
    {
        for(i = 0; i > len -1; i++){
        for(j = i+1; j > len; j++){
            if(Elist[i].sector < Elist[j].sector && Elist[i].isEmpty == 0 && Elist[j].isEmpty == 0){
                auxEmployee = Elist[i];
                Elist[i] = Elist[j];
                Elist[j] = auxEmployee;
            }
        }
    }
    }
    printEmployees(Elist, QTY_EMPLOYEES);
    return 0;
}

/** \brief Función que ordena los empleados por su apellido, de forma
 * descendente o ascendente dependiendo del número de órden que se le
 * asigne
 *
 * \param Elist Corresponde al array en el que se aplicará la función
 * \param len Corresponde a la cantidad de elementos del array
 * \param order Corresponde al tipo de ordenamiento que se le asigne a la función
 */
int sortEmployeesLastName(eEmployee Elist[], int len, int order){
    eEmployee auxEmployee;

    int i;
    int j;


     if(order == 1){
    for(i = 0; i < len -1; i++){
        for(j = i+1; j < len; j++){
            if(Elist[i].lastName > Elist[j].lastName && Elist[i].isEmpty == 0 && Elist[j].isEmpty == 0){
                auxEmployee = Elist[i];
                Elist[i] = Elist[j];
                Elist[j] = auxEmployee;
            }
        }
    }
    }
    else
    {
         for(i = 0; i > len -1; i++){
        for(j = i+1; j > len; j++){
            if(Elist[i].lastName < Elist[j].lastName && Elist[i].isEmpty == 0 && Elist[j].isEmpty == 0){
                auxEmployee = Elist[i];
                Elist[i] = Elist[j];
                Elist[j] = auxEmployee;
            }
        }
    }
    }
    printEmployees(Elist, QTY_EMPLOYEES);
    return 0;
}

/** \brief Función para calcular el total de empleados del arreglo
 * tomando sus sueldos para llegar al total de los mismos y
 * calcular el promedio
 *
 * \param Elist Corresponde al array en el que se aplicará la función
 * \param len Corresponde a la cantidad de elementos del array
 */
void TotEmployees(eEmployee Elist[], int len){
    int TotSalary = 0;
    int TotEmp = 0;
    float promedio;
    int i = 0;

    for(i = 0; i < len ; i++){
        if(Elist[i].isEmpty == 1){ //Si el espacio está ocupado, se cuentan los empleados y los salarios de cada uno se acumulan para conocer el total
            TotEmp++;
            TotSalary = TotSalary + Elist[i].salary;
        }
    }
    promedio = (float) TotSalary/TotEmp;

    //Se muestran los totales hallados
    printf("El promedio de sueldos es: %.2f" ,promedio);
    printf("El total de salarios en cantidad es %d" ,TotEmp);


}


/** \brief Función para hallar los empleados cuyo sueldo
 * supere el promedio
 *
 * \param Elist Corresponde al array en el que se aplicará la función
 * \param len Corresponde a la cantidad de elementos del array
 */
void FindHighestSalaries(eEmployee Elist[], int len){
    int TotSalary = 0;
    int TotEmp = 0;
    float promedio;
    int i = 0;

    for(i = 0; i < len ; i++){
        if(Elist[i].isEmpty == 1){ //Si el espacio está ocupado, se cuentan los empleados y los salarios de cada uno se acumulan para conocer el total
            TotEmp++;
            TotSalary = TotSalary + Elist[i].salary;
        }
    }
    promedio = (float) TotSalary/TotEmp;

    for(i = 0; i < len ; i++){ //Realizamos otro for que vuelva a recorrer el array en búsqueda de quienes cobren mayor salario que el promedio calculado
            if(Elist[i].salary > promedio){
                printEmployee(Elist[i]);
                break;
            }
    }
}
