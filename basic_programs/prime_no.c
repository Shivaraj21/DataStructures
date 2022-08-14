#include<stdio.h>
int isPrime(int num);


int main() {
    int num;
    printf("Enter the number\n");
    scanf("%d",&num);
    if(isPrime(num)) {
        printf("Prime number\n");
    } else {
        printf("Not a prime number\n");
    }
}

int isPrime(int num) {
    if(num == 0 || num == 1) return 0;
    for(int i = 2; i < num; i++) {
        if(num%i == 0) {
            return 0;
        }
    }
    return 1;
}