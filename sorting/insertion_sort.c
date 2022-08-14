#include<stdio.h>
#define SIZE 20

void insertion_sort(int arr[], int n);
void display(int arr[],int n);

int main() {
    int arr[SIZE], n;
    printf("Enter the no. of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, n);
    display(arr, n);
    return 0;
}

void insertion_sort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        
    }
}

void display(int arr[], int n) {
    printf("Sorted elements are\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}