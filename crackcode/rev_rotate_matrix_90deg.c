#include <stdio.h>

#define T 50
#define N 100
#define MAX_VALUE 100

void swap(int *a, int *b);
int read_matrix(int m[][N], int rows, int cols);
int print_matrix(int m[][N], int rows, int cols);
int rotate_matrix(int m[][N], int rows, int cols);

int main(int argc, char *argv[])
{
    int i = 0, rows = 0, cols = 0, test_count = 0; 
    int numbers[N][N] = {{0}};

    scanf("%d", &test_count);
    if (test_count > T) {
        printf("Executing first %d tests\n", T);
        test_count = T;
    }
    
    for (i = 0; i < test_count; i++) {
        scanf("%d", &rows); scanf("%d", &cols);
        read_matrix(numbers, rows, cols);
        rotate_matrix(numbers, rows, cols);
        print_matrix(numbers, rows, cols);
    }

    return 0;
}

int rotate_matrix(int m[][N], int rows, int cols)
{
    int i = 0, j = 0;
    int temp;

    for(i=0; i < rows/2; i++) {
        for(j=i; j < cols-1-i; j++) {
            temp = m[i][j];
            m[i][j] = m[rows-1-j][i];
            m[rows-1-j][i] = m[rows-1-i][cols-1-j];
            m[rows-1-i][cols-1-j] = m[j][cols-1-i];
            m[j][cols-1-i] = temp;
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
        printf("\n");
    }
    printf("\n");

    return 0;
}


