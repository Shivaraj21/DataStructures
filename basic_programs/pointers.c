#include<stdio.h>

int main() {
    int a = 10;
    int *adr = &a;
    int *badr = &a;
    int **padr = &adr;
    
    printf("a = %d\n",a);
    printf("&a = %u\n",&a);

    printf("\nadr = %u\n",adr);
    printf("&adr = %u\n",&adr);
    printf("*adr = %d\n",*adr);

    printf("\nbadr = %u\n",badr);
    printf("&badr = %u\n",&badr);
    printf("*badr = %d\n",*badr);

    printf("\npadr = %u\n",padr);
    printf("&padr = %u\n",&padr);
    printf("*padr = %u\n",*padr);
    printf("**padr = %d\n",**padr);
}