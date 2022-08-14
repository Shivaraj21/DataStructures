#include<stdio.h>
#define SIZE 20

int bin_search(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return 1;
        if (key <= arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

int main() {
    int arr[SIZE], key, n, i, count = 0, result;
    printf("Enter no. of array elements\n");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key element\n");
    scanf("%d", &key);
    result = bin_search(arr, n, key);
    if(result) {
        printf("Key is found\n");
    } else {
        printf("Key is not found\n");
    }
    return 0;
}