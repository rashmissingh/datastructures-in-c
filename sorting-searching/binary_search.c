#include <stdio.h>

#define MAXSIZE 10

int read_array(int *r, int *count);
int print_array(int *r, int size);
int binary_search(int *r, int size, int number, int *position);

int main()
{
    int found = -1, position = 0; 
    int array[MAXSIZE] = {1, 2, 3, 4, 5, 11, 12, 13, 14, 15};
    int number = 7;

    found = binary_search(array, sizeof(array)/sizeof(array[0]), number, &position);

    if (found)
        printf("Number %d found at position %d\n", number, position);
    else 
        printf("Number not found!\n");

    return 0;

}

int binary_search(int *array, int size, int number, int *position)
{
    int i = 0, found = 0;
    int left = 0, right = size-1, mid = ((right+1) - left)/2;

    *position = -1;
    if (size > MAXSIZE)
        return found;

    printf("size = %d, found = %d, left = %d, mid = %d, right = %d\n", size, found, left, mid, right);
    /* if the number is smaller than the smallest and bigger than
       the biggest number, return error */
    if ((number < array[left]) || (number > array[right]))
        return found;

    while ((!found) && (left < right)) {
        mid = left + (((right+1) - left) / 2);
	    if (number == array[mid])
	        found = 1;
	    if (number < array[mid])
	        right = mid - 1;
        if (number > array[mid]) 
	        left = mid + 1;
        printf("found = %d, left = %d, mid = %d, right = %d\n", found, left, mid, right);
    }
    if (found)
        *position = mid;

    return found;
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


