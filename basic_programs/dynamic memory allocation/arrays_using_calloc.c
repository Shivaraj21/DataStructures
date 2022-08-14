#include<stdio.h>
#include<stdlib.h>

int main() {
    int *ptr, n;
    printf("Enter the size of array\n");
    scanf("%d",&n);

    ptr = (int *) calloc(n, sizeof(int));

    printf("Enter the elements\n");
    for(int i = 0; i < n; i++) 
        scanf("%d", (ptr + i));
    
    for(int i = 0; i < n; i++)
        printf("%d ",*(ptr + i));

}