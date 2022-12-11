#include <stdio.h>

#define MAXSIZE 50

int read_array(int *r, int *count);
int print_array(int *r, int size);
int f3sum(int *r, int size, int number);

int main()
{
    int size = 0; 
    int array[MAXSIZE] = {0};
    int number;

	read_array(array, &size);
    printf("Enter the sum: \n");
	scanf("%d", &number);
    f3sum(array, size, number);

    return 0;

}

int f3sum(int *array, int size, int sum)
{
    int i = 0, found = 0, tsum = 0;
    int left = 0, right = size-1;

    if (size > MAXSIZE)
        return 1;

	i = 0;
	while ((!found) && (i < size)) {
		left = 0; right = size-1;
		tsum = sum - array[i];
        while ((!found) && (left < right)) {
		    if ((left == i) || (right == i)) {
		        if (i == left) 
			        left++;
                else 
			        right--;
            } else { 
	    	    if (tsum > (array[left] + array[right])) {
	    	        left++;
                } else if (tsum < (array[left] + array[right])) {
	                right--;
                } else {
		            found = 1;
                }
            }
		}
		if (!found) 
		    i++;
    }
    if (found)
        printf("Numbers at indexes %d, %d and %d sum to %d\n", i, left, right, sum);
    else 
        printf("No numbers sum up to %d\n", sum);

    return (!found);
}




int read_array(int *r, int *count)
{
    int temp = 0;
    int i = 0;
    
    printf("Enter size of array and elements: \n");
    scanf("%d", count);

    for(; i < MAXSIZE && i < *count; i++)
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


