#include <stdio.h>

#define MAXSIZE 11

int read_array(int *r, int *count);
int print_array(int *r, int size);
int find_min(int *r, int size, int *position);

int main()
{
    int position = -1; 
    int numbers[MAXSIZE] = {6, 7, 8, 9, 10, 0, 1, 2, 3, 4, 5};

    find_min(numbers, sizeof(numbers)/sizeof(numbers[0]), &position);
    printf("The minimum number %d is at index = %d\n", numbers[position], position);

    return 0;

}

int find_min(int *array, int size, int *position)
{
    int i = 0, found = 0;
    int left = 0, right = size - 1, mid = -1;

    *position = -1;

    mid = left + (((right+1) - left) / 2);
    if ((array[left] < array[mid]) && (array[mid] < array[right])) {
        *position = 0;
        return 0;
    }
        
    while (!found) {
        if ((mid == left) || (mid == right)) {
            found = 1;
            continue;
        }
        if (array[left] > array[mid]) 
            right = mid;

        if (array[mid] > array[right]) 
            left = mid;
        mid = left + (((right+1) - left) / 2);
    }
    if (found) 
        *position = mid;

    return 0;
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


