#include <stdio.h>

#define MAXSIZE 100

int read_array(int *r, int *count);
int print_array(int *r, int size);
int bubble_sort(int *r, int size);
void swap(int *a, int *b);

int main()
{
    int i = 0, position = -1, size = 0; 
    int numbers[MAXSIZE] = {0};
    /*size = sizeof(numbers)/sizeof(numbers[0]);*/

    read_array(numbers, &size);

    bubble_sort(numbers, size);

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;

}

int bubble_sort(int *array, int size)
{
    int i = 0, j =0, sorted = 0;
    int temp;

    for(i =0; ((i < size) && (!sorted)); i++) {
        sorted = 1;
        printf("i = %2d ", i); print_array(array, size);
        for (j = 0; j < size-i-1; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                sorted = 0;
            }
            printf("\t"); print_array(array, size);
        }
    }

    return 0;
}

int bubble_sort1(int *array, int size)
{
    int i = 0, j =0, sorted = 0;
    int temp;

    for(i =0; (!sorted) && (i < size); i++) {
        for (j = i + 1; j < size; j++) {
            sorted = 1;
            if (array[i] > array[j]) {
                swap(&array[i], &array[j]);
                sorted = 0;
            }
        }
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


