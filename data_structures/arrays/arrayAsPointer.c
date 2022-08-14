//array as pointer
#include<stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};

    // Printing address of elements
    printf("%u\n", arr);
    printf("%u\n", (arr + 1));
    printf("%u\n", (arr + 2));

    //different way of accessing address of first element
    printf("\n%u\n", arr);
    printf("%u\n", (arr + 0));
    printf("%u\n", &arr[0]);

    //different ways of accessing value of first element
    printf("\n%d\n", *arr);
    printf("%d\n", *(arr + 0));
    printf("%d\n", arr[0]);
 }