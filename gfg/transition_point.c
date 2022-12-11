#include <stdio.h>

#define T 100
#define N 500
#define MAX_VALUE 1200

int read_array(int *r, int count);
int transition_point(int *a, int size);

int main(int argc, char *argv[])
{
    int i = 0, xn_pt = 0, size = 0, test_count = 0; 
    int numbers[N] = {0};

    scanf("%d", &test_count);
    if (test_count > T) {
        printf("Executing first %d tests\n", T);
        test_count = T;
    }
    
    for (i = 0; i < test_count; i++) {
        scanf("%d", &size);
        read_array(numbers, size);
        xn_pt = transition_point(numbers, size);
        printf("%d\n", xn_pt);
    }
    return 0;
}

int transition_point(int *array, int size)
{
    int i = 0;

    for(i =0; ((array[i] == 0) && (i < size)); i++);
    return i;
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



