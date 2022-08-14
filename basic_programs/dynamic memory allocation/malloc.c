#include<stdio.h>
#include<stdlib.h>

int main() {
    int *ptr =(int *) malloc(sizeof(int));
    printf("ptr = %u\n", ptr);
    printf("*ptr = %d\n", *ptr);
    *ptr = 100;
    printf("*ptr = %d\n", *ptr);
    *ptr = 30;
    printf("*ptr = %d\n", *ptr);
}