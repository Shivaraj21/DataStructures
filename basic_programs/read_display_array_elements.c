#include<stdio.h>

int main() 
{
    int score[10],i;

    printf("Enter the score \n");
    for (i = 0; i < 10; i++)
        scanf("%d",&score[i]);

    printf("The scores are \n");
    for (i = 0; i < 10; i++)
        printf("%d ",score[i]);
}