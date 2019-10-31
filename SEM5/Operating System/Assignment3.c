#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int i, j, k;

int matrix_1[10][10];
int matrix_2[10][10];
int matrix_3[10][10];

int row_1, row_2;
int col_1, col_2;

void *on_multiply(void *var)
{
    int result = matrix_1[i][k] + matrix_2[k][j];
    pthread_exit((void*) result);
}

void read_matrix(int matrix[10][10], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++) 
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void show_matrix(int matrix[10][10], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++) 
    {
        printf("\n");
        for (j = 0; j < col; j++)
        {
            printf("\t%d", matrix[i][j]);
        }
    }
}

int main()
{
    pthread_t thread_id[20];
    int result;

    // Read Matrix 1
    printf("\nEnter the information of Matrix 1 - ");
    printf("\nROW Count : ");
    scanf("%d", &row_1);
    printf("COLUMN Count : ");
    scanf("%d", &col_1);
    printf("\n\nEnter the Elements of Matrix 1: ");
    read_matrix(matrix_1, row_1, col_1);

    // Read Matrix 2
    printf("\n\nEnter the information of Matrix 2 - ");
    printf("\nROW Count : ");
    scanf("%d", &row_2);
    printf("COLUMN Count : ");
    scanf("%d", &col_2);
    printf("\n\nEnter the Elements of Matrix 2: ");
    read_matrix(matrix_2, row_2, col_2);

    // Do Multiply Matrices
    for (i = 0; i < row_1; i++)
    {
        for (j = 0; j < col_2; j++)
        {
            matrix_3[i][j] = 0;
            for (k = 0; k < col_1; k++)
            {
                // Create thread
                pthread_create(&thread_id[k], NULL, on_multiply, NULL);

                // Store evaluation in result field.
                pthread_join(thread_id[k], (void*)&result);
                matrix_3[i][j] = matrix_3[i][j] + result;
            } // END Inner For Loop 3
        } // END Inner For Loop 2
    } // End Outer For Loop 1

    // Display the Resultant Matrix
    printf("\nMatrix Multiplication:");
    show_matrix(matrix_3, row_1, col_2);
}
