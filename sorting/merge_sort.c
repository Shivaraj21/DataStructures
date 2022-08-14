#include<stdio.h>
#define SIZE 20

void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
int main() {
	int n, arr[SIZE];
	printf("Enter no. of array elements\n");
	scanf("%d", &n);
	printf("Enter array elements\n");
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	merge_sort(arr, 0, n - 1);
	printf("Sorted element is ");
	for (int i = 0; i < n; i++)	{
		printf("%d ", arr[i]);
	}
}

void merge_sort(int arr[], int l, int r) {
	int mid;
	if(l < r) {
		mid = l + ((r - l) / 2);
		merge_sort(arr, l, mid);
		merge_sort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(i = 0; i < n1; i++) {
		L[i] = arr[l + i];
	}
	for(j = 0; j < n2; j++) {
		R[j] = arr[m + 1+ j];
	}

	i = j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	
}