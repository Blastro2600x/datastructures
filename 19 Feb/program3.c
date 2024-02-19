#include <stdio.h>

// Function to perform binary search iteratively
int binarySearchIterative(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid; // Element found, return its index
        else if (arr[mid] < key)
            low = mid + 1; // Search in the right half
        else
            high = mid - 1; // Search in the left half
    }

    return -1; // Element not found
}

int main() {
    int size, key;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Declare and input elements in a sorted array
    int myArray[size];
    printf("Enter %d sorted elements for the array:\n", size);
    for (int i = 0; i < size; ++i) {
        printf("Element %d: ", i + 1);
        scanf("%d", &myArray[i]);
    }

    // Get the key to search from the user
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform binary search iteratively
    int result = binarySearchIterative(myArray, size, key);

    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}


// 3B

#include <stdio.h>

// Function to perform binary search recursively
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid; // Element found, return its index
        else if (arr[mid] < key)
            return binarySearchRecursive(arr, mid + 1, high, key); // Search in the right half
        else
            return binarySearchRecursive(arr, low, mid - 1, key); // Search in the left half
    }

    return -1; // Element not found
}

int main() {
    int size, key;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Declare and input elements in a sorted array
    int myArray[size];
    printf("Enter %d sorted elements for the array:\n", size);
    for (int i = 0; i < size; ++i) {
        printf("Element %d: ", i + 1);
        scanf("%d", &myArray[i]);
    }

    // Get the key to search from the user
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform binary search recursively
    int result = binarySearchRecursive(myArray, 0, size - 1, key);

    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}
