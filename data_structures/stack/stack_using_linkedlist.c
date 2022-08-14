//Stack using Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack *link;
} NODE;

NODE *get_node();
NODE *push(int item, NODE *top);
NODE *pop(NODE *top);
void display(NODE *top);

int main() {
    int ch, item;
    NODE *top = NULL;
    for(;;) {
        printf("Enter 1:to-push 2:to-pop 3:to display 4:to exit\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter data\n");
            scanf("%d",&item);
            top = push(item, top);
            break;

        case 2:
            top = pop(top);
            break;
        
        case 3:
            display(top);
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

NODE *push(int item, NODE *top) {
    NODE *new = get_node();
    new -> data = item;
    new -> link = NULL;

    if (top == NULL)
    {
        return new;
    }
    if (top -> link == NULL) {
        top -> link = new;
        return top;
    } else {
         NODE *temp = top;
         while (temp -> link != NULL) {
            temp = (temp -> link);
         }
         temp -> link = new;
         return top;
    }
}

NODE *pop(NODE *top) {
    NODE *pres, *prev;
    if (top == NULL) {
        printf("stack is Empty\n");
        return NULL;
    }
    if (top -> link == NULL) {
        printf("popped element is %d\n",top ->data);
        free(top);
        return NULL;
    }
    prev = NULL;
    pres = top;
    while (pres -> link != NULL) {
        prev = pres;
        pres = pres -> link;
    }
    printf("The deleted node is %d\n", pres -> data);
    free(pres);
    prev -> link = NULL;
    return top;
}

void display(NODE *first) {
         NODE *temp = first;
         while (temp != NULL) {
            printf("%d ", temp -> data);
            temp = (temp -> link);
         }
         printf("\n");
}