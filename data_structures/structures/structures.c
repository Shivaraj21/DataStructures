#include<stdio.h>
#include<string.h>

struct  Employee {
    int E_no;
    char E_name[20];
    float E_sal;
};


int main() {
    printf("\n----Program 1----\n");
    struct Employee emp;
    emp.E_no = 122;
    strcpy(emp.E_name,"ABC");
    emp.E_sal = 1786.5;
    printf("Name = %s \nNumber=%d \nSalary = %f\n",emp.E_name, emp.E_no, emp.E_sal);
    return 0;
}