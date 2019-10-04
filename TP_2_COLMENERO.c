#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "ArrayEmployees.h"


#define QTY_EMPLOYEES 1000



int main(){
eEmployee Elist[QTY_EMPLOYEES];
int id = 100;
int flagA = 0;
char opcion = 'n';

initEmployees(Elist, QTY_EMPLOYEES); //Se indica que la posición se encuentra vacía.


do{
    switch(menu()){
    case 1:
        flagA = 1;

        if(addEmployees(Elist, id, QTY_EMPLOYEES)){
            id++;
        }
        system("pause");
        break;

    case 2:
        if(flagA == 1){
        removeEmployee(Elist, QTY_EMPLOYEES);
        } else {
        printf("Debe ingresar empleados primero \n");
        }
        system("pause");
        break;
    case 3:
        if(flagA == 1){
        modifyEmployees(Elist, QTY_EMPLOYEES);
        } else {
        printf("Por favor, ingresar empleados primero \n");
        }
        system("pause");
        break;
    case 4:
        if(flagA == 1){
        printEmployees(Elist, QTY_EMPLOYEES);
        } else {
        printf("Por favor, ingrese empleados y luego seleccione otra opcion nuevamente \n");
        }
        system("pause");
        break;
    case 5:
        if(flagA == 1){
        getInformes(Elist, QTY_EMPLOYEES);
        } else {
        printf("Aun no hay empleados que mostrar \n");
        }
        system("pause");
        break;
    case 6:
        printf("\n ¿Desea salir? s o n\n");
            fflush(stdin);
            opcion = getche();
            system("pause");
            break;
    default:
        printf("\n Opcion invalida \n");
    }
    system("pause");

} while(opcion == 'n');

return 0;
}
