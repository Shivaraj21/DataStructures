#include<stdio.h>
int isPrime(int num);


int main() {
    int num1,num2, sum=0;
    printf("Enter range\n");
    scanf("%d %d",&num1,&num2);
    for(int i = num1 ; i < num2; i++) {
        if(isPrime(i)) {
        printf("%d  ",i);
        sum = sum+ i;
        }
    }
    printf("\nsum of all the prime numbers = %d",sum);
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