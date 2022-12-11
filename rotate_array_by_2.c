#include <stdio.h>

#define T 100
#define N 500
#define MAX_VALUE 1000

int read_array(int *r, int count);
int print_array(int *r, int size);
int rotate_array(int *a, int size, int shift);

int main(int argc, char *argv[])
{
    int i = 0, shift = 2, size = 0, test_count = 0; 
    int numbers[N] = {0};

    scanf("%d", &test_count);
    if (test_count > T) {
        printf("Executing first %d tests\n", T);
        test_count = T;
    }
    
    for (i = 0; i < test_count; i++) {
        scanf("%d", &size);
        read_array(numbers, size);
        rotate_array(numbers, size, shift);
        print_array(numbers, size);
    }

    return 0;
}

int rotate_array(int *array, int size, int shift)
{
    int i = 0, temp1 = 0, temp2 = 0, temp3 = 0;

	temp1 = array[0]; temp2 = array[1]; temp3 = array[2];
    for(i =0; i < size-3; i++) {
	    printf("i = %d, ai = %d, ai+1 = %d, ai+2 = %d, temp1 = %d, temp2 = %d, temp3 = %d\n", i, array[i], array[i+1], array[i+2], temp1, temp2, temp3);
        array[i+2] = temp1;
		temp1 = temp2;
		temp2 = temp3;
		temp3 = array[i+3];
		print_array(array, size);
    }
	printf("temp1 = %d, temp2 = %d, temp3 = %d\n", temp1, temp2, temp3);
	array[size-1] = temp1;
	array[0] = temp2;
	array[1] = temp3;

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


