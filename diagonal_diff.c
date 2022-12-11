#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define N 100
#define MAX_VALUE 100

void swap(int *a, int *b);
int read_matrix(int m[][N], int rows, int cols);
int diagonal_diff(int matrix[][N], int rows, int cols);

int main(int argc, char *argv[])
{
    int diff = 0, rows = 0, cols = 0; 
    int numbers[N][N] = {{0}};

    scanf("%d", &rows); cols = rows;
    read_matrix(numbers, rows, cols);
    diff = diagonal_diff(numbers, rows, cols);
	printf("%d\n", diff);

    return 0;
}

int diagonal_diff(int matrix[][N], int rows, int cols)
{
    int diff = 0, sum1 = 0, sum2 = 0;

    for(int i=0, j=cols-1; (i < rows) && (j >= 0); i++, j--) {
		sum1 += matrix[i][i];
		sum2 += matrix[i][j];
    }
	diff = sum1 - sum2;
    return abs(diff);
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

