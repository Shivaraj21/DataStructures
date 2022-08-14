#include<stdio.h>

int main() {
	int arr[20], i , n, max, min;
	printf("Enter the no. of array\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for (i = 1; i <= n; i++) {
		scanf("%d",&arr[i]);
	}
	printf("Reversed Array is\n");
	for (i = n; i > 0; i--) {
		printf("%d ",arr[i]);
	}
}