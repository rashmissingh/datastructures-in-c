#include <stdio.h>

#define MAXSIZE 100

int read_array(int *r, int *count);
int print_array(int *r, int size);
int insertion_sort(int *r, int size);
void swap(int *a, int *b);

int main()
{
    int i = 0, position = -1, size = 0; 
    int numbers[MAXSIZE] = {0};
    /*size = sizeof(numbers)/sizeof(numbers[0]);*/

    read_array(numbers, &size);

    insertion_sort(numbers, size);

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;

}

int insertion_sort(int *array, int size)
{
    int i = 0, ptr=0, sorted = 0;

    for(i=1; i<size; i++) {
	sorted = 0, ptr = i;
        printf("i = %2d, ", i);
	print_array(array, size);
        while ((ptr > 0) && (!sorted)) {
	    if (array[ptr -1] > array[ptr]) {
	        swap(&array[ptr-1], &array[ptr]);
            }
            else { /* (array[ptr -1] <= array[ptr]) */
                sorted = 1;
            }
	    printf("\t"); print_array(array, size);
	    ptr--;
        }
    }
    return 0;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int read_array(int *r, int *count)
{
    int temp = 0;
    int i = 0;
    

    scanf("%d", &temp);

    for(; i < MAXSIZE && temp >= 0; i++)
    {
        r[i] = temp;
        scanf("%d", &temp);
    }

    *count = i;

    if (i == MAXSIZE)
        return 1;

    return 0;
}

int print_array(int *r, int size)
{
    int i = 0;

    if (size > MAXSIZE)
        return 1;

    for(i = 0; i < size; i++)
    {
        printf("%d ", r[i]);
    }
    printf("\n");

    return 0;
}


