#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertNode(struct node** head, int value) {
    struct node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Function to join two linked lists
struct node* joinTwoLists(struct node* a, struct node* b) {
    if (a == NULL) return b;
    struct node* temp = a;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = b;
    return a;
}

// Function to perform the bin/bucket sort for a specific digit position
void binSort(int arr[], int n, int exp) {
    int range = 10; // Base 10 for digits
    struct node* bins[range];
    for (int i = 0; i < range; i++) {
        bins[i] = NULL;
    }
    
    // Place elements into bins based on the selected digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % range;
        insertNode(&bins[digit], arr[i]);
    }

    // Combine bins back into the array
    int index = 0;
    for (int i = 0; i < range; i++) {
        arr[index] = bins[i]->data; // Update the array with the elements in this bin
        struct node* current = bins[i];
        bins[i] = current->next; // Move to the next node in the bin
        free(current); // Free the memory for the node
        index++;
    }
}

// Function to perform radix sort
void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Find the maximum number of digits in the maximum value
    int exp = 1;
    while (max / exp > 0) {
        binSort(arr, n, exp);
        exp *= 10;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    radixSort(arr, n);
    
    printf("\nAfter sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    free(arr); // Don't forget to free the allocated memory
    return 0;
}
