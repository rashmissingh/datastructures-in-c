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
        scanf("%d", &size); scanf("%d", &shift);
        read_array(numbers, size);
        rotate_array(numbers, size, shift);
        print_array(numbers, size);
    }

    return 0;
}

int rotate_array(int *array, int size, int shift)
{
    int i = 0, j = 0, new_pos = -1, temp1 = 0, temp2 = 0;
	int temp[N] = {0};

	if (shift == 0)
	    return 0;
    else 
	    shift = shift % size;
	for (i=0; i<shift;i++) {
	    temp[i] = array[i];
    }
    for(i =0; i < shift; i++) {
		temp1 = temp[i];
        for(j=i; j < size; j=j+shift) {
			new_pos = (j + shift) % size;
			temp2 = array[new_pos];
			array[new_pos] = temp1;
			temp1 = temp2;

	        printf("i = %d, j = %d, new_pos = %d, temp1 = %d, temp2 = %d\n", i, j, new_pos, temp1, temp2);
		    print_array(array, size);
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


