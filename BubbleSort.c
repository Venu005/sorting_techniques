#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped; // A flag to track whether any swaps were made in a pass
    
    // Loop through the array
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // No swaps made yet in this pass
        
        // Compare adjacent elements and swap if necessary
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Indicate a swap was made in this pass
            }
        }

        // If no swaps were made in the inner loop, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int n, i;
    
    printf("Please enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Great! Now, kindly enter the %d elements of the array, one by one:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bubbleSort(arr, n);  // Call the bubble sort function
    
    printf("\nSorting in progress...\n\n");
    
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
