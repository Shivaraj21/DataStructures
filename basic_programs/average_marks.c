#include<stdio.h>
int main() {
    char USN[10],name[20];
    int sem,test_marks1,test_marks_2,test_marks_3,quiz_marks_4,quiz_marks_5,assign_marks1,assign_marks2;
    float avgMarks,tAvg,qAvg,assignAvg;

    printf("Enter the USN and Name\n");
    scanf("%s %s",USN,name);
    printf("Enter the semester\n");
    scanf("%d",&sem);
    printf("Enter 3 Test Marks\n");
    scanf("%d %d %d",&test_marks1,&test_marks_2,&test_marks_3);
    printf("Enter 2 Quiz Marks\n");
    scanf("%d %d",&quiz_marks_4,&quiz_marks_5);
    printf("Enter 2 Assignment Marks\n");
    scanf("%d %d",&assign_marks1,&assign_marks2);

    tAvg = (test_marks1 + test_marks_2 + test_marks_3 )/5;
    qAvg = (quiz_marks_4 + quiz_marks_5)/5;
    assignAvg = (assign_marks1 + assign_marks2)/3.33;
    avgMarks = tAvg + qAvg + assignAvg;
    printf("The final average for %s is %f",name,avgMarks);
}