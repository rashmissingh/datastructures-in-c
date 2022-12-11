#include <stdio.h>

#define MAXSIZE 11

int read_array(int *r, int *count);
int print_array(int *r, int size);
int selection_sort(int *r, int size);
void swap(int *a, int *b);

int main()
{
    int i = 0, position = -1, size = 0; 
    int numbers[MAXSIZE] = {6, 7, 8, 9, 10, 0, 1, 2, 3, 4, 5};

    size = sizeof(numbers)/sizeof(numbers[0]);

    selection_sort(numbers, size);

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;

}

int selection_sort(int *array, int size)
{
    int i = 0, j =0, min = 0;

    for(i=0; i<size; i++) {
	min = i;
        for (j = i+1; j < size; j++) {
	    if (array[min] > array[j]) {
	        min = j;
            }
        }
	swap(&array[min], &array[i]);
	print_array(array, size);
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


