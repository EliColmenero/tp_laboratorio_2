#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;



#endif // ARRAYEMPLOYEES_H_INCLUDED


int menu();
int initEmployees(eEmployee Elist[], int len);
int findFreeSpace(eEmployee Elist[], int len);
int addEmployees(eEmployee Elist[], int id, int len);
int findEmployeeById(eEmployee Elist[], int id, int len);
void printEmployee(eEmployee Em);
int printEmployees(eEmployee Elist[], int length);
int removeEmployee(eEmployee Elist[], int len);
int modifyEmployees(eEmployee Elist[], int len);
int sortEmployeesSec(eEmployee Elist[],int len, int order);
int sortEmployeesLastName(eEmployee Elist[], int len, int order);
void getInformes(eEmployee Elist[], int len);
void TotalSalary(eEmployee Elist[], int len);
void FindHighestSalaries(eEmployee Elist[], int len);
void TotEmployees(eEmployee Elist[], int len);
eEmployee newEmployee(int id, char name[], char lastName[], float salary, int sector);


