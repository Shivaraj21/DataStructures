#include<stdio.h>
#include<stdlib.h>

int main() {
    int n = 1;
    int *ptr = (int *) calloc(n, sizeof(int));
    printf("ptr = %u\n", ptr);
    printf("*ptr = %d\n", *ptr);
    *ptr = 100;
    printf("*ptr = %d\n", *ptr);
}