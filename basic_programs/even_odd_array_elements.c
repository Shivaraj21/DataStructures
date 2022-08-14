#include<stdio.h>

int main() {
	int arr[20], i, n;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for (i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	printf("Even array elements are\n");
	for (i = 0; i < n; i++) {
		if(arr[i]%2 == 0) printf("%d ",arr[i]);
	}
	printf("\nOdd array elements are\n");
	for (i = 0; i < n; i++) {
		if(arr[i]%2 != 0) printf("%d ",arr[i]);
	}
}