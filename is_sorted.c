#include <stdio.h>

#define T 100
#define N 500
#define MAX_VALUE 1200

int read_array(int *r, int count);
int is_sorted(int *a, int size);

int main(int argc, char *argv[])
{
    int i = 0, sorted = 0, size = 0, test_count = 0; 
    int numbers[N] = {0};

    scanf("%d", &test_count);
    if (test_count > T) {
        printf("Executing first %d tests\n", T);
        test_count = T;
    }
    
    for (i = 0; i < test_count; i++) {
        scanf("%d", &size);
        read_array(numbers, size);
        sorted = is_sorted(numbers, size);
        printf("%d\n", sorted);
    }
    return 0;
}

int is_sorted(int *array, int size)
{
    int i = 0, j =0, sorted = 1;

    for(i =0; ((sorted) && (i+1 < size)); i++) {
       if (array[i] > array[i+1]) {
           sorted = 0; 
       }
    }
    return sorted;
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



