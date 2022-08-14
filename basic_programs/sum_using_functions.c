#include<stdio.h>
int sum(int a, int b);

int main() {
    int a = 20, b = 30, c;
    c = sum(a,b);
    printf("Sum is %d",c);
}

int sum(int a, int b) {
    int sums = a + b;
    return sums;
}