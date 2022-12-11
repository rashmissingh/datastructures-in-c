#include <stdio.h>

#define MAXSIZE 10

int read_array(int *r, int *count);
int print_array(int *r, int size);
int f2sum(int *r, int size, int number);

int main()
{
    int found = -1, size = 0; 
    //int array[MAXSIZE] = {1, 2, 3, 4, 5, 11, 12, 13, 14, 15};
    int array[MAXSIZE] = {0};
    int number = 7;

	read_array(array, &size);
    printf("Enter the sum: \n");
	scanf("%d", &number);
    found = f2sum(array, size, number);

    return 0;

}

int f2sum(int *array, int size, int sum)
{
    int i = 0, found = 0;
    int left = 0, right = size-1;

    if (size > MAXSIZE)
        return 1;

    while ((!found) && (left < right)) {
		if (sum > (array[left] + array[right])) {
		    left++;
        } else if (sum < (array[left] + array[right])) {
	        right--;
        } else {
		    found = 1;
        }
    }
    if (found)
        printf("Numbers at indexes %d and %d sum to %d\n", left, right, sum);
    else 
        printf("No numbers sum up to %d\n", sum);

    return (!found);
}




int read_array(int *r, int *count)
{
    int temp = 0;
    int i = 1;
    
    printf("Enter size of array and elements: \n");
    scanf("%d", count);

    for(; i < MAXSIZE && i <= *count; i++)
    {
        scanf("%d", &temp);
        r[i] = temp;
    }

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


