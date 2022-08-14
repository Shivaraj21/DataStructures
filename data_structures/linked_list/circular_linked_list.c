#include<stdio.h>
#include<stdlib.h>

typedef struct LIST {
    int data;
    struct LIST *link;
} NODE;
NODE *insert_front(int item, NODE *last);
NODE *insert_rear(int item, NODE *last);
NODE *get_node();
NODE *delete_front(NODE *last);
NODE *delete_rear(NODE *last);
void display(NODE *last);

int main() {
    int ch, item;
    NODE *last = NULL;
    for (;;) {
        printf("Enter to 1:insert-front 2:insert-rear 3:delete-front 4:delete-rare 5:display 6:to exit\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter the data\n");
            scanf("%d", &item);
            last = insert_front(item, last);
            break;

        case 2:
            printf("Enter the data\n");
            scanf("%d", &item);
            last = insert_rear(item, last);
            break;
        
        case 3:
            last = delete_front(last);
            break;

        case 4:
            last = delete_rear(last);
            break;

        case 5:
            display(last);
            break;

        case 6:
            exit(0);
        
        default:
            printf("Enter a valid choice\n");
            break;
        }
    }
    return 0;
}

NODE *get_node() {
    NODE *temp = (NODE *) malloc(sizeof(NODE));
    if(temp == NULL) {
    printf("Memory is not available\n");
    }
    return temp;
}
    
NODE *insert_front(int item, NODE *last) {
    NODE *new = get_node();
    new -> data = item;
    if(last == NULL) {
        new -> link = new;
        return new;
    }
    new -> link = last -> link;
    last -> link = new;
    return last;
}

NODE *delete_front(NODE *last) {
    NODE *temp;
    if(last == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if(last -> link == last) {
        printf("Deleted node is %d\n",last -> data);
        free(last);
        return NULL;
    }
    temp = last -> link;
    printf("Deleted node is %d\n", temp -> data);
    last -> link = temp -> link;
    free(temp);
    return last;
}

NODE *delete_rear(NODE *last) {
    if(last == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if(last -> link == last) {
        printf("Deleted node is %d\n",last -> data);
        free(last);
        return NULL;
    }
    NODE *temp = last -> link;
    while (temp -> link != last)  {
        temp = temp -> link;
    }
    printf("Deleted node is %d\n", last -> data);
    temp -> link = last -> link;
    free(last);
    return temp;
}

NODE *insert_rear(int item, NODE *last) {
    NODE *new = get_node();
    new -> data = item;
    if(last == NULL) {
        new -> link = new;
        return new;
    }
    new -> link = last -> link;
    last -> link = new;
    return new;
}

void display(NODE *last) {
    if (last == NULL) {
        printf("List is empty\n");
    }
    else {
        NODE *first;
        first = last -> link;
        printf("Contents of Linked list are\n");
        while (first != last) {
            printf("%d ", first -> data);
            first = first -> link;
        }
        printf("%d\n", first -> data);
    }    
}
