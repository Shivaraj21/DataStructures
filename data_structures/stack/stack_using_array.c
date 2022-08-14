#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

int stack_full(int top);
int stack_empty(int top);
void push(int ele, int *top, int stack[]);
int pop(int *top, int stack[]);
void display(int top, int stack[]);

int main() {
    int stack[SIZE], ch, top = -1, ele, del_ele;
    for(;;) {
        printf("Please enter 1:to push 2:to pop 3:to display 4:to exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (stack_full(top))
            {
                printf("Stack is full\n");
            } else {
                printf("Enter the element\n");
                scanf("%d",&ele);
                push(ele, &top, stack);
            }
            break;

        case 2:
            if(stack_empty(top)) {
                printf("Stack is empty\n");
            } else {
                del_ele = pop(&top, stack);
                printf("Popped element is %d\n",del_ele);
            }
            break;

        case 3:
            display(top, stack);
            break;

        case 4:
            exit(0);
        
        default:
            printf("Please input a valid choice\n");
            break;
        }

    }
}

//function to check whether stack is full
int stack_full(int top) {
    if(top == (SIZE - 1)) {
        return 1;
    }
    return 0;
}

// function to check whether stack empty
int stack_empty(int top) {
    if(top == -1) {
        return 1;
    }
    return 0;
}

//function to push an element into the stack
void push(int ele, int *top, int stack[]) {
    (*top)++;
    stack[*top] = ele;
    return;
}

//function to pop an element from the stack
int pop(int *top, int stack[]) {
    int del_ele;
    del_ele = stack[*top];
    (*top)--;
    return del_ele;
}

//function to display all the element in stack
void display(int top, int stack[]) {
    int i;
    printf("Elements in stack are: \n");
    for (i = 0; i <= top; i++) {
        printf("%d ",stack[i]);
    }
    printf("\n");
}