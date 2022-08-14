#include<stdio.h>
#define SIZE 20

int main() {
    int arr[SIZE];
    int n, i, key, flag = 0;

    printf("Enter the size of array\n");
    scanf("%d",&n);

    printf("Enter the elements\n");
    for (i = 0; i < n; i++) 
        scanf("%d",&arr[i]);

    printf("Enter the key element\n");
    scanf("%d",&key);
    
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("key found at %d position\n",i+1);
            flag = 1;
        }
    }
    if(flag == 0) 
        printf("key not found\n");
    
    return 0;
}