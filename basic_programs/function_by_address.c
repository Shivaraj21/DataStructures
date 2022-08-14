//calling function by address
#include<stdio.h>
void swap(int *a, int *b);

int main() {
	int a = 10, b = 20;
	printf("Original value: %d %d\n",a, b);
	swap(&a, &b);
	printf("After swap(): %d %d", a, b);
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}