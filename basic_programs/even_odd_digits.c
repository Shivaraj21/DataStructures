// odd and even digit count 27-02-2022
#include<stdio.h>

int main() {
    int num = 12345, temp = num;
    int rem, ec = 0, oc = 0;
    while (num != 0) {
        rem = num % 10;
        if(rem % 2 == 0) 
            ec++;
        else
            oc++;
        num = num / 10;
    }
    printf("%d has %d even digits and %d odd digits", temp, ec, oc);
}