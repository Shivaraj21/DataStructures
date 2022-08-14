#include<stdio.h>

int main() 
{
    int score[10], i, sum = 0;
    float avg;
    
    printf("Enter the score \n");
    for (i = 0; i < 10; i++)
        scanf("%d",&score[i]);

    printf("The scores are \n");
    for (i = 0; i < 10; i++)
        printf("%d ",score[i]);
    
    for (i = 0; i < 10; i++)
        sum = sum + score[i];
    
    avg = sum/10;
    printf("\nThe sum is %d and the average is %d",sum, avg);
    
}