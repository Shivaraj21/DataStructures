#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void arr_insert(int new,int pos,int arr[],int *n);
void arr_delete(int pos, int arr[], int *n);
void display(int n, int arr[]);

int main() {
    int n, i, arr[10], choice, pos, new;

    printf("Enter no. of elements in array\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

	//forever loop
    for(;;) {
        printf("\nplease enter 1:to insert 2:to delete 3:to display 4:to exit\n");
        
        scanf("%d",&choice);
        switch (choice) {
        case 1:
            printf("Enter position to insert\n");
            scanf("%d",&pos);

            if (pos > 0 && pos <= (n + 1)) {
                printf("Insertion is possible\n");
                printf("Enter new element\n");
                scanf("%d",&new);
                arr_insert(new, pos, arr, &n);
            } else {
                printf("Insertion is not possible\n");
            }
            break;

        case 2:
            printf("Enter position to delete\n");
            scanf("%d",&pos);
            if (pos > 0 && pos <= n) {
                printf("Deletion is possible\n");
                arr_delete(pos, arr, &n);
            } else {
                printf("Deletion is not possible\n");
            }
            break;
        
        case 3:
            display(n, arr);
            break;
        
        case 4:
            exit(0);

        default: 
            printf("please enter a valid choice\n");
            break;
        }
    }
}

//function to insert element into position
void arr_insert(int new, int pos, int arr[], int *n) {
    int i;
	//shift all the element to the right
    for (i = (*n - 1); i > (pos - 1); i--) {
        arr[i + 1] = arr[i];
    }
	//insert element in that position
    arr[i + 1] = new;
	//update n
    (*n)++;
    printf("%d is inserted at position %d\n", new, pos);
    return;
}

//function to delete element in array
void arr_delete(int pos, int arr[], int *n) {
    int i;
	//display deleted element
	printf("element %d is deleted from position %d\n", arr[pos - 1], pos);
	// shift all the element to the left
    for (i = (pos - 1); i < (*n - 1); i++) {
        arr[i] = arr[i + 1];
    }
	//update n
    *n = *n - 1;
    return;
}

//function for displaying elements in arrays
void display(int n, int arr[]) {
    int i;
    printf("Elements in array are \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}