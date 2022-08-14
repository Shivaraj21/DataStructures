#include<stdio.h>
#include<stdlib.h>

// Doubly linked list implementation
typedef struct list {
    int data;
    struct list *next;
    struct  list *prev;   
} NODE;

//declaration of first node and last node
NODE *first = NULL;
NODE *last = NULL;

//declaration of all the functions
NODE *get_node();
void insert_front(int item);
void insert_rear(int item);
void delete_front();
void delete_rear();
void display();

int main() {
    int ch, item;
    for(;;) {
        printf("Enter 1:to-insert-front\n2:to-insert-rear\n3:to-delete-front\n4:to-delete-rear\n5-to-display\n6-to-exit\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insert_front(item);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insert_rear(item);
                break;
            case 3:
                delete_front();
                break;
            case 4:
                delete_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}

NODE *get_node() {
    NODE *temp = (NODE *) malloc(sizeof(NODE));
    if(temp == NULL) {
        printf("Memory is not available");
    }
    return temp;
}

void insert_front(int item) {
    NODE *new = get_node();
    new -> data = item;
    new -> prev = NULL;
    if(first == NULL) {
        new -> next = NULL;
        first = new;
        last = new;
        return;
    }
    new -> next = first;
    first -> prev = new;
    first = new;
    return;
}

void insert_rear(int item) {
    NODE *new = get_node();
    new -> data = item;
    new -> next = NULL;
    if(first == NULL) {
        new -> next = NULL;
        first = new;
        last = new;
        return;
    }
    new -> prev = last;
    last -> next = new;
    last = new;
    return;
}

void delete_front() {
    if(first == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE *temp = first;
    printf("deleted element is %d\n", first -> data);
    if(first -> next == NULL) {
        printf("deleted element is %d\n", first -> data);
        first = NULL;
        last = NULL;
        free(temp);
        return;
    }
    first = first -> next;
    first -> prev = NULL;
    free(temp);
    return;
}

void delete_rear() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE *temp = last;
    if(first -> next == NULL) {
        printf("deleted element is %d\n", last -> data);
        first = NULL;
        last = NULL;
        free(temp);
        return;
    }
    printf("deleted element is %d\n", last -> data);
    last = last -> prev;
    last -> next = NULL;
    free(temp);
    return;    
}

void display() {
    if(first == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE *temp = first;
    printf("The element of list are:\n");
    while (temp!= NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
    
}