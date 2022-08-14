#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

int queue_full(int r);
void queue_insert(int ele, int *r, int queue[]);
int queue_empty(int f, int r);
int queue_delete(int *f, int queue[]);
void display(int f, int r, int queue[]);

int main() {
    int queue[SIZE], ch, f = 0, r = -1, ele, del_ele;
    
    for(;;) {
        printf("Please enter 1:to insert 2:to delete 3:to display 4:to exit\n");
        scanf("%d",&ch);
        switch (ch) {
        case 1:
            if (queue_full(r)) {
                printf("Queue is full. You can't insert element into queue\n");
            } else {
                printf("Enter the element\n");
                scanf("%d",&ele);
                queue_insert(ele, &r, queue);
            }
            break;

        case 2:
            if (queue_empty(f,r)) {
                printf("Queue is empty\n");
            } else {
                del_ele = queue_delete(&f, queue);
                printf("The element deleted is %d\n",del_ele);
            }
            break;
        
        case 3:
            display(f, r, queue);
            break;
        
        case 4:
            exit(0);
        
        default:
            printf("Please enter a valid option\n");
            break;
        }
    }
}

int queue_full(int r) {
    if(r == (SIZE - 1)) {
        return 1;
    }
    return 0;
}
void queue_insert(int ele, int *r, int queue[]) {
    (*r)++;
    queue[*r] = ele;
    return;
}

int queue_empty(int f, int r) {
    if(f > r) {
        return 1;
    }
    return 0;
}

int queue_delete(int *f, int queue[]) {
    int del_ele = queue[*f];
    (*f)++;
    return del_ele;
}

void display(int f, int r, int queue[]) {
    printf("Elements in queue are\n");
    for (int i = f; i <= r; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
    
}