#include<stdio.h>

int main() {
    int price, count = 0, total = 0, final_price;
    char ch = 'y';
    while(ch == 'y') {
        printf("Enter the price of item \n");
        scanf("%d",&price);
        count++;
        total = total + price;
        printf("Wanna buy more. Type y for yes, n for no: ");
        scanf(" %c",&ch);
    }

    if(count >= 5 || total >= 5000) {
        final_price = total*0.8;
    } else {
        final_price = total;
    }
    
    printf("Thank you for Shopping");
    printf("\nplease pay %d", final_price);
    return 0;
}