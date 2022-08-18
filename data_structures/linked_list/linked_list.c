#include<stdio.h>
#include<stdlib.h>

// Create a node
typedef struct  LIST {
    int data;
    struct LIST *link;
} NODE;

//Declaration of all functions
NODE *get_node();
NODE *insert_front(int item, NODE *front);
NODE *insert_rear(int item, NODE *front);
NODE *delete_front(NODE *first);
NODE *delete_rear(NODE *first);
void display(NODE *first);
void search(int key, NODE *front);

int main() {
    int ch, item;
    //initial first node as null
    NODE *first = NULL;
    for(;;) {
        printf("Enter 1:to insert-front 2:to insert-rear 3:to delete-front 4:to delete-rear  5:to display 6:to exit 7: to-search\n");
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
        
        case 7:
            printf("Enter the key element\n");
            scanf("%d", &item);
            search(item, first);
            break;
            
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}

// function for dynamic memory allocation of node
NODE *get_node() {
    NODE *temp = (NODE *) malloc(sizeof(NODE));
    if (temp == NULL) {
        printf("Memory is not available\n");
    }
    return temp;
}

//insert front operation
NODE *insert_front(int item, NODE *first) {
    //create a new node
    NODE *new = get_node();
    //if list is empty
    // new node is a first element
    if (first == NULL){
        new ->data = item;
        new -> link = NULL;
        return new;
    }
    // if list is not empty then
    // put a data into new node
    // link of new node is given to first node
    // make the new node as a first node
    new -> data = item;
    new -> link = first;
    return new;
}

NODE *insert_rear(int item, NODE *first) {
    NODE *new = get_node();
    // create a new node
    // insert data into the new node
    // make the link of the new node as null because it is a last element
    new -> data = item;
    new -> link = NULL;
    
    // if link is empty
    //new node is a last element
    if (first == NULL)
    {
        return new;
    }
    // if there is only one element
    // it is a second element
    // link of first element is given to second element
    if (first -> link == NULL) {
        first -> link = new;
        return first;
    } else {
        // if there are more than one element
        // create temperary node that traverse to the last element
        // link of last element is given to new element 
        // now assign new node to last element because last element is a new element
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
    // if linked is empty
    // no element can be deleted
    if (first == NULL) {
        printf("List is Empty\n");
        return NULL;
    }
    // if link is not empty
    // create a temperary element to store first element
    // make second element as first element
    // free the temp
    temp = first;
    first = first -> link;
    printf("The deleted node is %d\n", temp -> data);
    free(temp);
    return first;
}

NODE *delete_rear(NODE *first) {
    NODE *pres, *prev;
    // if the list is empty
    // then there is no node to delete
    if (first == NULL) {
        printf("List is Empty\n");
        return NULL;
    }
    // if there is only first element
    // delete first node
    // assign first node as null
    if (first -> link == NULL) {
        printf("The deleted node is %d\n",first ->data);
        free(first);
        return NULL;
    }
    //if there is more than one element
    //create a variable that traverse to the last node(pres)
    // create a another node that traverse to the node before the last element
    //free the last node
    // make the node before the last node as a last element
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

void search(int key, NODE *first) {
    NODE *temp = first;
    while(temp != NULL) {
        if(temp -> data = key) {
            printf("Element found\n");
            return;
        }
        temp = temp -> link;
    }
    printf("Element not found\n");
    return;
}
