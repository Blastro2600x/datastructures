#include <stdio.h>

// Function to display the array
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function for linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

// Function to insert an element at a specified position
void insertElement(int arr[], int *size, int position, int element) {
    if (position < 0 || position > *size) {
        printf("Invalid position for insertion.\n");
        return;
    }

    // Shift elements to make space for the new element
    for (int i = *size - 1; i >= position; --i) {
        arr[i + 1] = arr[i];
    }

    // Insert the new element
    arr[position] = element;

    // Increase the size of the array
    (*size)++;
}

// Function to delete an element from a specified position
void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position for deletion.\n");
        return;
    }

    // Shift elements to fill the gap left by the deleted element
    for (int i = position; i < *size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    // Decrease the size of the array
    (*size)--;
}

// Function to reverse the array
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // Swap elements at start and end positions
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move towards the center of the array
        start++;
        end--;
    }
}

// Function to update the array
void updateArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            // Even index: add 5 to the element
            arr[i] += 5;
        } else {
            // Odd index: multiply by 2
            arr[i] *= 2;
        }
    }
}

int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Declare an array of the given size
    int myArray[size];

    // Take input for each element of the array
    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; ++i) {
        printf("Element %d: ", i + 1);
        scanf("%d", &myArray[i]);
    }

    int choice, key, position, element;

    do {
        // Display menu
        printf("\nMENU:\n");
        printf("1. Linear search for an element\n");
        printf("2. Insert an element at specified position\n");
        printf("3. Delete an element from specified position\n");
        printf("4. Reverse the array\n");
        printf("5. Update the array\n");
        printf("6. Display the array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Linear search
                printf("Enter the element to search: ");
                scanf("%d", &key);
                int result = linearSearch(myArray, size, key);
                if (result != -1) {
                    printf("Element %d found at index %d.\n", key, result);
                } else {
                    printf("Element %d not found in the array.\n", key);
                }
                break;

            case 2:
                // Insert element at specified position
                printf("Enter the position for insertion: ");
                scanf("%d", &position);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(myArray, &size, position, element);
                displayArray(myArray, size);
                break;

            case 3:
                // Delete element from specified position
                printf("Enter the position for deletion: ");
                scanf("%d", &position);
                deleteElement(myArray, &size, position);
                displayArray(myArray, size);
                break;

            case 4:
                // Reverse the array
                reverseArray(myArray, size);
                displayArray(myArray, size);
                break;

            case 5:
                // Update the array
                updateArray(myArray, size);
                displayArray(myArray, size);
                break;

            case 6:
                // Display the array
                displayArray(myArray, size);
                break;

            case 0:
                // Exit
                printf("Exiting the program.\n");
                break;

            default:
                // Invalid choice
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
