#include<stdio.h>
#include<stdlib.h>
#define SIZE 6

int cirqueue_full(int count);
void cirqueue_insert(int ele, int *r, int queue[], int *count);
int cirqueue_empty(int count);
int cirqueue_delete(int *f, int queue[], int *count);
void display(int f, int count, int queue[]);

int main() {
    int ch, ele, r = -1, f = 0, queue[SIZE], count = 0, del_ele;
    
    for(;;) {
        printf("Please enter 1:to insert 2:to delete 3:to display 4:to delete\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if(cirqueue_full(count)) {
                printf("Queue is full\n");
            } else {
                printf("Enter the element to be inserted\n");
                scanf("%d", &ele);
                cirqueue_insert(ele, &r, queue, &count);
            }
            break;

        case 2:
            if(cirqueue_empty(count)) {
                printf("Queue is empty\n");
            } else {
                del_ele = cirqueue_delete(&f, queue, &count);
                printf("The element deleted is %d\n", del_ele);
            }
            break;

        case 3:
            display(f, count, queue);
            break;

        case 4:
            exit(0);

        default:
            printf("Please enter a valid choice\n");
            break;
        }
    }
}

int cirqueue_full(int count) {
    if(count == SIZE)
        return 1;
    return 0;
}


void cirqueue_insert(int ele, int *r, int queue[], int *count) {
    *r = (*r + 1) % SIZE;
    queue[*r] = ele;
    *count = *count + 1;
}

int cirqueue_empty(int count) {
    if(count == 0) 
        return 1;
    return 0;
}

int cirqueue_delete(int *f, int queue[], int *count) {
    int del_ele = queue[*f];
    *f = (*f + 1) % SIZE;
    *count = *count - 1;
    return del_ele;
}

void display(int f, int count, int queue[]) {
    printf("Elements in queue are \n");
    for (int i = 0; i < count; i++) {
        printf("%d ", queue[f]);
        f = (f + 1) % SIZE;
    }
    printf("\n");
    
}