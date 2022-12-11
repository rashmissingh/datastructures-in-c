#include <stdio.h>

#define T 100
#define N 100
#define MAX_VALUE 100

int read_array(int *r, int count);
int print_array(int *r, int count);
int remove_duplicates(int *a, int size);

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
        remove_duplicates(numbers, size);
        print_array(numbers, size);
    }
    return 0;
}

int remove_duplicates(int *array, int size)
{
    int i = 0, j = 0, newsize = 0;

	if (size == 1) return 1;
    i=0; j=1; 
    while (j < size) {
	   if (array[i] == array[j]) {
	       while (array[i] == array[j]) j++;
	   }
	   if (j-i > 1) 
           array[i+1] = array[j];
	   i++;
    }

	newsize = i;

	for(;i<size;i++) {
	    array[i] = 0;
	}
    return newsize;
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


