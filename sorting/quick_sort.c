#include<stdio.h>
#define SIZE 20

void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *first, int *second);

int main() {
    int arr[SIZE], n, low, high;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    printf("Enter the array elements\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    low = 0;
    high = n - 1;
    quick_sort(arr, low , high);
    printf("Sorted elements are \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
void swap(int *first, int *second) {
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low -1;
    for(int j = low; j <= high - 1; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quick_sort(int arr[], int low, int high) {
    if(low < high) {
        int j = partition(arr, low, high);
        quick_sort(arr, low, j - 1);
        quick_sort(arr, j + 1, high);
    }
}