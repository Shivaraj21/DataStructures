#include<stdio.h>
#define SIZE 20
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *first, int *second);
int main() {
    int arr[SIZE], n;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    printf("Enter the array elements\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);

    printf("Sorted elements are \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void swap(int *first, int *second) {
    int temp = *first;
    *second = *first;
    *first = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low], i = low, j = high;
    while(i < j) {
        do {
            i++;
        } while(arr[i]<=pivot);
        do {
            j--;
        } while(arr[j]>pivot);

        if(i < j) {
        swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;

}

void quick_sort(int arr[], int low, int high) {
    int j;
    if(low < high) {
        j = partition(arr, low, high);
        quick_sort(arr, low, j);
        quick_sort(arr, j + 1, high);
    }
}
