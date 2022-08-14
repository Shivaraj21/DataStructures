#include<stdio.h>
#include<stdlib.h>

typedef struct priorityQueue {
    int data;
    int priority;
    struct priorityQueue *link;    
} NODE;

NODE *front = NULL;

NODE *get_node();
void queue_insert(int item, int priority);
void queue_delete();
void display();

int main() {
    int ch, item, priority;
    for(;;) {
        printf("Enter the 1:to-insert 2:to-delete 3:to-display 4:to-exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            printf("Enter the priority of element: ");
            scanf("%d", &priority);
            queue_insert(item, priority);
            break;

        case 2:
            queue_delete();
            break;
        
        case 3:
            display();
            break;
        
        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

NODE *get_node() {
    NODE *temp = (NODE *) malloc(sizeof(NODE));
    if(temp == NULL) {
        printf("Memory is not available\n");
    }
    return temp;
}

void queue_insert(int item, int priority) {
    NODE *new = get_node();
    new -> data = item;
    new -> priority = priority;
    // if the first element is null, insert element in front
    // if priority of new element is less than first element, insert in front
    if(front == NULL || new -> priority < front -> priority) {
        new -> link = front;
        front = new;
        return;
    }
    NODE *temp;
    temp = front;
    while(temp -> link!= NULL && ((temp -> link) -> priority) <= (new -> priority)) {
        temp = temp -> link;
    }
    new -> link = temp -> link;
    temp -> link = new;
    return;
}

void queue_delete() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    NODE *temp = front;
    printf("deleted element is %d\n", front -> data);
    front = front -> link;
    free(temp);
    return;
}

void display() {
         NODE *temp = front;
         printf("Elements\tPriority\n");
         while (temp != NULL) {
            printf("%d\t\t%d\n", temp -> data, temp -> priority);
            temp = (temp -> link);
         }
         printf("\n");
}