#include<stdio.h>
#define SIZE 20

void selection_sort(int arr[], int n);
void display(int arr[],int n);

int main() {
    int arr[SIZE], n;
    printf("Enter the no. of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, n);
    display(arr, n);
    return 0;
}

void selection_sort(int arr[], int n) {
    int min_index, temp;
    for (int i = 1; i < n - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        //swap elements
        if(min_index != i) {
            temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }
    }
}

void display(int arr[], int n) {
    printf("Sorted elements are\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}