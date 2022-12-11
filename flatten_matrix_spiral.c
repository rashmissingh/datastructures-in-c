#include <stdio.h>

#define T 70
#define N 10
#define MAX_VALUE 100

void swap(int *a, int *b);
int read_matrix(int m[][N], int rows, int cols);
int print_matrix(int m[][N], int rows, int cols);
int flatten_matrix(int m[][N], int rows, int cols, int *arr);
int print_array(int *r, int size);

int main(int argc, char *argv[])
{
    int i = 0, rows = 0, cols = 0, test_count = 0; 
    int numbers[N][N] = {{0}};
    int arr[N*N] = {0};

    scanf("%d", &test_count);
   if (test_count > T) {
        printf("Executing first %d tests\n", T);
        test_count = T;
    }
    
    for (i = 0; i < test_count; i++) {
        scanf("%d", &rows); 
        cols = rows;
        read_matrix(numbers, rows, cols);
        flatten_matrix(numbers, rows, cols, arr);
        print_array(arr, rows*cols);
    }

    return 0;
}

int flatten_matrix(int matrix[][N], int rows, int cols, int *arr)
{
    int i = 0, j = 0, k = 0;
    int c = 0; 

    for(i=0; i < rows/2 + rows%2; i++) {
        for(j=i; j < cols-i; j++) {
            arr[c++] = matrix[i][j];
        }
        j--;
        for(k=i+1;k<rows-i;k++) {
            arr[c++] = matrix[k][j];
        }
        k--;
        for(j=j-1;j>=0+i;j--) {
            arr[c++] = matrix[k][j];
        }
        j++;
        for(k=k-1;k>i;k--) {
            arr[c++] = matrix[k][j];
        }
    }
    return 0;
}

int read_matrix(int m[][N], int rows, int cols)
{
    int i = 0, j = 0;
    
    if ((rows > N) || (cols > N)) {
        printf("Insufficient space for input numbers.\n");
        return 1;
    }

    for(i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    return 0;
}

int print_matrix(int m[][N], int rows, int cols)
{
    int i = 0, j = 0;

    if ((rows > N) || (cols > N)) {
        rows = N;
        cols = N;
        printf("Array size larger than allocated space.  Printing first %d numbers.\n", N);
    }

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", m[i][j]);
        }
    }
    printf("\n");

    return 0;
}

int print_array(int *r, int size)
{
    int i = 0;

    for(i = 0; i < size; i++)
    {
        printf("%d ", r[i]);
    }
    printf("\n");

    return 0;
}


