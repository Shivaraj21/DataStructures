#include<stdio.h>
#include<stdlib.h>

typedef struct BST {
    int data;
    struct BST *l_link;
    struct BST *r_link;
} NODE;

NODE *insert(int item, NODE *root);
void preorder(NODE *root);
void inorder(NODE *root);
void postorder(NODE *root);
NODE *delete(int item, NODE *root);
void search(int item, NODE *root);

int main() {
    NODE *root = NULL;
    int item, ch;
    for(;;) {
        printf("Enter 1:to-insert\n2:for-inorder-traversal\n3:for-preorder-traversal\n4:for-postorder-traversal\n5:search 6:to-exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Element to be inserted\n");
            scanf("%d", &item);
            root = insert(item, root);
            break;
        case 2:
            printf("Inorder traversal of the tree is \n");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder traversal of the tree is \n");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder traversal of the tree is \n");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter the key element\n");
            scanf("%d", &item);
            search(item, root);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice");
            break;
        }
    }
    return 0;
}

NODE *getnode() {
    NODE *temp = (NODE *) malloc(sizeof(NODE));
    if(temp == NULL) {
        printf("Memory not available\n");
        return NULL;
    }
    return temp;
}

NODE *insert(int item, NODE *root) {
    NODE *prev, *pres;
    NODE *new = getnode();
    new -> data = item;
    new -> l_link = NULL;
    new -> r_link = NULL;
    if(root == NULL) {
        return new;
    }
    prev = NULL;
    pres = root;
    while (pres != NULL) {
        prev = pres;
        if(new -> data < pres -> data) {
            pres = pres -> l_link;
        } else {
            pres = pres -> r_link;
        }
    }
    if(new -> data < prev -> data) {
        prev -> l_link = new;
    } else {
        prev -> r_link = new;
    }
    return root;    
}

void preorder(NODE* root) {
    if(root != NULL) {
    printf("%d ", root -> data);
    preorder(root -> l_link);
    preorder(root -> r_link);
    }
}

void inorder(NODE* root) {
    if(root != NULL) {
        inorder(root -> l_link);
        printf("%d ", root -> data);
        inorder(root -> r_link);
    }
}

void postorder(NODE* root) {
    if(root != NULL) {
        postorder(root -> l_link);
        postorder(root -> r_link);
        printf("%d ", root -> data);
    }
}

void search(int item, NODE *root) {
    if(root == NULL) {
        printf("%d not present in the tree!!\n", item);
        return;
    } else if(root -> data == item) {
        printf("Element %d is present in the tree\n", item);
        return;
    } else if (root -> data > item) {
        search(item , root-> l_link);
    } else {
        search(item, root -> r_link);
    }
    
}