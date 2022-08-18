#include<stdio.h>
#include<stdlib.h>

typedef struct binary_tree {
    int data;
    struct binary_tree *l_link;
    struct binary_tree *r_link;
} NODE;

NODE *get_node();
NODE *insert(int item, NODE *root);
void display(NODE *root);
int count = 1;

int main() {
    NODE *root = NULL;
    int ch, item;
    for(;;) {
        printf("Enter 1:to-insert 2:to-display 3:to-exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to insert\n");
            scanf("%d", &item);
            root = insert(item, root);
            break;
        case 2:
            printf("Elements of tree are \n");
            display(root);
            break;
        case 3:
            exit(0);        
        default:
            break;
        }
    }
    return 0;
}

NODE *get_node() {
    NODE *temp = (NODE *) malloc(sizeof(NODE));
    if(temp == NULL) {
        printf("Memory not available\n");
        return NULL;
    }
    return temp;
}

NODE *insert(int item, NODE *root) {
    if(root == NULL) {
        root = get_node();
        root -> l_link = root -> r_link = NULL;
        root -> data = item;
        count++;
    } else {
        if(count % 2 == 0) {
            root -> l_link = insert(item, root -> l_link);
        } else {
            root -> r_link = insert(item, root -> r_link);
        }
    }
    return root;
}

void display(NODE *root) {
    if(root -> l_link != NULL) {
        display(root -> l_link);
    }
    printf("%d ", root -> data);
    if(root -> r_link != NULL) {
        display(root -> r_link);
    }

}