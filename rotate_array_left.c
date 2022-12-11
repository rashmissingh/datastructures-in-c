#include <stdio.h>

#define T 50
#define N 100
#define MAX_VALUE 100

int read_array(int *r, int count);
int print_array(int *r, int size);
int rotate_array(int *a, int size, int shift);

int main(int argc, char *argv[])
{
    int i = 0, shift = 0, size = 0, test_count = 0; 
    int numbers[N] = {0};

    scanf("%d", &test_count);
    if (test_count > T) {
        printf("Executing first %d tests\n", T);
        test_count = T;
    }
    
    for (i = 0; i < test_count; i++) {
        scanf("%d", &size); scanf("%d", &shift);
        read_array(numbers, size);
        rotate_array(numbers, size, shift);
        print_array(numbers, size);
    }

    return 0;
}

int rotate_array(int *array, int size, int shift)
{
    int i = 0, j = 0, k = 0;
    int temp[N] = {0};

    shift = shift % size;
    if (shift == 0) 
        return 0;

    for (i = 0; i< shift; i++) {
        temp[i] = array[i];
    }
    for(i=shift, j=0; i < size; i++, j++) {
        array[j] = array[i];
    }
    for(k=0; k<shift; k++, j++) {
        array[j] = temp[k];
    }

    return 0;
}

int read_array(int *r, int count)
{
    int temp = 0;
    int i = 0;
    
    if (count > N) {
        printf("Insufficient space for input numbers.\n");
        return 1;
    }

    for(; i < count; i++)
    {
        scanf("%d", &r[i]);
    }

    return 0;
}

int print_array(int *r, int size)
{
    int i = 0;

    if (size > N) {
        size = N;
        printf("Array size larger than allocated space.  Printing first %d numbers.\n", N);
    }

    for(i = 0; i < size; i++)
    {
        printf("%d ", r[i]);
    }
    printf("\n");

    return 0;
}


