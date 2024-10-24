#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, columns;


    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    
    int** A = (int**)malloc(rows * sizeof(int*));
    int** B = (int**)malloc(rows * sizeof(int*));
    int** C = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        A[i] = (int*)malloc(columns * sizeof(int));
        B[i] = (int*)malloc(columns * sizeof(int));
        C[i] = (int*)malloc(columns * sizeof(int));
    }

    
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("Resultant matrix C after addition:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
