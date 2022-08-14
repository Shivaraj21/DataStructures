#include<stdio.h>

int main() {
	int arr[20], i , n, max, min;
	printf("Enter the no. of array\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for (i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	max = arr[0];
	min = arr[0];
	for(i = 0; i < n; i++) {
		if(max < arr[i]) {
			max = arr[i];
		}
		if(min > arr[i]) {
			min = arr[i];
		}
	}
	printf("Maximum of array element is %d",max);
	printf("\nMinimum of array element is %d",min);
}