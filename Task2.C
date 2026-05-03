#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    printf("Enter elements:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Matrix Addition
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Matrix Multiplication
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    int i, j, k;
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Matrix Transpose
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX], transpose[MAX][MAX];
    int r1, c1, r2, c2, choice;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);
    inputMatrix(A, r1, c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);
    inputMatrix(B, r2, c2);

    printf("\nChoose operation:\n");
    printf("1. Addition\n2. Multiplication\n3. Transpose (Matrix A)\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if(r1 == r2 && c1 == c2) {
                addMatrix(A, B, result, r1, c1);
                printf("\nResult of Addition:\n");
                displayMatrix(result, r1, c1);
            } else {
                printf("Addition not possible!\n");
            }
            break;

        case 2:
            if(c1 == r2) {
                multiplyMatrix(A, B, result, r1, c1, c2);
                printf("\nResult of Multiplication:\n");
                displayMatrix(result, r1, c2);
            } else {
                printf("Multiplication not possible!\n");
            }
            break;

        case 3:
            transposeMatrix(A, transpose, r1, c1);
            printf("\nTranspose of Matrix A:\n");
            displayMatrix(transpose, c1, r1);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}