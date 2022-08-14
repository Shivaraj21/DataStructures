#include<stdio.h>
#include<string.h>

struct  Employee {
    int E_no;
    char E_name[20];
    float E_sal;
};


int main() {
    printf("\n----Program 2----\n");
    struct Employee emp;
    struct Employee *eptr = &emp;
    eptr -> E_no = 122;
    strcpy(eptr -> E_name,"ABC");
    eptr -> E_sal = 1786.5;
    printf("Name = %s \nNumber=%d \nSalary = %f\n", (eptr -> E_name), (eptr -> E_no), (eptr -> E_sal));
    return 0;
}