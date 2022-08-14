#include<stdio.h>
#include<string.h>
#define SIZE 20

struct MOM {
    char name[20];
    int age;
    float s_rate;
    float p_money;
};


int main() {
    int n, i;
    struct MOM pl[SIZE];
    printf("Enter no. of players\n");
    scanf("%d",&n);
    printf("Enter the values in format\n name age s_rate p_money\n");
    for(i = 0; i < n; i++) {
        scanf("%s%d%f%f",pl[i].name,&pl[i].age,&pl[i].s_rate,&pl[i].p_money);
    }    
    for(i = 0; i < n; i++) {
        printf("Name: %s\n Age: %d\n Strike Rate: %f\n Prize Money: %f\n",pl[i].name,pl[i].age,pl[i].s_rate,pl[i].p_money);
    }    
}