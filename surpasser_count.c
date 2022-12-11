#include <stdio.h>

#define T 100
#define N 500
#define MAX_VALUE 1000

int read_array(int *r, int count);
int print_array(int *r, int size);
int surpasser_count(int *a, int *count, int size);

int main(int argc, char *argv[])
{
    int i = 0, position = -1, size = 0, test_count = 0; 
    int numbers[N] = {0};
    int surpasser[N] = {0};

    scanf("%d", &test_count);
    if (test_count > T) {
        printf("Executing first %d tests\n", T);
        test_count = T;
    }
    
    for (i = 0; i < test_count; i++) {
        scanf("%d", &size);
        read_array(numbers, size);
        surpasser_count(numbers, surpasser, size);

        print_array(array, size);
        print_array(count, size); printf("\n");
    }

    return 0;
}

int surpasser_count(int *array, int *count, int size)
{
    int i = 0, j =0;

    for(i =0; i < size; i++) {
    count[i] = 0;
        for (j = i+1; j < size; j++) {
            if (array[i] < array[j]) {
               count[i]++;
           }
       }
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

    if (size > N)
        return 1;

    for(i = 0; i < size; i++)
    {
        printf("%d ", r[i]);
    }
    printf("\n");

    return 0;
}


