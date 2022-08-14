#include<stdio.h>
#include<stdlib.h>

typedef struct  LIST {
    int data;
    struct LIST *link;
} NODE;

NODE *get_node();
NODE *insert_front(int item, NODE *front);
NODE *insert_rear(int item, NODE *front);
NODE *delete_front(NODE *first);
NODE *delete_rear(NODE *first);
void display(NODE *first);

int main() {
    int ch, item;
    NODE *first = NULL;
    for(;;) {
        printf("Enter 1:to insert-front 2:to insert-rear 3:to delete-front 4:to delete-rear  5:to display 6:to exit\n");
        scanf("%d", &ch);
        
        switch (ch) {
        case 1:
            printf("Enter data\n");
            scanf("%d",&item);
            first = insert_front(item, first);
            break;

        case 2:
            printf("Enter data\n");
            scanf("%d",&item);
            first = insert_rear(item, first);
            break;

        case 3:
            first = delete_front(first);
            break;
        
        case 4:
            first = delete_rear(first);
            break;

        case 5:
            if (first == NULL) {
                printf("Linked List is empty\n");
            } else {
            printf("Contents of list are:\n");
            display(first);
            }
            break;

        case 6:
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

NODE *insert_front(int item, NODE *first) {
    NODE *new = get_node();
    if (first == NULL){
        new ->data = item;
        new -> link = NULL;
        return new;
    }
    new -> data = item;
    new -> link = first;
    return new;
}

NODE *insert_rear(int item, NODE *first) {
    NODE *new = get_node();
    new -> data = item;
    new -> link = NULL;

    if (first == NULL)
    {
        return new;
    }
    if (first -> link == NULL) {
        first -> link = new;
        return first;
    } else {
         NODE *temp = first;
         while (temp -> link != NULL) {
            temp = (temp -> link);
         }
         temp -> link = new;
         return first;
    }
}

NODE *delete_front(NODE *first) {
    NODE *temp;
    if (first == NULL) {
        printf("List is Empty\n");
        return NULL;
    }
    temp = first;
    first = first -> link;
    printf("The deleted node is %d\n", temp -> data);
    free(temp);
    return first;
}

NODE *delete_rear(NODE *first) {
    NODE *pres, *prev;
    if (first == NULL) {
        printf("List is Empty\n");
        return NULL;
    }
    if (first -> link == NULL) {
        printf("The deleted node is %d\n",first ->data);
        free(first);
        return NULL;
    }
    prev = NULL;
    pres = first;
    while (pres -> link != NULL) {
        prev = pres;
        pres = pres -> link;
    }
    printf("The deleted node is %d\n", pres -> data);
    free(pres);
    prev -> link = NULL;
    return first;
}

void display(NODE *first) {
         NODE *temp = first;
         while (temp != NULL) {
            printf("%d ", temp -> data);
            temp = (temp -> link);
         }
         printf("\n");
}