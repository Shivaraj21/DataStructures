//Stack using Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int data;
    struct queue *link;
} NODE;

NODE *get_node();
void queue_insert(int item);
void queue_delete();
void display();

 NODE *front = NULL;
 NODE *rear = NULL;

int main() {
    int ch, item;
    for(;;) {
        printf("Enter 1:to-insert 2:to-delete 3:to display 4:to exit\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter data\n");
            scanf("%d",&item);
            queue_insert(item);
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
    return 0;
}

NODE *get_node() {
    NODE *temp = (NODE *) malloc(sizeof(NODE));
    if (temp == NULL) {
        printf("Memory is not available\n");
    }
    return temp;
}

void queue_insert(int item) {
    NODE *new = get_node();
    new -> data = item;
    new -> link = NULL;
    if(front == NULL) {
        front = new;
        rear = new;
        return;
    }
    rear -> link = new;
    rear = new;
    return;    
}

void queue_delete() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("deleted element is %d\n", front -> data);
    NODE *temp = front;
    front = front -> link;
    free(temp);
    return;
}

void display() {
         NODE *temp = front;
         printf("Elements of queue are\n");
         while (temp != NULL) {
            printf("%d ", temp -> data);
            temp = (temp -> link);
         }
         printf("\n");
}