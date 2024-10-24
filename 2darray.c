#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, columns;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    // Allocate memory for an array of pointers to rows
    int** array = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        // Allocate memory for each row
        array[i] = (int*)malloc(columns * sizeof(int));
    }

    // Fill the array with values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = i * columns + j;
        }
    }

    // Print the array
    printf("2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");  // Move to the next line after printing each row
    }

    // Free the memory
    for (int i = 0; i < rows; i++) {
        free(array[i]);  // Free each row's memory
    }
    free(array);  // Free the array of pointers

    return 0;
}
