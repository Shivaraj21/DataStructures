#include<stdio.h>
#define SIZE 20

void bubble_sort(int arr[], int n);
void display(int arr[], int n);

int main() {
    int arr[SIZE], n;
    printf("Enter the no. of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);
    display(arr, n);
    return 0;
}

void bubble_sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void display(int arr[], int n) {
    printf("Sorted elements are\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}