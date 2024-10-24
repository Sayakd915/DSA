#include <stdio.h>
#include <stdlib.h>

// Function to insert an element
void insert(int** arr, int* n) {
    int element, position;

    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert the element at (0-based index): ");
    scanf("%d", &position);

    if (position < 0 || position > *n) {
        printf("Invalid position!\n");
        return;
    }

    *arr = (int*)realloc(*arr, (*n + 1) * sizeof(int));
    for (int i = *n; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[position] = element;
    (*n)++;
}

// Function to delete an element
void delete(int** arr, int* n) {
    int position;

    printf("Enter the position of the element to delete (0-based index): ");
    scanf("%d", &position);

    if (position < 0 || position >= *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position; i < *n - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    *arr = (int*)realloc(*arr, (*n - 1) * sizeof(int));
    (*n)--;
}

// Function to perform linear search
void linear_search(int* arr, int n) {
    int key;

    printf("Enter the element to search for: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at index %d.\n", key, i);
            return;
        }
    }
    printf("Element %d not found.\n", key);
}

// Function to perform binary search
void binary_search(int* arr, int n) {
    int key, left = 0, right = n - 1, mid;

    printf("Enter the element to search for: ");
    scanf("%d", &key);

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            printf("Element %d found at index %d.\n", key, mid);
            return;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Element %d not found.\n", key);
}

// Function to sort the array in ascending order
void sort_ascending(int* arr, int n) {
    int temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

// Function to sort the array in descending order
void sort_descending(int* arr, int n) {
    int temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Array sorted in descending order.\n");
}

// Function to display the array
void display_array(int* arr, int n) {
    if (n == 0) {
        printf("The array is empty.\n");
        return;
    }

    printf("The array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int* arr;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));

    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int choice;
    do {
        printf("\nEnter the operation: \n");
        printf("1) Insertion\n");
        printf("2) Deletion\n");
        printf("3) Linear Search\n");
        printf("4) Binary Search\n");
        printf("5) Sort Ascending\n");
        printf("6) Sort Descending\n");
        printf("7) Display Array\n");
        printf("8) Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(&arr, &n);
                display_array(arr, n);
                break;
            case 2:
                delete(&arr, &n);
                display_array(arr, n);
                break;
            case 3:
                linear_search(arr, n);
                break;
            case 4:
                binary_search(arr, n);
                break;
            case 5:
                sort_ascending(arr, n);
                display_array(arr, n);
                break;
            case 6:
                sort_descending(arr, n);
                display_array(arr, n);
                break;
            case 7:
                display_array(arr, n);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 8);

    free(arr); // Free the allocated memory
    return 0;
}
